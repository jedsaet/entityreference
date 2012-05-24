<?php

/**
 * Implements hook_field_widget_info().
 */
function oggroup_reference_tree_field_widget_info() {
  return array(
    'oggroup_reference_tree' => array (
      'label' => 'Group audience reference tree',
      'field types' => array('group'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM, 
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ),
      'settings' => array(
        'start_minimized' => 0,
        'leaves_only' => 0,
        'filter_view' => '',
        'filter_view_arg_type' => 0,
        'filter_view_arg_key' => '',
        'select_parents' => 0,
        'cascading_selection' => 0,
        'track_list' => 0,
        'token_display' => '',
        'allowed_ids' => '',
        'parent_id' => '',
        'max_depth' => '',
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_settings_form().
 */
function oggroup_reference_tree_field_widget_settings_form($field, $instance) {
  $widget = $instance['widget'];
  $settings = $widget['settings'];
  $form = array();
  
  if ($widget['type'] == 'oggroup_reference_tree') {
    $form['start_minimized'] = array(
      '#type' => 'checkbox',
      '#title' => t('Start minimized'),
      '#description' => t('Make the tree appear minimized on the form by default'),
      '#default_value' => $settings['start_minimized'],
      '#return_value' => 1,
    );
    
    $form['leaves_only'] = array(
      '#type' => 'checkbox',
      '#title' => t('Leaves only'),
      '#description' => t("Don't allow the user to select items that have children"),
      '#default_value' => $settings['leaves_only'],
      '#return_value' => 1,
    );

    $form['select_parents'] = array(
      '#type' => 'checkbox',
      '#title' => t('Select parents automatically'),
      '#description' => t("When turned on, this option causes the widget to automatically select the ancestors of all selected items. In Leaves Only mode, the parents will be added invisibly to the selected value.  <em>This option is only valid if an unlimited number of values can be selected.</em>"),
      '#default_value' => $settings['select_parents'],
      '#element_validate' => array('_entity_reference_tree_select_parents_validate'),
      '#return_value' => 1,
    );

    $form['cascading_selection'] = array(
      '#type' => 'checkbox',
      '#title' => t('Cascading selection'),
      '#description' => t('On parent selection, automatically select children if none were selected. Some may then be manually unselected. In the same way, on parent unselection, unselect children if all were selected. <em>This option is only valid if an unlimited number of values can be selected.</em>'),
      '#default_value' => $settings['cascading_selection'],
      '#element_validate' => array('_entity_reference_tree_cascading_selection_validate'),
      '#return_value' => 1,
    );

    $form['filter_view'] = array(
      '#type' => 'hidden',
      '#value' => $settings['filter_view'],
    );

    $form['filter_view_arg_type'] = array(
      '#type' => 'hidden',
      '#value' => $settings['filter_view_arg_type'],
    );
    
    $form['filter_view_arg_key'] = array(
      '#type' => 'hidden',
      '#value' => $settings['filter_view_arg_key'],
    );

    $form['token_display'] = array(
      '#type' => 'hidden',
      '#value' => $settings['token_display'],
    );
    
    $form['track_list'] = array(
      '#type' => 'checkbox',
      '#title' => t('Track list'),
      '#description' => t(
          'Track what the user has chosen in a list below the tree.
           Useful when the tree is large, with many levels.'),
      '#default_value' => $settings['track_list'],
      '#return_value' => 1,
    );
    
    $form['max_depth'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum Depth'),
      '#description' => t("Only show items up to this many levels deep."),
      '#default_value' => $settings['max_depth'],
      '#size' => 2,
      '#return_value' => 1,
    );    
    
    $form['parent_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Parent Term ID'),
      '#description' => t("Only show items underneath the group with this ID number.  Leave this field blank to not limit groups by parent."),
      '#default_value' => $settings['parent_id'],
      '#size' => 8,
      '#return_value' => 1,
    );    
  }

  return $form;
}

/**
 * Implements hook_field_widget_form().
 */
function oggroup_reference_tree_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $settings = $instance['widget']['settings'];
  $value_key = key($field['columns']);
  $type = $instance['widget']['type'];
  
  $default_value = array();
  if ($items) {
    foreach($items as $item) {
      $key = $item[$value_key];
      if ($key === 0) {
        $default_value[$key] = '0';
      }
      else {
        $default_value[$key] = $key;
      }
    }
  }

  $multiple = $field['cardinality'] > 1 || $field['cardinality'] == FIELD_CARDINALITY_UNLIMITED;
  $properties = array();

  if (!array_key_exists('#value', $element))
    $element['#value'] = array();

  // A switch statement, in case we ever add more widgets to this module.
  switch($instance['widget']['type']) {
    case 'oggroup_reference_tree':
      $element['#field'] = 'oggroup_reference_tree';
      $element['#attached']['js'] = array(drupal_get_path('module', 'entity_reference_tree') . '/entity_reference_tree.js');
      $element['#attached']['css'] = array(drupal_get_path('module', 'entity_reference_tree') . '/entity_reference_tree.css', drupal_get_path('module', 'oggroup_reference_tree') . '/oggroup_reference_tree.css');
      $element['#type'] = 'checkbox_tree';   
      $element['#default_value'] = $multiple ? $default_value : array(reset($default_value) => reset($default_value));
      $element['#max_choices'] = $field['cardinality'];
      $element['#max_depth'] = $settings['max_depth'];
      $element['#start_minimized'] = $settings['start_minimized'];
      $element['#leaves_only'] = $settings['leaves_only'];
      $element['#filter_view'] = '';
      $element['#filter_view_arg_type'] = 0;
      $element['#filter_view_arg_key'] = '';
      $element['#select_parents'] = $settings['select_parents'];
      $element['#cascading_selection'] = $settings['cascading_selection'];
      $element['#track_list'] = $settings['track_list'];
      $element['#allowed_ids'] = ($settings['allowed_ids'] <> '') ? explode(',', str_replace(" ", "", $settings['allowed_ids'])) : array();
      $groups_root = _entity_reference_oggroup_get_oggroup_roots();
      $element['#allowed_bundles'] = array();
      foreach ($groups_root as $k => $group) {
        $element['#allowed_bundles'][$k]['entity_type'] = $group->entity_type;
        $element['#allowed_bundles'][$k]['bundle_name'] = $group->bundle;
        $element['#allowed_bundles'][$k]['parent_id'] = $group->entity_id;
      }
      $element['#token_display'] = '';
      $element['#target_id'] = 'gid';
      $element['#target_name'] = 'name';      
      break;      
  }
  
  $element += array(
    '#value_key' => $value_key,
    '#element_validate' => array('_entity_reference_tree_widget_validate'),
    '#properties' => $properties,
  );

  return $element;
}

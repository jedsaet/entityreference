<?php

/**
 * Implements hook_field_formatter_info().
 */
function oggroup_reference_tree_field_formatter_info() {
  return array(
    'oggroup_tree' => array(
      'label' => 'Group audience reference tree',
      'field types' => array('group'),
      'settings' => array(
        'token_display_selected' => '',
        'token_display_unselected' => '',
      ),
    ),
  );
}


/**
 * Implements hook_field_formatter_view().
 */
function oggroup_reference_tree_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'oggroup_tree':
      $element[] = array(
        '#theme' => 'oggroup_tree_list',
        '#data' => $items,
        '#display' => $display,
        '#attached' => array('css' => array(drupal_get_path('module', 'entity_reference_tree') . '/entity_reference_tree.css', drupal_get_path('module', 'oggroup_reference_tree') . '/oggroup_reference_tree.css')),
      );
      break;
  }

  return $element;
}


/**
 * Implements hook_field_formatter_settings_form().
 */
function oggroup_reference_tree_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();
  
  return $element;
}


/**
 * Implements hook_field_formatter_settings_summary().
 */
function oggroup_reference_tree_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = '';

  return $summary;
}


/**
 * This function returns a list of OG group that don't have any group audience
 *
 * @return
 *   An array of all group entities
 */
function _entity_reference_oggroup_get_oggroup_roots() {
  $query1 = db_select('field_data_group_group', 'g')->fields('g', array('entity_id'));
  $query1->join('field_data_group_audience', 'ga', 'ga.entity_id= g.entity_id AND ga.entity_type = g.entity_type');
  $query1->where('g1.entity_id = g.entity_id');
  $results = db_select('field_data_group_group', 'g1')->fields('g1', array('entity_id', 'entity_type', 'bundle'))->notExists($query1)->execute()->fetchAll(); 
  return $results;
}
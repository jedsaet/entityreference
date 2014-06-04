<?php

/**
 * @file
 * Configure an OG group audience field output format.
 */

/**
 * Implements hook_field_formatter_info().
 */
function og_group_audience_tree_field_formatter_info() {
  return array(
    'og_group_audience_tree' => array(
      'label' => 'OG group audience tree',
      'field types' => array('entityreference'),
      'settings' => array(
        'token_display_selected' => '',
        'token_display_unselected' => '',
        'target_entity' => 'node',
        'target_id' => 'target_id',
      ),
    ),
  );
}


/**
 * Implements hook_field_formatter_view().
 */
function og_group_audience_tree_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'og_group_audience_tree':
      if (!empty($items)) {
        $element[] = array(
          '#theme' => 'entity_reference_widget_tree_list',
          '#data' => $items,
          '#display' => $display,
          '#attached' => array(
            'css' => array(
              drupal_get_path('module', 'entity_reference_widget_tree') . '/entity_reference_widget_tree.css',
              drupal_get_path('module', 'og_group_audience_tree') . '/og_group_audience_tree.css'
            )
          ),
        );
      }
      break;
  }

  return $element;
}


/**
 * Implements hook_field_formatter_settings_form().
 */
function og_group_audience_tree_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $element = array();

  return $element;
}


/**
 * Implements hook_field_formatter_settings_summary().
 */
function og_group_audience_tree_field_formatter_settings_summary($field, $instance, $view_mode) {
  $summary = '';

  return $summary;
}

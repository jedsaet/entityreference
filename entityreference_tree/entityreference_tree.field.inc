<?php

/**
 * @file
 * Configuration of field formatter for entityreference field.
 */

/**
 * Implements hook_field_formatter_info().
 */
function entityreference_tree_field_formatter_info() {
  return array(
    'entityreference_tree' => array(
      'label' => 'Entityreference term tree',
      'field types' => array('entityreference'),
      'settings' => array(
        'token_display_selected' => '',
        'token_display_unselected' => '',
        'target_id' => 'target_id',
      ),
    ),
  );
}


/**
 * Implements hook_field_formatter_view().
 */
function entityreference_tree_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'entityreference_tree':
      if (!empty($items)) {
        $display['settings']['target_entity'] = $field['settings']['target_type'];
        $element[] = array(
          '#theme' => 'entity_reference_tree_list',
          '#data' => $items,
          '#display' => $display,
          '#attached' => array(
            'css' => array(
              drupal_get_path('module', 'entity_reference_tree') . '/entity_reference_tree.css',
              drupal_get_path('module', 'entityreference_tree') . '/entityreference_tree.css'
            ),
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
function entityreference_tree_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $element = array();

  return $element;
}


/**
 * Implements hook_field_formatter_settings_summary().
 */
function entityreference_tree_field_formatter_settings_summary($field, $instance, $view_mode) {
  $summary = '';

  return $summary;
}

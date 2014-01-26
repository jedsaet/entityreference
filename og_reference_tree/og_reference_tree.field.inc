<?php

/**
 * @file
 * Configuration of field formatter for OG group field.
 */

/**
 * Implements hook_field_formatter_info().
 */
function og_reference_tree_field_formatter_info() {
  return array(
    'og_reference_tree' => array(
      'label' => 'OG reference tree',
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
function og_reference_tree_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'og_reference_tree':
      if (!empty($items)) {
        $element[] = array(
          '#theme' => 'entity_reference_tree_list',
          '#data' => $items,
          '#display' => $display,
          '#attached' => array(
            'css' => array(drupal_get_path('module', 'entity_reference_tree') . '/entity_reference_tree.css', drupal_get_path('module', 'og_reference_tree') . '/og_reference_tree.css')
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
function og_reference_tree_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];

  $element = array();

  return $element;
}


/**
 * Implements hook_field_formatter_settings_summary().
 */
function og_reference_tree_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];

  $summary = '';

  return $summary;
}

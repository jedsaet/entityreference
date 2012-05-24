<?php

/**
 * Implements hook_field_formatter_info().
 */
function entityreference_term_tree_field_formatter_info() {
  return array(
    'entityreference_term_tree' => array(
      'label' => 'Entity reference tree',
      'field types' => array('entityreference'),
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
function entityreference_term_tree_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'entityreference_term_tree':
      $element[] = array(
        '#theme' => 'entityreference_term_tree_list',
        '#data' => $items,
        '#display' => $display,
        '#attached' => array('css' => array(drupal_get_path('module', 'entity_reference_tree') . '/entity_reference_tree.css', drupal_get_path('module', 'entityreference_term_tree') . '/entityreference_term_tree.css')),
      );
      break;
  }

  return $element;
}


/**
 * Implements hook_field_formatter_settings_form().
 */
function entityreference_term_tree_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();
  
  return $element;
}


/**
 * Implements hook_field_formatter_settings_summary().
 */
function entityreference_term_tree_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = '';

  return $summary;
}


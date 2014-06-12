<?php

/**
 * @file
 * Provides field widget mechanisms for entity reference widget tree.
 */

/**
 * Themes the OG group tree display (as opposed to the select widget).
 */
function theme_entity_reference_widget_tree_list($variables) {
  $element =& $variables['element'];
  $data =& $element['#data'];
  $tree = array();

  // For each selected group.
  foreach ($data as $item) {
    // Loop if the group ID is not zero:
    $values = array();
    $id = $item[$element['#display']['settings']['target_id']];
    $original_id = $id;
    while ($id != 0) {
      // Unshift the term onto an array.
      array_unshift($values, $id);

      // Repeat with parent group.
      $id = current(module_invoke_all('get_entity_parent', $element, $id));
    }
    $current =& $tree;
    // For each group in the above array.
    foreach ($values as $id) {
      // current[children][group_id] = new array.
      if (!isset($current['children'][$id])) {
        $current['children'][$id] = array('selected' => FALSE);
      }

      // If last value in the array, tree[children][group_id][selected] = true.
      if ($id == $original_id) {
        $current['children'][$id]['selected'] = TRUE;
      }

      $current['children'][$id]['id'] = $id;
      $current =& $current['children'][$id];
    }
  }

  $output = "<div class='entity-reference-widget-tree-list'>";
  $output .= _entity_reference_widget_tree_output_list_level($element, $tree);
  $output .= "</div>";
  return $output;
}

/**
 * Helper function output single level of entity reference widget tree display.
 */
function _entity_reference_widget_tree_output_list_level(&$element, &$tree) {
  if (isset($tree['children']) && is_array($tree['children']) && count($tree['children'] > 0)) {
    $output = '<ul class="entity">';
    $settings = $element['#display']['settings'];
    $tokens_selected = $settings['token_display_selected'];
    $tokens_unselected = ($settings['token_display_unselected'] != '') ? $settings['token_display_unselected'] : $tokens_selected;

    $entity_info = entity_get_info($settings['target_entity']);
    foreach ($tree['children'] as &$item) {
      $entity = $entity_info['load hook']($item['id']);
      $uri = $entity_info['uri callback']($entity);
      $uri['options']['html'] = TRUE;
      $class = $item['selected'] ? 'selected' : 'unselected';
      $output .= "<li class='$class'>";
      if ($tokens_selected != '' && module_exists('token')) {
        $replace = $item['selected'] ? $tokens_selected : $tokens_unselected;
        $output .= token_replace($replace, array('entity' => $entity), array('clear' => TRUE));
      }
      else {
        $output .= l(entity_label($settings['target_entity'], $entity), $uri['path'], $uri['options']);
      }
      if (isset($item['children'])) {
        $output .= _entity_reference_widget_tree_output_list_level($element, $item);
      }
      $output .= "</li>";
    }

    $output .= '</ul>';
    return $output;
  }
}

/**
 * Make sure that cardinality is unlimited if auto-select parents is enabled.
 */
function _entity_reference_widget_tree_select_parents_validate($element, &$form_state) {
  if ($form_state['values']['instance']['widget']['settings']['select_parents'] == 1 && $form_state['values']['field']['cardinality'] != -1) {
    // This is pretty wonky syntax for the field name in form_set_error,
    // but it's correct.
    form_set_error('field][cardinality', t('You must select an Unlimited number of values if Select Parents Automatically is enabled.'));
  }
}

/**
 * Make sure that cardinality is unlimited if cascading selection is enabled.
 */
function _entity_reference_widget_tree_cascading_selection_validate($element, &$form_state) {
  if ($form_state['values']['instance']['widget']['settings']['cascading_selection'] == 1 && $form_state['values']['field']['cardinality'] != -1) {
    // This is pretty wonky syntax for the field name in form_set_error,
    // but it's correct.
    form_set_error('field][cardinality', t('You must select an Unlimited number of values if Cascading selection is enabled.'));
  }
}

/**
 * Processthe checkbox_tree widget.
 *
 * This function processes the checkbox_tree widget.
 *
 * @param array $element
 *   The element to be drawn.
 * @param array $form_state
 *   The form state.
 *
 * @return array
 *   The processed element.
 */
function entity_reference_widget_tree_process_checkbox_tree(array $element, array $form_state) {

  // Retrieve target entity.
  $entity_info = isset($element['#target_entity']) ? entity_get_info($element['#target_entity']) : NULL;

  // Set all default mandatory value to the element.
  entity_reference_widget_tree_prepare_object($element);

  // For Form API element, transform the hierarchical
  // #options array into an object.
  if (isset($element['#options']) && $element['#options'] && !$entity_info) {
    $element['#options_tree'] = entity_reference_widget_tree_array_to_object($element['#options']);
  }

  // Add max choices settings.
  if (!empty($element['#max_choices']) && $element['#max_choices'] != '-1') {
    drupal_add_js(array('entity_reference_widget_tree' => array('trees' => array($element['#id'] => array('max_choices' => $element['#max_choices'])))), 'setting');
  }

  // Get allowed values.
  $allowed = '';
  if (isset($element['#filter_view']) && $element['#filter_view'] != '') {
    $allowed = _entity_reference_widget_tree_get_allowed_values($element);
  }

  // Get default values.
  $value = !empty($element['#default_value']) ? $element['#default_value'] : array();

  // If no #options has been set and the widget is attached
  // to a field entity, retrieve the hierarchy.
  if (empty($element['#options']) && $entity_info) {
    $element['#options_tree'] = module_invoke_all('get_entity_hierarchy', $element, $allowed, $value);

    $required = $element['#required'];
    if ($element['#max_choices'] == 1 && !$required) {
      array_unshift($element['#options_tree'], (object) array(
        $entity_info['entity keys']['id'] => '',
        $entity_info['entity keys']['label'] => 'N/A',
        'depth' => 0,
      ));
    }
    $element['#options'] = _entity_reference_widget_tree_get_options($element['#options_tree'], $allowed, $element['#filter_view'], $entity_info['entity keys']['id'], $entity_info['entity keys']['label']);
  }
  $entities = !empty($element['#options_tree']) ? $element['#options_tree'] : array();

  // Set max choices settings.
  $max_choices = isset($element['#max_choices']) ? $element['#max_choices'] : 1;
  if (array_key_exists('#select_parents', $element) && $element['#select_parents']) {
    $element['#attributes']['class'][] = 'select-parents';
  }
  if ($max_choices != 1) {
    $element['#tree'] = TRUE;
  }

  // Build the tree.
  $tree = new stdClass();
  $tree->children = $entities;
  $element[] = _entity_reference_widget_tree_build_level($element, $tree, $form_state, $value, $max_choices, array(), 1);

  // Add a track list element?
  $track_list = !empty($element['#track_list']) && $element['#track_list'];
  if ($track_list) {
    $element[] = array(
      '#type' => 'checkbox_tree_track_list',
      '#max_choices' => $max_choices,
    );
  }

  return $element;
}

/**
 * Prepare the element before rendering the form.
 *
 * @param array $element
 *   The element to be drawn.
 */
function entity_reference_widget_tree_prepare_object(array &$element) {
  if (!isset($element['#attached'])) {
    $element['#attached']['js'][] = drupal_get_path('module', 'entity_reference_widget_tree') . '/entity_reference_widget_tree.js';
    $element['#attached']['css'][] = drupal_get_path('module', 'entity_reference_widget_tree') . '/entity_reference_widget_tree.css';
  }
  $element['#max_choices'] = isset($element['#max_choices']) ? $element['#max_choices'] : 1;
  $element['#max_depth'] = isset($element['#max_depth']) ? $element['#max_depth'] : '';
  $element['#start_minimized'] = isset($element['#start_minimized']) ? $element['#start_minimized'] : 1;
  $element['#leaves_only'] = isset($element['#leaves_only']) ? $element['#leaves_only'] : 0;
  $element['#filter_view'] = isset($element['#filter_view']) ? $element['#filter_view'] : '';
  $element['#filter_view_arg_type'] = isset($element['#filter_view_arg_type']) ? $element['#filter_view_arg_type'] : 0;
  $element['#allowed_ids'] = isset($element['#allowed_ids']) ? $element['#allowed_ids'] : array();
  $element['#select_parents'] = isset($element['#select_parents']) ? $element['#select_parents'] : 0;
  if (!isset($element['#element_validate']) || !in_array('_entity_reference_widget_tree_validate', $element['#element_validate'])) {
    $element['#element_validate'][] = '_entity_reference_widget_tree_validate';
  }
}

/**
 * Transform an array into an object.
 *
 * @param array $array
 *   The array to convert.
 *
 * @return object
 *   The converted object.
 */
function entity_reference_widget_tree_array_to_object(array $array) {
  $result_obj = new stdClass();
  $result_arr = array();
  $has_int_keys = FALSE;
  $has_str_keys = FALSE;
  foreach ($array as $k => $v) {
    if (!$has_int_keys) {
      $has_int_keys = is_int($k);
    }
    if (!$has_str_keys) {
      $has_str_keys = is_string($k);
    }
    if ($has_int_keys && $has_str_keys) {
      $e = new \Exception('Current level has both integer and string keys, thus it is impossible to keep array or convert to object');
      $e->vars = array('level' => $array);
      throw $e;
    }
    if ($has_str_keys) {
      $result_obj->{$k} = is_array($v) ? entity_reference_widget_tree_array_to_object($v) : $v;
    }
    else {
      $result_arr[$k] = is_array($v) ? entity_reference_widget_tree_array_to_object($v) : $v;
    }
  }
  return ($has_str_keys) ? $result_obj : $result_arr;
}

/**
 * Returns HTML for a checkbox_tree form element.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *
 * @ingroup themeable
 */
function theme_checkbox_tree(array $variables) {
  $element = $variables['element'];
  $element['#children'] = drupal_render_children($element);

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'entity-reference-widget-tree';

  if (form_get_error($element)) {
    $attributes['class'][] = 'error';
  }

  if (!empty($element['#required'])) {
    $attributes['class'][] = 'required';
  }

  if (array_key_exists('#start_minimized', $element) && $element['#start_minimized']) {
    $attributes['class'][] = "entity-reference-widget-tree-start-minimized";
  }

  if (array_key_exists('#cascading_selection', $element) && $element['#cascading_selection']) {
    $attributes['class'][] = "entity-reference-widget-tree-cascading-selection";
  }

  if (array_key_exists('#track_list', $element) && $element['#track_list']) {
    $attributes['class'][] = "entity-reference-widget-tree-track-list-shown";
  }

  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }
  return
      '<div' . drupal_attributes($attributes) . '>'
    . (!empty($element['#children']) ? $element['#children'] : '')
    . '</div>';
}

/**
 * Print a list item of checkbox.
 *
 * This function prints a list item with a checkbox and an unordered list,
 * of all the elements inside it.
 */
function theme_checkbox_tree_level($variables) {
  $element = $variables['element'];
  $sm = '';
  if (array_key_exists('#level_start_minimized', $element) && $element['#level_start_minimized']) {
    $sm = " style='display: none;'";
  }

  $output = "<ul class='entity-reference-widget-tree-level '$sm>";
  $children = element_children($element);
  foreach ($children as $child) {
    $output .= "<li>";
    $output .= drupal_render($element[$child]);
    $output .= "</li>";
  }

  $output .= "</ul>";

  return $output;
}

/**
 * Print a single item in the tree.
 *
 * This function prints a single item in the tree, followed by that item's,
 * children (which may be another checkbox_tree_level).
 */
function theme_checkbox_tree_item($variables) {
  $element = $variables['element'];
  $children = element_children($element);
  $output = "";

  $sm = $element['#level_start_minimized'] ? ' entity-reference-widget-tree-collapsed' : '';

  if (is_array($children) && count($children) > 1) {
    $output .= "<div class='entity-reference-widget-tree-button$sm'></div>";
  }
  elseif (!$element['#leaves_only']) {
    $output .= "<div class='no-entity-reference-widget-tree-button'></div>";
  }

  foreach ($children as $child) {
    $output .= drupal_render($element[$child]);
  }

  return $output;
}

/**
 * This function prints a label that cannot be selected.
 */
function theme_checkbox_tree_label($variables) {
  $element = $variables['element'];
  $output = "<div class='parent-entity'>" . $element['#value'] . "</div>";
  return $output;
}

/**
 * Shows a list of items that have been checked.
 *
 * The display happens on the client-side.
 * Use this function to theme the element's label,
 * and the "nothing selected" message.
 *
 * @param array $variables
 *   Variables available for theming.
 */
function theme_checkbox_tree_track_list(array $variables) {
  // Depends on cardinality of entity field, the label is singular or plural.
  static $nothingselected;

  if (!$nothingselected) {
    $nothingselected = t('[Nothing selected]');
    // Add the "Nothing selected" text.
    drupal_add_js(
      'var entityReferenceWidgetTreeNothingSelectedText = "' . $nothingselected . '";',
      'inline'
    );
  }

  $label = format_plural(
      $variables['element']['#max_choices'],
      'Selected item (click the item to uncheck it)',
      'Selected items (click an item to uncheck it)'
  );
  $output = '<div class="entity-reference-widget-tree-track-list-container">';
  $output .= '<div class="entity-reference-widget-tree-track-list-label">' . $label . '</div>';
  $output .= '<ul class="entity-reference-widget-tree-track-list"><li class="entity-reference-widget-tree-nothing-message">' . $nothingselected . '</li></ul>';
  $output .= '</div>';

  return $output;
}

/**
 * Validates the entity reference Widget tree.
 *
 * This function sets the value of the tree widgets into a form
 * that Drupal can understand, and also checks if the field is
 * required and has been left empty.
 *
 * @param array $element
 *   The element to be validated.
 * @param array $form_state
 *   The state of the form.
 *
 * @return array
 *   The validated element.
 */
function _entity_reference_widget_tree_validate(array &$element, array &$form_state) {
  $items = _entity_reference_widget_tree_flatten($element, $form_state);
  $value = array();

  if ($element['#max_choices'] != 1) {
    foreach ($items as $child) {
      if (!empty($child['#value'])) {
        array_push($value, array($element['#value_key'] => $child['#value']));

        // If the element is leaves only and select parents is on,
        // then automatically add all the parents of each selected value.
        if ($element['#select_parents'] && $element['#leaves_only']) {
          foreach ($child['#parent_values'] as $parent_id) {
            if (!in_array(array($element['#value_key'] => $parent_id), $value)) {
              array_push($value, array($element['#value_key'] => $parent_id));
            }
          }
        }
      }
    }
  }
  else {
    // If it's a tree of radio buttons, they all have the same value,
    // so we can just grab the value of the first one.
    if (count($items) > 0) {
      $child = reset($items);
      if (!empty($child['#value'])) {
        array_push($value, array($element['#value_key'] => $child['#value']));
      }
    }
  }

  if ($element['#required'] && empty($value)) {
    // The title is already check_plained so it's appropriate to use !.
    form_error($element, t('!name field is required.', array('!name' => $element['#title'])));
  }

  form_set_value($element, $value, $form_state);
  return $element;
}

/**
 * Returns an array of allowed values defined by the given view.
 *
 * @param array $element
 *   A view, in the format VIEWNAME:DISPLAYNAME.
 *
 * @return array
 *   An array of entity IDs ({id} => true) returned by the view.
 */
function _entity_reference_widget_tree_get_allowed_values(array $element) {
  $filter = $element['#filter_view'];
  $arg_type = $element['#filter_view_arg_type'];
  $arg_value = $element['#filter_view_arg_key'];
  $entity_info = entity_get_info($element['#target_entity']);
  $id = $entity_info['entity keys']['id'];
  $viewname = "";
  $displayname = "";
  $args = "";
  $allowed = array();
  $viewname = "";
  $displayname = "";

  // Get the arguments for the view.
  if ($arg_type == 1 && is_numeric($arg_value)) {
    $args = arg($arg_value);
  }
  if ($arg_type == 2 && $arg_value <> '' && isset($_REQUEST[$arg_value])) {
    if (is_array($_REQUEST[$arg_value])) {
      foreach ($_REQUEST[$arg_value] as $k => $arg) {
        $args .= $arg;
        if ($k < count($arg) - 1) {
          $args .= ',';
        }
      }
    }
    else {
      $args = $_REQUEST[$arg_value];
    }
  }

  if (module_exists('views') && $filter != '') {
    list($viewname, $displayname) = explode(":", $filter);
    $view = views_get_view($viewname);
    if (is_object($view)) {
      if ($view->access($displayname)) {
        // Save the page title first.
        $title = drupal_get_title();
        $view->execute_display($displayname);
        $title = drupal_set_title($title, PASS_THROUGH);
        foreach ($view->result as $item) {
          $allowed[$item->{$id}] = TRUE;
        }
      }
      else {
        drupal_set_message("Cannot access view for entity reference widget tree.", 'warning');
      }
    }
    else {
      drupal_set_message("Entity reference widget tree: no view named '$viewname'", 'warning');
    }
  }

  return $allowed;
}

/**
 * Builds a single item in the entity reference widget tree.
 *
 * This function returns an element with a checkbox for a single entity.
 * If that entity has children, it appends checkbox_tree_level element that
 * contains the children.  It is meant to be called recursively when the widget
 * is built.
 *
 * @param array $element
 *   The main checkbox_tree element.
 * @param object $entity
 *   An entity object.  $entity->children should be an array of the entity
 *   objects that are that entity's children.
 * @param array $form_state
 *   The form state.
 * @param string $value
 *   The value of the element.
 * @param int $max_choices
 *   The maximum number of allowed selections.
 *
 * @return array
 *   A completed checkbox_tree_item element, which contains a checkbox and
 *   possibly a checkbox_tree_level element as well.
 */
function _entity_reference_widget_tree_build_item(array &$element, &$entity, array $form_state, $value, $max_choices, $parent_ids, $parent, $depth) {
  $entity_info = isset($element['#target_entity']) ? entity_get_info($element['#target_entity']) : NULL;
  $id = isset($entity_info['entity keys']['id']) ? $entity_info['entity keys']['id'] : 'value';

  $leaves_only = FALSE;
  if (array_key_exists('#leaves_only', $element)) {
    $leaves_only = $element['#leaves_only'];
  }

  $entity_name = isset($entity_info['entity keys']['label']) ? $entity->{$entity_info['entity keys']['label']} : $entity->title;

  $container = array(
    '#type' => 'checkbox_tree_item',
    '#max_choices' => $max_choices,
    '#leaves_only' => $leaves_only,
    '#entity_name' => $entity_name,
    '#level_start_minimized' => FALSE,
    '#depth' => $depth,
  );

  if (!$element['#leaves_only'] || count($entity->children) == 0) {
    if (!$element['#allowed_ids'] || in_array($entity->{$id}, $element['#allowed_ids'])) {
      $e = array(
        '#type' => ($max_choices == 1) ? 'radio' : 'checkbox',
        '#title' => $entity_name,
        '#on_value' => $entity->{$id},
        '#off_value' => 0,
        '#return_value' => $entity->{$id},
        '#parent_values' => $parent_ids,
        '#default_value' => isset($value[$entity->{$id}]) ? $entity->{$id} : NULL,
        '#attributes' => isset($element['#attributes']) ? $element['#attributes'] : NULL,
        '#ajax' => isset($element['#ajax']) ? $element['#ajax'] : NULL,
      );
    }
    else {
      $e = array(
        '#type' => 'markup',
        '#suffix' => $entity_name,
      );
    }
    if (isset($element['#token_display']) && $element['#token_display'] != '' && module_exists('token')) {
      $ent = entity_load($entity->type, $entity->{$id});
      $e['#title'] = token_replace($element['#token_display'], array('entity' => $ent), array('clear' => TRUE));
    }

    if ($e['#type'] == 'radio') {
      $parents_for_id = array_merge($element['#parents'], array($entity->{$id}));
      $e['#id'] = drupal_html_id('edit-' . implode('-', $parents_for_id));
      $e['#parents'] = $element['#parents'];
    }
  }
  else {
    $e = array(
      '#type' => 'checkbox_tree_label',
      '#value' => $entity->name,
    );
  }

  $container[$entity->{$id}] = $e;

  if (($depth + 1 <= $element['#max_depth'] || !$element['#max_depth']) && property_exists($entity, 'children') && count($entity->children) > 0) {
    $parents = $parent_ids;
    $parents[] = $entity->{$id};
    $container[$entity->{$id} . '-children'] = _entity_reference_widget_tree_build_level($element, $entity, $form_state, $value, $max_choices, $parents, $depth + 1);
    $container['#level_start_minimized'] = $container[$entity->{$id} . '-children']['#level_start_minimized'];
  }

  return $container;
}

/**
 * Builds a level in the entity reference widget tree.
 *
 * Function returns an element that has a number of checkbox_tree_item elements
 * as children.  It is meant to be called recursively when the widget is built.
 *
 * @param array $element
 *   The main checkbox_tree element.
 * @param object $entity
 *   An entity object.  $entity->children should be an array of the entity
 *   objects that are that entity's children.
 * @param array $form_state
 *   The form state.
 * @param string $value
 *   The value of the element.
 * @param int $max_choices
 *   The maximum number of allowed selections.
 *
 * @return array
 *   A completed checkbox_tree_level element.
 */
function _entity_reference_widget_tree_build_level(array $element, $entity, array $form_state, $value, $max_choices, $parent_ids, $depth) {
  $entity_info = isset($element['#target_entity']) ? entity_get_info($element['#target_entity']) : NULL;
  $start_minimized = FALSE;
  if (array_key_exists('#start_minimized', $element)) {
    $start_minimized = $element['#start_minimized'];
  }

  $leaves_only = FALSE;
  if (array_key_exists('#leaves_only', $element)) {
    $leaves_only = $element['#leaves_only'];
  }

  $container = array(
    '#type' => 'checkbox_tree_level',
    '#max_choices' => $max_choices,
    '#leaves_only' => $leaves_only,
    '#start_minimized' => $start_minimized,
    '#depth' => $depth,
  );

  $container['#level_start_minimized'] = isset($entity->children_selected) ? $depth > 1 && $element['#start_minimized'] && !($entity->children_selected) : $depth > 1 && $element['#start_minimized'];

  foreach ($entity->children as $key => $child) {
    if ($entity_info) {
      $container[$child->{$entity_info['entity keys']['id']}] = _entity_reference_widget_tree_build_item($element, $child, $form_state, $value, $max_choices, $parent_ids, $container, $depth);
    }
    else {
      $container[$key] = _entity_reference_widget_tree_build_item($element, $child, $form_state, $value, $max_choices, $parent_ids, $container, $depth);
    }
  }

  return $container;
}

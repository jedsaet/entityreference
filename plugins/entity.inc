<?php
/**
 * @file
 * The entity.inc is used to handle EntityReference hierarchy
 *
 */

/**
 * Themes the entity tree display (as opposed to the select widget).
 */
function theme_entity_tree_list($variables) {
  $element =& $variables['element'];
  $data =& $element['#data'];

  $tree = array();

  # For each selected entity:
  foreach ($data as $item) {
    # Loop if the entity ID is not zero:
    $values = array();
    $target_id = $item['target_id'];
    $original_target_id = $target_id;
    while ($target_id != 0) {
      # Unshift the entity onto an array
      array_unshift($values, $target_id);
      
      # Repeat with parent entity
      $target_id = _entity_reference_tree_get_term_parent($target_id);
    }
    
    $current =& $tree;
    # For each entity in the above array:
    foreach ($values as $target_id) {
      # current['children']['entity_id'] = new array
      if (!isset($current['children'][$target_id])) {
        $current['children'][$target_id] = array('selected' => FALSE);
      }
      
      # If this is the last value in the array, tree['children']['entity_id']['selected'] = TRUE
      if ($target_id == $original_target_id) {
        $current['children'][$target_id]['selected'] = TRUE;
      }

      $current['children'][$target_id]['target_id'] = $target_id;
      $current =& $current['children'][$target_id];
    }
  }
  
  return _entity_reference_entity_tree_output_list_level($element, $tree);
}

/**
 * Helper function to output a single level of the entity reference tree
 * display.
 */
function _entity_reference_entity_tree_output_list_level(&$element, &$tree) {
  if (isset($tree['children']) && is_array($tree['children']) && count($tree['children'] > 0)) {
    $output = '<ul class="entity">';
    $settings = $element['#display']['settings'];
    $tokens_selected = $settings['token_display_selected'];
    $tokens_unselected = ($settings['token_display_unselected'] != '') ? $settings['token_display_unselected'] : $tokens_selected;

    foreach ($tree['children'] as &$item) {
      $entity = taxonomy_term_load($item['target_id']);
      $uri = taxonomy_term_uri($entity);
      $class = $item['selected'] ? 'selected' : 'unselected';
      $output .= "<li class='$class'>";
      if ($tokens_selected != '' && module_exists('token')) {
        $replace = $item['selected'] ? $tokens_selected : $tokens_unselected;
        $output .= token_replace($replace, array('entity' => $entity), array('clear' => TRUE));
      }
      else {
        $output .= l($entity->name, $uri['path'], array('html' => TRUE));
      }
      if (isset($item['children'])) {
        $output .= _entity_reference_entity_tree_output_list_level($element, $item);
      }
      $output .= "</li>";
    }

    $output .= '</ul>';
    return $output;
  }
}

/**
 * This function returns a taxonomy entity hierarchy in a nested array.
 *
 * @param $array
 *   An array containing the ID of the root entity and the ID of the vocabulary
 * @param $vid
 *   The vocabulary ID to restrict the child search.
 *
 * @return
 *   A nested array of the entity's child objects.  
 */
function _entity_reference_tree_get_entity_hierarchy($array, &$allowed, $filter, $label) {
  $vid = $array['#vocabulary'];
  $entities = _entity_reference_tree_get_entity_children($array['#parent_id'], $vid);
  
  $result = array();

  if ($filter != '') {
    foreach ($allowed as $k => $v) {
      if (array_key_exists($k, $entities)) {
        $entity =& $entities[$k];
        $children = _entity_reference_tree_get_entity_hierarchy(array('#parent_id' => $entity->target_id, '#vocabulary' => $vid), $allowed, $filter, $label);
        if (is_array($children)) {
          $entity->children = $children;
        }
        array_push($result, $entity);
      }      
    }
  }
  else {
    foreach ($entities as &$entity) {
      if ($filter == '' || array_key_exists($entity->target_id, $allowed)) {
        $children = _entity_reference_tree_get_entity_hierarchy(array('#parent_id' => $entity->target_id, '#vocabulary' => $vid), $allowed, $filter, $label);
        if (is_array($children)) {
          $entity->children = $children;
        }
        array_push($result, $entity);
      }
    }
  }
  
  return $result;
}

/**
 * This function is like taxonomy_get_children, except it doesn't load the entire term.
 *
 * @param $tid
 *   The ID of the term whose children you want to get.
 * @param $vid
 *   The vocabulary ID.
 *
 * @return
 *   An array of taxonomy terms, each in the form array('tid' => $tid, 'name' => $name)
 */
function _entity_reference_tree_get_entity_children($tid, $vid) {
  //Should this use the new DB layer?
  $q = db_query("SELECT d.tid, d.name FROM {taxonomy_term_data} d INNER JOIN {taxonomy_term_hierarchy} h ON d.tid = h.tid WHERE d.vid = :vid AND h.parent = :tid ORDER BY d.weight, d.name, d.tid", array(':vid' => $vid, ':tid'  => $tid));

  $terms = array();
  
  foreach ($q as $term) {
    $term->target_id = $term->tid;
    unset($term->tid);
    $terms[$term->target_id] = (object) $term;
  }

  return $terms;
}

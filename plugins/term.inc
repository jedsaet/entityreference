<?php
/**
 * @file
 * The entity.inc is used to handle Taxonomy Term Reference hierarchy
 *
 */

/**
 * Themes the term tree display (as opposed to the select widget).
 */
function theme_term_tree_list($variables) {
  $element =& $variables['element'];
  $data =& $element['#data'];

  $tree = array();

  # For each selected term:
  foreach ($data as $item) {
    # Loop if the term ID is not zero:
    $values = array();
    $tid = $item['tid'];
    $original_tid = $tid;
    while ($tid != 0) {
      # Unshift the term onto an array
      array_unshift($values, $tid);
      
      # Repeat with parent term
      $tid = _entity_reference_tree_get_term_parent($tid);
    }
    
    $current =& $tree;
    # For each term in the above array:
    foreach ($values as $tid) {
      # current['children']['term_id'] = new array
      if (!isset($current['children'][$tid])) {
        $current['children'][$tid] = array('selected' => FALSE);
      }
      
      # If this is the last value in the array, tree['children']['term_id']['selected'] = TRUE
      if ($tid == $original_tid) {
        $current['children'][$tid]['selected'] = TRUE;
      }

      $current['children'][$tid]['tid'] = $tid;
      $current =& $current['children'][$tid];
    }
  }
  
  return _entity_reference_term_tree_output_list_level($element, $tree);
}

/**
 * Helper function to output a single level of the term reference tree
 * display.
 */
function _entity_reference_term_tree_output_list_level(&$element, &$tree) {
  if (isset($tree['children']) && is_array($tree['children']) && count($tree['children'] > 0)) {
    $output = '<ul class="term">';
    $settings = $element['#display']['settings'];
    $tokens_selected = $settings['token_display_selected'];
    $tokens_unselected = ($settings['token_display_unselected'] != '') ? $settings['token_display_unselected'] : $tokens_selected;

    foreach ($tree['children'] as &$item) {
      $term = taxonomy_term_load($item['tid']);
      $uri = taxonomy_term_uri($term);
      $class = $item['selected'] ? 'selected' : 'unselected';
      $output .= "<li class='$class'>";
      if ($tokens_selected != '' && module_exists('token')) {
        $replace = $item['selected'] ? $tokens_selected : $tokens_unselected;
        $output .= token_replace($replace, array('term' => $term), array('clear' => TRUE));
      }
      else {
        $output .= l($term->name, $uri['path'], array('html' => TRUE));
      }
      if (isset($item['children'])) {
        $output .= _entity_reference_term_tree_output_list_level($element, $item);
      }
      $output .= "</li>";
    }

    $output .= '</ul>';
    return $output;
  }
}

/**
 * This function returns a taxonomy term hierarchy in a nested array.
 *
 * @param $array
 *   An array containing the ID of the root term and the ID of the vocabulary
 * @param $vid
 *   The vocabulary ID to restrict the child search.
 *
 * @return
 *   A nested array of the term's child objects.  
 */
function _entity_reference_tree_get_term_hierarchy($array, &$allowed, $filter, $label) {
  $vid = $array['#vocabulary'];
  $terms = _entity_reference_tree_get_term_children($array['#parent_id'], $vid);
  
  $result = array();

  if ($filter != '') {
    foreach ($allowed as $k => $v) {
      if (array_key_exists($k, $terms)) {
        $term =& $terms[$k];
        $children = _entity_reference_tree_get_term_hierarchy(array('#parent_id' => $term->tid, '#vocabulary' => $vid), $allowed, $filter, $label);
        if (is_array($children)) {
          $term->children = $children;
        }
        array_push($result, $term);
      }      
    }
  }
  else {
    foreach ($terms as &$term) {
      if ($filter == '' || array_key_exists($term->tid, $allowed)) {
        $children = _entity_reference_tree_get_term_hierarchy(array('#parent_id' => $term->tid, '#vocabulary' => $vid), $allowed, $filter, $label);
        if (is_array($children)) {
          $term->children = $children;
        }
        array_push($result, $term);
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
function _entity_reference_tree_get_term_children($tid, $vid) {
  $q = db_select('taxonomy_term_data', 'd');
  $q->innerJoin('taxonomy_term_hierarchy', 'h', 'h.tid = d.tid');
  $q->condition('d.vid', $vid);
  $q->condition('h.parent', $tid);
  $q->addField('d', 'tid');
  $q->addField('d', 'name');
  $q->orderBy('weight');
  $q->orderBy('name');
  $q->orderBy('tid');
  $r = $q->execute()->fetchAll();
  
  $terms = array();
  
  foreach ($r as $term) {
    $terms[$term->tid] = (object) $term;
  }

  return $terms;
}

function _entity_reference_tree_get_term_parent($tid) {
  $q = db_select('taxonomy_term_hierarchy', 'h');
  $q->condition('tid', $tid);
  $q->addField('h', 'parent');
  $terms = $q->execute()->fetchAll();

  $t = 0;
  foreach ($terms as $term) {
    $t = $term->parent;
  }

  return $t;
}

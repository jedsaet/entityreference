<?php

/**
 * Themes the OG group tree display (as opposed to the select widget).
 */
function theme_oggroup_tree_list($variables) {
  $element =& $variables['element'];
  $data =& $element['#data'];

  $tree = array();

  # For each selected term:
  foreach($data as $item) {
    # Loop if the term ID is not zero:
    $values = array();
    $gid = $item['gid'];
    $original_tid = $gid;
    while($gid != 0) {
      # Unshift the term onto an array
      array_unshift($values, $gid);
      
      # Repeat with parent term
      $gid = _oggroup_reference_tree_get_parent($gid);
    }

    $current =& $tree;
    # For each term in the above array:
    foreach($values as $gid) {
      # current[children][gid] = new array
      if(!isset($current['children'][$gid])) {
        $current['children'][$gid] = array('selected' => FALSE);
      }
      
      # If this is the last value in the array, tree[children][gid][selected] = true
      if($gid == $original_tid) {
        $current['children'][$gid]['selected'] = TRUE;
      }

      $current['children'][$gid]['gid'] = $gid;
      $current =& $current['children'][$gid];
    }
  }
  
  return _entity_reference_tree_output_list_level($element, $tree);
}

/**
 * Helper function to output a single level of the term reference tree
 * display.
 */
function _entity_reference_tree_output_list_level(&$element, &$tree) {
  if(isset($tree['children']) && is_array($tree['children']) && count($tree['children'] > 0)) {
    $output = '<ul class="term">';
    $settings = $element['#display']['settings'];
    $tokens_selected = $settings['token_display_selected'];
    $tokens_unselected = ($settings['token_display_unselected'] != '') ? $settings['token_display_unselected'] : $tokens_selected;

    foreach($tree['children'] as &$item) {
      $group = og_load($item['gid']);
      $info = entity_get_info($group->entity_type);
      $group_entity = og_load_entity_from_group($item['gid']);
      $id = $info['entity keys']['id'];
      $label = $info['entity keys']['label'];
      $uri = $group->entity_type . '/' . $group_entity->$id;
      $class = $item['selected'] ? 'selected' : 'unselected';
      $output .= "<li class='$class'>";
      if($tokens_selected != '' && module_exists('token')) {
        $replace = $item['selected'] ? $tokens_selected : $tokens_unselected;
        $output .= token_replace($replace, array('term' => $term), array('clear' => TRUE));
      }
      else {
        $output .= l($group_entity->$label, 'fred', array('html' => true));
      }
      if(isset($item['children'])) {
        $output .= _entity_reference_tree_output_list_level($element, $item);
      }
      $output .= "</li>";
    }

    $output .= '</ul>';
    return $output;
  }
}

function _oggroup_reference_tree_get_parent($gid) {
  $q = db_query("select h.group_audience_gid from {field_data_group_audience} h inner join {og} og ON (og.etid=h.entity_id AND og.entity_type=h.entity_type) where og.gid = :gid limit 1", array(':gid'  => $gid));

  $g = 0;
  foreach($q as $group) {
    $g = $group->group_audience_gid;
  }

  return $g;
}


/**
 * This function returns a list of OG group that don't have any group audience
 *
 * @return
 *   An array of all group entities
 */
function entity_get_oggroup_roots() {
  $query1 = db_select('field_data_group_group', 'g')->fields('g', array('entity_id'));
  $query1->join('field_data_group_audience', 'ga', 'ga.entity_id= g.entity_id AND ga.entity_type = g.entity_type');
  $query1->where('g1.entity_id = g.entity_id');
  $results = db_select('field_data_group_group', 'g1')->fields('g1', array('entity_id', 'entity_type', 'bundle'))->notExists($query1)->execute()->fetchAll(); 
  return $results;
}
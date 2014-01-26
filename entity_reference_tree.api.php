<?php

/**
 * Retrieve a tree of an entity hierarchy.
 *
 * @param $element
 *   The main checkbox_tree element.
 * @param $allowed_ids
 *   A list of allowed Ids
 * @param $label
 *   A list of allowed Ids
 *
 * @return
 *   A nested tree of entities
 */
function hook_get_entity_hierarchy($element, $allowed_ids, $label = '') {
}

/**
 * Get entity parent item
 *
 * @param $element
 *   The main checkbox_tree element.
 * @param $entity_id
 *   The entity ID
 *
 * @return
 *   The parent IDs
 */
function hook_get_entity_parent($element, $entity_id) {
}

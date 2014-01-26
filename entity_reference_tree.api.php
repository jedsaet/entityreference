<?php

/**
 * @file
 * Hooks provided by the Entity Reference Tree module.
 */

/**
 * Retrieve a tree of an entity hierarchy.
 *
 * @param object $element
 *   The main checkbox_tree element.
 * @param int $allowed_ids
 *   A list of allowed Ids
 * @param string $label
 *   A list of allowed Ids
 *
 * @return object
 *   A nested tree of entities
 */
function hook_get_entity_hierarchy($element, $allowed_ids, $label = '') {
}

/**
 * Get entity parent item
 *
 * @param object $element
 *   The main checkbox_tree element.
 * @param int $entity_id
 *   The entity ID
 *
 * @return int
 *   The parent IDs
 */
function hook_get_entity_parent($element, $entity_id) {
}

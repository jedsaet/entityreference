<?php

/**
 * @file
 * Provides an API for entity reference tree.
 */

/**
 * Retrieve a tree of an entity hierarchy.
 *
 * @param array $element
 *   The main checkbox_tree element.
 * @param array $allowed_ids
 *   A list of allowed Ids
 * @param string $label
 *   A list of allowed Ids
 *
 * @return array
 *   A nested tree of entities
 */
function hook_get_entity_hierarchy($element, $allowed_ids, $label = '') {
}

/**
 * Retrieve the entity parent.
 *
 * @param array $element
 *   The main checkbox_tree element.
 * @param int $entity_id
 *   The entity ID
 *
 * @return object
 *   An entity object
 */
function hook_get_entity_parent($element, $entity_id) {
}

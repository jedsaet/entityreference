<?php

/**
 * @file
 * Hooks provided by the Entity Reference Widget Tree module.
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
function entity_reference_widget_tree_get_entity_hierarchy($element, $allowed_ids, $label = '') {
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
function entity_reference_widget_tree_get_entity_parent($element, $entity_id) {
}

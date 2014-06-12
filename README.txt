***********
* README: *
***********

DESCRIPTION:
------------
Based on the fabulous Taxonomy Term Reference Tree Widget,
this module aim to extend its functionality to display
any type of hierarchical entities in a tree view selection.


INSTALLATION:
-------------
1. Place the entire entity_reference_widget_tree directory
   into your Drupal sites/all/modules/ directory.

2. Enable the Entity Reference Widget Tree module by navigating to:

     administer > modules

   You may choose to activate the submodules upon your need:

   - EntityReference (https://drupal.org/project/entityreference)
   - Group Reference (https://drupal.org/project/group)
   - OG Group audience (https://drupal.org/project/og)
   - Term Reference (Core)


USAGE
-----

You can use it either as a widget attached to a field or you may also use it as a form type (like checkbox or radio), below please find an example

$test = array (
  array(
    'title' => 'Test A',
    'value' => 'A',
    'children' => array(
      array(
        'title' => 'Test A - 1',
        'value' => 'A1',
      ),
      array(
        'title' => 'Test A - 2',
        'value' => 'A2',
      ),
    ),
  ),
  array(
    'title' => 'Test B',
    'value' => 'B',
    'children' => array(
      array(
        'title' => 'Test B - 1',
        'value' => 'B1',
      ),
      array(
        'title' => 'Test B - 2',
        'value' => 'B2',
      ),
    ),
  ),
);

$form['test'] = array(
  '#title' => 'Tree selection test',
  '#description' => '',
  '#type' => 'checkbox_tree',
  '#options' => $test,
);

Author:
-------
Fredrik Lahode
https://drupal.org/user/626634

<?php
/**
 * @file
 * fycsyfy_permissions_and_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function fycsyfy_permissions_and_roles_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  // Exported role: senior editor.
  $roles['senior editor'] = array(
    'name' => 'senior editor',
    'weight' => 4,
  );

  return $roles;
}

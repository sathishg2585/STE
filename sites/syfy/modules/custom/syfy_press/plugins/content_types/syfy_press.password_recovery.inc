<?php

$plugin = array(
  'title' => t('SyFy Press Password recovery'),
  'description' => t('Recovery password form.'),
  'single' => TRUE,
  'content_types' => array('syfy_password_recovery'),
  'render callback' => 'syfy_press_password_recovery_content_type_render',
  'edit form' => 'syfy_press_password_recovery_content_type_edit_form',
  'category' => array(t('SyFy press'), -9),
);

/**
 * Renders plugin with password recovery form.
 */
function syfy_press_password_recovery_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = drupal_get_form('user_pass');

  return $block;
}

/**
 * Settings form for plugin.
 */
function syfy_press_password_recovery_content_type_edit_form($form, &$form_state) {
  return $form;
}

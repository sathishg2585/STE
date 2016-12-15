<?php

$plugin = array(
  'title' => t('FYC Password recovery'),
  'description' => t('Recovery password form.'),
  'single' => TRUE,
  'content_types' => array('fyc_password_recovery'),
  'render callback' => 'fyc_password_recovery_content_type_render',
  'edit form' => 'fyc_password_recovery_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders plugin with password recovery form.
 */
function fyc_password_recovery_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = drupal_get_form('user_pass');

  return $block;
}

/**
 * Settings form for plugin.
 */
function fyc_password_recovery_content_type_edit_form($form, &$form_state) {
  return $form;
}

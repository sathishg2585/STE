<?php

$plugin = array(
  'title' => t('FYC Login Logo'),
  'description' => t('Displays login logo.'),
  'single' => TRUE,
  'content_types' => array('fyc_login_logo'),
  'render callback' => 'fyc_login_logo_content_type_render',
  'category' => array(t('FYC'), -9),
);


/**
 * Renders usa logo for login form.
 */
function fyc_login_logo_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = '<div class="fyc-login-logo"></div>';

  return $block;
}

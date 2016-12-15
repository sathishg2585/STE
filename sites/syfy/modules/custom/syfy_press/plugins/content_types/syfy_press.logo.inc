<?php

$plugin = array(
  'title' => t('SyFy logo'),
  'description' => t('Displays a logo.'),
  'single' => TRUE,
  'content_types' => array('syfy_logo'),
  'render callback' => 'syfy_press_logo_content_type_render',
  'category' => array(t('SyFy press'), -9),
);


/**
 * Renders markup for syfy logo.
 */
function syfy_press_logo_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = '<div class="syfy-press-logo"></div>';

  return $block;
}

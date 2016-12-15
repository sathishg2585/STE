<?php

$plugin = array(
  'title' => t('USA Network logo'),
  'description' => t('Displays a logo.'),
  'single' => TRUE,
  'content_types' => array('usanetwork_logo'),
  'render callback' => 'usanetwork_press_logo_content_type_render',
  'category' => array(t('USA Network press'), -9),
);


/**
 * Renders markup for usanetwork logo.
 */
function usanetwork_press_logo_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = '<div class="usanetwork-press-logo"></div>';

  return $block;
}

<?php

$plugin = array(
  'title' => t('FYC Header'),
  'description' => t('Displays FYC Header'),
  'single' => TRUE,
  'content_types' => array('fyc_header'),
  'render callback' => 'fyc_header_content_type_render',
  'category' => array(t('FYC'), -9),
);


/**
 * Renders fyc header.
 */
function fyc_header_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $content = array(
    '#theme' => 'fyc_header',
  );
  $block->content = $content;
  return $block;
}

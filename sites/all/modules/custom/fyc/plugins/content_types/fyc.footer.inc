<?php

$plugin = array(
  'title' => t('FYC Footer'),
  'description' => t('FYC Footer'),
  'single' => TRUE,
  'content_types' => array('fyc_footer'),
  'render callback' => 'fyc_footer_content_type_render',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders fyc footer.
 */
function fyc_footer_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $content = array(
    '#theme' => 'fyc_footer'
  );
  $block->content = $content;
  return $block;
}

<?php

$plugin = array(
  'title' => t('SyFy page unavailable'),
  'description' => t('Page unavailable.'),
  'single' => TRUE,
  'content_types' => array('syfy_page_unavailable'),
  'render callback' => 'syfy_press_page_unavailable_content_type_render',
  'category' => array(t('SyFy press'), -9),
);


/**
 * Renders markup for syfy page not found.
 */
function syfy_press_page_unavailable_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = '<div class="syfy-error-title"><span>' . t('We\'re Sorry') . '</span></div>';
  $block->content .= '<div class="syfy-error-text"><p>' . t('The page you are trying to reach is unavailable. Perhaps you are looking for something that can be found on Syfy.com?') . '</p></div>';
  $block->content .= '<div class="syfy-error-links">' . l('syfy.com', 'http://www.syfy.com', array(
      'external' => TRUE,
      'attributes' => array(
        'class' => array('button'),
      ),
    )) . '</div>';

  return $block;
}

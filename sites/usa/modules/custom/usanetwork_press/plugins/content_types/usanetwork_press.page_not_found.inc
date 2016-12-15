<?php

$plugin = array(
  'title' => t('USA Network page not found'),
  'description' => t('Page not found.'),
  'single' => TRUE,
  'content_types' => array('usanetwork_page_not_found'),
  'render callback' => 'usanetwork_press_page_not_found_content_type_render',
  'category' => array(t('USA Network press'), -9),
);


/**
 * Renders markup for usanetwork page not found.
 */
function usanetwork_press_page_not_found_content_type_render($subtype, $conf, $args, $context) {
  $page_not_found_beg = 'Error 404';
  $page_not_found_end = 'File Not Found';
  $page_not_found_text = variable_get('404_error_message');
  $block = new stdClass();
  $block->content = '<div class="usanetwork-error-title"><span>' . $page_not_found_beg . '</span> ' . $page_not_found_end . '</div>';
  $block->content .= '<div class="usanetwork-error-text">' . $page_not_found_text['value'] . '</div>';

  return $block;
}

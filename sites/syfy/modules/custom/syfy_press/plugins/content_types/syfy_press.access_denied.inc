<?php

$plugin = array(
  'title' => t('SyFy access denied page'),
  'description' => t('Access denied page.'),
  'single' => TRUE,
  'content_types' => array('syfy_access_denied'),
  'render callback' => 'syfy_press_access_denied_content_type_render',
  'category' => array(t('SyFy press'), -9),
);


/**
 * Renders markup for syfy access denied page.
 */
function syfy_press_access_denied_content_type_render($subtype, $conf, $args, $context) {
  $page_not_found_beg = 'Error 403';
  $page_not_found_end = 'Forbidden';
  $access_denied_text = variable_get('403_error_message');
  $block = new stdClass();
  $block->content = '<div class="syfy-error-title"><span>' . $page_not_found_beg . '</span> ' . $page_not_found_end . '</div>';
  $block->content .= '<div class="syfy-error-text">' . $access_denied_text['value'] . '</div>';

  return $block;
}

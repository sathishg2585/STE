<?php

$plugin = array(
  'title' => t('FYC access denied page'),
  'description' => t('Access denied page.'),
  'single' => TRUE,
  'content_types' => array('fyc_access_denied'),
  'render callback' => 'fyc_access_denied_content_type_render',
  'category' => array(t('FYC'), -9),
);


/**
 * Renders markup for fyc access denied page.
 */
function fyc_access_denied_content_type_render($subtype, $conf, $args, $context) {
  $page_not_found_beg = 'Error 403';
  $page_not_found_end = 'Forbidden';
  $access_denied_text = variable_get('403_error_message');
  
  $link = array(
    'text' => 'Go Back',
    'url' => '<front>',
    'options' => array(),
  );

  $block = new stdClass();
  $block->content = '<div class="fyc-error-title"><span>' . $page_not_found_beg . '</span> ' . $page_not_found_end . '</div>';
  $block->content .= '<div class="fyc-error-text">' . $access_denied_text['value'] . '</div>';
  $block->content .= '<div class="fyc-error-links">' . l($link['text'], $link['url'], array_merge($link['options'], array(
      'attributes' => array(
        'class' => array('button'),
        'onclick' => 'window.history.back();',
      ),
    ))) . '</div>';

  return $block;
}

<?php

$plugin = array(
  'title' => t('FYC page unavailable'),
  'description' => t('Page unavailable.'),
  'single' => TRUE,
  'content_types' => array('fyc_page_unavailable'),
  'render callback' => 'fyc_page_unavailable_content_type_render',
  'category' => array(t('FYC'), -9),
);


/**
 * Renders markup for fyc page not found.
 */
function fyc_page_unavailable_content_type_render($subtype, $conf, $args, $context) {
  $text = variable_get('page_unavailable_error_message', array(
    'value' => '',
    'format' => NULL,
  ));
  $link = variable_get('page_unavailable_link', array(
    'text' => SITE_PARENT,
    'url' => SITE_PARENT_LINK,
    'options' => array(
      'external' => TRUE,
    ),
  ));
  $link += array(
    'text' => '',
    'url' => '<front>',
    'options' => array(),
  );

  $block = new stdClass();
  $block->content = '<div class="fyc-error-title"><span>' . t('We\'re Sorry') . '</span></div>';
  $block->content .= '<div class="fyc-error-text">' . check_markup($text['value'], $text['format']) . '</div>';
  $block->content .= '<div class="fyc-error-links">' . l($link['text'], $link['url'], array_merge($link['options'], array(
      'attributes' => array(
        'class' => array('button'),
      ),
    ))) . '</div>';

  return $block;
}

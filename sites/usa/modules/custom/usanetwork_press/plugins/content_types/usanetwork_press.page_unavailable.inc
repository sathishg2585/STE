<?php

$plugin = array(
  'title' => t('USA Network page unavailable'),
  'description' => t('Page unavailable.'),
  'single' => TRUE,
  'content_types' => array('usanetwork_page_unavailable'),
  'render callback' => 'usanetwork_press_page_unavailable_content_type_render',
  'category' => array(t('USA Network press'), -9),
);


/**
 * Renders markup for usanetwork page not found.
 */
function usanetwork_press_page_unavailable_content_type_render($subtype, $conf, $args, $context) {
  $text = variable_get('page_unavailable_error_message', array(
    'value' => '',
    'format' => NULL,
  ));
  $link = variable_get('page_unavailable_link', array(
    'text' => 'usanetwork.com',
    'url' => 'http://www.usanetwork.com',
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
  $block->content = '<div class="usanetwork-error-title"><span>' . t('We\'re Sorry') . '</span></div>';
  $block->content .= '<div class="usanetwork-error-text">' . check_markup($text['value'], $text['format']) . '</div>';
  $block->content .= '<div class="usanetwork-error-links">' . l($link['text'], $link['url'], array_merge($link['options'], array(
      'attributes' => array(
        'class' => array('button'),
      ),
    ))) . '</div>';

  return $block;
}

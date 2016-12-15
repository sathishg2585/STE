<?php

$plugin = array(
  'title' => t('FYC Video Page'),
  'description' => t('FYC Video Page'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('fyc_video_page'),
  'render callback' => 'fyc_video_page_content_type_render',
  'edit form' => 'fyc_video_page_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders fyc video
 */
function fyc_video_page_content_type_render($subtype, $conf, $args, $context) {

  if (empty($context) || empty($context->data) || $context->data->type != 'fyc_video') {
    return FALSE;
  }

  $block = new stdClass();
  $block->content = '';

  $node_wrapper = entity_metadata_wrapper('node', $context->data->nid);
  $video_category = $node_wrapper->{'field_fyc_mpx_feed_url'}->value();

  $data = array(
    'video_category' => $video_category,
  );

  $content = array(
    '#theme' => 'fyc_video_page',
    '#content' => $data,
  );
  $block->content = $content;

  return $block;

}

/**
 * Settings form for plugin.
 */
function fyc_video_page_content_type_edit_form($form, &$form_state) {
  return $form;
}

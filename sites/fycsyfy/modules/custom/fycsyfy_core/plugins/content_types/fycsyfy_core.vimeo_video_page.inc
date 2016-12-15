<?php

$plugin = array(
  'title' => t('FYC Syfy Vimeo Video Page'),
  'description' => t('FYC Syfy Vimeo Video Page'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('fycsyfy_core_vimeo_video_page'),
  'render callback' => 'fycsyfy_core_vimeo_video_page_content_type_render',
  'edit form' => 'fycsyfy_core_vimeo_video_page_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders fyc syfy vimeo video
 */
function fycsyfy_core_vimeo_video_page_content_type_render($subtype, $conf, $args, $context) {

  if (empty($context) || empty($context->data) || $context->data->type != 'fycsyfy_vimeo_video') {
    return FALSE;
  }

  $block = new stdClass();
  $block->content = '';

  $node_wrapper = entity_metadata_wrapper('node', $context->data->nid);
  $fycsyfy_vimeo_list = $node_wrapper->field_fycsyfy_vimeo_list;

  $data = array(
    'fycsyfy_vimeo_list' => $fycsyfy_vimeo_list
  );

  $content = array(
    '#theme' => 'fycsyfy_core_vimeo_video_page',
    '#content' => $data,
  );
  $block->content = $content;

  return $block;

}

/**
 * Settings form for plugin.
 */
function fycsyfy_core_vimeo_video_page_content_type_edit_form($form, &$form_state) {
  return $form;
}

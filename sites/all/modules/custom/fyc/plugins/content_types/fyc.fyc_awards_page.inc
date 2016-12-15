<?php

$plugin = array(
  'title' => t('FYC Awards Page'),
  'description' => t('FYC Awards Page'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('fyc_awards_page'),
  'render callback' => 'fyc_awards_page_content_type_render',
  'edit form' => 'fyc_awards_page_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Render fyc awards page
 */
function fyc_awards_page_content_type_render($subtype, $conf, $args, $context) {

  if (empty($context) || empty($context->data) || $context->data->type != 'fyc_award') {
    return FALSE;
  }

  $block = new stdClass();
  $block->content = '';

  $node_wrapper = entity_metadata_wrapper('node', $context->data->nid);
  $fyc_awards_list = $node_wrapper->field_fyc_awards_list;

  $data = array(
    'fyc_awards_list' => $fyc_awards_list
  );

  $content = array(
    '#theme' => 'fyc_awards_page',
    '#content' => $data,
  );
  $block->content = $content;

  return $block;

}

/**
 * Settings form for plugin.
 */
function fyc_awards_page_content_type_edit_form($form, &$form_state) {
  return $form;
}

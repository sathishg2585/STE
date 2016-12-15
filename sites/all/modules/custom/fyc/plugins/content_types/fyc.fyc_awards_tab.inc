<?php

$plugin = array(
  'title' => t('FYC Awards Tab'),
  'description' => t('FYC Awards Tab'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('fyc_awards_tab'),
  'render callback' => 'fyc_awards_tab_content_type_render',
  'edit form' => 'fyc_awards_tab_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Render fyc awards tab
 */
function fyc_awards_tab_content_type_render($subtype, $conf, $args, $context) {

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
    '#theme' => 'fyc_awards_tab',
    '#content' => $data,
  );
  $block->content = $content;

  return $block;

}

/**
 * Settings form for plugin.
 */
function fyc_awards_tab_content_type_edit_form($form, &$form_state) {
  return $form;
}

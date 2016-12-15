<?php

$plugin = array(
  'title' => t('FYC node link'),
  'description' => t('Displays a link.'),
  'single' => TRUE,
  'content_types' => array('fyc_node_link'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'render callback' => 'fyc_node_link_content_type_render',
  'edit form' => 'fyc_node_link_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);


/**
 * Renders markup for node.
 */
function fyc_node_link_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $block = new stdClass();
  $block->content = '<a href="' . url('node/' . $context->data->nid) . '" class="fyc-pres-row-link"></a>';

  return $block;
}

/**
 * Settings form for plugin.
 */
function fyc_node_link_content_type_edit_form($form, &$form_state) {
  return $form;
}

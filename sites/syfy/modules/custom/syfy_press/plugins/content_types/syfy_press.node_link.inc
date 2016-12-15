<?php

$plugin = array(
  'title' => t('SyFy node link'),
  'description' => t('Displays a link.'),
  'single' => TRUE,
  'content_types' => array('syfy_node_link'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'render callback' => 'syfy_press_node_link_content_type_render',
  'edit form' => 'syfy_press_node_link_content_type_edit_form',
  'category' => array(t('SyFy press'), -9),
);


/**
 * Renders markup for syfy logo.
 */
function syfy_press_node_link_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $block = new stdClass();
  $block->content = '<a href="' . url('node/' . $context->data->nid) . '" class="syfy-pres-row-link"></a>';

  return $block;
}

/**
 * Settings form for plugin.
 */
function syfy_press_node_link_content_type_edit_form($form, &$form_state) {
  return $form;
}

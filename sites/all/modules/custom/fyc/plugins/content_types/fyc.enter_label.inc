<?php

$plugin = array(
  'title' => t('FYC Enter Site label'),
  'description' => t('Displays a label.'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('fyc_enter_laber'),
  'render callback' => 'fyc_enter_label_content_type_render',
  'edit form' => 'fyc_enter_label_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders "enter site lablel".
 */
function fyc_enter_label_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $label = t('Enter show site');

  if (!empty($context->data) && $context->data->type == 'fyc_show') {
    $wrapper = entity_metadata_wrapper('node', $context->data);
    $enter_button = $wrapper->{'field_fyc_show_enter_button'}->value();
    if (!empty($enter_button)) {
      $label = $enter_button;
    }
  }

  $block->content = '<div class="enter-site-label"><div class="fyc-enter-site-label">'. $label .'</div></div>';
  return $block;
}

function fyc_enter_label_content_type_edit_form($form, &$form_state) {
  return $form;
}

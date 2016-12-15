<?php

$plugin = array(
  'title' => t('USA Network Enter Press Site label'),
  'description' => t('Displays a label.'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('usanetwork_enter_laber'),
  'render callback' => 'usanetwork_enter_label_content_type_render',
  'edit form' => 'usanetwork_enter_label_content_type_edit_form',
  'category' => array(t('USA Network press'), -9),
);

/**
 * Renders "enter site lablel".
 */
function usanetwork_enter_label_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $label = t('Enter press site');

  if (!empty($context->data) && $context->data->type == 'press_kit') {
    $wrapper = entity_metadata_wrapper('node', $context->data);
    $enter_button = $wrapper->{'field_press_enter_button'}->value();
    if (!empty($enter_button)) {
      $label = $enter_button;
    }
  }

  $block->content = '<div class="enter-site-label"><div class="usanetwork-press-enter-site-label">'. $label .'</div></div>';
  return $block;
}

function usanetwork_enter_label_content_type_edit_form($form, &$form_state) {
  return $form;
}

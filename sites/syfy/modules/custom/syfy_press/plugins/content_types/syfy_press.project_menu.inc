<?php

$plugin = array(
  'title' => t('SyFy Press Project menu'),
  'description' => t('Displays a menu.'),
  'single' => TRUE,
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'content_types' => array('syfy_project_menu'),
  'render callback' => 'syfy_press_project_menu_content_type_render',
  'edit form' => 'syfy_press_project_menu_content_type_edit_form',
  'category' => array(t('SyFy press'), -9),
);

/**
 * Renders plugin with node links.
 */
function syfy_press_project_menu_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $items = array();
  $block = new stdClass();

  $attributes = array(
    'id' => 'syfy-project-menu',
    'class' => 'syfy-project-menu-list',
  );

  $items[] = array(
    'data' => l('Edit Project', 'node/' . $context->data->nid . '/edit'),
    'class' => array('syfy-project_menu-item'),
  );

  $block->content = theme('item_list', array(
    'items' => $items,
    'title'=> '',
    'type' => 'ul',
    'attributes' => $attributes,
  ));
  return $block;
}

/**
 * Settings form for plugin.
 */
function syfy_press_project_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}

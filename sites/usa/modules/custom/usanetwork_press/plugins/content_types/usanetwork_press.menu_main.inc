<?php
/**
 * @file
 * Plugin to provide access control based upon a parent term.
 */

$plugin = array(
  'title' => t('Main menu'),
  'description' => t('Main menu on press kit pages.'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('usanetwork_menu_main'),
  'render callback' => 'usanetwork_press_menu_main_content_type_render',
  'edit form' => 'usanetwork_press_menu_main_content_type_edit_form',
  'category' => array(t('USA Network press'), -9),
);

function usanetwork_press_menu_main_content_type_render($subtype, $conf, $args, $context) {

  if (empty($context) || empty($context->data) || $context->data->type != 'press_kit') {
    return FALSE;
  }

  $field_tax_item = entity_metadata_wrapper('node', $context->data->nid)->field_press_kit_tax_item->value();
  $tax_items = taxonomy_get_children($field_tax_item->tid, $field_tax_item->vid);

  $attributes = array(
    'id' => 'usanetwork-main-menu',
    'class' => 'usanetwork-main-menu-list',
  );

  foreach($tax_items as $item) {
    $alias = drupal_get_path_alias('taxonomy/term/' . $item->tid);
    $current_path = current_path();
    $path_alias = drupal_lookup_path('alias', $current_path);
    $class_selected = strpos($path_alias, $alias) === 0 ? 'active' : NULL;

    if ($class_selected && !empty($path_alias[strlen($alias)]) && $path_alias[strlen($alias)] != '/') {
      $class_selected = NULL;
    }

    $items[] = array(
        'data' => l($item->name, $alias),
        'id' => 'usanetwork_main_menu_item_' . $item->tid,
        'class' => array('usanetwork-main-menu-item', $class_selected),
    );
  }

  $block = new stdClass();
  $block->content = theme('item_list', array(
    'items' => $items,
    'title'=> '',
    'type' => 'ul',
    'attributes' => $attributes,
  ));
  return $block;
}

function usanetwork_press_menu_main_content_type_edit_form($form, &$form_state) {
  return $form;
}

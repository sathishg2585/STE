<?php

$plugin = array(
  'title' => t('FYC Tab'),
  'description' => t('Tab on show pages.'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('fyc_tab'),
  'render callback' => 'fyc_tab_content_type_render',
  'edit form' => 'fyc_tab_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders fyc inner page tab
 */
function fyc_tab_content_type_render($subtype, $conf, $args, $context) {

  if (empty($context) || empty($context->data) || $context->data->type != 'fyc_show') {
    return FALSE;
  }

  $field_tax_item = entity_metadata_wrapper('node', $context->data->nid)->field_fyc_show_tax_item->value();
  $tax_items = taxonomy_get_children($field_tax_item->tid, $field_tax_item->vid);

  $attributes = array(
    'id' => 'fyc-tab',
    'class' => 'fyc-tab-list tabs',
  );
  $zindex = 99;
  foreach($tax_items as $item) {
    $alias = drupal_get_path_alias('taxonomy/term/' . $item->tid);
    $current_path = current_path();
    $extract_tid = substr(strrchr($current_path, "/"), 1);
    if ($extract_tid != '') {
      $extract_tid_parents = taxonomy_get_parents($extract_tid);
      if (count($extract_tid_parents) > 0) {
        $item_parent = array_shift($extract_tid_parents);
        $class_selected = ($item_parent->name == $item->name) ? 'current' : '';

        $items[] = array(
            'data' => l($item->name, $alias, array('attributes' => array('class' => $class_selected))),
            'id' => 'fyc_tab_list_item_' . $item->tid,
            'class' => array('fyc-tab-list-item'),
            'style' => 'z-index: '.$zindex
        );
        $zindex--;
      }
    }
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

function fyc_tab_content_type_edit_form($form, &$form_state) {
  return $form;
}

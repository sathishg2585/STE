<?php
/**
 * @file
 * Plugin to provide access control based upon a parent term.
 */

$plugin = array(
  'title' => t('Secondary menu'),
  'description' => t('Secondary menu on press kit pages.'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('syfy_secondary_menu'),
  'render callback' => 'syfy_press_secondary_menu_content_type_render',
  'edit form' => 'syfy_press_secondary_menu_content_typ_edit_form',
  'category' => array(t('SyFy press'), -9),
);

/**
 * Plugin logic.
 */
function syfy_press_secondary_menu_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $node = $context->data;
  $wrapper = entity_metadata_wrapper('node', $node);

  $menu_position = $wrapper->{'field_menu_position'}->value();

  if (empty($menu_position)) {
    return FALSE;
  }
  $parents = taxonomy_get_parents_all($menu_position->tid);
  if (count($parents) < 2) {
    return FALSE;
  }
  $term = $parents[count($parents)-2];
  $items = _syfy_press_secondary_menu_content_type_items($term);

  $block = new stdClass();
  $attributes = array(
    'id' => 'syfy-secondary-menu',
    'class' => 'syfy-secondary-menu-list',
  );
  $block->content = theme('item_list', array(
    'items' => $items,
    'title'=> $term->name,
    'type' => 'ul',
    'attributes' => $attributes,
  ));
  return $block;
}

/**
 * Settings form for plugin.
 */
function syfy_press_secondary_menu_content_typ_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Returns nested menu list.
 */
function _syfy_press_secondary_menu_content_type_items($term) {
  $children = taxonomy_get_children($term->tid, $term->vid);
  $items = array();

  foreach($children as $child) {
    $node_count = FALSE;
    if (variable_get('taxonomy_maintain_index_table', TRUE)) {
      $query = db_select('taxonomy_index', 't');
      $query->addTag('node_access');
      $query->condition('tid', $child->tid);
      $query->addExpression('COUNT(t.nid)');
      $node_count = $query->execute()->fetchField();
    }
    if ($node_count === FALSE || $node_count > 0) {
      $alias = drupal_get_path_alias('taxonomy/term/' . $child->tid);
      $menu_item = array(
        'data' => ($node_count === FALSE || $node_count > 0) ? l($child->name, $alias) : $child->name,
        'id' => 'syfy_secondary_menu_item_' . $child->tid,
        'class' => array('syfy-secondary_menu-item'),
      );

      $current_path = current_path();
      $path_alias = drupal_lookup_path('alias', $current_path);
      if (strcmp($path_alias, $alias) === 0) {
        $menu_item['class'][] = 'active';
      }

      $menu_item['children'] = _syfy_press_secondary_menu_content_type_items($child);
      if (count($menu_item['children']) > 0) {
        if ($node_count === FALSE) {
          $menu_item['data'] = $child->name;
        }
        $menu_item['class'][] = 'expanded';
      }

      $items[] = $menu_item;
    }
  }

  return $items;
}

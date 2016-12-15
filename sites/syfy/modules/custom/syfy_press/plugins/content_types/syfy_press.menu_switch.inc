<?php
/**
 * @file
 * Plugin to provide access control based upon a parent term.
 */

$plugin = array(
  'title' => t('Menu switch'),
  'description' => t('Menu switch between press kits of project.'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('syfy_menu_switch'),
  'render callback' => 'syfy_press_menu_switch_content_type_render',
  'edit form' => 'syfy_press_menu_switch_content_type_edit_form',
  'category' => array(t('SyFy press'), -9),
);

function syfy_press_menu_switch_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data) || $context->data->type != 'press_kit') {
    return FALSE;
  }

  // Search parent node.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'press_kit_project')
    ->fieldCondition('field_press_kit', 'target_id', $context->data->nid);
  $result = $query->execute();


  $block = new stdClass();
  $block->content = '';

  if(!empty($result) && !empty($result['node'])){
    foreach($result['node'] as $project) {
      $node_wrapper = entity_metadata_wrapper('node', $project->nid);
      $values = $node_wrapper->{'field_press_kit'}->value();

      if(count($values) <= 1) {
        return FALSE;
      }

      $items = array();
      foreach($values as $key => $value) {
        $alias = drupal_get_path_alias('node/' . $value->nid);
        $current_path = current_path();
        $path_alias = drupal_lookup_path('alias',$current_path);
        $class_selected = strpos($path_alias, $alias) === 0 ? 'active' : NULL;

        if ($class_selected && !empty($path_alias[strlen($alias)]) && $path_alias[strlen($alias)] != '/') {
          $class_selected = NULL;
        }

        $items[] = array(
          'data' => l($value->title, $alias),
          'class' => array($class_selected, 'syfy-menu-switch')
        );
      }

      $block->content = theme_item_list(array('items' => $items, 'title'=> '', 'type' => 'ul', 'attributes' => array()));
    }
  }

  return $block;
}

/**
 * Settings form for plugin.
 */
function syfy_press_menu_switch_content_type_edit_form($form, &$form_state) {
  return $form;
}

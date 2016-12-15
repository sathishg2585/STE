<?php
/**
 * @file
 * fycusa_build.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function fycusa_build_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__fyc-multi-show-project';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'FYC Multi Project',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'fyc-multi-homepage',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'fyc-multi-show-project',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'fyc.single_project',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'fyc_project' => 'fyc_project',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'fyc.landing_page',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        3 => array(
          'name' => 'fyc.premissions',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'landing';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'header' => NULL,
      'projects' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
    'header' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7d96d9e1-a4df-4327-9206-e91396b6a8a6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-029e9090-50bd-44c2-a1d6-5f75e200d0a5';
    $pane->panel = 'content';
    $pane->type = 'fyc.landing_page_menu';
    $pane->subtype = 'fyc.landing_page_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '029e9090-50bd-44c2-a1d6-5f75e200d0a5';
    $display->content['new-029e9090-50bd-44c2-a1d6-5f75e200d0a5'] = $pane;
    $display->panels['content'][0] = 'new-029e9090-50bd-44c2-a1d6-5f75e200d0a5';
    $pane = new stdClass();
    $pane->pid = 'new-d567a038-98e1-42fb-b0b7-c8a93a87162d';
    $pane->panel = 'content';
    $pane->type = 'fyc.project_menu';
    $pane->subtype = 'fyc.project_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any fyc_project content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd567a038-98e1-42fb-b0b7-c8a93a87162d';
    $display->content['new-d567a038-98e1-42fb-b0b7-c8a93a87162d'] = $pane;
    $display->panels['content'][1] = 'new-d567a038-98e1-42fb-b0b7-c8a93a87162d';
    $pane = new stdClass();
    $pane->pid = 'new-8902c828-81e2-4098-8467-89dde6982f5b';
    $pane->panel = 'content';
    $pane->type = 'views_panes';
    $pane->subtype = 'fyc_landing_page_projects-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8902c828-81e2-4098-8467-89dde6982f5b';
    $display->content['new-8902c828-81e2-4098-8467-89dde6982f5b'] = $pane;
    $display->panels['content'][2] = 'new-8902c828-81e2-4098-8467-89dde6982f5b';
    $pane = new stdClass();
    $pane->pid = 'new-1aec663f-a6ee-4eb6-abe9-33dd860da5cb';
    $pane->panel = 'footer';
    $pane->type = 'fyc.footer';
    $pane->subtype = 'fyc.footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1aec663f-a6ee-4eb6-abe9-33dd860da5cb';
    $display->content['new-1aec663f-a6ee-4eb6-abe9-33dd860da5cb'] = $pane;
    $display->panels['footer'][0] = 'new-1aec663f-a6ee-4eb6-abe9-33dd860da5cb';
    $pane = new stdClass();
    $pane->pid = 'new-2627cbd9-0763-4279-9e08-16b8d8e867e3';
    $pane->panel = 'header';
    $pane->type = 'fyc.header';
    $pane->subtype = 'fyc.header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2627cbd9-0763-4279-9e08-16b8d8e867e3';
    $display->content['new-2627cbd9-0763-4279-9e08-16b8d8e867e3'] = $pane;
    $display->panels['header'][0] = 'new-2627cbd9-0763-4279-9e08-16b8d8e867e3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__fyc-multi-show-project'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__fyc-single-show-project';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'FYC Single Project',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'fyc-single-landingpage',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Node (on Node: FYC Show [field_fyc_show])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_fyc_show-node-node',
        'delta' => '0',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'fyc-single-show-project',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'fyc_project' => 'fyc_project',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'fyc.single_project',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'fyc.landing_page',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        3 => array(
          'name' => 'fyc.premissions',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'landing';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3435e468-a721-41b6-900c-4f93ad754a51';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6edd0013-c233-4167-a68a-6079134c6704';
    $pane->panel = 'content';
    $pane->type = 'fyc.landing_page_menu';
    $pane->subtype = 'fyc.landing_page_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6edd0013-c233-4167-a68a-6079134c6704';
    $display->content['new-6edd0013-c233-4167-a68a-6079134c6704'] = $pane;
    $display->panels['content'][0] = 'new-6edd0013-c233-4167-a68a-6079134c6704';
    $pane = new stdClass();
    $pane->pid = 'new-eda28f11-8744-47a3-b954-a290ec53b6d9';
    $pane->panel = 'content';
    $pane->type = 'fyc.project_menu';
    $pane->subtype = 'fyc.project_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any fyc_project content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'eda28f11-8744-47a3-b954-a290ec53b6d9';
    $display->content['new-eda28f11-8744-47a3-b954-a290ec53b6d9'] = $pane;
    $display->panels['content'][1] = 'new-eda28f11-8744-47a3-b954-a290ec53b6d9';
    $pane = new stdClass();
    $pane->pid = 'new-930cf5b1-0fc3-4b8f-9eea-b4a754d1b699';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_fyc_show_background';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'node_status',
          'settings' => NULL,
          'context' => 'relationship_entity_from_field:field_fyc_show-node-node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'fyc_large_home_page_background',
        'css_settings' => array(
          'bg_image_selector' => '.fyc-single-landingpage .fyc-homepage-single-project-wrapper',
          'bg_image_color' => '#FFFFFF',
          'bg_image_x' => 'left',
          'bg_image_y' => 'top',
          'bg_image_attachment' => 'scroll',
          'bg_image_repeat' => 'no-repeat',
          'bg_image_background_size' => '',
          'bg_image_background_size_ie8' => 0,
          'bg_image_media_query' => 'all',
          'bg_image_important' => 0,
        ),
        'image_link' => 'content',
      ),
      'context' => 'relationship_entity_from_field:field_fyc_show-node-node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '930cf5b1-0fc3-4b8f-9eea-b4a754d1b699';
    $display->content['new-930cf5b1-0fc3-4b8f-9eea-b4a754d1b699'] = $pane;
    $display->panels['content'][2] = 'new-930cf5b1-0fc3-4b8f-9eea-b4a754d1b699';
    $pane = new stdClass();
    $pane->pid = 'new-53755f54-7f5d-4fb4-89d2-8eeee5d85e7d';
    $pane->panel = 'footer';
    $pane->type = 'fyc.footer';
    $pane->subtype = 'fyc.footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '53755f54-7f5d-4fb4-89d2-8eeee5d85e7d';
    $display->content['new-53755f54-7f5d-4fb4-89d2-8eeee5d85e7d'] = $pane;
    $display->panels['footer'][0] = 'new-53755f54-7f5d-4fb4-89d2-8eeee5d85e7d';
    $pane = new stdClass();
    $pane->pid = 'new-7d83c7dc-ccb6-4e15-9538-b2ba65f168a9';
    $pane->panel = 'header';
    $pane->type = 'fyc.header';
    $pane->subtype = 'fyc.header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7d83c7dc-ccb6-4e15-9538-b2ba65f168a9';
    $display->content['new-7d83c7dc-ccb6-4e15-9538-b2ba65f168a9'] = $pane;
    $display->panels['header'][0] = 'new-7d83c7dc-ccb6-4e15-9538-b2ba65f168a9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__fyc-single-show-project'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__fyc-project';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'FYC Project',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'fyc-project',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'fyc_project' => 'fyc_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'fyc.premissions',
          'settings' => NULL,
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b354155d-d1fd-44a3-80b9-944977677a40';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-695eade2-01d1-4968-a7fc-52beaf6d3c83';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'fyc-access_code_block';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '695eade2-01d1-4968-a7fc-52beaf6d3c83';
    $display->content['new-695eade2-01d1-4968-a7fc-52beaf6d3c83'] = $pane;
    $display->panels['middle'][0] = 'new-695eade2-01d1-4968-a7fc-52beaf6d3c83';
    $pane = new stdClass();
    $pane->pid = 'new-cb02cda3-7c9e-412b-947f-2b3d884ea79b';
    $pane->panel = 'middle';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cb02cda3-7c9e-412b-947f-2b3d884ea79b';
    $display->content['new-cb02cda3-7c9e-412b-947f-2b3d884ea79b'] = $pane;
    $display->panels['middle'][1] = 'new-cb02cda3-7c9e-412b-947f-2b3d884ea79b';
    $pane = new stdClass();
    $pane->pid = 'new-c10cc115-a14a-43fb-bc0b-d83f03307b88';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c10cc115-a14a-43fb-bc0b-d83f03307b88';
    $display->content['new-c10cc115-a14a-43fb-bc0b-d83f03307b88'] = $pane;
    $display->panels['middle'][2] = 'new-c10cc115-a14a-43fb-bc0b-d83f03307b88';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c10cc115-a14a-43fb-bc0b-d83f03307b88';
  $handler->conf['display'] = $display;
  $export['site_template__fyc-project'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__fyc-project-pages';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'FYC Show',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: FYC Entityreference context',
        'keyword' => 'view',
        'name' => 'view_from_argument:fyc_entityreference_context-ctools_context_1',
        'context' => array(
          0 => 'node',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node_from_view',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:fyc_entityreference_context-ctools_context_1_1',
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Taxonomy term parent',
        'keyword' => 'taxonomy_term_parent',
        'name' => 'entity_from_field:field_fyc_show_tax_item-node-taxonomy_term',
        'delta' => 0,
        'context' => 'node',
        'id' => 1,
      ),
    ),
    'name' => 'fyc-project-pages',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'fyc_show' => 'fyc_show',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'fyc.premissions',
          'settings' => NULL,
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '925c86db-6f9b-4982-8682-d8dfbf7a2ac9';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__fyc-project-pages'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__fyc-taxonomy-term-page-wrapper';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'FYC Taxonomy Term Page Wrapper',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Term parent',
        'keyword' => 'parent_term',
        'name' => 'term_parent',
        'type' => 'top',
        'context' => 'term',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'View: FYC get node from term item',
        'keyword' => 'view',
        'name' => 'view_from_argument:fyc_get_node_from_term_item-ctools_context_1',
        'context' => array(
          0 => 'relationship_term_parent_1',
        ),
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:fyc_get_node_from_term_item-ctools_context_1_1',
        'id' => 1,
      ),
      3 => array(
        'identifier' => 'View: FYC get node from term item(secondary menu)',
        'keyword' => 'view_2',
        'name' => 'view_from_argument:fyc_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'term',
        ),
        'id' => 1,
      ),
      4 => array(
        'identifier' => 'View: FYC Entityreference context',
        'keyword' => 'view_3',
        'name' => 'view_from_argument:fyc_entityreference_context-ctools_context_1',
        'context' => array(
          0 => 'relationship_node_from_view_1',
        ),
        'id' => 1,
      ),
      5 => array(
        'identifier' => 'Project node',
        'keyword' => 'project_node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:fyc_entityreference_context-ctools_context_1_1',
        'id' => 2,
      ),
      6 => array(
        'identifier' => 'File from Node (on Node: Show Logo [field_fyc_show_logo])',
        'keyword' => 'file',
        'name' => 'entity_from_field:field_fyc_show_logo-node-file',
        'delta' => 0,
        'context' => 'relationship_node_from_view_2',
        'id' => 1,
      ),
    ),
    'name' => 'fyc-taxonomy-term-page-wrapper',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'fyc_show_items' => 'fyc_show_items',
            ),
          ),
          'context' => 'term',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'innerpages';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'fyc_shows' => NULL,
      'header_image' => NULL,
      'main_menu' => NULL,
      'content' => NULL,
      'press_kits' => NULL,
      'header' => NULL,
      'footer' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '31b60b55-418a-4bb6-98ad-70c4a6a3be59';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7927ea96-6cb4-494c-98d1-4f19ffc1fdb4';
    $pane->panel = 'content';
    $pane->type = 'fyc.inner_page_menu';
    $pane->subtype = 'fyc.inner_page_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'term',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7927ea96-6cb4-494c-98d1-4f19ffc1fdb4';
    $display->content['new-7927ea96-6cb4-494c-98d1-4f19ffc1fdb4'] = $pane;
    $display->panels['content'][0] = 'new-7927ea96-6cb4-494c-98d1-4f19ffc1fdb4';
    $pane = new stdClass();
    $pane->pid = 'new-8f61fd5d-7ebb-4e21-a4ef-0962d5e1999e';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_fyc_show_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'bg_image_formatter',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => '',
        'css_settings' => array(
          'bg_image_selector' => '.pane-fyc-tab',
          'bg_image_color' => '#FFFFFF',
          'bg_image_x' => '10em',
          'bg_image_y' => '0.8em',
          'bg_image_attachment' => 'scroll',
          'bg_image_repeat' => 'no-repeat',
          'bg_image_background_size' => '',
          'bg_image_background_size_ie8' => 0,
          'bg_image_media_query' => 'all',
          'bg_image_important' => 0,
        ),
      ),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8f61fd5d-7ebb-4e21-a4ef-0962d5e1999e';
    $display->content['new-8f61fd5d-7ebb-4e21-a4ef-0962d5e1999e'] = $pane;
    $display->panels['content'][1] = 'new-8f61fd5d-7ebb-4e21-a4ef-0962d5e1999e';
    $pane = new stdClass();
    $pane->pid = 'new-26824e19-3582-470f-80d2-8ec08a04aa6b';
    $pane->panel = 'content';
    $pane->type = 'fyc.tab';
    $pane->subtype = 'fyc.tab';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '26824e19-3582-470f-80d2-8ec08a04aa6b';
    $display->content['new-26824e19-3582-470f-80d2-8ec08a04aa6b'] = $pane;
    $display->panels['content'][2] = 'new-26824e19-3582-470f-80d2-8ec08a04aa6b';
    $pane = new stdClass();
    $pane->pid = 'new-02ea9791-5515-4ae8-9c8c-56885a3e8eae';
    $pane->panel = 'content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '02ea9791-5515-4ae8-9c8c-56885a3e8eae';
    $display->content['new-02ea9791-5515-4ae8-9c8c-56885a3e8eae'] = $pane;
    $display->panels['content'][3] = 'new-02ea9791-5515-4ae8-9c8c-56885a3e8eae';
    $pane = new stdClass();
    $pane->pid = 'new-964aa8ad-3436-4246-ad2b-24b87feaf5ed';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_fyc_show_color';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'colorfield_raw_rgb',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'display_hash' => 1,
      ),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'fyc_show_color',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '964aa8ad-3436-4246-ad2b-24b87feaf5ed';
    $display->content['new-964aa8ad-3436-4246-ad2b-24b87feaf5ed'] = $pane;
    $display->panels['content'][4] = 'new-964aa8ad-3436-4246-ad2b-24b87feaf5ed';
    $pane = new stdClass();
    $pane->pid = 'new-25848fb9-8fac-4c0a-8ae7-e9bac4481fab';
    $pane->panel = 'footer';
    $pane->type = 'fyc.footer';
    $pane->subtype = 'fyc.footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '25848fb9-8fac-4c0a-8ae7-e9bac4481fab';
    $display->content['new-25848fb9-8fac-4c0a-8ae7-e9bac4481fab'] = $pane;
    $display->panels['footer'][0] = 'new-25848fb9-8fac-4c0a-8ae7-e9bac4481fab';
    $pane = new stdClass();
    $pane->pid = 'new-870655a4-57b4-46fa-becf-2aebcf010cd6';
    $pane->panel = 'header';
    $pane->type = 'block';
    $pane->subtype = 'fyc-access_code_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '870655a4-57b4-46fa-becf-2aebcf010cd6';
    $display->content['new-870655a4-57b4-46fa-becf-2aebcf010cd6'] = $pane;
    $display->panels['header'][0] = 'new-870655a4-57b4-46fa-becf-2aebcf010cd6';
    $pane = new stdClass();
    $pane->pid = 'new-86fbba49-d2e6-4b43-9ce9-0740c8028157';
    $pane->panel = 'header';
    $pane->type = 'fyc.header';
    $pane->subtype = 'fyc.header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '86fbba49-d2e6-4b43-9ce9-0740c8028157';
    $display->content['new-86fbba49-d2e6-4b43-9ce9-0740c8028157'] = $pane;
    $display->panels['header'][1] = 'new-86fbba49-d2e6-4b43-9ce9-0740c8028157';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__fyc-taxonomy-term-page-wrapper'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__fyc_403';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => '403',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '403',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'access-denied',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'innerpages';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
      'middle' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f5565ab1-b05a-4916-b94c-c268895240ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4bf44b13-e8da-4208-8b67-df7bef3ac8cc';
    $pane->panel = 'content';
    $pane->type = 'fyc.access_denied';
    $pane->subtype = 'fyc.access_denied';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4bf44b13-e8da-4208-8b67-df7bef3ac8cc';
    $display->content['new-4bf44b13-e8da-4208-8b67-df7bef3ac8cc'] = $pane;
    $display->panels['content'][0] = 'new-4bf44b13-e8da-4208-8b67-df7bef3ac8cc';
    $pane = new stdClass();
    $pane->pid = 'new-d6b77328-ab36-4d6f-905b-26c826c182fc';
    $pane->panel = 'footer';
    $pane->type = 'fyc.footer';
    $pane->subtype = 'fyc.footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd6b77328-ab36-4d6f-905b-26c826c182fc';
    $display->content['new-d6b77328-ab36-4d6f-905b-26c826c182fc'] = $pane;
    $display->panels['footer'][0] = 'new-d6b77328-ab36-4d6f-905b-26c826c182fc';
    $pane = new stdClass();
    $pane->pid = 'new-58277e98-6490-4a09-98b4-e3042625c10d';
    $pane->panel = 'header';
    $pane->type = 'fyc.header';
    $pane->subtype = 'fyc.header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '58277e98-6490-4a09-98b4-e3042625c10d';
    $display->content['new-58277e98-6490-4a09-98b4-e3042625c10d'] = $pane;
    $display->panels['header'][0] = 'new-58277e98-6490-4a09-98b4-e3042625c10d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__fyc_403'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__fyc_404';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => '404',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '404',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'page-not-found
user/login',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'innerpages';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
      'middle' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a3b1dd41-80f3-4056-8501-ef94837617d8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7d082efe-4a72-43e7-86d0-231e8b8b74fc';
    $pane->panel = 'content';
    $pane->type = 'fyc.page_unavailable';
    $pane->subtype = 'fyc.page_unavailable';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7d082efe-4a72-43e7-86d0-231e8b8b74fc';
    $display->content['new-7d082efe-4a72-43e7-86d0-231e8b8b74fc'] = $pane;
    $display->panels['content'][0] = 'new-7d082efe-4a72-43e7-86d0-231e8b8b74fc';
    $pane = new stdClass();
    $pane->pid = 'new-e215f686-a181-4213-a085-2a0ac1f5e82d';
    $pane->panel = 'footer';
    $pane->type = 'fyc.footer';
    $pane->subtype = 'fyc.footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e215f686-a181-4213-a085-2a0ac1f5e82d';
    $display->content['new-e215f686-a181-4213-a085-2a0ac1f5e82d'] = $pane;
    $display->panels['footer'][0] = 'new-e215f686-a181-4213-a085-2a0ac1f5e82d';
    $pane = new stdClass();
    $pane->pid = 'new-3c4f72c5-bea7-4a91-9b3f-ccaa99407788';
    $pane->panel = 'header';
    $pane->type = 'fyc.header';
    $pane->subtype = 'fyc.header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3c4f72c5-bea7-4a91-9b3f-ccaa99407788';
    $display->content['new-3c4f72c5-bea7-4a91-9b3f-ccaa99407788'] = $pane;
    $display->panels['header'][0] = 'new-3c4f72c5-bea7-4a91-9b3f-ccaa99407788';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__fyc_404'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__fyc_login_page';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Login page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'login_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e190e955-9eb1-4408-a0a3-7d7a489e7f1f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b7e17752-8f35-4df2-a402-f005368678a4';
    $pane->panel = 'middle';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b7e17752-8f35-4df2-a402-f005368678a4';
    $display->content['new-b7e17752-8f35-4df2-a402-f005368678a4'] = $pane;
    $display->panels['middle'][0] = 'new-b7e17752-8f35-4df2-a402-f005368678a4';
    $pane = new stdClass();
    $pane->pid = 'new-512675a4-baab-4249-bb34-d7a98247576a';
    $pane->panel = 'middle';
    $pane->type = 'fyc.login_logo';
    $pane->subtype = 'fyc.login_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '512675a4-baab-4249-bb34-d7a98247576a';
    $display->content['new-512675a4-baab-4249-bb34-d7a98247576a'] = $pane;
    $display->panels['middle'][1] = 'new-512675a4-baab-4249-bb34-d7a98247576a';
    $pane = new stdClass();
    $pane->pid = 'new-323d4509-78a3-48b8-a903-232c6953aef3';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '323d4509-78a3-48b8-a903-232c6953aef3';
    $display->content['new-323d4509-78a3-48b8-a903-232c6953aef3'] = $pane;
    $display->panels['middle'][2] = 'new-323d4509-78a3-48b8-a903-232c6953aef3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__fyc_login_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__fyc_reset_password_page';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Reset password page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'reset_password_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/reset/*',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a27f541e-f3d7-44fa-a0fc-d6156b56c366';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-deab2279-0682-4d52-aeeb-956e79803fb4';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'deab2279-0682-4d52-aeeb-956e79803fb4';
    $display->content['new-deab2279-0682-4d52-aeeb-956e79803fb4'] = $pane;
    $display->panels['middle'][0] = 'new-deab2279-0682-4d52-aeeb-956e79803fb4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__fyc_reset_password_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__fyc_user_password_recovery';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'User password recovery',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'user_password_recovery',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/password',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd64cdb08-9c97-4f54-a365-ef12dbe7b2d6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c9e1fbcc-fd29-4504-bd64-6c53d02d2010';
    $pane->panel = 'middle';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c9e1fbcc-fd29-4504-bd64-6c53d02d2010';
    $display->content['new-c9e1fbcc-fd29-4504-bd64-6c53d02d2010'] = $pane;
    $display->panels['middle'][0] = 'new-c9e1fbcc-fd29-4504-bd64-6c53d02d2010';
    $pane = new stdClass();
    $pane->pid = 'new-0ef36284-9c9e-40c9-b771-ef684811800a';
    $pane->panel = 'middle';
    $pane->type = 'fyc.login_logo';
    $pane->subtype = 'fyc.login_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0ef36284-9c9e-40c9-b771-ef684811800a';
    $display->content['new-0ef36284-9c9e-40c9-b771-ef684811800a'] = $pane;
    $display->panels['middle'][1] = 'new-0ef36284-9c9e-40c9-b771-ef684811800a';
    $pane = new stdClass();
    $pane->pid = 'new-10faed5d-e529-4d61-98b5-2515376ab759';
    $pane->panel = 'middle';
    $pane->type = 'fyc.password_recovery';
    $pane->subtype = 'fyc.password_recovery';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '10faed5d-e529-4d61-98b5-2515376ab759';
    $display->content['new-10faed5d-e529-4d61-98b5-2515376ab759'] = $pane;
    $display->panels['middle'][2] = 'new-10faed5d-e529-4d61-98b5-2515376ab759';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__fyc_user_password_recovery'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__fyc-awards';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'FYC Awards',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: FYC get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:fyc_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:fyc_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'fyc-awards',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'fyc_show_items' => 'fyc_show_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'fyc_award' => 'fyc_award',
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'fyc.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'innerblock_top_left_right';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
    ),
    'middle' => array(
      'style' => '-1',
    ),
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f3377396-d5b9-4d23-977c-a1a0ae985407';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-56fbbf6a-e1a8-4e03-baa5-eabec93528d2';
    $pane->panel = 'left';
    $pane->type = 'fyc.fyc_awards_page';
    $pane->subtype = 'fyc.fyc_awards_page';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '56fbbf6a-e1a8-4e03-baa5-eabec93528d2';
    $display->content['new-56fbbf6a-e1a8-4e03-baa5-eabec93528d2'] = $pane;
    $display->panels['left'][0] = 'new-56fbbf6a-e1a8-4e03-baa5-eabec93528d2';
    $pane = new stdClass();
    $pane->pid = 'new-14fe9121-6363-4e20-a03d-ef0738e291c6';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_fyc_cover_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => '',
        'css_settings' => array(
          'bg_image_selector' => '.fyc-award-right-wrapper',
          'bg_image_color' => '#FFFFFF',
          'bg_image_x' => 'left',
          'bg_image_y' => 'top',
          'bg_image_attachment' => 'scroll',
          'bg_image_repeat' => 'no-repeat',
          'bg_image_background_size' => '',
          'bg_image_background_size_ie8' => 0,
          'bg_image_media_query' => 'all',
          'bg_image_important' => 1,
        ),
        'image_link' => '',
      ),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '14fe9121-6363-4e20-a03d-ef0738e291c6';
    $display->content['new-14fe9121-6363-4e20-a03d-ef0738e291c6'] = $pane;
    $display->panels['right'][0] = 'new-14fe9121-6363-4e20-a03d-ef0738e291c6';
    $pane = new stdClass();
    $pane->pid = 'new-80adf394-715d-4b51-bdcc-ad31f7489bc0';
    $pane->panel = 'top';
    $pane->type = 'fyc.content_menu';
    $pane->subtype = 'fyc.content_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create fyc_award content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any fyc_award content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'argument_term_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '80adf394-715d-4b51-bdcc-ad31f7489bc0';
    $display->content['new-80adf394-715d-4b51-bdcc-ad31f7489bc0'] = $pane;
    $display->panels['top'][0] = 'new-80adf394-715d-4b51-bdcc-ad31f7489bc0';
    $pane = new stdClass();
    $pane->pid = 'new-67468df1-4955-474c-a234-f3face5108ec';
    $pane->panel = 'top';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'none',
      'id' => '',
      'class' => '',
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '67468df1-4955-474c-a234-f3face5108ec';
    $display->content['new-67468df1-4955-474c-a234-f3face5108ec'] = $pane;
    $display->panels['top'][1] = 'new-67468df1-4955-474c-a234-f3face5108ec';
    $pane = new stdClass();
    $pane->pid = 'new-4aa1ed88-b146-4ba5-8a87-4490d9ee28d2';
    $pane->panel = 'top';
    $pane->type = 'fyc.fyc_awards_tab';
    $pane->subtype = 'fyc.fyc_awards_tab';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4aa1ed88-b146-4ba5-8a87-4490d9ee28d2';
    $display->content['new-4aa1ed88-b146-4ba5-8a87-4490d9ee28d2'] = $pane;
    $display->panels['top'][2] = 'new-4aa1ed88-b146-4ba5-8a87-4490d9ee28d2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__fyc-awards'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__fyc-series-overview';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'FYC Series Overview ',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: FYC get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:fyc_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:fyc_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'fyc-series-overview',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'fyc_show_items' => 'fyc_show_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'fyc_series_overview' => 'fyc_series_overview',
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'fyc.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'innerblock_left_right';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
    'middle' => array(
      'style' => '-1',
    ),
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f3377396-d5b9-4d23-977c-a1a0ae985407';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-72b13b94-d722-4c75-a8bf-fc75ab10a279';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_fyc_cover_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'bg_image_formatter',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => '',
        'css_settings' => array(
          'bg_image_selector' => '.fyc-left-wrapper',
          'bg_image_color' => '',
          'bg_image_x' => 'left',
          'bg_image_y' => 'top',
          'bg_image_attachment' => 'scroll',
          'bg_image_repeat' => 'no-repeat',
          'bg_image_background_size' => '',
          'bg_image_background_size_ie8' => 0,
          'bg_image_media_query' => 'all',
          'bg_image_important' => 1,
        ),
      ),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '72b13b94-d722-4c75-a8bf-fc75ab10a279';
    $display->content['new-72b13b94-d722-4c75-a8bf-fc75ab10a279'] = $pane;
    $display->panels['left'][0] = 'new-72b13b94-d722-4c75-a8bf-fc75ab10a279';
    $pane = new stdClass();
    $pane->pid = 'new-e78b78e7-0706-4216-a8bb-4f099ccb5d82';
    $pane->panel = 'right';
    $pane->type = 'fyc.content_menu';
    $pane->subtype = 'fyc.content_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create fyc_series_overview content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any fyc_series_overview content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'argument_term_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e78b78e7-0706-4216-a8bb-4f099ccb5d82';
    $display->content['new-e78b78e7-0706-4216-a8bb-4f099ccb5d82'] = $pane;
    $display->panels['right'][0] = 'new-e78b78e7-0706-4216-a8bb-4f099ccb5d82';
    $pane = new stdClass();
    $pane->pid = 'new-45569348-b9d6-4af3-aa50-bfa3354ef19c';
    $pane->panel = 'right';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h3',
      'id' => '',
      'class' => '',
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '45569348-b9d6-4af3-aa50-bfa3354ef19c';
    $display->content['new-45569348-b9d6-4af3-aa50-bfa3354ef19c'] = $pane;
    $display->panels['right'][1] = 'new-45569348-b9d6-4af3-aa50-bfa3354ef19c';
    $pane = new stdClass();
    $pane->pid = 'new-0b77e4b0-2437-4d89-b981-3d079f4cf7c7';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_fyc_overview_text';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0b77e4b0-2437-4d89-b981-3d079f4cf7c7';
    $display->content['new-0b77e4b0-2437-4d89-b981-3d079f4cf7c7'] = $pane;
    $display->panels['right'][2] = 'new-0b77e4b0-2437-4d89-b981-3d079f4cf7c7';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__fyc-series-overview'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__fyc-video';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'FYC Video',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: FYC get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:fyc_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:fyc_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'fyc-video',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'fyc_show_items' => 'fyc_show_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'fyc_video' => 'fyc_video',
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'fyc.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
    'middle' => array(
      'style' => '-1',
    ),
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f3377396-d5b9-4d23-977c-a1a0ae985407';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a1111cd6-af9c-4d7c-9e02-ba0759adc303';
    $pane->panel = 'middle';
    $pane->type = 'fyc.content_menu';
    $pane->subtype = 'fyc.content_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create fyc_video content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any fyc_video content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'argument_term_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a1111cd6-af9c-4d7c-9e02-ba0759adc303';
    $display->content['new-a1111cd6-af9c-4d7c-9e02-ba0759adc303'] = $pane;
    $display->panels['middle'][0] = 'new-a1111cd6-af9c-4d7c-9e02-ba0759adc303';
    $pane = new stdClass();
    $pane->pid = 'new-dec6db97-5038-4272-9212-3d7674c3f5e2';
    $pane->panel = 'middle';
    $pane->type = 'fyc.video_page';
    $pane->subtype = 'fyc.video_page';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'dec6db97-5038-4272-9212-3d7674c3f5e2';
    $display->content['new-dec6db97-5038-4272-9212-3d7674c3f5e2'] = $pane;
    $display->panels['middle'][1] = 'new-dec6db97-5038-4272-9212-3d7674c3f5e2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__fyc-video'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__fyc_403_term_page';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => '403 term page',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: FYC get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:fyc_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:fyc_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'code' => '403',
    'destination' => '',
    'name' => '403_term_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'fyc_show_items' => 'fyc_show_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'fyc.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['term_view__fyc_403_term_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__fyc_redirect_user_on_content_page';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Redirect user on content page',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'admin/content',
    'name' => 'redirect_user_on_content_page',
  );
  $export['user_view__fyc_redirect_user_on_content_page'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function fycusa_build_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panels_customerror_403_fyc';
  $page->task = 'page';
  $page->admin_title = 'Panels Custom Error Access Denied';
  $page->admin_description = '';
  $page->path = 'access-denied';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panels_customerror_403_fyc_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panels_customerror_403_fyc';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Page not available';
  $display->uuid = '7e0e26d2-b517-443a-9d53-95a60f476fa6';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panels_customerror_403_fyc'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panels_customerror_404_fyc';
  $page->task = 'page';
  $page->admin_title = 'Panels Custom Error Page Not Found';
  $page->admin_description = '';
  $page->path = 'page-not-found';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panels_customerror_404_fyc_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panels_customerror_404_fyc';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Page not available';
  $display->uuid = '17b277ea-d05c-4565-93c9-95bde15960eb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3d5c99b1-384d-4450-8d63-f1f7abf3410f';
    $pane->panel = 'middle';
    $pane->type = 'fyc.header';
    $pane->subtype = 'fyc.header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3d5c99b1-384d-4450-8d63-f1f7abf3410f';
    $display->content['new-3d5c99b1-384d-4450-8d63-f1f7abf3410f'] = $pane;
    $display->panels['middle'][0] = 'new-3d5c99b1-384d-4450-8d63-f1f7abf3410f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panels_customerror_404_fyc'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'password_recovery_page_fyc';
  $page->task = 'page';
  $page->admin_title = 'Password recovery page';
  $page->admin_description = '';
  $page->path = 'user/reset/%text';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'text' => array(
      'settings' => array(),
      'identifier' => 'No context',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_password_recovery_page_fyc__panel_context_8ab04700-a8f4-4ab2-9148-14b451f79b70';
  $handler->task = 'page';
  $handler->subtask = 'password_recovery_page_fyc';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9c84afba-0cfc-44bf-b7ca-9c104e0926eb';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['password_recovery_page_fyc'] = $page;

  return $pages;

}

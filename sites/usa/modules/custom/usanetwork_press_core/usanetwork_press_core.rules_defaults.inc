<?php
/**
 * @file
 * usanetwork_press_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function usanetwork_press_core_default_rules_configuration() {
  $items = array();
  $items['rules_after_creating_menu_item'] = entity_import('rules_config', '{ "rules_after_creating_menu_item" : {
      "LABEL" : "After creating menu item",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "path", "taxonomy" ],
      "ON" : {
        "taxonomy_term_insert--press_kit_items" : { "bundle" : "press_kit_items" },
        "taxonomy_term_update--press_kit_items" : { "bundle" : "press_kit_items" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "term:parents-all" ], "op" : "\\u003E", "value" : "2" } }
      ],
      "DO" : [
        { "path_alias" : { "source" : "taxonomy\\/term\\/[term:tid]" } },
        { "taxonomy_term_path_alias" : { "node" : [ "term" ], "alias" : "[term:parent:url:alias]\\/[term:name]" } }
      ]
    }
  }');
  $items['rules_after_creating_menu_item_from_tax_admin'] = entity_import('rules_config', '{ "rules_after_creating_menu_item_from_tax_admin" : {
      "LABEL" : "After creating menu item from tax admin",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "6",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "path", "taxonomy" ],
      "ON" : {
        "taxonomy_term_insert--press_kit_items" : { "bundle" : "press_kit_items" },
        "taxonomy_term_update--press_kit_items" : { "bundle" : "press_kit_items" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "term:parents-all" ], "value" : "2" } },
        { "views_bulk_operations_condition_result_count" : {
            "view" : "press_kits_from_term|default",
            "args" : "[term:parent:tid]",
            "minimum" : "2"
          }
        },
        { "views_bulk_operations_condition_result_count" : {
            "view" : "usanetwork_get_node_from_term_item|ctools_context_1",
            "args" : "[term:parent:tid]",
            "minimum" : "1"
          }
        }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "usanetwork_get_node_from_term_item|ctools_context_1",
              "args" : "[term:parent:tid]"
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "entity-list:0:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "path_alias" : { "source" : "taxonomy\\/term\\/[term:tid]" } },
        { "taxonomy_term_path_alias" : {
            "node" : [ "term" ],
            "alias" : "[entity-fetched:url:alias]\\/[term:name]"
          }
        }
      ]
    }
  }');
  $items['rules_after_creating_menu_item_from_tax_admin_single_press_kit_'] = entity_import('rules_config', '{ "rules_after_creating_menu_item_from_tax_admin_single_press_kit_" : {
      "LABEL" : "After creating menu item from tax admin (Single press kit)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "7",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "path", "taxonomy" ],
      "ON" : {
        "taxonomy_term_insert--press_kit_items" : { "bundle" : "press_kit_items" },
        "taxonomy_term_update--press_kit_items" : { "bundle" : "press_kit_items" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "term:parents-all" ], "value" : "2" } },
        { "NOT views_bulk_operations_condition_result_count" : {
            "view" : "press_kits_from_term|default",
            "args" : "[term:parent:tid]",
            "minimum" : "2"
          }
        },
        { "views_bulk_operations_condition_result_count" : {
            "view" : "usanetwork_get_node_from_term_item|ctools_context_1",
            "args" : "[term:parent:tid]",
            "minimum" : "1"
          }
        }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "usanetwork_get_node_from_term_item|ctools_context_1",
              "args" : "[term:parent:tid]"
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "entity-list:0:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "usanetwork_entitireference_context|panel_pane_1",
              "args" : "[entity-fetched:nid]"
            },
            "PROVIDE" : { "entity_list" : { "ref_nodes" : "A list of entities" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "ref-nodes:0:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "project" : "Fetched entity" } }
          }
        },
        { "path_alias" : { "source" : "taxonomy\\/term\\/[term:tid]" } },
        { "taxonomy_term_path_alias" : { "node" : [ "term" ], "alias" : "[project:url:alias]\\/[term:name]" } }
      ]
    }
  }');
  $items['rules_after_deleting_content_of_project'] = entity_import('rules_config', '{ "rules_after_deleting_content_of_project" : {
      "LABEL" : "After deleting content of project",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_delete" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "usanetwork_photos" : "usanetwork_photos",
                "press_materials_page" : "press_materials_page",
                "videos_page" : "videos_page"
              }
            }
          }
        }
      ],
      "DO" : [ { "entity_delete" : { "data" : [ "node:field-menu-position" ] } } ]
    }
  }');
  $items['rules_after_save_multi_project'] = entity_import('rules_config', '{ "rules_after_save_multi_project" : {
      "LABEL" : "After save multi project",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "5",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "path" ],
      "ON" : {
        "node_insert--press_kit_project" : { "bundle" : "press_kit_project" },
        "node_update--press_kit_project" : { "bundle" : "press_kit_project" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "node:field-press-kit" ], "op" : "\\u003E", "value" : "1" } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-press-kit" ] },
            "ITEM" : { "press_kit_item" : "Current list item" },
            "DO" : [
              { "entity_fetch" : {
                  "USING" : { "type" : "node", "id" : [ "press-kit-item:nid" ] },
                  "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : {
                    "view" : "usanetwork_menu_reference|default",
                    "args" : [ "press-kit-item:nid" ]
                  },
                  "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
                }
              },
              { "entity_fetch" : {
                  "USING" : { "type" : "taxonomy_term", "id" : [ "entity-list:0:tid" ] },
                  "PROVIDE" : { "entity_fetched" : { "term_fetched" : "Fetched entity" } }
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : {
                    "view" : "usanetwork_press_rules_get_child_terms|default",
                    "args" : [ "term-fetched:tid" ]
                  },
                  "PROVIDE" : { "entity_list" : { "child_list" : "A list of entities" } }
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "child-list" ] },
                  "ITEM" : { "list_item" : "Current list item" },
                  "DO" : [
                    { "taxonomy_term_path_alias" : {
                        "node" : [ "list-item" ],
                        "alias" : "[press-kit-item:url:alias]\\/[list-item:name]"
                      }
                    }
                  ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_after_save_single_project'] = entity_import('rules_config', '{ "rules_after_save_single_project" : {
      "LABEL" : "After save single project",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "path" ],
      "ON" : { "node_insert--press_kit_project" : { "bundle" : "press_kit_project" } },
      "IF" : [
        { "list_count_is" : { "list" : [ "node:field-press-kit" ], "value" : "1" } }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "usanetwork_menu_reference|default",
              "args" : [ "node:field-press-kit:0:nid" ]
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "taxonomy_term", "id" : [ "entity-list:0:tid" ] },
            "PROVIDE" : { "entity_fetched" : { "term_fetched" : "Fetched entity" } }
          }
        },
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "usanetwork_press_rules_get_child_terms|default",
              "args" : [ "term-fetched:tid" ]
            },
            "PROVIDE" : { "entity_list" : { "child_list" : "A list of entities" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "child-list" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "taxonomy_term_path_alias" : {
                  "node" : [ "list-item" ],
                  "alias" : "[node:url:alias]\\/[list-item:name]"
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_create_url_aliases_for_press_kits'] = entity_import('rules_config', '{ "rules_create_url_aliases_for_press_kits" : {
      "LABEL" : "Create url aliases for press kits",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "path" ],
      "ON" : {
        "node_insert--press_kit_project" : { "bundle" : "press_kit_project" },
        "node_update--press_kit_project" : { "bundle" : "press_kit_project" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "node:field-press-kit" ], "op" : "\\u003E", "value" : "1" } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-press-kit" ] },
            "ITEM" : { "press_kit_item" : "Press kit item" },
            "DO" : [
              { "node_path_alias" : {
                  "node" : [ "press-kit-item" ],
                  "alias" : "[node:url:alias]\\/[press-kit-item:title]"
                }
              },
              { "entity_save" : { "data" : [ "press-kit-item" ], "immediate" : "1" } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_create_url_aliases_for_single_project'] = entity_import('rules_config', '{ "rules_create_url_aliases_for_single_project" : {
      "LABEL" : "Create url aliases for single project",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "path" ],
      "ON" : {
        "node_insert--press_kit_project" : { "bundle" : "press_kit_project" },
        "node_update--press_kit_project" : { "bundle" : "press_kit_project" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "node:field-press-kit" ], "value" : "1" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "node:field-press-kit:0" ] },
            "PROVIDE" : { "variable_added" : { "single_press_kit" : "Single press kit" } }
          }
        },
        { "node_path_alias" : { "node" : [ "single-press-kit" ], "alias" : "[single-press-kit:title]" } }
      ]
    }
  }');
  $items['rules_on_project_view'] = entity_import('rules_config', '{ "rules_on_project_view" : {
      "LABEL" : "On project view",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations" ],
      "ON" : { "node_view--press_kit" : { "bundle" : "press_kit" } },
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "taxonomy_term",
              "id" : [ "node:field-press-kit-tax-item:tid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "menu_term_fetched" : "Fetched entity" } }
          }
        },
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "usanetwork_press_rules_get_child_terms|default",
              "args" : "[menu-term-fetched:tid]"
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_term", "value" : [ "entity-list:0" ] },
            "PROVIDE" : { "variable_added" : { "first_menu_item" : "Added variable" } }
          }
        },
        { "redirect" : { "url" : "[first-menu-item:url]" } }
      ]
    }
  }');
  $items['rules_press_kit_add'] = entity_import('rules_config', '{ "rules_press_kit_add" : {
      "LABEL" : "Add press kit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--press_kit" : { "bundle" : "press_kit" } },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "taxonomy_term",
              "param_name" : [ "node:title" ],
              "param_vocabulary" : "press_kit_items"
            },
            "PROVIDE" : { "entity_created" : { "tax_term_created" : "Tax term created" } }
          }
        },
        { "entity_save" : { "data" : [ "tax-term-created" ], "immediate" : 1 } },
        { "data_set" : {
            "data" : [ "node:field-press-kit-tax-item" ],
            "value" : [ "tax-term-created" ]
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_vocabulary", "value" : "menu_items" },
            "PROVIDE" : { "variable_added" : { "vocabulary_menu_items" : "Vocabulary menu items" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "taxonomy_term",
              "property" : "vocabulary",
              "value" : [ "vocabulary-menu-items" ]
            },
            "PROVIDE" : { "entity_fetched" : { "fetched_terms" : "Fetched terms" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "fetched-terms" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_press_kit_tax_items_add" : {
                  "tax_term_name" : [ "list-item:name" ],
                  "parent_term" : [ "tax-term-created" ],
                  "term_weight" : [ "list-item:weight" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_press_kit_delete'] = entity_import('rules_config', '{ "rules_press_kit_delete" : {
      "LABEL" : "Delete press kit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_delete--press_kit" : { "bundle" : "press_kit" } },
      "DO" : [ { "entity_delete" : { "data" : [ "node:field-press-kit-tax-item" ] } } ]
    }
  }');
  $items['rules_press_kit_edit'] = entity_import('rules_config', '{ "rules_press_kit_edit" : {
      "LABEL" : "Edit press kit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--press_kit" : { "bundle" : "press_kit" } },
      "IF" : [
        { "NOT data_is" : { "data" : [ "node:title" ], "value" : [ "node-unchanged:title" ] } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "taxonomy_term",
              "id" : [ "node:field-press-kit-tax-item:tid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "data_set" : { "data" : [ "entity-fetched:name" ], "value" : [ "node:title" ] } }
      ]
    }
  }');
  $items['rules_press_kit_tax_items_add'] = entity_import('rules_config', '{ "rules_press_kit_tax_items_add" : {
      "LABEL" : "Add taxonomy items for press kit",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "tax_term_name" : { "label" : "Tax term name", "type" : "text" },
        "parent_term" : { "label" : "Parent term", "type" : "taxonomy_term" },
        "term_weight" : { "label" : "Term weight", "type" : "integer" }
      },
      "ACTION SET" : [
        { "entity_create" : {
            "USING" : {
              "type" : "taxonomy_term",
              "param_name" : [ "tax-term-name" ],
              "param_vocabulary" : "press_kit_items"
            },
            "PROVIDE" : { "entity_created" : { "created_tax_term" : "Created tax term" } }
          }
        },
        { "entity_save" : { "data" : [ "created-tax-term" ], "immediate" : 1 } },
        { "data_set" : { "data" : [ "created-tax-term:parent:0" ], "value" : [ "parent-term" ] } },
        { "data_set" : { "data" : [ "created-tax-term:weight" ], "value" : [ "term-weight" ] } }
      ]
    }
  }');
  $items['rules_redirect_on_press_material_page_raw_view'] = entity_import('rules_config', '{ "rules_redirect_on_press_material_page_raw_view" : {
      "LABEL" : "Redirect on press material page raw view",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_view--press_materials_page" : { "bundle" : "press_materials_page" } },
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_term", "value" : [ "node:field-menu-position" ] },
            "PROVIDE" : { "variable_added" : { "menu_term" : "Added variable" } }
          }
        },
        { "redirect" : { "url" : "[menu-term:url]" } }
      ]
    }
  }');
  $items['rules_redirect_on_videos_page_raw_view'] = entity_import('rules_config', '{ "rules_redirect_on_videos_page_raw_view" : {
      "LABEL" : "Redirect on videos page raw view",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_view--videos_page" : { "bundle" : "videos_page" } },
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_term", "value" : [ "node:field-menu-position" ] },
            "PROVIDE" : { "variable_added" : { "menu_term" : "Added variable" } }
          }
        },
        { "redirect" : { "url" : [ "menu-term:url" ] } }
      ]
    }
  }');
  $items['rules_secondary_menu_items_viewed'] = entity_import('rules_config', '{ "rules_secondary_menu_items_viewed" : {
      "LABEL" : "Secondary menu items viewed",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "taxonomy" ],
      "ON" : { "taxonomy_term_view" : [] },
      "IF" : [
        { "list_count_is" : { "list" : [ "term:parents-all" ], "op" : "\\u003E", "value" : "1" } },
        { "NOT views_bulk_operations_condition_result_count" : {
            "view" : "usanetwork_get_node_from_term_item_secondary_menu|panel_pane_1",
            "args" : "[term:tid]",
            "minimum" : "1"
          }
        },
        { "views_bulk_operations_condition_result_count" : {
            "view" : "usanetwork_press_rules_get_child_terms|default",
            "args" : [ "term:tid" ],
            "minimum" : "1"
          }
        }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "usanetwork_press_rules_get_child_terms|default",
              "args" : "[term:tid]"
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_term", "value" : [ "entity-list:0" ] },
            "PROVIDE" : { "variable_added" : { "child_term" : "Added variable" } }
          }
        },
        { "redirect" : { "url" : "[child-term:url]" } }
      ]
    }
  }');
  $items['usanetwork_press_core_redirect_on_photos_page_raw_view'] = entity_import('rules_config', '{ "usanetwork_press_core_redirect_on_photos_page_raw_view" : {
      "LABEL" : "Redirect on photos page raw view",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_view--usanetwork_photos" : { "bundle" : "usanetwork_photos" },
        "node_view--contacts_page" : { "bundle" : "contacts_page" },
        "node_view--links_page" : { "bundle" : "links_page" }
      },
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_term", "value" : [ "node:field-menu-position" ] },
            "PROVIDE" : { "variable_added" : { "menu_term" : "Added variable" } }
          }
        },
        { "redirect" : { "url" : "[menu-term:url]" } }
      ]
    }
  }');
  return $items;
}

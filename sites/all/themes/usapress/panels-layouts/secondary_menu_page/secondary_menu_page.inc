<?php

// Plugin definition
$plugin = array(
  'title' => t('Page content and secondary menu'),
  'category' => t('Pages'),
  'icon' => 'secondary_menu_page.png',
  'theme' => 'secondary_menu_page',
  'css' => 'secondary_menu_page.css',
  'regions' => array(
    'content' => t('Page content'),
    'secondary_menu' => t('Secondary menu'),
  ),
);

<?php

// Plugin definition
$plugin = array(
  'title' => t('Header'),
  'category' => t('Pages'),
  'icon' => 'header.png',
  'theme' => 'header',
  'css' => 'header.css',
  'regions' => array(
    'press_kits' => t('Available Press Kits menu'),
    'header_image' => t('Header of selected Press Kit'),
    'main_menu' => t('Main Menu'),
    'content' => t('Content'),
  ),
);

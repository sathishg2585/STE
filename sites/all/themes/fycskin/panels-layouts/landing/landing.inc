<?php

// Plugin definition
$plugin = array(
  'title' => t('Landing'),
  'category' => t('Landing Page'),
  'icon' => 'landing.png',
  'theme' => 'landing',
  'css' => 'landing.css',
  'regions' => array(
    'header' => t('Header'),
    'content' => t('Content'),
    'footer' => t('Footer'),
  ),
);

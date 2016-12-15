<?php
/**
 * FYC Header
 */
?>

  <div class="fyc-logo-wrapper">
    <?php
      $logo_link = array(
        'text' => '<div class="fyc-logo"><img src="' . theme_get_setting('logo') . '" class="fyc-logo-img"/></div>',
        'url' => base_path(),
      );
      echo l($logo_link['text'], $logo_link['url'], array('html' => TRUE)); 
    ?>
  </div>
  <div class="fyc-usa-wrapper">
    <div class="fyc-usa-message">
    <?php
      $usa_link = array(
        'text' => t('FOR MORE ABOUT') . ' ' . SITE_PARENT . ', ' . t('CLICK HERE'),
        'url' => SITE_PARENT_LINK,
        'options' => array(
          'external' => TRUE,
        ),
      );    
      echo l($usa_link['text'], $usa_link['url'], array_merge($usa_link['options'], array('attributes' => array('class' => array('header_link'))))); 
    ?>
    </div>
    <div class="fyc-usa-logo"></div>
  </div>

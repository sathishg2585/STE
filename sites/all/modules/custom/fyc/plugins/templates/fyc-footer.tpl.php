<?php
/**
 * FYC Footer
 */
?>
<div class="fyc-footer">
  <?php
    $footer_link = array(
      array(
        'text' => SITE_PARENT,
        'url' => SITE_PARENT_LINK,
      ),
      array(
        'text' => t('Terms of Service'),
        'url' => SITE_PARENT_LINK . '/terms/',
      ),
      array(
        'text' => t('Privacy Policy'),
        'url' => SITE_PARENT_LINK . '/privacy/',
      ),    
    );

    $items = array();
    foreach($footer_link as $key => $value) {
      $items[] = array(
        'data' => l($value['text'], $value['url'])
      );
    }
    
    print theme_item_list(array('items' => $items, 'title'=> '', 'type' => 'ul', 'attributes' => array()));
  ?>
  <div class="fyc-copyright">&copy;&nbsp;<?php echo date("Y");?>&nbsp;<?php echo t('NBCUniversal, Inc. All Rights Reserved.'); ?></div>
  <div class="fyc-corp"></div>
</div>

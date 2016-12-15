<?php
/**
 * @file
 * Template for a 3 regions panel layout for header on pages.
 *
 * This template provides a 3 region panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Tab menu.
 *   - $content['left']: awards.
 *   - $content['right']: awards background image.
 */
?>
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="award-wrapper">
    <div class="fyc-award-top-wrapper clearfix">
      <?php if (!empty($content['top'])): ?>
        <?php print $content['top']; ?>
      <?php endif; ?>
    </div>
    <div class="fyc-award-wrapper clearfix">
      <div class="fyc-award-left-wrapper clearfix">
        <?php if (!empty($content['left'])): ?>
        <div id="tabcontent">
          <div class="tabscrollcontent">
            <?php print $content['left']; ?>
          </div>
        </div>
        <?php endif; ?>
      </div>
      <div class="fyc-award-right-wrapper clearfix">
        <?php if (!empty($content['right'])): ?>
          <?php print $content['right']; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>

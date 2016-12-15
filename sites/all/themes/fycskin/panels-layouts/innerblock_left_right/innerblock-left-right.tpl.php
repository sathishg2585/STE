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
 *   - $content['left']: Series overview background image part.
 *   - $content['right']: Series overview content.
 */
?>
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="fyc-left-wrapper clearfix">
    <?php if (!empty($content['left'])): ?>
      <?php print $content['left']; ?>
    <?php endif; ?>
  </div>
  <div class="fyc-right-wrapper clearfix">
    <?php if (!empty($content['right'])): ?>
      <div id="scrollwrapper">
        <div class="scrollcontent">
          <?php print $content['right']; ?>
        </div>
      </div>
    <?php endif; ?>
  </div>
</div>

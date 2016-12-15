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
 *   - $content['header']: Content in the fyc_show part.
 *   - $content['content']: Content in the header_image part.
 *   - $content['footer']: Content in the main_menu part.
 */
?>
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<div class="fyc-homepage-project-wrapper">
	  <div class="fyc-header-wrapper clearfix">
	  <?php if (!empty($content['header'])): ?>
		 <?php print $content['header']; ?>
	  <?php endif; ?>
	  </div>
	  <div class="fyc-content-wrapper">
	  <?php if (!empty($content['content'])): ?>
		<?php print $content['content']; ?>
	  <?php endif; ?>
	  </div>
	  <div class="fyc-footer-wrapper">
		<?php if (!empty($content['footer'])): ?>
			<?php print $content['footer']; ?>
		<?php endif; ?>
	  </div>
	</div>
</div>

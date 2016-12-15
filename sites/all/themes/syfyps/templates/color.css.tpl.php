<?php if (!empty($tune_in)): ?>
.sy-fy-press-single-homepage .pane-node-field-press-kit-date-text .field,
.sy-fy-press-single-homepage .pane-node-field-press-kit-date-date .field,
.sy-fy-press-multi-homepage .views-field-field-press-kit-date-text .field,
.sy-fy-press-multi-homepage .views-field-field-press-kit-date-date .field,
.syfy-press-header-wrapper .pane-node-field-press-kit-date-text .field,
.syfy-press-header-wrapper .pane-node-field-press-kit-date-date .field,
.pane-syfy-press-enter-label .enter-site-label .syfy-press-enter-site-label {
  color: <?php print $tune_in; ?>
}
.pane-syfy-press-enter-label .enter-site-label .syfy-press-enter-site-label {
  border-color: <?php print $tune_in; ?>
}
<?php endif; ?>

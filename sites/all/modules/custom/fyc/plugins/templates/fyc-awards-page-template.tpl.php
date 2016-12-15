<?php
/**
 * FYC Awards page
 */
?>
<div class="fyc-award-nominations">
  <div class="show-bio">
      <div class="bio_content">
        <?php foreach ($data['#content']['fyc_awards_list'] as $awards_list): ?>
          <?php
            $patterns = array('/[^A-Za-z0-9\-]/');
            $replacements = array("");
            $classname = strtolower(preg_replace($patterns, $replacements, $awards_list->field_fyc_award_name->value()));
          ?>
          <div class="content fyc-award-tab-content <?php print $classname; ?>-tab-content">
            <h3><?php print $awards_list->field_fyc_award_name->value(); ?></h3>
            <ul class="fyc_list">
              <li class="upcase">
                <?php if (isset($awards_list->field_fyc_award_category->value()->name) && !empty($awards_list->field_fyc_award_category->value()->name)): ?>
                  <span><?php print $awards_list->field_fyc_award_category->value()->name; ?></span>
                <?php endif; ?>
                <ul>
                  <?php foreach($awards_list->field_fyc_nominees as $nominee): ?>
                    <li>
                      <?php print $nominee->field_award_name->value(); ?>
                      <?php if (($nominee->field_award_nominee->value() != "") && !empty($nominee->field_award_nominee->value())): ?>
                      - <span><?php print $nominee->field_award_nominee->value(); ?></span>
                      <?php endif; ?>
                    </li>
                  <?php endforeach; ?>              
                </ul>
              </li>            
            </ul>                  
          </div>
        <?php endforeach; ?>
      </div>
  </div>
</div>

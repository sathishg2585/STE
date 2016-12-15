<?php
/**
 * FYCSyfy Vimeo Video page
 */
?>
<div class="fyc-video-page">
  <?php if (!empty($data['#content']['fycsyfy_vimeo_list'])): ?>
    <?php
      if (count($data['#content']['fycsyfy_vimeo_list']) > 0 && isset($data['#content']['fycsyfy_vimeo_list'][0])) {
        $first_video = $data['#content']['fycsyfy_vimeo_list'][0];
      }
    ?>
    <section class="player vimeo-feed">
      <section class="grid">				
        <section class="video-player" data-enabled="true<?php //= $enabled ?>" data-url="<?php print $first_video->field_fycsyfy_vimeo_url->value() ? $first_video->field_fycsyfy_vimeo_url->value() : ''; ?>">
          <iframe src="<?php print $first_video->field_fycsyfy_vimeo_url->value() ? $first_video->field_fycsyfy_vimeo_url->value() : ''; ?>" name="vimeo-player" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>
          <aside class="playlist">
            <div id="video-scroll" class="scroll-vertical scrollbars container">
              <ul class="content scrollbars">
                <?php foreach ($data['#content']['fycsyfy_vimeo_list'] as $vimeo_list):?>
										<li>
											<a title="<?php print $vimeo_list->field_fycsyfy_vimeo_title->value(); ?>" href="<?php print $vimeo_list->field_fycsyfy_vimeo_url->value(); ?>" target="vimeo-player"
                        <?php foreach ($vimeo_list as $key => $value): ?>
                          <?php if (strtolower(substr(strrchr($key, "_"), 1)) != '' && strtolower(substr(strrchr($key, "_"), 1)) != 'entity' && strtolower(substr(strrchr($key, "_"), 1)) != 'id' && strtolower(substr(strrchr($key, "_"), 1)) != 'thumbnail' && strtolower(substr(strrchr($key, "_"), 1)) != 'name'): ?>
                            <?php print ' data-' . strtolower(substr(strrchr($key, "_"), 1)) . '="' . htmlentities($value->value()) . '"'; ?>
                          <?php endif; ?>
                        <?php endforeach; ?>>
                        <?php if (!empty($vimeo_list->field_fycsyfy_vimeo_thumbnail->value())): ?>
												<img src="<?php print file_create_url($vimeo_list->field_fycsyfy_vimeo_thumbnail->value()['uri']); ?>"/>
                        <?php else: ?>
                        <img src="/<?php print drupal_get_path('theme', 'fycsyfy_skin') . '/images/videos-default-thumb.jpg'; ?>"/>
                        <?php endif; ?>
												<span><?php print (!empty($vimeo_list->field_fycsyfy_vimeo_fullepisode) && $vimeo_list->field_fycsyfy_vimeo_fullepisode->value() == 'full' && !empty($vimeo_list->field_fycsyfy_vimeo_season->value()) && !empty($vimeo_list->field_fycsyfy_vimeo_episode->value())) ? 'Episode #' . $vimeo_list->field_fycsyfy_vimeo_season->value() . str_pad($vimeo_list->field_fycsyfy_vimeo_episode->value(), 2, '0', STR_PAD_LEFT) . ' ' : ''; ?>
                          <?php print $vimeo_list->field_fycsyfy_vimeo_title->value(); ?>
                        </span>
											</a>
										</li>
                <?php endforeach; ?>
              </ul>
            </div>
          </aside>
        </section>

        <section class="grid">
          <section class="video-description">
            <span>
              <h1></h1>
              <p></p>
            </span>
          </section>
          <section class="quotes">
            <span class="fyc">
              For Your Consideration
            </span>
          </section>
        </section>			
      </section><!-- /.grid -->
    </section>
  <?php endif; ?>
</div>
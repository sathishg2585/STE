(function ($) {

Drupal.behaviors.usanetwork_press_media = {
  attach: function(context, settings) {
    Drupal.media.usanetwork_press  = {};

    Drupal.media.formatForm.submit = function (fid) {
      // @see Drupal.behaviors.mediaFormatForm.attach().
      var buttons = $(parent.window.document.body).find('#mediaStyleSelector').parent('.ui-dialog').find('.ui-icon-closethick');

      if (Drupal.settings.hasOwnProperty('usanetwork_press') && Drupal.settings.usanetwork_press[fid] != undefined) {
        var instanceId = Object.keys(parent.window.Drupal.wysiwyg.instances)[0];
        var element = parent.window.Drupal.media.filter.create_element(Drupal.settings.usanetwork_press[fid], {
          fid: fid,
          view_mode: 'default',
          attributes: [],
          fields: []
        });
        // Get the markup and register it for the macro / placeholder handling.
        var markup = parent.window.Drupal.media.filter.getWysiwygHTML(element);

        // Insert placeholder markup into wysiwyg.
        parent.window.Drupal.wysiwyg.instances[instanceId].insert(markup);
      }
      buttons[0].click();
    }
  }
};

})(jQuery);

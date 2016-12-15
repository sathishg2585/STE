(function ($) {

Drupal.behaviors.ManualCrop = {
  attach: function(context, settings) {
    if (typeof ManualCrop === 'object') {
      ManualCrop.showCroptool = function(identifier, style, fid) {
        var styleName, styleSelect, cropType, origContainer, conWidth, conHeight;

        if (ManualCrop.croptool) {
          // Close the current croptool.
          ManualCrop.closeCroptool();
        }

        // Get the style name.
        if (typeof style == 'string') {
          styleName = style
        }
        else {
          styleSelect = $(style);
          styleName = styleSelect.val();
        }

        ManualCrop.isLoaded('.manualcrop-file-' + fid + '-holder', function() {
          // IE executes this callback twice, so we check if the ManualCrop.croptool
          // has already been set and skip the rest if this is the case.
          if (!ManualCrop.croptool) {
            // Determine the croptool type.
            if ($('#manualcrop-overlay-' + fid).length == 1) {
              cropType = 'overlay';
              origContainer = $('#manualcrop-overlay-' + fid);
            }
            else {
              cropType = 'inline';
              origContainer = $('#manualcrop-inline-' + fid);
            }

            // Get the settings.
            var styleSettings = Drupal.settings.manualcrop.styles[styleName] || null;
            var elementSettings = Drupal.settings.manualcrop.elements[identifier] || null;

            // Get the destination element and the current selection.
            ManualCrop.output = $('#manualcrop-area-' + fid + '-' + styleName);
            ManualCrop.oldSelection = ManualCrop.parseStringSelection(ManualCrop.output.val());

            // Create the croptool.
            ManualCrop.croptool = origContainer.clone()
              .removeAttr('id')
              .removeClass('element-hidden');

            // Get the container maximum width and height.
            if (cropType == 'overlay') {
              conWidth = $(window).width();
              conHeight = $(window).height();
            }
            else {
              conWidth = origContainer.parent().innerWidth();
              conHeight = $(window).height();
            }

            // Tool width and height.
            ManualCrop.croptool.css('width', conWidth + 'px');

            if (cropType == 'overlay') {
              ManualCrop.croptool.css('height', conHeight + 'px');
            }

            // Get the image and its dimensions.
            var image = $('.manualcrop-image', origContainer);
            var dimensions = ManualCrop.getImageDimensions(image);

            // Scale the image to fit the maximum width and height (so all is visible).
            var maxWidth = conWidth - ManualCrop.parseInt(image.css('marginLeft')) - ManualCrop.parseInt(image.css('marginRight'));
            var maxHeight = conHeight - ManualCrop.parseInt(image.css('marginTop')) - ManualCrop.parseInt(image.css('marginBottom'));

            // Calculate the clone image dimensions.
            var resized = ManualCrop.resizeDimensions(dimensions.width, dimensions.height, maxWidth, maxHeight);

            // Set the new width and height to the cloned image.
            image = $('.manualcrop-image', ManualCrop.croptool)
              .css('width', resized.width + 'px')
              .css('height', resized.height + 'px');

            // Basic imgAreaSelect options; All options are set - also if it's their
            // default value - because IE doesn't seem to use the default values.
            var options = {
              handles: true,
              instance: true,
              keys: (!elementSettings || elementSettings.keyboard),
              movable: true,
              resizable: true,
              parent: image.parent(),
              imageWidth: dimensions.width,
              imageHeight: dimensions.height,
              onSelectChange: ManualCrop.updateSelection
            };

            // Additional options based upon the effect.
            if (styleSettings) {
              switch (styleSettings.effect) {
                // Crop and scale effect.
                case 'manualcrop_crop_and_scale':
                  options.aspectRatio = styleSettings.data.width + ':' + styleSettings.data.height;

                  if (styleSettings.data.respectminimum) {
                    // Crop at least the minimum.
                    options.minWidth = ManualCrop.parseInt(styleSettings.data.width);
                    options.minHeight = ManualCrop.parseInt(styleSettings.data.height);
                  }
                  break;

                // Crop effect.
                case 'manualcrop_crop':
                  if (styleSettings.data.width) {
                    options.minWidth = ManualCrop.parseInt(styleSettings.data.width);
                  }

                  if (styleSettings.data.height) {
                    options.minHeight = ManualCrop.parseInt(styleSettings.data.height);
                  }

                  if (typeof styleSettings.data.keepproportions != 'undefined' && styleSettings.data.keepproportions) {
                    options.aspectRatio = styleSettings.data.width + ':' + styleSettings.data.height;
                  }
              }
              var button_id = ($('.manualcrop-style-button-' + fid).attr("id"));
              var recurring_id = button_id.substr(27, 1);
              var check_box_id = "#edit-field-syfy-photos-und-"+recurring_id+"-field-syfy-vertical-photo-und";
              if ($(check_box_id).is(":checked")) {
                options.aspectRatio = false;
              }            
            }

            // Set the image style name.
            $('.manualcrop-style-name', ManualCrop.croptool).text(styleName);

            if (typeof styleSelect != 'undefined') {
              // Reset the image style selection list.
              styleSelect.val('');
              styleSelect.blur();
            }
            else {
              // Hide the crop button.
              $('.manualcrop-style-button-' + fid).hide();
            }

            // Append the cropping area (last, to prevent that "_11" is undefined).
            if (cropType == 'overlay') {
              $('body').append(ManualCrop.croptool);
            }
            else {
              origContainer.parent().append(ManualCrop.croptool);
            }

            // Put our overlay on top.
            if (cropType == 'overlay') {
              var overlayContainer = $('#overlay-container', top.document);
              if (overlayContainer.length) {
                overlayContainer
                  .addClass('manualcrop-tweaked')
                  .data('old-z-index', overlayContainer.css('z-index'))
                  .css('z-index', '1000');
              }
            }

            // Create the crop widget.
            ManualCrop.widget = image.imgAreaSelect(options);

            // IE seems to have some issues with the imgAreaSelect $parent variable,
            // so we set the options again to initialize it correctly.
            if (navigator.userAgent.toLowerCase().indexOf('msie ') != -1) {
              ManualCrop.widget.setOptions(options);
            }

            // Move the selection info into the widget.
            var selectionInfo = $('.manualcrop-selection-info', ManualCrop.croptool);
            if (selectionInfo.length) {
              $('.imgareaselect-selection', ManualCrop.croptool)
                .after(selectionInfo)
                .parent().css('overflow', 'visible');
            }

            // Insert the instant preview image.
            var instantPreview = $('.manualcrop-instantpreview', ManualCrop.croptool);
            if (instantPreview.length) {
              // Save the current width as maximum width and height.
              instantPreview
                .data('maxWidth', instantPreview.width())
                .data('maxHeight', instantPreview.width())
                .height(instantPreview.width());

              // Calculate the instant preview dimensions.
              resized = ManualCrop.resizeDimensions(dimensions.width, dimensions.height, instantPreview.width(), instantPreview.width());

              // Set those dimensions.
              image.clone().appendTo(instantPreview)
                .removeClass()
                .css('width', resized.width + 'px')
                .css('height', resized.height + 'px');
            }

            if (!ManualCrop.oldSelection) {
              // Create a default crop area.
              if (elementSettings && elementSettings.defaultCropArea) {
                if (elementSettings.maximizeDefaultCropArea) {
                  ManualCrop.isLoaded(ManualCrop.croptool, ManualCrop.maximizeSelection);
                }
                else {
                  var minWidth = (typeof options.minWidth != 'undefined' ? options.minWidth : 0);
                  var minHeight = (typeof options.minHeight != 'undefined' ? options.minHeight : 0)

                  // Set a width and height.
                  var selection = {
                    width: (minWidth ? minWidth * 100 : (width / 2)),
                    height: (minHeight ? minHeight * 100 : (height / 2)),
                    maxWidth: (dimensions.width / 2),
                    maxHeight: (dimensions.height / 2)
                  };

                  // Resize the selection.
                  selection = ManualCrop.resizeDimensions(selection);

                  // Make sure we respect the minimum dimensions.
                  if (minWidth || minHeight) {
                    if (minWidth && selection.width < minWidth) {
                      selection.width = minWidth;

                      if (minHeight) {
                        selection.height = minHeight;
                      }
                    }
                    else if (minHeight && selection.height < minHeight) {
                      selection.height = minHeight;

                      if (minWidth) {
                        selection.width = minWidth;
                      }
                    }
                  }

                  // Center the selection.
                  selection.x1 = Math.round((dimensions.width - selection.width) / 2);
                  selection.y1 = Math.round((dimensions.height - selection.height) / 2);
                  selection.x2 = selection.x1 + selection.width;
                  selection.y2 = selection.y1 + selection.height;

                  // Set the selection.
                  ManualCrop.isLoaded(ManualCrop.croptool, function() {
                    ManualCrop.setSelection(selection);
                  });
                }
              }
            }
            else {
              // Set the initial selection.
              ManualCrop.isLoaded(ManualCrop.croptool, ManualCrop.resetSelection);
            }

            // Handle keyboard shortcuts.
            if (!elementSettings || elementSettings.keyboard) {
              $(document).keyup(ManualCrop.handleKeyboard);
            }
          }
        });
      }
    }
  }
};

})(jQuery);

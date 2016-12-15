(function ($) {

/**
 * A progressbar object. Initialized with the given id. Must be inserted into
 * the DOM afterwards through progressBar.element.
 *
 * method is the function which will perform the HTTP request to get the
 * progress bar state. Either "GET" or "POST".
 *
 * e.g. pb = new progressBar('myProgressBar');
 *      some_element.appendChild(pb.element);
 */
Drupal.progressBar = function (id, updateCallback, method, errorCallback) {
  var pb = this;
  this.id = id;
  this.method = method || 'GET';
  this.updateCallback = updateCallback;
  this.errorCallback = errorCallback;

  // The WAI-ARIA setting aria-live="polite" will announce changes after users
  // have completed their current activity and not interrupt the screen reader.
  this.element = $('<div class="progress" aria-live="polite"></div>').attr('id', id);
  this.element.html('<div class="bar"><div class="filled"></div></div>' +
                    '<div class="percentage"></div>' +
                    '<div class="message">&nbsp;</div>');
};

/**
 * Set the percentage and status message for the progressbar.
 */
Drupal.progressBar.prototype.setProgress = function (percentage, message) {
  if (percentage >= 0 && percentage <= 100) {
    $('div.filled', this.element).css('width', percentage + '%');
    $('div.percentage', this.element).html(percentage + '%');
  }
  $('div.message', this.element).html(message);
  if (this.updateCallback) {
    this.updateCallback(percentage, message, this);
  }
};

/**
 * Start monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.startMonitoring = function (uri, delay) {
  this.delay = delay;
  this.uri = uri;
  this.sendPing();
};

/**
 * Stop monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.stopMonitoring = function () {
  clearTimeout(this.timer);
  // This allows monitoring to be stopped from within the callback.
  this.uri = null;
};

/**
 * Request progress data from server.
 */
Drupal.progressBar.prototype.sendPing = function () {
  if (this.timer) {
    clearTimeout(this.timer);
  }
  if (this.uri) {
    var pb = this;
    // When doing a post request, you need non-null data. Otherwise a
    // HTTP 411 or HTTP 406 (with Apache mod_security) error may result.
    $.ajax({
      type: this.method,
      url: this.uri,
      data: '',
      dataType: 'json',
      success: function (progress) {
        // Display errors.
        if (progress.status == 0) {
          pb.displayError(progress.data);
          return;
        }
        // Update display.
        pb.setProgress(progress.percentage, progress.message);
        // Schedule next timer.
        pb.timer = setTimeout(function () { pb.sendPing(); }, pb.delay);
      },
      error: function (xmlhttp) {
        pb.displayError(Drupal.ajaxError(xmlhttp, pb.uri));
      }
    });
  }
};

/**
 * Display errors on the page.
 */
Drupal.progressBar.prototype.displayError = function (string) {
  var error = $('<div class="messages error"></div>').html(string);
  $(this.element).before(error).hide();

  if (this.errorCallback) {
    this.errorCallback(this);
  }
};

})(jQuery);
;
/**
 * @file
 * Provides JavaScript additions to the managed file field type.
 *
 * This file provides progress bar support (if available), popup windows for
 * file previews, and disabling of other file fields during Ajax uploads (which
 * prevents separate file fields from accidentally uploading files).
 */

(function ($) {

/**
 * Attach behaviors to managed file element upload fields.
 */
Drupal.behaviors.fileValidateAutoAttach = {
  attach: function (context, settings) {
    if (settings.file && settings.file.elements) {
      $.each(settings.file.elements, function(selector) {
        var extensions = settings.file.elements[selector];
        $(selector, context).bind('change', {extensions: extensions}, Drupal.file.validateExtension);
      });
    }
  },
  detach: function (context, settings) {
    if (settings.file && settings.file.elements) {
      $.each(settings.file.elements, function(selector) {
        $(selector, context).unbind('change', Drupal.file.validateExtension);
      });
    }
  }
};

/**
 * Attach behaviors to the file upload and remove buttons.
 */
Drupal.behaviors.fileButtons = {
  attach: function (context) {
    $('input.form-submit', context).bind('mousedown', Drupal.file.disableFields);
    $('div.form-managed-file input.form-submit', context).bind('mousedown', Drupal.file.progressBar);
  },
  detach: function (context) {
    $('input.form-submit', context).unbind('mousedown', Drupal.file.disableFields);
    $('div.form-managed-file input.form-submit', context).unbind('mousedown', Drupal.file.progressBar);
  }
};

/**
 * Attach behaviors to links within managed file elements.
 */
Drupal.behaviors.filePreviewLinks = {
  attach: function (context) {
    $('div.form-managed-file .file a, .file-widget .file a', context).bind('click',Drupal.file.openInNewWindow);
  },
  detach: function (context){
    $('div.form-managed-file .file a, .file-widget .file a', context).unbind('click', Drupal.file.openInNewWindow);
  }
};

/**
 * File upload utility functions.
 */
Drupal.file = Drupal.file || {
  /**
   * Client-side file input validation of file extensions.
   */
  validateExtension: function (event) {
    // Remove any previous errors.
    $('.file-upload-js-error').remove();

    // Add client side validation for the input[type=file].
    var extensionPattern = event.data.extensions.replace(/,\s*/g, '|');
    if (extensionPattern.length > 1 && this.value.length > 0) {
      var acceptableMatch = new RegExp('\\.(' + extensionPattern + ')$', 'gi');
      if (!acceptableMatch.test(this.value)) {
        var error = Drupal.t("The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.", {
          // According to the specifications of HTML5, a file upload control
          // should not reveal the real local path to the file that a user
          // has selected. Some web browsers implement this restriction by
          // replacing the local path with "C:\fakepath\", which can cause
          // confusion by leaving the user thinking perhaps Drupal could not
          // find the file because it messed up the file path. To avoid this
          // confusion, therefore, we strip out the bogus fakepath string.
          '%filename': this.value.replace('C:\\fakepath\\', ''),
          '%extensions': extensionPattern.replace(/\|/g, ', ')
        });
        $(this).closest('div.form-managed-file').prepend('<div class="messages error file-upload-js-error" aria-live="polite">' + error + '</div>');
        this.value = '';
        return false;
      }
    }
  },
  /**
   * Prevent file uploads when using buttons not intended to upload.
   */
  disableFields: function (event){
    var clickedButton = this;

    // Only disable upload fields for Ajax buttons.
    if (!$(clickedButton).hasClass('ajax-processed')) {
      return;
    }

    // Check if we're working with an "Upload" button.
    var $enabledFields = [];
    if ($(this).closest('div.form-managed-file').length > 0) {
      $enabledFields = $(this).closest('div.form-managed-file').find('input.form-file');
    }

    // Temporarily disable upload fields other than the one we're currently
    // working with. Filter out fields that are already disabled so that they
    // do not get enabled when we re-enable these fields at the end of behavior
    // processing. Re-enable in a setTimeout set to a relatively short amount
    // of time (1 second). All the other mousedown handlers (like Drupal's Ajax
    // behaviors) are excuted before any timeout functions are called, so we
    // don't have to worry about the fields being re-enabled too soon.
    // @todo If the previous sentence is true, why not set the timeout to 0?
    var $fieldsToTemporarilyDisable = $('div.form-managed-file input.form-file').not($enabledFields).not(':disabled');
    $fieldsToTemporarilyDisable.attr('disabled', 'disabled');
    setTimeout(function (){
      $fieldsToTemporarilyDisable.attr('disabled', false);
    }, 1000);
  },
  /**
   * Add progress bar support if possible.
   */
  progressBar: function (event) {
    var clickedButton = this;
    var $progressId = $(clickedButton).closest('div.form-managed-file').find('input.file-progress');
    if ($progressId.length) {
      var originalName = $progressId.attr('name');

      // Replace the name with the required identifier.
      $progressId.attr('name', originalName.match(/APC_UPLOAD_PROGRESS|UPLOAD_IDENTIFIER/)[0]);

      // Restore the original name after the upload begins.
      setTimeout(function () {
        $progressId.attr('name', originalName);
      }, 1000);
    }
    // Show the progress bar if the upload takes longer than half a second.
    setTimeout(function () {
      $(clickedButton).closest('div.form-managed-file').find('div.ajax-progress-bar').slideDown();
    }, 500);
  },
  /**
   * Open links to files within forms in a new window.
   */
  openInNewWindow: function (event) {
    $(this).attr('target', '_blank');
    window.open(this.href, 'filePreview', 'toolbar=0,scrollbars=1,location=1,statusbar=1,menubar=0,resizable=1,width=500,height=550');
    return false;
  }
};

})(jQuery);
;
/**
 * @file
 * Provides default functions for the media browser
 */

(function ($) {
namespace('Drupal.media.browser');

Drupal.media.browser.selectedMedia = [];
Drupal.media.browser.mediaAdded = function () {};
Drupal.media.browser.selectionFinalized = function (selectedMedia) {
  // This is intended to be overridden if a callee wants to be triggered
  // when the media selection is finalized from inside the browser.
  // This is used for the file upload form for instance.
};

Drupal.behaviors.MediaBrowser = {
  attach: function (context) {
    if (Drupal.settings.media && Drupal.settings.media.selectedMedia) {
      Drupal.media.browser.selectMedia(Drupal.settings.media.selectedMedia);
      // Fire a confirmation of some sort.
      Drupal.media.browser.finalizeSelection();
    }

    // Instantiate the tabs.
    var showFunc = function(event, ui) {
      // Store index of the tab being activated.
      if (parent_iframe = Drupal.media.browser.getParentIframe(window)) {
        $(parent_iframe).attr('current_tab', $('#media-tabs-wrapper > ul > li.ui-state-active').index());
      }
    };
    var activeTab = Drupal.media.browser.tabFromHash();
    $('#media-browser-tabset').once('MediaBrowser').tabs({
      selected: activeTab, // jquery < 1.9
      active: activeTab, // jquery >= 1.9
      show: showFunc, // jquery ui < 1.8
      activate: showFunc // jquery ui >= 1.8
    });

    $('.media-browser-tab').each( Drupal.media.browser.validateButtons );
  }
  // Wait for additional params to be passed in.
};

Drupal.media.browser.getParentIframe = function (window) {
  var arrFrames = parent.document.getElementsByTagName("IFRAME");
  for (var i = 0; i < arrFrames.length; i++) {
    if (arrFrames[i].contentWindow === window) {
      return arrFrames[i];
    }
  }
}

/**
 * Get index of the active tab from window.location.hash
 */
Drupal.media.browser.tabFromHash = function () {
  if (parent_iframe = Drupal.media.browser.getParentIframe(window)) {
    return $(parent_iframe).attr('current_tab');
  }
  return 0;
};

Drupal.media.browser.launch = function () {

};

Drupal.media.browser.validateButtons = function() {
  // The media browser runs in an IFRAME. The Drupal.media.popups.mediaBrowser()
  // function sets up the IFRAME and an "OK" button that is outside of the
  // IFRAME, so that its click handlers can destroy the IFRAME while retaining
  // information about what media items were selected. However, Drupal UI
  // convention is to place all action buttons on the same "line" at the bottom
  // of the form, so if the form within the IFRAME contains a "Submit" button or
  // other action buttons, then the "OK" button will appear below the IFRAME
  // which breaks this convention and is confusing to the user. Therefore, we
  // add a "Submit" button inside the IFRAME, and have its click action trigger
  // the click action of the corresponding "OK" button that is outside the
  // IFRAME. media.css contains CSS rules that hide the outside buttons.

  // If a submit button is present, another round-trip to the server is needed
  // before the user's selection is finalized. For these cases, when the form's
  // real Submit button is clicked, the server either returns another form for
  // the user to fill out, or else a completion page that contains or sets the
  // Drupal.media.browser.selectedMedia variable. If the latter, then
  // Drupal.media.popups.mediaBrowser.mediaBrowserOnLoad() auto-triggers the
  // "OK" button action to finalize the selection and remove the IFRAME.

  // We need to check for the fake submit button that is used on non-form based
  // pane content. On these items we need to bind the clicks so that media can
  // be selected or the window can be closed. This is still a hacky approach,
  // but it is a step in the right direction.

  $('a.button.fake-submit', this).once().bind('click', Drupal.media.browser.submit);
};

Drupal.media.browser.submit = function () {
  // @see Drupal.media.browser.validateButtons().
  var buttons = $(parent.window.document.body).find('#mediaBrowser').parent('.ui-dialog').find('.ui-dialog-buttonpane button');
  buttons[0].click();

  // Return false to prevent the fake link "click" from continuing.
  return false;
}

Drupal.media.browser.selectMedia = function (selectedMedia) {
  Drupal.media.browser.selectedMedia = selectedMedia;
};

Drupal.media.browser.selectMediaAndSubmit = function (selectedMedia) {
  Drupal.media.browser.selectedMedia = selectedMedia;
  Drupal.media.browser.submit();
};

Drupal.media.browser.finalizeSelection = function () {
  if (!Drupal.media.browser.selectedMedia) {
    throw new exception(Drupal.t('Cannot continue, nothing selected'));
  }
  else {
    Drupal.media.browser.selectionFinalized(Drupal.media.browser.selectedMedia);
  }
};

}(jQuery));
;
(function ($, win) {

Drupal.behaviors.hideSubmitBlockit = {
  attach: function(context) {
    var timeoutId = null;
    $('form', context).once('hideSubmitButton', function () {
      var $form = $(this);

      // Bind to input elements.
      $('input.form-submit', $form).click(function (e) {
        var el = $(this);
        el.after('<input type="hidden" name="' + el.attr('name') + '" value="' + el.attr('value') + '" />');
        return true;
      });

      // Bind to form submit.
      $('form', context).submit(function (e) {
        var settings = Drupal.settings.hide_submit;
        var $inp;
        if (!e.isPropagationStopped()) {
          if (settings.hide_submit_method == 'disable') {
            $('input.form-submit', $form).attr('disabled', 'disabled').each(function (i) {
              var $button = $(this);
              if (settings.hide_submit_css) {
                $button.addClass(settings.hide_submit_css);
              }
              if (settings.hide_submit_abtext) {
                $button.val($button.val() + ' ' + settings.hide_submit_abtext);
              }
              $inp = $button;
            });

            if ($inp && settings.hide_submit_atext) {
              $inp.after('<span class="hide-submit-text">' + Drupal.checkPlain(settings.hide_submit_atext) + '</span>');
            }
          }
          else {
            var pdiv = '<div class="hide-submit-text' + (settings.hide_submit_hide_css ? ' ' + Drupal.checkPlain(settings.hide_submit_hide_css) + '"' : '') + '>' + Drupal.checkPlain(settings.hide_submit_hide_text) + '</div>';
            if (settings.hide_submit_hide_fx) {
              $('input.form-submit', $form).addClass(settings.hide_submit_css).fadeOut(100).eq(0).after(pdiv);
              $('input.form-submit', $form).next().fadeIn(100);
            }
            else {
              $('input.form-submit', $form).addClass(settings.hide_submit_css).hide().eq(0).after(pdiv);
            }
          }
          // Add a timeout to rerset the buttons (if needed).
          if (settings.hide_submit_reset_time) {
            timeoutId = window.setTimeout(function() {
              hideSubmitResetButtons(null, $form);
            }, settings.hide_submit_reset_time);
          }
        }
        return true;
      });
    });

    // Bind to clientsideValidationFormHasErrors to support clientside validation.
    $(document).bind('clientsideValidationFormHasErrors', function(event, form) {
      //hideSubmitResetButtons(event, form.form);
    });

    // Reset all buttons.
    function hideSubmitResetButtons(event, form) {
      // Clear timer.
      window.clearTimeout(timeoutId);
      timeoutId = null;

      var settings = Drupal.settings.hide_submit;
      if (settings.hide_submit_method == 'disable') {
        $('input.' + Drupal.checkPlain(settings.hide_submit_css), form)
          .removeClass(Drupal.checkPlain(settings.hide_submit_hide_css))
          .removeAttr('disabled');
        $('.hide-submit-text', form).remove();
      }
      else {
        $('input.' + Drupal.checkPlain(settings.hide_submit_css), form)
          .stop()
          .removeClass(Drupal.checkPlain(settings.hide_submit_hide_css))
          .show();
        $('.hide-submit-text', form).remove();
      }
    }
  }
};

})(jQuery, window);

;
// Generated by CoffeeScript 1.4.0
/*
jQuery Waypoints - v2.0.2
Copyright (c) 2011-2013 Caleb Troughton
Dual licensed under the MIT license and GPL license.
https://github.com/imakewebthings/jquery-waypoints/blob/master/licenses.txt
*/
(function(){var t=[].indexOf||function(t){for(var e=0,n=this.length;e<n;e++){if(e in this&&this[e]===t)return e}return-1},e=[].slice;(function(t,e){if(typeof define==="function"&&define.amd){return define("waypoints",["jquery"],function(n){return e(n,t)})}else{return e(t.jQuery,t)}})(this,function(n,r){var i,o,l,s,f,u,a,c,h,d,p,y,v,w,g,m;i=n(r);c=t.call(r,"ontouchstart")>=0;s={horizontal:{},vertical:{}};f=1;a={};u="waypoints-context-id";p="resize.waypoints";y="scroll.waypoints";v=1;w="waypoints-waypoint-ids";g="waypoint";m="waypoints";o=function(){function t(t){var e=this;this.$element=t;this.element=t[0];this.didResize=false;this.didScroll=false;this.id="context"+f++;this.oldScroll={x:t.scrollLeft(),y:t.scrollTop()};this.waypoints={horizontal:{},vertical:{}};t.data(u,this.id);a[this.id]=this;t.bind(y,function(){var t;if(!(e.didScroll||c)){e.didScroll=true;t=function(){e.doScroll();return e.didScroll=false};return r.setTimeout(t,n[m].settings.scrollThrottle)}});t.bind(p,function(){var t;if(!e.didResize){e.didResize=true;t=function(){n[m]("refresh");return e.didResize=false};return r.setTimeout(t,n[m].settings.resizeThrottle)}})}t.prototype.doScroll=function(){var t,e=this;t={horizontal:{newScroll:this.$element.scrollLeft(),oldScroll:this.oldScroll.x,forward:"right",backward:"left"},vertical:{newScroll:this.$element.scrollTop(),oldScroll:this.oldScroll.y,forward:"down",backward:"up"}};if(c&&(!t.vertical.oldScroll||!t.vertical.newScroll)){n[m]("refresh")}n.each(t,function(t,r){var i,o,l;l=[];o=r.newScroll>r.oldScroll;i=o?r.forward:r.backward;n.each(e.waypoints[t],function(t,e){var n,i;if(r.oldScroll<(n=e.offset)&&n<=r.newScroll){return l.push(e)}else if(r.newScroll<(i=e.offset)&&i<=r.oldScroll){return l.push(e)}});l.sort(function(t,e){return t.offset-e.offset});if(!o){l.reverse()}return n.each(l,function(t,e){if(e.options.continuous||t===l.length-1){return e.trigger([i])}})});return this.oldScroll={x:t.horizontal.newScroll,y:t.vertical.newScroll}};t.prototype.refresh=function(){var t,e,r,i=this;r=n.isWindow(this.element);e=this.$element.offset();this.doScroll();t={horizontal:{contextOffset:r?0:e.left,contextScroll:r?0:this.oldScroll.x,contextDimension:this.$element.width(),oldScroll:this.oldScroll.x,forward:"right",backward:"left",offsetProp:"left"},vertical:{contextOffset:r?0:e.top,contextScroll:r?0:this.oldScroll.y,contextDimension:r?n[m]("viewportHeight"):this.$element.height(),oldScroll:this.oldScroll.y,forward:"down",backward:"up",offsetProp:"top"}};return n.each(t,function(t,e){return n.each(i.waypoints[t],function(t,r){var i,o,l,s,f;i=r.options.offset;l=r.offset;o=n.isWindow(r.element)?0:r.$element.offset()[e.offsetProp];if(n.isFunction(i)){i=i.apply(r.element)}else if(typeof i==="string"){i=parseFloat(i);if(r.options.offset.indexOf("%")>-1){i=Math.ceil(e.contextDimension*i/100)}}r.offset=o-e.contextOffset+e.contextScroll-i;if(r.options.onlyOnScroll&&l!=null||!r.enabled){return}if(l!==null&&l<(s=e.oldScroll)&&s<=r.offset){return r.trigger([e.backward])}else if(l!==null&&l>(f=e.oldScroll)&&f>=r.offset){return r.trigger([e.forward])}else if(l===null&&e.oldScroll>=r.offset){return r.trigger([e.forward])}})})};t.prototype.checkEmpty=function(){if(n.isEmptyObject(this.waypoints.horizontal)&&n.isEmptyObject(this.waypoints.vertical)){this.$element.unbind([p,y].join(" "));return delete a[this.id]}};return t}();l=function(){function t(t,e,r){var i,o;r=n.extend({},n.fn[g].defaults,r);if(r.offset==="bottom-in-view"){r.offset=function(){var t;t=n[m]("viewportHeight");if(!n.isWindow(e.element)){t=e.$element.height()}return t-n(this).outerHeight()}}this.$element=t;this.element=t[0];this.axis=r.horizontal?"horizontal":"vertical";this.callback=r.handler;this.context=e;this.enabled=r.enabled;this.id="waypoints"+v++;this.offset=null;this.options=r;e.waypoints[this.axis][this.id]=this;s[this.axis][this.id]=this;i=(o=t.data(w))!=null?o:[];i.push(this.id);t.data(w,i)}t.prototype.trigger=function(t){if(!this.enabled){return}if(this.callback!=null){this.callback.apply(this.element,t)}if(this.options.triggerOnce){return this.destroy()}};t.prototype.disable=function(){return this.enabled=false};t.prototype.enable=function(){this.context.refresh();return this.enabled=true};t.prototype.destroy=function(){delete s[this.axis][this.id];delete this.context.waypoints[this.axis][this.id];return this.context.checkEmpty()};t.getWaypointsByElement=function(t){var e,r;r=n(t).data(w);if(!r){return[]}e=n.extend({},s.horizontal,s.vertical);return n.map(r,function(t){return e[t]})};return t}();d={init:function(t,e){var r;if(e==null){e={}}if((r=e.handler)==null){e.handler=t}this.each(function(){var t,r,i,s;t=n(this);i=(s=e.context)!=null?s:n.fn[g].defaults.context;if(!n.isWindow(i)){i=t.closest(i)}i=n(i);r=a[i.data(u)];if(!r){r=new o(i)}return new l(t,r,e)});n[m]("refresh");return this},disable:function(){return d._invoke(this,"disable")},enable:function(){return d._invoke(this,"enable")},destroy:function(){return d._invoke(this,"destroy")},prev:function(t,e){return d._traverse.call(this,t,e,function(t,e,n){if(e>0){return t.push(n[e-1])}})},next:function(t,e){return d._traverse.call(this,t,e,function(t,e,n){if(e<n.length-1){return t.push(n[e+1])}})},_traverse:function(t,e,i){var o,l;if(t==null){t="vertical"}if(e==null){e=r}l=h.aggregate(e);o=[];this.each(function(){var e;e=n.inArray(this,l[t]);return i(o,e,l[t])});return this.pushStack(o)},_invoke:function(t,e){t.each(function(){var t;t=l.getWaypointsByElement(this);return n.each(t,function(t,n){n[e]();return true})});return this}};n.fn[g]=function(){var t,r;r=arguments[0],t=2<=arguments.length?e.call(arguments,1):[];if(d[r]){return d[r].apply(this,t)}else if(n.isFunction(r)){return d.init.apply(this,arguments)}else if(n.isPlainObject(r)){return d.init.apply(this,[null,r])}else if(!r){return n.error("jQuery Waypoints needs a callback function or handler option.")}else{return n.error("The "+r+" method does not exist in jQuery Waypoints.")}};n.fn[g].defaults={context:r,continuous:true,enabled:true,horizontal:false,offset:0,triggerOnce:false};h={refresh:function(){return n.each(a,function(t,e){return e.refresh()})},viewportHeight:function(){var t;return(t=r.innerHeight)!=null?t:i.height()},aggregate:function(t){var e,r,i;e=s;if(t){e=(i=a[n(t).data(u)])!=null?i.waypoints:void 0}if(!e){return[]}r={horizontal:[],vertical:[]};n.each(r,function(t,i){n.each(e[t],function(t,e){return i.push(e)});i.sort(function(t,e){return t.offset-e.offset});r[t]=n.map(i,function(t){return t.element});return r[t]=n.unique(r[t])});return r},above:function(t){if(t==null){t=r}return h._filter(t,"vertical",function(t,e){return e.offset<=t.oldScroll.y})},below:function(t){if(t==null){t=r}return h._filter(t,"vertical",function(t,e){return e.offset>t.oldScroll.y})},left:function(t){if(t==null){t=r}return h._filter(t,"horizontal",function(t,e){return e.offset<=t.oldScroll.x})},right:function(t){if(t==null){t=r}return h._filter(t,"horizontal",function(t,e){return e.offset>t.oldScroll.x})},enable:function(){return h._invoke("enable")},disable:function(){return h._invoke("disable")},destroy:function(){return h._invoke("destroy")},extendFn:function(t,e){return d[t]=e},_invoke:function(t){var e;e=n.extend({},s.vertical,s.horizontal);return n.each(e,function(e,n){n[t]();return true})},_filter:function(t,e,r){var i,o;i=a[n(t).data(u)];if(!i){return[]}o=[];n.each(i.waypoints[e],function(t,e){if(r(i,e)){return o.push(e)}});o.sort(function(t,e){return t.offset-e.offset});return n.map(o,function(t){return t.element})}};n[m]=function(){var t,n;n=arguments[0],t=2<=arguments.length?e.call(arguments,1):[];if(h[n]){return h[n].apply(null,t)}else{return h.aggregate.call(null,n)}};n[m].settings={resizeThrottle:100,scrollThrottle:30};return i.load(function(){return n[m]("refresh")})})}).call(this);;
// Generated by CoffeeScript 1.4.0
/*
Sticky Elements Shortcut for jQuery Waypoints - v2.0.2
Copyright (c) 2011-2013 Caleb Troughton
Dual licensed under the MIT license and GPL license.
https://github.com/imakewebthings/jquery-waypoints/blob/master/licenses.txt
*/
(function(){(function(t,n){if(typeof define==="function"&&define.amd){return define(["jquery","waypoints"],n)}else{return n(t.jQuery)}})(this,function(t){var n,e;n={wrapper:'<div class="sticky-wrapper" />',stuckClass:"stuck"};e=function(n,e){n.wrap(e.wrapper);n.each(function(){var n;n=t(this);n.parent().height(n.outerHeight());return true});return n.parent()};return t.waypoints("extendFn","sticky",function(r){var i,a;r=t.extend({},t.fn.waypoint.defaults,n,r);i=e(this,r);a=r.handler;r.handler=function(n){var e,i;e=t(this).children(":first");i=n==="down"||n==="right";e.toggleClass(r.stuckClass,i);if(a!=null){return a.call(this,n)}};i.waypoint(r);return this})})}).call(this);;
(function($) {
  /**
   * This entire SIAF basically just adds a class in 3 different cases.
   */
  Drupal.behaviors.stickyEditActions = {
    attach: function(context, settings) {
      // This fires the waypoint on the element normally being at the bottom
      // of the viewport.
      $('.my-sticky-element', context).waypoint('sticky', {
        offset: 'bottom-in-view',
        stuckClass: 'unstuck'
      });

      // This fires the waypoint when fieldsets are expanded, since Drupal
      // uses $.slideDown(), which has a callback which ends up using a
      // window.scrollTo() to do the expansion.
      // This fires the waypoint when vertical tabs are clicked.
      $('.vertical-tab-button a').click(function() {
        $.waypoints('refresh');
      });

      // Set dimensions of .my-sticky-element. We must do
      // this because once we 'position: fixed' in CSS it comes out of the DOM
      // flow and is uncontrollable by percentage.
      function setStickyElementWidthAndParentHeight() {
        $('.my-sticky-element').each(function (e) {
	  var $this = $(this);
          $this.width( $this.parent().width() );
          $this.parent().height( $this.outerHeight() );
        });
      }
      // First set dimensions on page load.
      setStickyElementWidthAndParentHeight();

      // Then continue to set the dimensions on resize events.
      $(window).resize(setStickyElementWidthAndParentHeight);

      // This sets everything up on the Media browser since when the tabs
      // are hidden with 'display: none;' the browser does not render them
      // and there are no dimensions yet so we need to have everything happen
      // on a click handler.
      $('#media-browser-tabset a').click(function() {
	$.waypoints('refresh');
	setStickyElementWidthAndParentHeight();
      });
    }
  };

  /**
   * OVERRIDING this function from collapse.js so we can add some
   * callbacks to slideDown & slideUp(). The .click() handler will not work on
   * fieldsets.
   *
   * Toggle the visibility of a fieldset using smooth animations.
   */
  Drupal.toggleFieldset = function (fieldset) {
    var $fieldset = $(fieldset);
    if ($fieldset.is('.collapsed')) {
      var $content = $('> .fieldset-wrapper', fieldset).hide();
      $fieldset
        .removeClass('collapsed')
        .trigger({ type: 'collapsed', value: false })
        .find('> legend span.fieldset-legend-prefix').html(Drupal.t('Hide'));
      $content.slideDown({
        duration: 'fast',
        easing: 'linear',
        complete: function () {
          Drupal.collapseScrollIntoView(fieldset);
          fieldset.animating = false;
          $.waypoints('refresh');
        },
        step: function () {
          // Scroll the fieldset into view.
          Drupal.collapseScrollIntoView(fieldset);
        }
      });
    }
    else {
      $fieldset.trigger({ type: 'collapsed', value: true });
      $('> .fieldset-wrapper', fieldset).slideUp('fast', function () {
        $fieldset
          .addClass('collapsed')
          .find('> legend span.fieldset-legend-prefix').html(Drupal.t('Show'));
        fieldset.animating = false;
        $.waypoints('refresh');
      });
    }
  };
}) (jQuery);
;

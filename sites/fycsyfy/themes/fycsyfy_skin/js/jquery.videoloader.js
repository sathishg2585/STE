
;(function( $, Mustache, window, document, undefined ) {

    var pluginName = 'videoloader',
    defaults = {
			videoBaseURL:			'//player.theplatform.com/p/HNK2IC/dd_syfy_vod_noauth_bare/select/media/guid/2304990266/',
			videoURLParams:		'?',
			feedBaseURL:			'//feed.theplatform.com/f/HNK2IC/FFb5gQRDlhib?form=json&sort=pubDate|asc',
			feedCategories:		'&byCategories=',
			feedGuid:					'&byGuid=',
			size:							'medium',
			autoplay:					false,
			posterWidth:			680,
			thumbWidth:				188,
			medaiExpression:		'full',
			selectedClass:			'selected',
			posterClass:				'poster',
			posterLoadedClass:	'loaded',
			descriptionClass: 	'video-description',
			enabled:						false,
			template:						null,
			category:						null,
			onDisabledClick:		null
		};

    function VideoLoader( element, options ) {
        this.element 			= element;
		this.options 			= $.extend( {}, defaults, options );
        this.defaults 			= defaults;
		this.hasPlaylist		= false;

		// jQuery DOM objects
		this.$element			= $( this.element );
		this.$iframe 			= $( '<iframe scrolling="no" frameborder="0" />' ).appendTo( this.$element );
		this.$poster 			= this.$element.find( '.' + this.options.posterClass );
		this.$desc 			= this.$element.siblings('.grid').children( '.' + this.options.descriptionClass );

		this.options.enabled	= this.options.enabled || this.$element.data( 'enabled' );
		this.options.category	= this.options.category || this.$element.data( 'category' );
		this.options.id 		= this.options.id || this.$element.data( 'id' );

		this.init();
    };

    VideoLoader.prototype.init = function() {
		// load feed if template and category have been provided
		if ( this.options.template && this.options.category ) {
			this.load( this.options.feedBaseURL + this.options.feedCategories + this.options.category );
			this.hasPlaylist = true;
		}

		this.addListeners();
    };

	// DOM listeners
	VideoLoader.prototype.addListeners = function() {
		var self = this;

		// playlist listener
		this.$element.on( 'click', 'li a', function( e ) {
			e.preventDefault();
			self.play( $( this ).attr( 'href' ), $(this).parent() );

      var title = $(this).data( 'title' );
      if ($(this).data('fullepisode') == 'long' && $(this).data('season') && $(this).data('episode')) {
        title = 'Episode ' + $(this).data('season') + ($(this).data('episode') < 10 ? '0' : '') + $(this).data('episode') + ': ' + title;
      }
			self.setDesc( $( this ).data( 'description' ), title, $( this ).data( 'fullepisode' ) );

		});

		// poster listener
		this.$poster.on( 'click', function( e ) {
			e.preventDefault();

			var url;

			if ( self.hasPlaylist ) {
				// get first video in list
				url = self.$element.find( 'ul li:eq(0) a' ).attr( 'href' );
			} else {
				// create url from id (autoplay regardless of options to avoid needing a second click to play)
				url = self.composeURL( self.options.id, true );
			}

			self.play( url );
		});
    };

	// load the feed
	VideoLoader.prototype.load = function( url ) {
		var self = this;

		$.ajax({
			type: 		'GET',
			dataType: 	'jsonp',
			url: 		url,
			cache: 		true // platform throws error if there is an underscore parameter, so keep this set to true
		}).done(function( data ) {
			self.render( self.clean( data ) );
		});
    };

	// clean JSON data into a format Mustache can work with
	VideoLoader.prototype.clean = function( data ) {
		var videos = [],
			poster,
			dirty,
			clean,
			thumb;

		if ( !data.hasOwnProperty( 'entries' ) || !data.entries.length ) {
			return false;
		}

		for ( var l = data.entries.length, i = 0; i < l; i++ ) {
			dirty = data.entries[ i ];
			clean = {
				id:		dirty.guid,
				description:	dirty.description,
				fullEpisode: ( dirty.pl1$fullEpisode == true ) ? 'long' : 'short' ,
				season: (typeof dirty.pl1$seasonNumber !== 'undefined') ? parseInt(dirty.pl1$seasonNumber) : null,
        episode: (typeof dirty.pl1$episodeNumber !== 'undefined') ? parseInt(dirty.pl1$episodeNumber) : null,
				url:	this.composeURL( dirty.guid, this.options.autoplay )
			};
			clean.title = ( dirty.title.indexOf(': ') > -1 ) ? dirty.title.substring( dirty.title.indexOf(': ')+2, dirty.title.length ) : dirty.title ;


			// find thumbnail/poster images in array
      var thumbWidth = 1920;
      var posterWidth = 1920;
			for ( var ii = dirty.media$thumbnails.length; ii--; ) {
				thumb = dirty.media$thumbnails[ ii ];

				if ( thumb.plfile$width >= this.options.thumbWidth && thumb.plfile$width <= thumbWidth) {
					clean.thumb = thumb.plfile$url;
          thumbWidth = thumb.plfile$width;
				}
        if ( i == 0 && (thumb.plfile$width >= this.options.posterWidth && thumb.plfile$width <= posterWidth)) {
					poster = thumb.plfile$url;
          posterWidth = thumb.plfile$width;
				}
			}


			videos.push( clean );
		}

		// add poster image
		this.$poster.append( '<img src="' + poster + '" />' );

		return { videos: videos };
    };

    VideoLoader.prototype.composeURL = function( id, autoplay ) {
		//var url = this.options.videoBaseURL + id + '/' + this.options.size; //04-May-15 removed old player parameters
		var url = this.options.videoBaseURL + id + '/';

		if ( autoplay ) {
			url += '/autoplay';
		}

		return url + this.options.videoURLParams;
    };

	// render data with Mustache
    VideoLoader.prototype.render = function( data ) {
      this.$element.append( Mustache.to_html( this.options.template, data ) );
		  this.setSelectedThumb( this.$element.find( 'li:eq(0) a' ).parent() );

      var $first = this.$element.find( 'li:eq(0) a' );
      if ($first.length > 0) {
        var title = $first.data( 'title' );
        if ($first.data('fullepisode') == 'long' && $first.data('season') && $first.data('episode')) {
          title = 'Episode ' + $first.data('season') + ($first.data('episode') < 10 ? '0' : '') + $first.data('episode') + ': ' + title;
        }

        this.setDesc( $first.data( 'description' ), title, this.$element.find( 'li:eq(0) a' ).data( 'fullepisode' ) );
      }
    };

	// play video
    VideoLoader.prototype.play = function( url, ele ) {
		ele = ele || this.$element.find('li').eq(0);
		if ( !this.options.enabled ) {
			this.applyDisabledCallback();
			return;
		}

		this.$iframe.attr( { 'src': url } );
		this.$poster.fadeOut();

		if ( this.hasPlaylist ) {
			// find matching element with url (remove autoplay from url if present since its added automatically to the first video)
			this.setSelectedThumb( ele );
		}
    };

	VideoLoader.prototype.reset = function() {
		_Log.info('reset called on :', this);
		this.$iframe.attr( 'src', '' );
		this.$poster.fadeIn();
		this.setSelectedThumb( this.$element.find( 'ul li:eq(0)' ) );
    };

	VideoLoader.prototype.setSelectedThumb = function( $li ) {
		this.$element.find( 'li.' + this.options.selectedClass )
			.removeClass( this.options.selectedClass );
		$li.addClass( this.options.selectedClass );
    };

	VideoLoader.prototype.setDesc = function( desc, title, fullEpisode ) {
		desc = desc || '';
		title = title || '';
		ele = this.$desc.find('span');
		_Log.info('full episode flag: ' + fullEpisode );
		_Log.info('args: ', arguments );
		var episodeFlag = ( fullEpisode == "long" ) ? "<small>(Full Episode)</small>" : '' ;
		// var subTitle = ( this.$element.data( 'category' ).indexOf('Series') > -1 ) ? ''  : '(Full Episode)' ;
		ele.fadeOut('fast', function(){
			$(this).html( '<h1>'+ title + episodeFlag + '</h1>\n<p>' + desc + '</p>').fadeIn('slow');
		});
    };


	VideoLoader.prototype.applyDisabledCallback = function() {
		if ( typeof this.options.onDisabledClick === 'function' ) {
			this.options.onDisabledClick.apply();
		}
	};

	// jQuery plugin implementation
    $.fn[pluginName] = function( options ) {
        return this.each(function() {
            if ( !$.data( this, pluginName ) ) {
                $.data( this, pluginName, new VideoLoader( this, options ) );
            }
        });
    };

})( jQuery, Mustache, window, document );

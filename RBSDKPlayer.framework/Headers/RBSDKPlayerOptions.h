//
//  RBSDKPlayerOptions.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 12/11/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

#ifndef RBSDKPlayerOptions_h
#define RBSDKPlayerOptions_h

/**
 `RBSDKPlayerOption` provide extra data for initializing players
 */
typedef NS_OPTIONS(NSUInteger, RBSDKPlayerOption) {
    /**
     Play as soon as the main video has loaded.
     */
    RBSDKPlayerOptionAutoPlay                   = 1 << 0,

    /**
     The player will show the fullscreen button and will have the ability
     to go fullscreen, enable this if you want autofullscreen on landscape.
     */
    RBSDKPlayerOptionAllowFullscreen            = 1 << 1,

    /**
     Go fullscreen automatically when rotating the device to a landscape position.
     */
    RBSDKPlayerOptionAutoFullscreenOnLandscape  = 1 << 2,
    
    /**
     Change the player Video Gravity.
     By default, the Video Gravity is Aspect Fill.
     RBSDKPlayerOptionVideoGravityAspectFit preserves the aspect ratio and fit within layer bounds.
     */
    RBSDKPlayerOptionVideoGravityAspectFit      = 1 << 3,

    /**
     Hide the stream caption on the player controls
     By default the captions are shown.
     */
    RBSDKPlayerOptionHideCaption                = 1 << 4,

    /**
     Playback mode as preview.
     This means the player will show the clips defined and by some action
     will switch to full video playback.
     */
    RBSDKPlayerOptionPlaybackPreview            = 1 << 5,

    /**
     Enables realtime features, as likes and chat
     */
    RBSDKPlayerOptionEnableRealtime             = 1 << 6,

    /**
     Allow to stop the player controller manually, this means player controller tear down
     will not be managed automatically at dissapear..
     The tearDown method must be called on the implementation.
     */
    RBSDKPlayerOptionManualTearDown             = 1 << 7
};

#endif /* RBSDKPlayerOptions_h */

//
//  RBSDKPlayerOptions.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 12/11/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

#ifndef RBSDKPlayerOptions_h
#define RBSDKPlayerOptions_h

typedef NS_ENUM(NSUInteger, RBSDKPlayerOption) {
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
};

#endif /* RBSDKPlayerOptions_h */

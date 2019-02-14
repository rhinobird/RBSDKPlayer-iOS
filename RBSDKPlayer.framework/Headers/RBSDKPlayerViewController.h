//
//  RBSDKPlayerViewController.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 4/17/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

@import UIKit;

#import <RBSDKPlayer/RBPlayerViewControllerDelegate.h>
#import "RBSDKPlayerOptions.h"

FOUNDATION_EXPORT NSNotificationName _Nonnull const RBSDKPlayerGoToFullScreenNotification;

@class PlayerViewController;

@interface RBSDKPlayerViewController : UIViewController

// Player's options
@property (nonatomic) RBSDKPlayerOption options;

// Real player view controller
@property (strong, nonatomic) PlayerViewController * _Nullable playerViewController;

// Object's delegate
@property (weak, nonatomic) id <RBPlayerViewControllerDelegate> _Nullable delegate;

/**
 Check RBPlayerViewControllerDelegate for details

 @params delegate Object's delegate
 */
- (void)setDelegate:(nullable id<RBPlayerViewControllerDelegate>)delegate;

/**
 Set playback to YES (rate = 1.0) for the entire reel
 */
- (void)play;

/**
 Set playback to NO (rate = 0.0) for the entire reel
 */
- (void)pause;

/**
 These methods are intended for internal use, don't use them or everything can
 break
 */
- (void)initializePlayerViewController;
- (void)attachPlayerViewController;

@end

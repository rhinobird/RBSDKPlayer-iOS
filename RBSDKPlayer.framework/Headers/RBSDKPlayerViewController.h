//
//  RBSDKPlayerViewController.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 4/17/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

@import UIKit;

#import "RBSDKPlayerViewControllerDelegate.h"
#import "RBSDKPlayerOptions.h"

FOUNDATION_EXPORT NSNotificationName _Nonnull const RBSDKPlayerGoToFullScreenNotification;

@class PlayerViewController;

/**
 `RBSDKPlayerViewController` is an abstract class, you're not suposed to initialize
 this object directly, use `RBSDKRhinobirdPlayerViewController` or
 `RBSDKBrightcovePlayerViewController` instead.
 */
@interface RBSDKPlayerViewController : UIViewController

/**
 Player's options
 */
@property (nonatomic) RBSDKPlayerOption options;

/**
 Player view controller internal logic
 */
@property (strong, nonatomic, nullable) PlayerViewController * playerViewController;

/**
 Player's delegate
 */
@property (weak, nonatomic, nullable) id <RBSDKPlayerViewControllerDelegate> delegate;

/**
 Check RBPlayerViewControllerDelegate for details

 @params delegate Object's delegate
 */
- (void)setDelegate:(nullable id<RBSDKPlayerViewControllerDelegate>)delegate;

/**
 Set playback to YES (rate = 1.0) for the entire reel
 */
- (void)play;

/**
 Set playback to NO (rate = 0.0) for the entire reel
 */
- (void)pause;

/**
 This methods is intended for internal use.
 */
- (void)initializePlayerViewController;

/**
 This methods is intended for internal use.
 */
- (void)attachPlayerViewController;

/**
 Returns the playing status of the player
 
 @return BOOL YES if is playing
 */
- (BOOL)isPlaying;

/**
 Returns the media info of the current media showing
 
 @return RBSDKPlayerMediaInfo Media info
 */
- (nullable RBSDKPlayerMediaInfo *)currentMediaInfo;

@end

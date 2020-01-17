//
//  RBSDKPlayerViewControllerDelegate.h
//  Rhinobird-Camera-IOS
//
//  Created by Benjamin Fantini on 6/15/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

#ifndef RBPlayerViewControllerDelegate_h
#define RBPlayerViewControllerDelegate_h

#import "RBSDKPlayerContentDirection.h"

NS_ASSUME_NONNULL_BEGIN

@class UIScrollView;
@class RBSDKPlayerMediaInfo;
@class RBSDKPlayerViewController;

/**
 Using the `RBSDKPlayerViewControllerDelegate` protocol, you can connect your
 controllers with the player and comunicate betweem them.
 */
@protocol RBSDKPlayerViewControllerDelegate <NSObject>

@optional

/**
 Notifies that the player controller has loaded.
 This doesn't means that the player is ready to play.

 @param succeed YES if the controller was able to load, NO if not i.e. the
 moment doesn't exist.
 @param error If succeed is NO, then will contain a error.
 */
- (void)playerControllerLoadDidSucceed:(BOOL)succeed withError:(nullable NSError *)error;

/**
 Notifies that the player controller is ready to Play.
 This means that the player first track (angle at position 0) is ready to play.
 */
- (void)playerControllerIsReadyToPlay;

/**
 Notifies the video on screen did switch to a new one.
 The player call this delegate method to inform the switch direction and the new media information.

 @param contentDirection Switch content direction.
 @param media The media information.
 */
- (void)playerControllerDidSwitchDirection:(RBSDKPlayerContentDirection)contentDirection media:(RBSDKPlayerMediaInfo *)media;

/**
 Notifies the player has changed the playing status.
 The player call this delegate method to inform the new playing status information.
 
 @param isPlaying Current player playing status
 */
- (void)playerControllerDidChangePlayingStatus:(BOOL)isPlaying;

/**
 Override the desired color on the player's controls and other UI

 @return desired color
 */
- (UIColor *)playerControllerColor;

/**
 Notifies the player current media watched time.
 The player call this delegate to report watched time of the current media showing.
 Watched Time is the total time that the media is playing and focused on view.
 
 @param media Media information
 @param watchedTime Total watched time
 */
- (void)playerControllerCurrentMedia:(RBSDKPlayerMediaInfo *)media watchedTime:(float)watchedTime;

/**
 Notifies the player did change the fullscreen status.
 The player call this delegate method to inform the fullscreen status information.
 */
- (void)playerControllerDidChangeFullscreenStatus;

/**
 Notifies the player will change the fullscreen status.
 The player call this delegate method to inform the fullscreen status information.
 */
- (void)playerControllerWillChangeFullscreenStatus;

/**
 Notifies the player will reach the end of the player content at direction.

 @discussion If this delegate is added, all the content loading (vertical or horizontal)
 won't be automatically added by the Rhinobird Api Itself. This means, this should be manually
 done trough the playerController methods at the SDK to add content in the end.

 @param contentDirection Content direction.
 @param completionHandler Call after updating the content.
 */
- (void)playerControllerWillReachEnd:(RBSDKPlayerContentDirection)contentDirection completionHandler:(void(^)(void))completionHandler;

/**
 Notifies the player is showing controls.
 The player call this delegate method to notify the controls visibility (show/hide).

 @param showingControls YES if is showing controls at the moment, No if the controls are hide.
 */
- (void)playerControllerShowingControls:(BOOL)showingControls;

@end

NS_ASSUME_NONNULL_END

#endif /* RBPlayerViewControllerDelegate_h */

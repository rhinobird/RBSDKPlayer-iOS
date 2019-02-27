//
//  RBSDKPlayerViewControllerDelegate.h
//  Rhinobird-Camera-IOS
//
//  Created by Benjamin Fantini on 6/15/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

#ifndef RBPlayerViewControllerDelegate_h
#define RBPlayerViewControllerDelegate_h

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
 Implement this method to override any vertical scroll in which the player
 is a subview.

 @return a vertical scrollview (or any subclass)
 */
- (nullable UIScrollView *)playerControllerMainScrollView;

/**
 Notifies the video on screen did switch to a new one.
 The player call this delegate method to inform the new media information.
 
 @param media The media information
 */
- (void)playerControllerDidSwitchToMedia:(nullable RBSDKPlayerMediaInfo *)media;

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
- (nullable UIColor *)playerControllerColor;

/**
 Notifies the player current media watched time.
 The player call this delegate to report watched time of the current media showing.
 Watched Time is the total time that the media is playing and focused on view.
 
 @param media Media information
 @param watchedTime Total watched time
 */
- (void)playerControllerCurrentMedia:(nullable RBSDKPlayerMediaInfo *)media watchedTime:(float)watchedTime;

@end

#endif /* RBPlayerViewControllerDelegate_h */

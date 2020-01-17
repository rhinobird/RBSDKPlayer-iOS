//
//  RBSDKPlayerViewController+Private.h
//  Rhinobird-Camera-IOS
//
//  Created by Bastian Suarez on 1/9/20.
//  Copyright © 2020 Rhinobird. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 `RBSDKPlayerViewController+Private` contains methods that shouldn't be
 accesed by the public RBSDK.
 This are all methods to use internally or next releases of the SDK.
 */
@interface RBSDKPlayerViewController (Private)

/**
 This methods is intended for internal use.
 */
- (void)initializePlayerViewController;

/**
 This methods is intended for internal use.
 */
- (void)attachPlayerViewController;

/**
 This method sets if the player should playback as preview (clips) or full length.
 Allows to change the playback from Preview to Full length, or change from Full length to Preview.

 @discussion To use this method it's neccesary that the player options (RBSDKPlayerOption)
 is configured as RBSDKPlayerOptionPlaybackPreview, otherwise this method won't work.

 @params playbackModePreview YES if playback should be Preview, NO if playback should be Full Length
 */
- (void)enablePlaybackPreviewMode:(BOOL)playbackModePreview;

/**
 Returns if the playback mode is enabled.

 @return BOOL YES if Preview Playback Mode is Enabled
 */
- (BOOL)isPreviewPlaybackModeEnabled;

/**
 This method sets if the player should show captions inside the player..

 @discussion This method works even If the player options (RBSDKPlayerOption)
 contains RBSDKPlayerOptionHideCaption.

 @params showCaptions YES if captions should show.
 */
- (void)showCaptions:(BOOL)showCaptions;

@end

NS_ASSUME_NONNULL_END

//
//  RBSDKYoutubeChannelPlayerViewController.h
//  RBSDKPlayer
//
//  Created by Bastian Suarez on 7/31/19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#import <RBSDKPlayer/RBSDKPlayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `RBSDKYoutubeChannelPlayerViewController` is the player controller for
 Youtube playlists from a Youtube channel.
 */
@interface RBSDKYoutubeChannelPlayerViewController : RBSDKPlayerViewController

/**
 Creates an instance of a Youtube Channel player controller from a Youtube channel id.
 This contains a collections provided by the playlists of the channel.
 
 @param youtubeChannelId Youtube channel id.
 @param options RBSDKPlayerOption.
 
 @return An instance of `RBSDKYoutubeChannelPlayerViewController`.
 */
- (instancetype)initWithYoutubeChannelId:(NSString *)youtubeChannelId
                                 options:(RBSDKPlayerOption)options;

@end

NS_ASSUME_NONNULL_END

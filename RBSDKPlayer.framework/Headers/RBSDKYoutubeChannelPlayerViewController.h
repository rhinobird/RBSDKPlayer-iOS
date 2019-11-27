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
 `RBSDKYoutubeChannelPlayerViewController` is the collection player controller for
 Youtube videos from a Youtube channel.
 */
@interface RBSDKYoutubeChannelPlayerViewController : RBSDKPlayerViewController

/**
 Initialize a collection player controller from a Youtube channel id
 
 @param youtubeChannelId Youtube channel id
 @param options RBSDKPlayerOption
 
 @return An instance of `RBSDKYoutubeChannelPlayerViewController`
 */
- (nonnull instancetype)initWithYoutubeChannelId:(nonnull NSString *)youtubeChannelId
                                          options:(RBSDKPlayerOption)options;

@end

NS_ASSUME_NONNULL_END

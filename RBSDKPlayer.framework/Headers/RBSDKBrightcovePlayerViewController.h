//
//  RBSDKBrightcovePlayerViewController.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 2/4/19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#import <RBSDKPlayer/RBSDKPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface RBSDKBrightcovePlayerViewController : RBSDKPlayerViewController

/**
 Initialize a player controller with an array of brightcove media ids

 @params mediaIdArray Brightcove media ids
 @params accountId Brightcove account id
 @params options RBSDKPlayerOption

 @return An instance of RBSDKPlayerViewController
 */
- (instancetype _Nonnull)initWithBrightcoveMediaIdArray:(nonnull NSArray<NSString *> *)mediaIdArray
                                              accountId:(nonnull NSString *)accountId
                                                options:(RBSDKPlayerOption)options;

/**
 Initialize a player controller with an array of brightcove media ids

 @params videoId Brightcove media id
 @params accountId Brightcove account id
 @params options RBSDKPlayerOption

 @return An instance of RBSDKPlayerViewController
 */
- (instancetype _Nonnull)initWithBrightcoveMediaId:(nonnull NSString *)mediaId
                                         accountId:(nonnull NSString *)accountId
                                           options:(RBSDKPlayerOption)options;

/**
 Initialize a player controller with an array of brightcove media ids

 @params playlistId Brightcove playlist id
 @params accountId Brightcove account id
 @params options RBSDKPlayerOption

 @return An instance of RBSDKPlayerViewController
 */
- (instancetype _Nonnull)initWithBrightcovePlaylistId:(nonnull NSString *)playlistId
                                            accountId:(nonnull NSString *)accountId
                                              options:(RBSDKPlayerOption)options;

@end

NS_ASSUME_NONNULL_END

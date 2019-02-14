//
//  RBSDKBrightcovePlayerViewController.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 2/4/19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#import "RBSDKPlayer.h"

NS_ASSUME_NONNULL_BEGIN

/**
 `RBSDKBrightcovePlayerViewController` is the Reel player controller for
 Brightcove videos, there're 3 ways to initialize the player.

 1. By using an array of valid media ids from the Brightcove video cloud, see
 `-[RBSDKBrightcovePlayerViewController initWithBrightcoveMediaIdArray:accountId:options:]`

 2. By using a media id from the Brightcove video cloud, Rhinobird API will
 retreive related videos and put them all together as a Reel see
 `-[RBSDKBrightcovePlayerViewController initWithBrightcoveMediaId:accountId:options:]`

 3. By using a playlist id from the Brightcove video cloud and wit that information
 create a Reel, see
 `-[RBSDKBrightcovePlayerViewController initWithBrightcovePlaylistId:accountId:options:]`

 */
@interface RBSDKBrightcovePlayerViewController : RBSDKPlayerViewController

/**
 Initialize a player controller with an array of brightcove media ids

 @param mediaIdArray Brightcove array of media ids
 @param accountId Brightcove account id
 @param options RBSDKPlayerOption

 @return An instance of `RBSDKPlayerViewController`
 */
- (nonnull instancetype)initWithBrightcoveMediaIdArray:(nonnull NSArray<NSString *> *)mediaIdArray
                                             accountId:(nonnull NSString *)accountId
                                               options:(RBSDKPlayerOption)options;

/**
 Initialize a player controller with an array of brightcove media ids

 @param mediaId Brightcove media id
 @param accountId Brightcove account id
 @param options RBSDKPlayerOption

 @return An instance of `RBSDKPlayerViewController`
 */
- (nonnull instancetype)initWithBrightcoveMediaId:(nonnull NSString *)mediaId
                                        accountId:(nonnull NSString *)accountId
                                          options:(RBSDKPlayerOption)options;

/**
 Initialize a player controller with an array of brightcove media ids

 @param playlistId Brightcove playlist id
 @param accountId Brightcove account id
 @param options RBSDKPlayerOption

 @return An instance of `RBSDKPlayerViewController`
 */
- (nonnull instancetype)initWithBrightcovePlaylistId:(nonnull NSString *)playlistId
                                           accountId:(nonnull NSString *)accountId
                                             options:(RBSDKPlayerOption)options;

@end

NS_ASSUME_NONNULL_END

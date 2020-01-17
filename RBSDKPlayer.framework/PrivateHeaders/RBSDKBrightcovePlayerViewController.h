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
 `RBSDKBrightcovePlayerViewController` is the player controller for Brightcove accounts.
 */
@interface RBSDKBrightcovePlayerViewController : RBSDKPlayerViewController

/**
 Creates an instance of a Brightcove player controller using a Brightcove single media id and a Brightcove account id.

 @param mediaId Brightcove media id.
 @param accountId Brightcove account id.
 @param options RBSDKPlayerOption configuration.

 @return An instance of `RBSDKBrightcovePlayerViewController`.
 */
- (nonnull instancetype)initWithBrightcoveMediaId:(nonnull NSString *)mediaId
                                        accountId:(nonnull NSString *)accountId
                                          options:(RBSDKPlayerOption)options;

/**
 Creates an instance of a Brightcove player controller using an array of Brightcove medias id and a Brightcove account id.

 @param mediaIdArray Brightcove array of media ids
 @param accountId Brightcove account id
 @param options RBSDKPlayerOption configuration.

 @return An instance of `RBSDKBrightcovePlayerViewController`.
 */
- (nonnull instancetype)initWithBrightcoveMediaIdArray:(nonnull NSArray<NSString *> *)mediaIdArray
                                             accountId:(nonnull NSString *)accountId
                                               options:(RBSDKPlayerOption)options;

/**
 Creates an instance of a Brightcove player controller using a Brightcove playlist id and a Brightcove account id.

 @param playlistId Brightcove playlist id.
 @param accountId Brightcove account id.
 @param options RBSDKPlayerOption configuration.

 @return An instance of `RBSDKBrightcovePlayerViewController`.
 */
- (nonnull instancetype)initWithBrightcovePlaylistId:(nonnull NSString *)playlistId
                                           accountId:(nonnull NSString *)accountId
                                             options:(RBSDKPlayerOption)options;

/**
 Inserts a Reel to the Brightcove player controller using a Brightcove media id and requesting related medias from it.

 @note There isn't a limit on the amount of reels that you can add.

 @param mediaId Brightcove media id.
 */
- (void)addMediaId:(nonnull NSString *)mediaId;

/**
 Inserts a Reel to the Brightcove player controller using an array of Brightcove media ids.

 @note There isn't a limit on the amount of reels that you can add.

 @param mediaIdArray Brightcove array of media ids.
 */
- (void)addMediaIdArray:(nonnull NSArray<NSString *> *)mediaIdArray;

/**
 Inserts a Reel to the Brightcove player controller using a Brightcove playlist id.

 @note There isn't a limit on the amount of reels that you can add.

 @param playlistId Brightcove playlist id.
 */
- (void)addPlaylistId:(nonnull NSString *)playlistId;

@end

NS_ASSUME_NONNULL_END

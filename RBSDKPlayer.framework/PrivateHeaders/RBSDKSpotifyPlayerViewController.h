//
//  RBSDKSpotifyPlayerViewController.h
//  RBSDKPlayer
//
//  Created by Bastian Suarez on 9/3/19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#import <RBSDKPlayer/RBSDKPlayer.h>

@class RBSpotifyPlaylist;

NS_ASSUME_NONNULL_BEGIN

/**
 `RBSDKSpotifyPlayerViewController` is the collection player controller for Spotify Playlists.
 */
@interface RBSDKSpotifyPlayerViewController : RBSDKPlayerViewController

/**
 Creates an instance of Spotifly player controller from a Spotify playlist array.
 
 @param playlistMutableArray Spotify Playlist Array.
 @param options RBSDKPlayerOption configuration.
 
 @return An instance of `RBSDKSpotifyPlayerViewController` with a collection.
 */
- (nonnull instancetype)initWithSpotifyPlaylist:(NSMutableArray<RBSpotifyPlaylist *> *)playlistMutableArray
                                        options:(RBSDKPlayerOption)options;

@end

NS_ASSUME_NONNULL_END

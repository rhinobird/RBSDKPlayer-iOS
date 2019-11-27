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
 `RBSDKSpotifyPlayerViewController` is the collection player controller for
 Youtube videos from a Spotify Playlist.
 */
@interface RBSDKSpotifyPlayerViewController : RBSDKPlayerViewController

/**
 Initialize a collection player controller from a Spotify playlist array
 
 @param playlistMutableArray Spotify Playlist Array
 @param options RBSDKPlayerOption
 
 @return An instance of `RBSDKSpotifyPlayerViewController`
 */
- (nonnull instancetype)initWithSpotifyPlaylist:(NSMutableArray<RBSpotifyPlaylist *> *)playlistMutableArray
                                        options:(RBSDKPlayerOption)options;

@end

NS_ASSUME_NONNULL_END

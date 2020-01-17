//
//  RBSDKRhinobirdPlayerViewController.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 2/4/19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RBSDKPlayerOptions.h"
#import "RBSDKPlayerViewController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 `RBSDKRhinobirdPlayerViewController` is the player controller for Rhinobird.
 */
@interface RBSDKRhinobirdPlayerViewController : RBSDKPlayerViewController

/**
 Creates an instance of a Rhinobird player controller with a Reel id provided by the dashboard.

 @param reelId Reel id.
 @param options RBSDKPlayerOption configuration.
 @param delegate Controller delegate.

 @return An instance of `RBSDKPlayerViewController` with a Reel.
 */
- (nonnull instancetype)initWithReelId:(nonnull NSString *)reelId
                               options:(RBSDKPlayerOption)options
                              delegate:(id)delegate;

/**
 Inserts a Reel (by it's id) to the player controller (vertically added).

 @note There isn't a limit on the amount of reels that you can add.

 @param reelId Reel id.
 */
- (void)addReelId:(nonnull NSString *)reelId;

/**
 Creates an instance of a Rhinobird player controller with a collection id provided by the dashboard.

 @param collectionId collection id.
 @param options RBSDKPlayerOption configuration.
 @param delegate Controller delegate.

 @return An instance of `RBSDKPlayerViewController` with a Collection.
 */
- (nonnull instancetype)initWithCollectionId:(nonnull NSString *)collectionId
                                     options:(RBSDKPlayerOption)options
                                    delegate:(id)delegate;

@end

NS_ASSUME_NONNULL_END

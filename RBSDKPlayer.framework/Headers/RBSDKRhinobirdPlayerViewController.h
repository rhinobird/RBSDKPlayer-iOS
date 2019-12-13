//
//  RBSDKRhinobirdPlayerViewController.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 2/4/19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#import "RBSDKPlayer.h"

@class RBSDKMoment;
@class RBSDKMomentStream;

NS_ASSUME_NONNULL_BEGIN

/**
 `RBSDKRhinobirdPlayerViewController` is the Reel player controller for
 Rhinobird videos.
 */
@interface RBSDKRhinobirdPlayerViewController : RBSDKPlayerViewController

/**
 Initialize a player controller with a specific moment-id

 @param momentId Moment's string id
 @param options RBSDKPlayerOption
 @param delegate Related controller delegate.

 @return An instance of `RBSDKPlayerViewController`
 */
- (nonnull instancetype)initWithMomentId:(nonnull NSString *)momentId
                                 options:(RBSDKPlayerOption)options
                                delegate:(id)delegate;

/**
 Initialize a player controller with a specific moment

 @param moment RBSDKMoment New Moment model.
 @param options RBSDKPlayerOption
 @param delegate Related controller delegate.

 @return An instance of `RBSDKPlayerViewController`
 */
- (nonnull instancetype)initWithNewMoment:(nonnull RBSDKMoment *)moment
                                  options:(RBSDKPlayerOption)options
                                  delegate:(id)delegate;

/**
 Add another moment to the player (enabling the vertical swiping), there isn't a
 limit on the amount of moments that you can add.

 @param momentId Moment's string id
 */
- (void)addMomentId:(nonnull NSString *)momentId;

/**
 Add another new moment to the player (enabling the vertical swiping).
 There isn't a limit on the amount of moments that you can add.

 @param newMoment New Moment.
 */
- (void)addNewMoment:(RBSDKMoment *)newMoment;

/**
 Add moment streams to the current moment.
 There isn't a limit on the amount of moment streans that you can add.

 @param momentStreamsArray Array of moment streams.
 */
- (void)addMomentStreamsArray:(NSArray<RBSDKMomentStream *> *)momentStreamsArray;

/**
 Initialize a player controller with a specific collection-id

 @param collectionId collection's string id
 @param options RBSDKPlayerOption
 @param delegate Related controller delegate. 

 @return An instance of `RBSDKPlayerViewController`
 */
- (nonnull instancetype)initWithCollectionId:(nonnull NSString *)collectionId
                                     options:(RBSDKPlayerOption)options
                                     delegate:(id)delegate;

@end

NS_ASSUME_NONNULL_END

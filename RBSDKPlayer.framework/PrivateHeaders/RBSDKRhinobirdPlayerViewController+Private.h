//
//  RBSDKRhinobirdPlayerViewController+Private.h
//  Rhinobird-Camera-IOS
//
//  Created by Bastian Suarez on 1/9/20.
//  Copyright © 2020 Rhinobird. All rights reserved.
//

#import "RBSDKRhinobirdPlayerViewController.h"

@class RBSDKMoment;
@class RBSDKMomentStream;

NS_ASSUME_NONNULL_BEGIN

/**
 `RBSDKRhinobirdPlayerViewController+Private` contains methods that shouldn't be
 accesed by the public RBSDK.
 This are all methods to use internally or next releases of the SDK.
 */
@interface RBSDKRhinobirdPlayerViewController (Private)

/**
 Inserts a Moment to the player controller (vertically added).

 @discussion There isn't a limit on the amount of reels that you can add.

 @param newMoment New Moment.
 */
- (void)addMoment:(RBSDKMoment *)moment;

/**
 Inserts a moment streams array to the current moment.

 @discussion There isn't a limit on the amount of reels that you can add.

 @param momentStreamsArray Array of moment streams.
 */
- (void)addMomentStreamsArray:(NSArray<RBSDKMomentStream *> *)momentStreamsArray;

@end

NS_ASSUME_NONNULL_END

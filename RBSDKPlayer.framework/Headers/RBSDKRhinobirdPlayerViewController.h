//
//  RBSDKRhinobirdPlayerViewController.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 2/4/19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#import "RBSDKPlayer.h"

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

 @return An instance of `RBSDKPlayerViewController`
 */
- (nonnull instancetype)initWithMomentId:(nonnull NSString *)momentId
                                 options:(RBSDKPlayerOption)options;

@end

NS_ASSUME_NONNULL_END

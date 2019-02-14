//
//  RBSDKRhinobirdPlayerViewController.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 2/4/19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#import <RBSDKPlayer/RBSDKPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface RBSDKRhinobirdPlayerViewController : RBSDKPlayerViewController

/**
 Initialize a player controller with a specific moment-id

 @params momentId Moment's string id
 @params options RBSDKPlayerOption

 @return An instance of RBSDKPlayerViewController
 */
- (instancetype _Nonnull)initWithMomentId:(nonnull NSString *)momentId
                                  options:(RBSDKPlayerOption)options;

@end

NS_ASSUME_NONNULL_END

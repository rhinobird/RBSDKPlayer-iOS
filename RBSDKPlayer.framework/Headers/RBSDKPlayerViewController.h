//
//  RBSDKPlayerViewController.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 4/17/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

@import UIKit;

#import <RBSDKPlayer/RBPlayerViewControllerDelegate.h>

FOUNDATION_EXPORT NSNotificationName _Nonnull const RBSDKPlayerGoToFullScreenNotification;

@interface RBSDKPlayerViewController : UIViewController

/**
 Initialize a player controller with a specific moment-id

 @params momentId Moment's string id
 @params autoplay Autoplay when the player is ready to play

 @return An instance of RBSDKPlayerViewController
 */
- (instancetype _Nonnull)initWithMomentId:(nonnull NSString *)momentId
                                 autoplay:(BOOL)autoplay;

/**
 Check RBPlayerViewControllerDelegate for details

 @params delegate Object's delegate
 */
- (void)setDelegate:(nullable id<RBPlayerViewControllerDelegate>)delegate;

@end

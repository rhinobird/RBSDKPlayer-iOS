//
//  RBSDKPlayerViewControllerDelegate.h
//  Rhinobird-Camera-IOS
//
//  Created by Benjamin Fantini on 6/15/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

#ifndef RBPlayerViewControllerDelegate_h
#define RBPlayerViewControllerDelegate_h

@class UIScrollView;
@class RBSDKPlayerViewController;

/**
 Using the `RBSDKPlayerViewControllerDelegate` protocol, you can connect your
 controllers with the player and comunicate betweem them.
 */
@protocol RBSDKPlayerViewControllerDelegate <NSObject>

@optional

/**
 Called after the player controller has loaded, this doesn't means that the
 player is ready to play.

 @param succeed YES if the controller was able to load, NO if not i.e. the
 moment doesn't exist.
 */
- (void)playerControllerLoadDidSucceed:(BOOL)succeed;

/**
 Implement this method to override any vertical scroll in which the player
 is a subview.

 @return a vertical scrollview (or any subclass)
 */
- (nullable UIScrollView *)playerControllerMainScrollView;

/**
 Everytime the video that's on screen changes, the player call this delegate
 method to inform the new caption.

 @param caption the new main view caption
 */
- (void)playerControllerCaptionChanged:(nullable NSString *)caption;

@end

#endif /* RBPlayerViewControllerDelegate_h */

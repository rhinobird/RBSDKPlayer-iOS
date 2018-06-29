//
//  ViewController.h
//  sdkdemo-objc
//
//  Created by Benjamin Fantini on 5/15/18.
//  Copyright © 2018 Rhinobird Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <RBSDKPlayer/RBPlayerViewControllerDelegate.h>

@class RBSDKPlayerViewController;

@interface ViewController : UIViewController <RBPlayerViewControllerDelegate>

@property (weak, nonatomic) IBOutlet UIView *playerContainerView;
@property (strong, nonatomic) RBSDKPlayerViewController *playerController;

@end


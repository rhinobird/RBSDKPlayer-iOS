//
//  ViewController.m
//  sdkdemo-objc
//
//  Created by Benjamin Fantini on 5/15/18.
//  Copyright © 2018 Rhinobird Inc. All rights reserved.
//

#import "ViewController.h"

#import <RBSDKPlayer/RBSDKPlayer.h>

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [RBSDK.sharedInstance loadAsynchronouslyWithCompletionHandler:^(BOOL success, NSError * _Nullable error) {
        if (success) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [self loadPlayer];
            });
        } else {
            NSLog(@"Error trying to configure the sdk: %@", error.localizedDescription);
        }
    }];
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];

    self.playerController.view.frame = self.playerContainerView.bounds;
}

- (void)loadPlayer {
    self.playerController = [[RBSDKPlayerViewController alloc] initWithMomentId:@"comeymemos-f19599"
                                                                       autoplay:YES];
    [self.playerController setDelegate:self];
    self.playerController.view.frame = self.playerContainerView.bounds;
    self.playerController.view.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
    [self.playerContainerView addSubview:self.playerController.view];
    [self addChildViewController:self.playerController];
}

# pragma mark - RBPlayerViewControllerDelegate

- (void)playerControllerLoadDidSucceed:(BOOL)succeed {
    if (succeed) {
        NSLog(@"Player load succeed");
    } else {
        NSLog(@"Player was not able to load");
    }
}

@end

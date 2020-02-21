//
//  ViewController.m
//  sdkdemo-objc
//
//  Created by Benjamin Fantini on 5/15/18.
//  Copyright © 2018 Rhinobird Inc. All rights reserved.
//

#import "ViewController.h"

#import <RBSDKPlayer/RBSDKPlayer.h>

@interface ViewController () <RBSDKPlayerViewControllerDelegate>

@property (strong, nonatomic) RBSDKPlayerViewController *playerController;

@end

@implementation ViewController

# pragma mark - View Controller lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];

    [RBSDKV2 loadAsynchronouslyWithCompletionHandler:^(BOOL success, NSError * error) {
        if (success) {
            dispatch_async(dispatch_get_main_queue(), ^{
                // Load a Rhinobird player controller with a Reel id
                [self loadPlayerWithReelId];
                // Load a Rhinobird player controller with a Collection id
                //[self loadPlayerWithCollectionId];
            });
        } else {
            NSLog(@"Error trying to configure the sdk: %@", error.localizedDescription);
        }
    }];
}

# pragma mark - Load methods

- (void)loadPlayerWithReelId {
    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);
    NSString *reelId = @"#SET A REEL ID PROVIDED BY THE RHINOBIRD DASHBOARD#";
    self.playerController = [[RBSDKRhinobirdPlayerViewController alloc] initWithReelId:reelId
                                                                               options:options
                                                                              delegate:self];
    [self attachPlayerController];
}

- (void)loadPlayerWithCollectionId {
    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);
    NSString *collectionId = @"#SET A COLLECTION ID PROVIDED BY THE RHINOBIRD DASHBOARD#";
    self.playerController = [[RBSDKRhinobirdPlayerViewController alloc] initWithCollectionId:collectionId
                                                                                     options:options
                                                                                    delegate:self];
    [self attachPlayerController];
}

- (void)attachPlayerController {
    [self addChildViewController:self.playerController];
    self.playerController.view.frame = self.playerContainerView.bounds;
    [self.playerContainerView addSubview:self.playerController.view];
}

# pragma mark - RBPlayerViewControllerDelegate

- (void)playerControllerLoadDidSucceed:(BOOL)succeed withError:(NSError *)error {
    if (succeed) {
        NSLog(@"Player load succeed");
    } else if (error) {
        NSLog(@"Player was not able to load, error: %@", error.localizedDescription);
    } else {
        NSLog(@"Player was not able to load");
    }
}

@end

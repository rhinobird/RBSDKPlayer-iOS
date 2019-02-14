//
//  ViewController.m
//  sdkdemo-objc
//
//  Created by Benjamin Fantini on 5/15/18.
//  Copyright © 2018 Rhinobird Inc. All rights reserved.
//

#import "ViewController.h"

#import <RBSDKPlayer/RBSDKPlayer.h>

@interface ViewController ()

@property (strong, nonatomic, nullable) NSString *bcAccountId;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.bcAccountId = @""; //TODO: Change this to your Brightcove account id

    [RBSDK.sharedInstance loadAsynchronouslyWithCompletionHandler:^(BOOL success, NSError * _Nullable error) {
        if (success) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [self loadPlayerWithMediaIdArray];
//                [self loadPlayerWithMediaId];
//                [self loadPlayerWithPlaylistId];
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

- (void)loadPlayerWithMediaIdArray {
    if (!self.bcAccountId) {
        NSLog(@"BC Account Id not provided");
        return;
    }

    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);

    NSArray<NSString *> *mediaIdArray = @[@"",
                                          @"",
                                          @""]; //TODO: Change this to a list of Brightcove media ids

    self.playerController = [[RBSDKBrightcovePlayerViewController alloc] initWithBrightcoveMediaIdArray:mediaIdArray
                                                                                              accountId:self.bcAccountId
                                                                                                options:options];

    [self.playerController setDelegate:self];

    [self attachPlayerController];
}

- (void)loadPlayerWithMediaId {
    if (!self.bcAccountId) {
        NSLog(@"BC Account Id not provided");
        return;
    }

    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);

    NSString *mediaId = @""; //TODO: Change this to a Brightcove media id

    self.playerController = [[RBSDKBrightcovePlayerViewController alloc] initWithBrightcoveMediaId:mediaId
                                                                                         accountId:self.bcAccountId
                                                                                           options:options];

    [self.playerController setDelegate:self];

    [self attachPlayerController];
}

- (void)loadPlayerWithPlaylistId {
    if (!self.bcAccountId) {
        NSLog(@"BC Account Id not provided");
        return;
    }

    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);

    NSString *playlistId = @""; //TODO: Change this to a Brightcove playlist id

    self.playerController = [[RBSDKBrightcovePlayerViewController alloc] initWithBrightcovePlaylistId:playlistId
                                                                                            accountId:self.bcAccountId
                                                                                              options:options];

    [self.playerController setDelegate:self];

    [self attachPlayerController];
}

- (void)attachPlayerController {
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

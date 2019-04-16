# RBSDKPlayer

[![Version](https://img.shields.io/badge/pod-v0.3.1-blue.svg)](https://cocoapods.org/pods/RBSDKPlayer)
[![Platform](https://img.shields.io/badge/platform-iOS-lightgrey.svg)](https://cocoapods.org/pods/RBSDKPlayer)

## Introduction
The rhinobird SDK supports content hosted by Rhinobird but it can also connect to other services like Mediastream and Brightcove.

We're working on making this sdk completely public, but in the mean, to make it work you'll need to get direct authorization from us, [send us an email](mailto:benjamin@rhinobird.tv) and we will send you the needed keys to make this work.

## Documentation
The documentation of this project can be found [here](https://rhinobird.github.io/RBSDKPlayer-iOS/)

## Changelog
The complete changelog of this project can be found [here](https://github.com/rhinobird/RBSDKPlayer-iOS/blob/master/Changelog.md)

## Install the SDK using CocoaPods
[CocoaPods](http://cocoapods.org) is a dependency manager for Swift and Objective-C Cocoa projects. See [Installation Guide](https://cocoapods.org/#install) for more information. You can install it with the following command:

```
$ gem install cocoapods
```

### Podfile
To integrate RBSDKPlayer with your iOS project using CocoaPods, just add the following in your `Podfile`:

```
source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/brightcove/BrightcoveSpecs.git'

platform :ios, '10.0'

target 'AppTargetName' do
  pod 'Brightcove-Player-Core', '~> 6.3'
  pod 'RBSDKPlayer', '~> 0.3'
end
```

Then run the installation command:

```
$ pod install
```

## Install the SDK using Carthage
_We're currently working on adding support for Carthage._

## Requirements

Minimum iOS Target: `10.0`

## Usage

RBSDKPlayer works for both Objective-C & Swift projects. There're multiple ways to add a controller as a subview, treat `RBSDKRhinobirdPlayerViewController` or `RBSDKBrightcovePlayerViewController` the same as any other controller. This is just an example.

An Objective-C demo project is included [here](https://github.com/rhinobird/RBSDKPlayer-iOS/tree/master/sdkdemo-objc)
A Swift demo project is included [here](https://github.com/rhinobird/RBSDKPlayer-iOS/tree/master/sdkdemo-swift)

**Initialize the SDK by setting the security & access key**

The first step is to configure the sdk for auth, use the provided keys, if you don't have them, refer to the [Introduction Section](#introduction) of this document.

```
[RBSDK.sharedInstance setSecretKey:<#Secret Key Here#>
                         accessKey:<#Access Key Here#>];
```
```
RBSDK.sharedInstance().setSecretKey(<#Secret Key Here#>,
                                    accessKey: <#Access Key Here#>)
```

**Create the properties**

```
@property (weak, nonatomic) IBOutlet UIView *playerContainerView;
@property (strong, nonatomic) RBSDKPlayerViewController *playerController;
```
```
@IBOutlet weak var playerContainerView: UIView?
var playerController: RBSDKPlayerViewController?
```
Connect them to the interface file if needed.

**Setting everything before loading the player**

Before creating a player, make sure that everything in the SDK core is loaded, by calling `loadAsynchronouslyWithCompletionHandler:` method and in the `completionHandler` set the player. Also, is important to load the player on the main thread.
```
// Objective-C
[RBSDK.sharedInstance loadAsynchronouslyWithCompletionHandler:^(BOOL success, NSError * _Nullable error) {
        if (success) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [self loadPlayer];
            });
        } else {
            NSLog(@"Error trying to configure the sdk: %@", error.localizedDescription);
        }
    }];
```
```
// Swift
RBSDK.sharedInstance().loadAsynchronously { success, error in
            if (success) {
                DispatchQueue.main.async {
                    self.loadPlayer()
                }

            } else if let error = error {
                print("Error trying to configure the sdk: \(error)")
            }
        }
```

**Loading the player with Rhinobird cloud data**
```
// Objective-C
- (void)loadPlayer {
    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);
    NSString *momentId = <#Moment Id#>;
    self.playerController = [[RBSDKRhinobirdPlayerViewController alloc] initWithMomentId:momentId
                                                                                 options:options];
    [self.playerController setDelegate:self];

    self.playerController.view.frame = self.playerContainerView.bounds;
    self.playerController.view.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
    [self.playerContainerView addSubview:self.playerController.view];
    [self addChildViewController:self.playerController];
}
```
**Loading the player with an array of Brightcove media ids**
```
// Objective-C
- (void)loadPlayer {
    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);

    NSArray<NSString *> *mediaIdArray = <#Media Ids Array#>;
    NSString *bcAccountId = <#BC Account Id#>;

    self.playerController = [[RBSDKBrightcovePlayerViewController alloc] initWithBrightcoveMediaIdArray:mediaIdArray
                                                                                              accountId:bcAccountId
                                                                                                options:options];

    [self.playerController setDelegate:self];

    self.playerController.view.frame = self.playerContainerView.bounds;
    self.playerController.view.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
    [self.playerContainerView addSubview:self.playerController.view];
    [self addChildViewController:self.playerController];
}
```

**Loading the player with a Brightcove media id, the player will create a Reel with content related to the media id**
```
// Objective-C
- (void)loadPlayer {
    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);

    NSString *mediaId = <#Media Id#>;
    NSString *bcAccountId = <#BC Account Id#>;

    self.playerController = [[RBSDKBrightcovePlayerViewController alloc] initWithBrightcoveMediaId:mediaId
                                                                                         accountId:bcAccountId
                                                                                           options:options];

    [self.playerController setDelegate:self];

    self.playerController.view.frame = self.playerContainerView.bounds;
    self.playerController.view.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
    [self.playerContainerView addSubview:self.playerController.view];
    [self addChildViewController:self.playerController];
}
```

**Loading the player with a Brightcove playlist id, the player will create a Reel with all the media contained by the playlist**
```
// Objective-C
- (void)loadPlayer {
    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);

    NSString *playlistId = <#PlaylistI Id#>;
    NSString *bcAccountId = <#BC Account Id#>;

    self.playerController = [[RBSDKBrightcovePlayerViewController alloc] initWithBrightcovePlaylistId:playlistId
                                                                                            accountId:bcAccountId
                                                                                              options:options];

    [self.playerController setDelegate:self];

    self.playerController.view.frame = self.playerContainerView.bounds;
    self.playerController.view.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
    [self.playerContainerView addSubview:self.playerController.view];
    [self addChildViewController:self.playerController];
}
```

**Resize the player view on any layout change**
```
// Objective-C
- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];

    // ...

    self.playerController.view.frame = self.playerContainerView.bounds;
}
```
```
// Swift
override func viewDidLayoutSubviews() {
    super.viewDidLayoutSubviews()

    // ...

    if let bounds = playerContainerView?.bounds {
        playerController?.view.frame = bounds
    }
}
```

**Delegate**

If you need feedback about the player, implement the `RBSDKPlayerViewControllerDelegate` methods on your class. Check [the documentation](https://rhinobird.github.io/RBSDKPlayer-iOS/Protocols/RBSDKPlayerViewControllerDelegate.html) for more details.

```
// Objective-C
# pragma mark - RBSDKPlayerViewControllerDelegate

- (void)playerControllerLoadDidSucceed:(BOOL)succeed withError:(NSError *)error {}
- (void)playerControllerIsReadyToPlay {}
- (UIScrollView *)playerControllerMainScrollView {}
- (void)playerControllerDidSwitchToMedia:(RBSDKPlayerMediaInfo *)media {}
- (void)playerControllerDidChangePlayingStatus:(BOOL)isPlaying {}
- (UIColor *)playerControllerColor {}
- (void)playerControllerCurrentMedia:(RBSDKPlayerMediaInfo *)media watchedTime:(float)watchedTime {}
```

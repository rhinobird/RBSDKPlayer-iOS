# RBSDKPlayer

[![Version](https://img.shields.io/badge/pod-v1.0.0-blue.svg)](https://cocoapods.org/pods/RBSDKPlayer)
[![Platform](https://img.shields.io/badge/platform-iOS-lightgrey.svg)](https://cocoapods.org/pods/RBSDKPlayer)

## Introduction
The rhinobird SDK supports content hosted by Rhinobird.

We're working on making this sdk completely public, but in the mean, to make it work you'll need to get direct authorization from us, [send us an email](mailto:bastian@rhinobird.tv) and we will send you the needed keys to make this work.

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
  pod 'RBSDKPlayer', '~> 1.0'
  pod 'YoutubePlayer-in-WKWebView', :git => 'https://github.com/rhinobird/YoutubePlayer-in-WKWebView.git'
  pod 'Brightcove-Player-Core/dynamic', '~> 6.4'
end
```

Then run the installation command:

```
$ pod install
```

## Requirements

Minimum iOS Target: `10.0`

## Usage

RBSDKPlayer works for both Objective-C & Swift projects. There're multiple ways to add a controller as a subview, treat `RBSDKRhinobirdPlayerViewController` the same as any other controller. This is just an example.

An Objective-C demo project is included [here](https://github.com/rhinobird/RBSDKPlayer-iOS/tree/master/sdkdemo-objc).
A Swift demo project is included [here](https://github.com/rhinobird/RBSDKPlayer-iOS/tree/master/sdkdemo-swift).

**Initialize the SDK by setting the security & access key**

The first step is to configure the sdk for auth, use the provided keys, if you don't have them, refer to the [Introduction Section](#introduction) of this document.

```objc
// Objective-C
[RBSDKV2 setKeysWithClientId:@""
                clientSecret:@""
                   accountId:@""];
```
```swift
// Swift
SDK.setKeys(clientId: "",
            clientSecret: "",
            accountId: "")
```

**Create the properties**

```objc
// Objective-C
@property (weak, nonatomic) IBOutlet UIView *playerContainerView;
@property (strong, nonatomic) RBSDKPlayerViewController *playerController;
```
```swift
// Swift
@IBOutlet weak var playerContainerView: UIView!
var playerController: RBSDKPlayerViewController?
```
Connect them to the interface file if needed.

**Setting everything before loading the player**

Before creating a player, make sure that everything in the SDK core is loaded, by calling `loadAsynchronouslyWithCompletionHandler:` method and in the `completionHandler` set the player. Also, is important to load the player on the main thread.
```objc
// Objective-C
[RBSDKV2 loadAsynchronouslyWithCompletionHandler:^(BOOL success, NSError * error) {
    if (success) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self loadPlayer];
        });
    } else if (error) {
        NSLog(@"Error trying to configure the sdk: %@", error.localizedDescription);
    }
}];
```
```swift
// Swift
SDK.loadAsynchronously { (success, error) in
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
```objc
// Objective-C
- (void)loadPlayer {
    RBSDKPlayerOption options = (RBSDKPlayerOptionAutoPlay);
    NSString *reelId = <#Reel Id#>;
    self.playerController = [[RBSDKRhinobirdPlayerViewController alloc] initWithReelId:reelId
                                                                               options:options
                                                                              delegate:self];

    [self addChildViewController:self.playerController];
    self.playerController.view.frame = self.playerContainerView.bounds;
    [self.playerContainerView addSubview:self.playerController.view];
}
```
```swift
// Swift
func loadPlayer() {
    let options: RBSDKPlayerOption = [.autoPlay]
    let reelId = <#Reel Id#>
    playerController = RBSDKRhinobirdPlayerViewController(reelId: reelId,
                                                          options: options,
                                                          delegate: self)

    guard let playerController = playerController else { return }
    addChild(playerController)
    playerController.view.frame = playerContainerView.bounds
    playerContainerView.addSubview(playerController.view)
}
```

**Delegate**

If you need feedback about the player, implement the `RBSDKPlayerViewControllerDelegate` methods on your class. Check [the documentation](https://rhinobird.github.io/RBSDKPlayer-iOS/Protocols/RBSDKPlayerViewControllerDelegate.html) for more details.

```objc
// Objective-C
# pragma mark - RBSDKPlayerViewControllerDelegate

- (void)playerControllerLoadDidSucceed:(BOOL)succeed withError:(NSError *)error {}
- (void)playerControllerIsReadyToPlay {}
- (void)playerControllerDidSwitchDirection:(RBSDKPlayerContentDirection)contentDirection media:(RBSDKPlayerMediaInfo *)media {}
- (void)playerControllerDidChangePlayingStatus:(BOOL)isPlaying {}
- (UIColor *)playerControllerColor {}
- (void)playerControllerCurrentMedia:(RBSDKPlayerMediaInfo *)media watchedTime:(float)watchedTime {}
- (void)playerControllerDidChangeFullscreenStatus {}
- (void)playerControllerWillChangeFullscreenStatus {}
- (void)playerControllerWillReachEnd:(RBSDKPlayerContentDirection)contentDirection completionHandler:(void(^)(void))completionHandler {}
- (void)playerControllerShowingControls:(BOOL)showingControls {}
```
```swift
// Swift
// MARK: RBSDKPlayerViewControllerDelegate

func playerControllerLoadDidSucceed(_ succeed: Bool, withError error: Error?) {}
func playerControllerIsReadyToPlay() {}
func playerControllerDidSwitch(_ contentDirection: RBSDKPlayerContentDirection, media: RBSDKPlayerMediaInfo) {}
func playerControllerDidChangePlayingStatus(_ isPlaying: Bool) {}
func playerControllerColor() -> UIColor {}
func playerControllerCurrentMedia(_ media: RBSDKPlayerMediaInfo, watchedTime: Float) {}
func playerControllerDidChangeFullscreenStatus() {}
func playerControllerWillChangeFullscreenStatus() {}
func playerControllerWillReachEnd(_ contentDirection: RBSDKPlayerContentDirection, completionHandler: @escaping () -> Void) {}
func playerControllerShowingControls(_ showingControls: Bool) {}
```

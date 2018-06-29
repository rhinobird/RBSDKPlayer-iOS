# RBSDKPlayer

[![Version](https://img.shields.io/badge/pod-v0.0.1-blue.svg)](https://cocoapods.org/pods/RBSDKPlayer)
[![Platform](https://img.shields.io/badge/platform-iOS-lightgrey.svg)](https://cocoapods.org/pods/RBSDKPlayer)

## Installation with CocoaPods
[CocoaPods](http://cocoapods.org) is a dependency manager for Swift and Objective-C Cocoa projects. See [Installation Guide](https://cocoapods.org/#install) for more information. You can install it with the following command:

```
$ gem install cocoapods
```

### Podfile
To integrate RBSDKPlayer with your iOS project using CocoaPods, just add the following in your `Podfile`:

```
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '10.0'

target 'AppTargetName' do
  pod 'RBSDKPlayer', '~> 0.1'
end
```

Then run the installation command:

```
$ pod install
```

## Requirements

Minimum iOS Target: `10.0`

## Usage

RBSDKPlayer works for both Objective-C & Swift projects. There're multiple ways to add a controller as a subview, treat `RBSDKPlayerViewController` the same as any other controller. This is just an example.

### Objective-C

A demo project is included [here](https://github.com/rhinobird/RBSDKPlayer/tree/master/sdkdemo-objc)

**Create the properties (ViewController.h)**

```
@property (weak, nonatomic) IBOutlet UIView *playerContainerView;
@property (strong, nonatomic) RBSDKPlayerViewController *playerController;
```

**Create the controller, add it as a subview**
```
self.playerController = [[RBSDKPlayerViewController alloc] initWithMomentId:<moment_id>
                                                                   autoplay:YES];

self.playerController.view.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
[self.playerContainerView addSubview:self.playerController.view];
[self addChildViewController:self.playerController];
```

**Resize the player view on any layout change**
```
- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];

    // ...

    self.playerController.view.frame = self.playerContainerView.bounds;
}
```

### Swift

A demo project is included [here](https://github.com/rhinobird/RBSDKPlayer/tree/master/sdkdemo-swift)

**Create the properties**

```
@IBOutlet weak var playerContainerView: UIView?
var playerController: RBSDKPlayerViewController?
```

**Create the controller, add it as a subview**
```
playerController = RBSDKPlayerViewController(momentId: <moment_id>,
                                             autoplay: true)

if let playerController = playerController,
    let playerContainerView = playerContainerView {

    playerController.view.autoresizingMask = [.flexibleWidth,
                                              .flexibleHeight]
    playerContainerView.addSubview(playerController.view)
    addChildViewController(playerController)
}
```

**Resize the player view on any layout change**
```
override func viewDidLayoutSubviews() {
    super.viewDidLayoutSubviews()

    // ...

    if let bounds = playerContainerView?.bounds {
        playerController?.view.frame = bounds
    }
}
```

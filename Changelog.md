# RBSDKPlayer - Changelog

This is the changelog for Rhinobird's iOS SDK, the complete project can be found [here](https://github.com/rhinobird/RBSDKPlayer-iOS/).

## v1.0.2 (2020/02/28)

### Enhancements

1. Add initialization in RBSDKRhinobirdPlayerViewController to start a reel from a specific stream at position.

## v1.0.1 (2020/02/26)

### Enhancements

1. Add more information to RBSDKMediaInfo.
2. Add option to hide Reel and Stream index.

## v1.0.0 (2020/02/21)

### Enhancements

1. Improve Player performance.
2. Update Rhinobird API.
3. Update Set keys and Load methods.

## v0.6.0 (2020/01/17)

### Enhancements

1. Improve Player performance.
2. Add delegate to notify when controls are showing on Player controller.
3. Initialize methods now are only available trough RBSDKRhinobirdPlayerViewController.
4. Add a new Configuration option (RBSDKPlayerOption) to tear down controller manually.
5. Add a new method on Player controller to tear down manually.

### Bugs

1. Fix playerControllerColor delegate method.

## v0.5.0 (2019/12/13)

### Enhancements

1. Improve Player performance.
2. Add more delegate methods to notify Player information.
3. Add methods to init Player with a new Moment type.
4. Add methods to append new Moment Streams to a current Moment.
5. Add Preview funcionality.
6. Add Vertical and Horizontal current position of the Player.

## v0.4.1 (2019/11/27)

### Enhancements

1. Improve player performance.
2. Add accountId parameter to the sdk as config key.

## v0.3.1 (2019/04/16)

### Bugs

1. Fix a dependency issue.

## v0.3.0 (2019/04/16)

### Enhancements

1. Add vertical swiping support.
2. Add infinite horizontal support.
3. The player is capable of automatically loading more videos to support the infinite functionality.
4. Add support to flag inappropriate content.
5. Add support for synchronized videos.
6. Improve the performance by using background threads for low priority tasks.

### Bugs

1. Fix some memory leaks.

## v0.2.1 (2019/03/20)

### Enhancements

1. Add a `NSDictionary` on the `RBSDKPlayerMediaInfo` class called `otherParameters` with specific information about the used platform. If there's no extra data, this dictionary will be `nil`.
2. Refine compatibility with devices with a notch (iPhoneX family).
3. Add partial implementation for Ads. (Still needs more work).

### Bugs

1. Fix UI glitches when going to fullscreen or rotating the device.
2. Fix some issues when trying to use the seekbar on the player, there were some cases in which the player wasn't able to detect the touch gesture.

## v0.2.0 (2019/02/27)

### Enhancements

1. Add the ability to play videos on AspectFit (the default is AspectFill).
2. Add the ability to define the player color, it will change the way the loading layers and the controls look.
3. Improve feedback from the player to it delegate controller.
4. Modify `-[RBSDKPlayerViewControllerDelegate playerControllerLoadDidSucceed:]` to `-[RBSDKPlayerViewControllerDelegate playerControllerLoadDidSucceed:withError:]`, this way if the player fails to load there’s a related error to handle it.

### Bugs

1. Fix a `Visual Index` resizing bug, now it resizes as it should when the user switch toggle the fullscreen.
2. Fix RBSDKPlayerOption bug, now is `NS_OPTIONS` instead of `NS_ENUM` (edited).

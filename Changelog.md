# RBSDKPlayer - Changelog

This is the changelog for Rhinobird's iOS SDK, the complete project can be found [here](https://github.com/rhinobird/RBSDKPlayer-iOS/)

## v0.2.2 (not yet published)

### Enhancements

1. Add `Brightcove-Player-Core` as a pod dependency. The project using the `RBSDKPlayer` pod needs to add the source of this dependency on the `Podfile`.

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

1. Add the ability to play videos on AspectFit (the default is AspectFill)
2. Add the ability to define the player color, it will change the way the loading layers and the controls look.
3. Improve feedback from the player to it delegate controller
4. Modify `-[RBSDKPlayerViewControllerDelegate playerControllerLoadDidSucceed:]` to `-[RBSDKPlayerViewControllerDelegate playerControllerLoadDidSucceed:withError:]`, this way if the player fails to load there’s a related error to handle it.

### Bugs

1. Fix a `Visual Index` resizing bug, now it resizes as it should when the user switch toggle the fullscreen
2. Fix RBSDKPlayerOption bug, now is `NS_OPTIONS` instead of `NS_ENUM` (edited)
//
//  RBSDKPlayerContentDirection.h
//  RBSDKPlayer
//
//  Created by Bastian Suarez on 12/9/19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#ifndef RBSDKPlayerContentDirection_h
#define RBSDKPlayerContentDirection_h

/**
 `RBSDKPlayerContentDirection` indicates the direction of the content
 */
typedef NS_ENUM(NSUInteger, RBSDKPlayerContentDirection) {
    /**
     This indicates there is none direction asigned.
     This never should be set.
     */
    RBSDKPlayerContentDirectionNone,

    /**
     This indicates the content movement direction
     or the content load direction is horizontal
     */
    RBSDKPlayerContentDirectionHorizontal,

    /**
     This indicates the content movement direction
     or the content load direction is vertical
     */
    RBSDKPlayerContentDirectionVertical
};

#endif /* RBSDKPlayerContentDirection_h */

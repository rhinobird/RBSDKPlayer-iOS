//
//  RBSDKPlayerMediaInfo.h
//  RBSDKPlayer
//
//  Created by Bastian Suarez on 25-02-19.
//  Copyright © 2019 Rhinobird. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Class to retrieve information about a media
 */
@interface RBSDKPlayerMediaInfo : NSObject

# pragma mark - properties

/**
 Stream id assigned in the Rhinobird dashboard.
 */
@property (weak, nonatomic, nullable, readonly) NSString *streamId;

/**
 Reel id assigned in the Rhinobird dashboard.
 */
@property (weak, nonatomic, nullable, readonly) NSString *reelId;

/**
 Caption (title) of the stream.
 */
@property (weak, nonatomic, nullable, readonly) NSString *caption;

/**
 Dictionary with other useful information. e.g. referenceId.
 */
@property (weak, nonatomic, nullable, readonly) NSDictionary *otherParameters;

@end

NS_ASSUME_NONNULL_END

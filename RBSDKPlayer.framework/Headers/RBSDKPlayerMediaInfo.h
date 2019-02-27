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
 Media id (related to the platform you're using
 */
@property (weak, nonatomic, nullable) NSString *mediaId;

/**
 Caption (title) of the media
 */
@property (weak, nonatomic, nullable) NSString *caption;

/**
 Angle position index
 */
@property (nonatomic) NSInteger anglePosition;

# pragma mark - Init

/**
 Initialize a `RBSDKPlayerMediaInfo` instance with its data

 @param mediaId The media id
 @param caption The media's caption (title)
 @param anglePosition The media's angle position (on the horizontal scrolling)

 @return An instance of `RBSDKPlayerMediaInfo`
 */
- (instancetype)initWithMediaId:(NSString *)mediaId caption:(NSString *)caption anglePosition:(NSInteger)anglePosition;

@end

NS_ASSUME_NONNULL_END

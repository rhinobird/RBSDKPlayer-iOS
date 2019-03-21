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

/**
 Dictionary with other useful information.
 e.g. referenceId
 */
@property (weak, nonatomic, nullable) NSDictionary *otherParameters;

# pragma mark - Init

/**
 Initialize a `RBSDKPlayerMediaInfo` instance with its data

 @param mediaId The media id
 @param caption The media's caption (title)
 @param anglePosition The media's angle position (on the horizontal scrolling)
 @param otherParameters Other useful info e.g. referenceId

 @return An instance of `RBSDKPlayerMediaInfo`
 */
- (instancetype)initWithMediaId:(nullable NSString *)mediaId caption:(nullable NSString *)caption anglePosition:(NSInteger)anglePosition otherParameters:(nullable NSDictionary *)otherParameters;

@end

NS_ASSUME_NONNULL_END

//
//  RBSDKPlayerMediaInfo+Private.h
//  RBSDKPlayer
//
//  Created by Bastian Suarez on 1/13/20.
//  Copyright © 2020 Rhinobird. All rights reserved.
//

#import "RBSDKPlayerMediaInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 `RBSDKPlayerMediaInfo+Private` contains methods that shouldn't be
 accesed by the public RBSDK.
 This are all methods to use internally or next releases of the SDK.
 */
@interface RBSDKPlayerMediaInfo (Private)

# pragma mark - Properties

/**
 Username of the video owner.
 */
@property (weak, nonatomic, nullable, readonly) NSString *username;

/**
 User profile image url of the video owner.
 */
@property (weak, nonatomic, nullable, readonly) NSURL *userImageUrl;

/**
 Total seconds duration of the media.
 */
@property (nonatomic, readonly) float duration;

# pragma mark - Init

/**
 Initialize a `RBSDKPlayerMediaInfo` instance with its data

 @param mediaId The media id.
 @param caption The media's caption (title).
 @param username The media's username owner.
 @param userImageUrl The media's user image url.
 @param duration The media's duration (seconds).
 @param otherParameters Other useful info e.g. referenceId.

 @return An instance of `RBSDKPlayerMediaInfo`
 */
- (instancetype)initWithMediaId:(nullable NSString *)mediaId
                        caption:(nullable NSString *)caption
                       username:(nullable NSString *)username
                   userImageUrl:(nullable NSURL *)userImageUrl
                       duration:(float)duration
                otherParameters:(nullable NSDictionary *)otherParameters;

@end


NS_ASSUME_NONNULL_END

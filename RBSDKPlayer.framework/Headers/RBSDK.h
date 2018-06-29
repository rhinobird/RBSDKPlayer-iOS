//
//  RBSDK.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 6/21/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

#import <Foundation/Foundation.h>

// Loading completion handler
typedef void(^RBLoadHandlerBlock)(BOOL success, NSError * _Nullable error);

@interface RBSDK : NSObject

// YES when is safe to create a player and all is already loaded
@property (nonatomic, getter=isReady) BOOL ready;

// YES when the configurator is still loading stuff
@property (nonatomic, getter=isLoading) BOOL loading;

/**
 Returns a RBSDK configuration singleton

 @return A RBSDK configuration singleton
 */
+ (instancetype)sharedInstance;

/**
 Set the secrect and access key, this is needed for creating RBSDKPlayerViewController

 @params secretKey SDK's secret key
 @params accessKey SDK's access key
 */
- (void)setSecretKey:(nonnull NSString *)secretKey
           accessKey:(nonnull NSString *)accessKey;

/**
 Use this method if you want to initialize a player a soon as posible, completion
 handler will be called after the configuration ends, is important to check
 if the process ended successfully or not.

 @params completionHandler The completion handler will say if the configuration
 was successfull or not, and if is not, check the NSError information.
 */
- (void)loadAsynchronouslyWithCompletionHandler:(RBLoadHandlerBlock)completionHandler;

@end

//
//  RBSDK.h
//  RBSDKPlayer
//
//  Created by Benjamin Fantini on 6/21/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Loading completion handler
 */
typedef void(^RBLoadHandlerBlock)(BOOL success, NSError * _Nullable error);


/**
 `RBSDK` object provide a singleton to load easily player controllers, the first
 step is to set the secret and access keys, then use the
 `-[RBSDK loadAsynchronouslyWithCompletionHandler:]` method to load everything.
 */
@interface RBSDK : NSObject

/**
 Returns a `RBSDK` configuration singleton, only use the singleton or unexpected
 things will happen.

 @return A `RBSDK` configuration singleton
 */
+ (nonnull instancetype)sharedInstance;

/**
 Set the secret and access key, this is needed for creating a player controller

 @param secretKey SDK's secret key
 @param accessKey SDK's access key
 */
- (void)setSecretKey:(nonnull NSString *)secretKey
           accessKey:(nonnull NSString *)accessKey;

/**
 Set the secret, access and token key, this is needed for creating a player
 controller

 @param secretKey SDK's secret key
 @param accessKey SDK's access key
 @param tokenKey SDK's token key
 */
- (void)setSecretKey:(nonnull NSString *)secretKey
           accessKey:(nonnull NSString *)accessKey
            tokenKey:(nonnull NSString *)tokenKey;

/**
 Use this method if you want to initialize a player a soon as posible, completion
 handler will be called after the configuration ends, is important to check
 if the process ended successfully or not.

 @param completionHandler The completion handler will say if the configuration
 was successfull or not, and if is not, check the NSError information.
 */
- (void)loadAsynchronouslyWithCompletionHandler:(nullable RBLoadHandlerBlock)completionHandler;

/**
 Check if the sdk is ready to load players

 @return YES when is safe to create a player and all is already loaded
 */
- (BOOL)isReady;

/**
 Check if the sdk is still loading

 @return YES when the configurator is still loading stuff
 */
- (BOOL)isLoading;

/**
 Set a session identifier. This is needed to identify the current session and
 a user behaviour anonymously.
 
 @param sessionIdentifier identifier for the current session.
 */
- (void)setSessionIdentifier:(nonnull NSString *)sessionIdentifier;

@end

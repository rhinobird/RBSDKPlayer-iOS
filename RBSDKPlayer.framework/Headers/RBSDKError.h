//
//  RBSDKError.h
//  Rhinobird-Camera-IOS
//
//  Created by Benjamin Fantini on 6/27/18.
//  Copyright © 2018 Rhinobird. All rights reserved.
//

#ifndef RBSDKError_h
#define RBSDKError_h

/**
 Refers to all the internal errors uses all the defined error in the below enum
 */
FOUNDATION_EXPORT NSString * _Nonnull const RBSDKErrorDomainInternal;

/**
 Refers to all the http errors uses all the conventional http errors
 */
FOUNDATION_EXPORT NSString * _Nonnull const RBSDKErrorDomainHttp;

/**
 `RBSDKErrorDomainInternal` is the error domain for the sdk errors
 */
NS_ERROR_ENUM(RBSDKErrorDomainInternal) {
    /**
     Unknown error
     */
    RBSDKErrorUnknown              = -1,

    /**
     The credential is invalid or has expired
     */
    RBSDKErrorInvalidCredentials   = 101,

    /**
     The are no credentials
     */
    RBSDKErrorMissingCredentials   = 102,

    /**
     If the configuration key doesn't exists. (For internal use)
     */
    RBSDKErrorMissingKey           = 201,

    /**
     If the configuration key has no data. (For internal use)
     */
    RBSDKErrorNoDataAtAll          = 202,
};

#endif /* RBSDKError_h */

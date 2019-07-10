//
//  TDProperties.h
//  Tapdaq
//
//  Created by Tapdaq <support@tapdaq.com>
//  Copyright (c) 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TDAdTypeEnum.h"
#import "TDTestDevices.h"
#import "TDLogLevel.h"


typedef NS_ENUM(NSInteger, TDSubjectToGDPR) {
    TDSubjectToGDPRNo = 0,
    TDSubjectToGDPRYes = 1,
    TDSubjectToGDPRUnknown = 2
};


@interface TDProperties : NSObject

/**
 * Enables/Disables logging of the adapters.
 */
@property (nonatomic) BOOL isDebugEnabled;

/**
 * Enables/Disables ad auto reloading.
 */
@property (nonatomic) BOOL autoReloadAds;

/**
 Note: For plugin developers only.
 */
@property (nonatomic) NSString *pluginVersion;

/**
 * Set how fine-grained information is provided in Tapdaq's logs.
 * Default level is TDLogLevelInfo
 */
@property (assign, nonatomic) TDLogLevel logLevel;

/**
 * Property identifing the user.
 */
@property (strong, nonatomic) NSString *userId;

/**
 * If the to YES userId property will be forwarded to ad networks.
 */
@property (assign, nonatomic) BOOL forwardUserId;

/**
 * User is subject to EU GDPR laws.
 */
@property (assign, nonatomic) TDSubjectToGDPR userSubjectToGDPR;

/**
 * Property that indicates whether a user has given consent to use his private data.
 */
@property (assign, nonatomic) BOOL isConsentGiven;

/**
 * User is of age 16 or below.
 */
@property (assign, nonatomic) BOOL isAgeRestrictedUser;

/**
 * AdMob Ad content filtering options.
 */
@property (strong, nonatomic) NSString *adMobContentRating;

/**
 * An new instance with default values;
 */
+ (instancetype)defaultProperties;

- (BOOL)registerTestDevices:(TDTestDevices *)testDevices;

- (NSArray *)registeredTestDevices;

@end

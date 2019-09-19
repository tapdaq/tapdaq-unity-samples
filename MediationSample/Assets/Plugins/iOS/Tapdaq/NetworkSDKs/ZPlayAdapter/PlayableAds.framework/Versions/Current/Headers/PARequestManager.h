//
//  PARequestManager.h
//  Pods
//
//  Created by d on 19/7/2017.
//
//

#import "PAResponseModel.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

static NSString *const ZPLAYAdsRequestTypeUser = @"user";
static NSString *const ZPLAYAdsRequestTypeSdk = @"sdk";
static NSString *const ZPLAYAdsRequestTypeAutoRetry = @"auto_retry";

@interface PARequestManager : NSObject

+ (instancetype)sharedManager;

- (void)requestAdWithAdUnitID:(NSString *)adUnitID
                        appID:(NSString *)appID
                  requestType:(NSString *)type
                    channelId:(NSString *)channelId
                      success:(void (^)(PAResponseModel *ad))success
                      failure:(void (^)(NSError *error))failure;

- (void)requestTrackers:(NSArray<NSString *> *)trackers
             parameters:(nullable NSDictionary *)parameters
       withReplacements:(NSDictionary<NSString *, NSString *> *_Nullable)replacements;

- (void)sendStartDownloadTrackerUrl:(NSString *)trackerUrl;
- (void)sendEndedDownloadTrackerUrl:(NSString *)trackerUrl stateFlag:(NSString *)state;

@end

NS_ASSUME_NONNULL_END

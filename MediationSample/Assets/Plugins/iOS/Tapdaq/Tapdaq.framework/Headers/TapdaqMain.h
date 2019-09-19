//
//  Tapdaq.h
//  Tapdaq
//
//  Created by Tapdaq <support@tapdaq.com>
//  Copyright (c) 2016 Tapdaq. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <Tapdaq/TDOrientation.h>

#import <Tapdaq/TDAdTypeEnum.h>
#import <Tapdaq/TDMNetworkEnum.h>
#import <Tapdaq/TDMBannerSizeEnum.h>
#import <Tapdaq/TDReward.h>
#import <Tapdaq/TDMediatedNativeAd.h>
#import <Tapdaq/TDProperties.h>
#import <Tapdaq/TapdaqDelegate.h>
@protocol TDAdRequestDelegate;

@class TDAdvert;
@class TDInterstitialAdvert;
@class TDPlacement;
@class TDMoreAppsConfig;
@class TDError;

@interface Tapdaq : NSObject

/**
 * Current version of the SDK
 */
@property (readonly, nonatomic) NSString *sdkVersion;

@property (nonatomic, weak) id <TapdaqDelegate> delegate;

@property (nonatomic) NSString *userId;
@property (nonatomic) BOOL forwardUserId;
@property (nonatomic) TDSubjectToGDPR userSubjectToGDPR;
@property (nonatomic) BOOL isConsentGiven;
@property (nonatomic) BOOL isAgeRestrictedUser;
@property (nonatomic) NSString *adMobContentRating;

@property (readonly, nonatomic) TDProperties *properties;

#pragma mark Singleton
/**
 The singleton Tapdaq object, use this for all method calls
 
 @return The Tapdaq singleton.
 */
+ (instancetype)sharedSession;

- (void)trackPurchaseForProductName:(NSString *)productName
                              price:(double)price
                        priceLocale:(NSString *)priceLocale
                           currency:(NSString *)currency
                      transactionId:(NSString *)transactionId
                          productId:(NSString *)productId;

#pragma mark Initializing Tapdaq

/**
 A setter for the Application ID of your app, and the Client Key associated with your Tapdaq account. 
 You can obtain these details when you sign up and add your app to https://tapdaq.com
 You must use this in the application:didFinishLaunchingWithOptions method.
 
 @param applicationId The application ID tied to your app.
 @param clientKey The client key tied to your app.
 @param properties The properties object that overrides the Tapdaq defaults. See TDProperties for info on all configuration options.
 */
- (void)setApplicationId:(NSString *)applicationId
               clientKey:(NSString *)clientKey
              properties:(TDProperties *)properties;

/**
 * Get current SDK initialisation status
 *
 * @return YES if the SDK is initialised. NO otherwise.
 */
- (BOOL)isInitialised;

#pragma mark Reward
- (NSString *)rewardIdForPlacementTag:(NSString *)placementTag;

#pragma mark Debugger
- (void)presentDebugViewController;

#pragma mark Banner

- (void)loadBannerWithSize:(TDMBannerSize)size completion:(void(^)(UIView *))completion;

#pragma mark Interstitial
- (void)loadInterstitialForPlacementTag:(NSString *)placementTag delegate:(id<TDAdRequestDelegate>)delegate;

- (void)loadInterstitialForPlacementTag:(NSString *)placementTag;

- (BOOL)isInterstitialReadyForPlacementTag:(NSString *)placementTag;

- (void)showInterstitialForPlacementTag:(NSString *)placementTag;


#pragma mark Video
- (void)loadVideoForPlacementTag:(NSString *)placementTag delegate:(id<TDAdRequestDelegate>)delegate;

- (void)loadVideoForPlacementTag:(NSString *)placementTag;

- (BOOL)isVideoReadyForPlacementTag:(NSString *)placementTag;

- (void)showVideoForPlacementTag:(NSString *)placementTag;


#pragma mark Rewarded Video
- (void)loadRewardedVideoForPlacementTag:(NSString *)placementTag delegate:(id<TDAdRequestDelegate>)delegate;

- (void)loadRewardedVideoForPlacementTag:(NSString *)placementTag;

- (BOOL)isRewardedVideoReadyForPlacementTag:(NSString *)placementTag;

- (void)showRewardedVideoForPlacementTag:(NSString *)placementTag;

- (void)showRewardedVideoForPlacementTag:(NSString *)placementTag hashedUserId:(NSString *)hashedUserId __attribute__((deprecated("showRewardedVideoForPlacementTag:hashedUserId: has been deprecated. Please use showRewardedVideoForPlacementTag: instead. To set user ID plese use userId property of TDProperties class or Tapdaq interface. This method will be removed in future releases. Deprecated on 09/07/2019 version 7.2.0.")));


#pragma mark Mediated native ads

- (void)loadNativeAdInViewController:(UIViewController *)viewController
                        placementTag:(NSString *)placementTag
                             options:(TDMediatedNativeAdOptions)options
                            delegate:(id<TDAdRequestDelegate>)delegate;

#pragma mark Misc

/**
 * This method is only used for plugins such as Unity which do not automatically trigger the launch request on application bootup.
 * Or in the case -setApplicationId:clientKey:properties: is called outside AppDelegate.
 */
- (void)launch;

@end

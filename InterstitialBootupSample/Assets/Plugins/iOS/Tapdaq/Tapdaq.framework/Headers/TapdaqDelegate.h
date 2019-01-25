//
//  TapdaqDelegate.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 10/12/2018.
//  Copyright © 2018 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TDError;
@class TDReward;

@protocol TapdaqDelegate <NSObject>

@optional

- (void)didLoadConfig;

- (void)didFailToLoadConfigWithError:(NSError *)error;

#pragma mark Banner delegate methods

/**
 Called immediately after the banner is loaded.
 This method should be used in conjunction with -getBanner:.
 */
- (void)didLoadBanner;

/**
 Called when, for whatever reason, the banner was not able to be loaded.
 Tapdaq will automatically attempt to load a banner again with a 1 second delay.
 */
- (void)didFailToLoadBannerWithError:(TDError *)error;

/**
 Called when the user clicks the banner.
 */
- (void)didClickBanner;

/**
 Called when the ad within the banner view loads another ad.
 */
- (void)didRefreshBanner;

#pragma mark Interstitial delegate methods

/**
 Called immediately after an interstitial is available to the user for a specific placement tag.
 This method should be used in conjunction with -showInterstitialForPlacementTag:.
 @param placementTag A placement tag.
 */
- (void)didLoadInterstitialForPlacementTag:(NSString *)placementTag;

/**
 Called when the interstitial was not able to be loaded for a specific placement tag.
 Tapdaq will automatically attempt to load an interstitial again with a 1 second delay.
 @param placementTag A placement tag.
 @param error Error object.
 */
- (void)didFailToLoadInterstitialForPlacementTag:(NSString *)placementTag withError:(TDError *)error;

/**
 Called immediately before the interstitial is to be displayed to the user.
 */
- (void)willDisplayInterstitialForPlacementTag:(NSString *)placementTag;

/**
 Called immediately after the interstitial is displayed to the user.
 */
- (void)didDisplayInterstitialForPlacementTag:(NSString *)placementTag;

/**
 Called when interstitial has failed to display.
 */
- (void)didFailToDisplayInterstitialForPlacementTag:(NSString *)placementTag withError:(TDError *)error;

/**
 Called when the user closes interstitial, either by tapping the close button, or the background surrounding the interstitial.
 */
- (void)didCloseInterstitialForPlacementTag:(NSString *)placementTag;

/**
 Called when the user clicks the interstitial.
 */
- (void)didClickInterstitialForPlacementTag:(NSString *)placementTag;

#pragma mark Video delegate methods

/**
 Called immediately after a video is available to the user for a specific placement tag.
 This method should be used in conjunction with -showVideoForPlacementTag:.
 @param placementTag A placement tag.
 */
- (void)didLoadVideoForPlacementTag:(NSString *)placementTag;

/**
 Called when, for whatever reason, the video was not able to be loaded.
 Tapdaq will automatically attempt to load a video again with a 1 second delay.
 @param placementTag A placement tag.
 @param error Error object.
 */
- (void)didFailToLoadVideoForPlacementTag:(NSString *)placementTag withError:(TDError *)error;

/**
 Called immediately before the video is to be displayed to the user.
 */
- (void)willDisplayVideoForPlacementTag:(NSString *)placementTag;

/**
 Called immediately after the video is displayed to the user.
 */
- (void)didDisplayVideoForPlacementTag:(NSString *)placementTag;

/**
 Called when video has failed to display.
 */
- (void)didFailToDisplayVideoForPlacementTag:(NSString *)placementTag withError:(TDError *)error;

/**
 Called when the user closes the video.
 */
- (void)didCloseVideoForPlacementTag:(NSString *)placementTag;

/**
 Called when the user clicks the video ad.
 */
- (void)didClickVideoForPlacementTag:(NSString *)placementTag;


#pragma mark Rewarded Video delegate methods

/**
 Called immediately after a rewarded video is available to the user for a specific placement tag.
 This method should be used in conjunction with -showRewardedVideoForPlacementTag:.
 @param placementTag A placement tag.
 */
- (void)didLoadRewardedVideoForPlacementTag:(NSString *)placementTag;

/**
 Called when, for whatever reason, the rewarded video was not able to be loaded.
 Tapdaq will automatically attempt to load a rewarded video again with a 1 second delay.
 @param placementTag A placement tag.
 @param error Error object.
 */
- (void)didFailToLoadRewardedVideoForPlacementTag:(NSString *)placementTag withError:(TDError *)error;
/**
 Called immediately before the rewarded video is to be displayed to the user.
 */
- (void)willDisplayRewardedVideoForPlacementTag:(NSString *)placementTag;

/**
 Called immediately after the rewarded video is displayed to the user.
 */
- (void)didDisplayRewardedVideoForPlacementTag:(NSString *)placementTag;

/**
 Called when interstitial has failed to display.
 */
- (void)didFailToDisplayRewardedVideoForPlacementTag:(NSString *)placementTag withError:(TDError *)error;

/**
 Called when the user closes the rewarded video.
 */
- (void)didCloseRewardedVideoForPlacementTag:(NSString *)placementTag;

/**
 Called when the user clicks the rewarded video ad.
 */
- (void)didClickRewardedVideoForPlacementTag:(NSString *)placementTag;

/**
 Called when a reward is ready for the user.
 @param reward Reward object.
 @see TDReward
 */
- (void)rewardValidationSucceeded:(TDReward *)reward;

/**
 Called when a reward failed to validate.
 @param reward Reward object.
 @see TDReward
 */
- (void)rewardValidationFailed:(TDReward *)reward;


#pragma mark Offerwall delegate methods

- (void)didLoadOfferwall;

- (void)didFailToLoadOfferwallWithError:(TDError *)error;

- (void)willDisplayOfferwall;

- (void)didDisplayOfferwall;

- (void)didFailToDisplayOfferwallWithError:(TDError *)error;

- (void)didCloseOfferwall;

- (void)didReceiveOfferwallCredits:(NSDictionary *)creditInfo;

- (void)didFailToReceiveOfferwallCredits;
@end

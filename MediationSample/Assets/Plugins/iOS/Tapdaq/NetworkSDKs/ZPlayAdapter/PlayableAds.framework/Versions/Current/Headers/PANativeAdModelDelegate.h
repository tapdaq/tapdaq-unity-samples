//
//  PANativeAdModelDelegate.h
//  Pods
//
//  Created by Michael Tang on 2018/9/5.
//

#import <Foundation/Foundation.h>
@class PANativeAdModel;

@protocol PANativeAdModelDelegate <NSObject>

@optional
/// Tells the delegate that an ad has been successfully loaded.
- (void)nativeAdDidReceive:(PANativeAdModel *)nativeAd;
/// Tells the delegate that a request failed.
- (void)nativeAdDidFailWithError:(NSError *)error;
/// Tells the delegate that did click media view
- (void)nativeAdDidClickMediaView:(PANativeAdModel *)nativeAd;
/// Tells the delegate that did click playable button
- (void)nativeAdDidClickPlayableButton:(PANativeAdModel *)nativeAd;

@end

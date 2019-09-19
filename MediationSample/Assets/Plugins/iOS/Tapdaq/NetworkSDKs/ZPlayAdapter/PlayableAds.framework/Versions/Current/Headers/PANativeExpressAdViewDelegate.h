//
//  PANativeExpressAdViewDelegate.h
//  PlayableAds
//
//  Created by Michael Tang on 2018/8/31.
//

#import <Foundation/Foundation.h>
@class PANativeExpressAdView;

@protocol PANativeExpressAdViewDelegate <NSObject>

@optional
/// Tells the delegate that an ad has been successfully loaded.
- (void)nativeExpressAdViewDidReceive:(PANativeExpressAdView *)nativeExpressAdView;

/// Tells the delegate that a request failed.
- (void)nativeExpressAdViewDidFailWithError:(NSError *)error;

/// Tells the delegate that the Native view has been clicked.
- (void)nativeExpressAdViewDidClick:(PANativeExpressAdView *)nativeExpressAdView;

@end

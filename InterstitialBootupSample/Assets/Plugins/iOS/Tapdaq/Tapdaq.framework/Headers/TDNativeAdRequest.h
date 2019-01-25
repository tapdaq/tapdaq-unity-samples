//
//  TDNativeAdRequest.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 27/03/2018.
//  Copyright © 2018 Tapdaq. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TDAdRequest.h"
#import "TDMediatedNativeAd.h"

@protocol TDAdRequestDelegate;

@interface TDNativeAdRequest : TDAdRequest
@property (readonly, nonatomic, nonnull) UIViewController *viewController;
@property (readonly, nonatomic, nullable) TDMediatedNativeAd *nativeAd;
@property (readonly, nonatomic) TDMediatedNativeAdOptions options;

@end

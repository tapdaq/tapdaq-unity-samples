//
//  TDAdTypeEnum.h
//  Tapdaq
//
//  Created by Tapdaq <support@tapdaq.com>
//  Copyright (c) 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, TDAdTypes) {
    
    TDAdTypeNone         = 1 << 0,
    
    TDAdTypeInterstitial = 1 << 1,
    
    TDAdTypeVideo        = 1 << 23,
    TDAdTypeRewardedVideo= 1 << 24,
    TDAdTypeBanner       = 1 << 25,
    
    TDAdTypeOfferwall    = 1 << 26,
    
    TDAdTypeMediatedNative = 1 << 27

};

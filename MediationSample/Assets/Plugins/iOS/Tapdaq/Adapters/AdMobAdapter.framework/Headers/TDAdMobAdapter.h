//
//  TDAdMobAdapter.h
//  Tapdaq iOS SDK
//
//  Created by Mukund Agarwal on 09/09/2016.
//  Copyright © 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TDMediationBannerAdapter.h"
#import "TDMediationNativeAdapter.h"
#import "TDAdapter.h"

@interface TDAdMobAdapter : TDAdapter <TDMediationBannerAdapter, TDMediationNativeAdapter>
@end


//
//  TDAppLovinAdapter.h
//  Tapdaq iOS SDK
//
//  Created by Mukund Agarwal on 14/09/2016.
//  Copyright © 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TDAdapter.h"
#import "TDMediationBannerAdapter.h"
#import "TDMediationNativeAdapter.h"

@interface TDAppLovinAdapter : TDAdapter <TDMediationBannerAdapter, TDMediationNativeAdapter>
@end


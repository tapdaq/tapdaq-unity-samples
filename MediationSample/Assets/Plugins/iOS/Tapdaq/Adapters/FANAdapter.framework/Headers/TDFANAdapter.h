//
//  TDFANAdapter.h
//  Tapdaq iOS SDK
//
//  Created by Mukund Agarwal on 05/09/2016.
//  Copyright © 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TDAdapter.h"
#import "TDMediationBannerAdapter.h"
#import "TDMediationNativeAdapter.h"

@interface TDFANAdapter : TDAdapter <TDMediationBannerAdapter, TDMediationNativeAdapter>
@end


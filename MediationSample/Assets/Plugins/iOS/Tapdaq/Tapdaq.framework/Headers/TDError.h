//
//  TDError.h
//  Tapdaq iOS SDK
//
//  Created by Dmitry Dovgoshliubnyi on 27/07/2017.
//  Copyright © 2017 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const TDErrorDomain;

@interface TDError : NSError
@property (strong, nonatomic) NSDictionary<NSString *, NSArray<NSError *> *> *subErrors;
@end

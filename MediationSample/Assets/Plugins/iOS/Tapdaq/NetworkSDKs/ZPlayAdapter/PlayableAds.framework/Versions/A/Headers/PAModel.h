//
//  PAModel.h
//  PAModel <https://github.com/ibireme/PAModel>
//
//  Created by ibireme on 15/5/10.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

#if __has_include(<PAModel / PAModel.h>)
FOUNDATION_EXPORT double PAModelVersionNumber;
FOUNDATION_EXPORT const unsigned char PAModelVersionString[];
#import <PAModel/NSObject+PAModel.h>
#import <PAModel/PAClassInfo.h>
#else
#import "NSObject+PAModel.h"
#import "PAClassInfo.h"
#endif

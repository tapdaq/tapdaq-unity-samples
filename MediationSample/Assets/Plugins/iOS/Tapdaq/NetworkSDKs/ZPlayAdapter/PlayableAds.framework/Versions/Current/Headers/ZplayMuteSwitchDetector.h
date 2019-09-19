//
//  ZplayMuteSwitchDetector.h
//
//  Created by Moshe Gottlieb on 6/2/13.
//  Copyright (c) 2013 Zplay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^ZplayMuteSwitchDetectorBlock)(BOOL silent);

@interface ZplayMuteSwitchDetector : NSObject

+ (ZplayMuteSwitchDetector *)shared;

@property (nonatomic, readonly) BOOL isMute;
@property (nonatomic, copy) ZplayMuteSwitchDetectorBlock silentNotify;

@end

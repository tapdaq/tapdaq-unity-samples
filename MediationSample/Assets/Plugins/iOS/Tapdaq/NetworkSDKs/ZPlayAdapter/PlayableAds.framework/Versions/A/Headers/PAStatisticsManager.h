//
//  PAStatisticsManager.h
//  Pods
//
//  Created by Michael Tang on 2018/9/13.
//

#import <Foundation/Foundation.h>

@interface PAStatisticsManager : NSObject

+ (instancetype)sharedStatisticsManager;

- (void)persistPlayableReport:(NSString *)reportUrl isSuccess:(BOOL)isSuccess errorCode:(NSInteger)code;

@end

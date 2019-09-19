//
//  PALogEntry.h
//  Pods
//
//  Created by d on 26/5/2017.
//
//

#import "PALogLevel.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PALogEntry : NSObject

@property (nonatomic, readonly) NSString *prefix;
@property (nonatomic, readonly) NSString *message;
@property (nonatomic, readonly) NSDate *time;
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> *extras;
@property (nonatomic, assign, readonly) PALogLevel level;

+ (instancetype)entryWithLevel:(PALogLevel)level
                          time:(NSDate *)time
                        prefix:(NSString *)prefix
                       message:(NSString *)message
                        extras:(NSDictionary<NSString *, id> *_Nullable)extras;

@end

NS_ASSUME_NONNULL_END

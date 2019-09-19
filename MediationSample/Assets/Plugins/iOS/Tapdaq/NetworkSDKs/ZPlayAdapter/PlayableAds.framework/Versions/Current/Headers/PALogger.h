//
//  PALogger.h
//  Pods
//
//  Created by d on 26/5/2017.
//
//

#import "PALogFormatter.h"
#import "PALogHook.h"
#import "PALogLevel.h"
#import <Foundation/Foundation.h>

#define PAStdLogger [PALogger stdLogger]

NS_ASSUME_NONNULL_BEGIN

@interface PALogger : NSObject

+ (instancetype)stdLogger;

+ (instancetype)loggerWithPrefix:(NSString *)prefix level:(PALogLevel)level;

- (void)setLevel:(PALogLevel)level;
- (void)setFormatter:(id<PALogFormatter>)formatter;

// set metadata that will always be logged
- (void)setMetadata:(NSDictionary<NSString *, id> *)metadata;

- (void)addHook:(id<PALogHook>)hook;

- (void)log:(PALogLevel)level message:(NSString *)message;
- (void)log:(PALogLevel)level message:(NSString *)message extras:(NSDictionary<NSString *, id> *_Nullable)extras;

- (void)debug:(NSString *)message;
- (void)info:(NSString *)message;
- (void)warning:(NSString *)message;
- (void)error:(NSString *)message;

- (void)debug:(NSString *)message extras:(NSDictionary<NSString *, id> *)extras;
- (void)info:(NSString *)message extras:(NSDictionary<NSString *, id> *)extras;
- (void)warning:(NSString *)message extras:(NSDictionary<NSString *, id> *)extras;
- (void)error:(NSString *)message extras:(NSDictionary<NSString *, id> *)extras;

@end

NS_ASSUME_NONNULL_END

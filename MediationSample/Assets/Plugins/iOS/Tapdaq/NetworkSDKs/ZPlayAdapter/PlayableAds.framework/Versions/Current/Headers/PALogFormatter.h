//
//  PALogFormatter.h
//  Pods
//
//  Created by d on 26/5/2017.
//
//

#import "PALogEntry.h"
#import <Foundation/Foundation.h>

@protocol PALogFormatter <NSObject>

- (NSString *_Nonnull)logMessageWithEntry:(PALogEntry *_Nonnull)entry;

@end

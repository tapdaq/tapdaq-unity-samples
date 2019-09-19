//
//  PALogHook.h
//  Pods
//
//  Created by d on 26/5/2017.
//
//

#import "PALogEntry.h"
#import <Foundation/Foundation.h>

@protocol PALogHook <NSObject>

- (void)fire:(PALogEntry *_Nonnull)entry;

@end

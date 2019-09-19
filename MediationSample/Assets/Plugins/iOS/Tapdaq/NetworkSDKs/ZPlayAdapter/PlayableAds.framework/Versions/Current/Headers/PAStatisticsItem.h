//
//  PAStatisticsItem.h
//  Pods
//
//  Created by Michael Tang on 2018/9/13.
//

#import <Foundation/Foundation.h>

@interface PAStatisticsItem : NSObject

@property (nonatomic) NSString *trackingType;
@property (nonatomic) NSUInteger count;
@property (nonatomic) NSUInteger errorCount;
@property (nonatomic) NSArray *errorCode;

@end

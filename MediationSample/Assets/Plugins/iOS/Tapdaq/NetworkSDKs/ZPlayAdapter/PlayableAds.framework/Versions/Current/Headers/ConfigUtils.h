//
//  ConfigUtils.h
//  Expecta
//
//  Created by lgd on 2018/4/17.
//

#import <Foundation/Foundation.h>

static NSString *const PRODUCT_HOST = @"https://pa-engine.zplayads.com";
static NSString *const TEST_HOST = @"http://101.201.78.229:8999";

@interface ConfigUtils : NSObject

+ (id)shared;
- (NSString *)zplayServer;
- (BOOL)hasTestTagFile;

@end

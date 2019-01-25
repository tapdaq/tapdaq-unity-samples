//
//  TDTestDevices.h
//  Tapdaq iOS SDK
//
//  Created by Nick Reffitt on 08/01/2017.
//  Copyright © 2017 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TDTestDevices : NSObject

@property (nonatomic) NSString *network;
@property (nonatomic, strong) NSArray *testDevices;

- (id)initWithNetwork:(NSString *)network testDevices:(NSArray *)testDevices;

@end

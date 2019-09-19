//
//  PARequestModel.h
//  Pods
//
//  Created by d on 19/7/2017.
//
//

#import <Foundation/Foundation.h>

@interface PARequestModel : NSObject

+ (instancetype _Nonnull)modelWithAdUnitID:(NSString *_Nonnull)adUnitID
                                     appID:(NSString *_Nonnull)appID
                               requestType:(NSString *)type
                                 channelId:(NSString *)channelId;

@end

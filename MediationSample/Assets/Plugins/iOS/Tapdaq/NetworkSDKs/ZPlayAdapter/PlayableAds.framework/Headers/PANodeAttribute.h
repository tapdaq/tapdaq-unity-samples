//
//  PANodeAttribute.h
//  Pods
//
//  Created by d on 14/7/2017.
//
//

#import "PAHTMLNode.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PANodeAttribute : NSObject

+ (instancetype)attributeWithName:(NSString *)name
                        remoteURL:(NSURL *)remoteURL
                    localFilename:(NSString *)localFilename
                             node:(PAHTMLNode *)node;

@property (nonatomic) NSString *name;
@property (nonatomic) NSURL *remoteURL;
@property (nonatomic) NSString *localFilename;
@property (nonatomic) PAHTMLNode *node;

@end

NS_ASSUME_NONNULL_END

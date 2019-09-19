//
//  PACacheManager.h
//  Pods
//
//  Created by d on 11/7/2017.
//
//

#import "PAResponseModel.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PACacheManager : NSObject

+ (instancetype)sharedManager;

/// append html snippet when not from editor
/// Calling it must be earlier than ‘cacheHTMLURL:’
- (void)appendScriptSnippetIfNotEditor:(NSString *)scriptSnippet;

// cache html url or html snippet
- (void)cacheHTMLURL:(NSString *)htmlURL
             success:(void (^)(NSURL *htmlFileURL, NSURL *assetsDirectoryURL, BOOL isCache))success
             failure:(void (^)(NSError *error))failure;

- (NSURL *)baseDirectoryURL;

// load retry duration
- (void)persistRetryInterval:(PAResponseRetryIntervalModel *)interval;
- (PAResponseRetryIntervalModel *)getResponseRetryInterval;

@end

NS_ASSUME_NONNULL_END

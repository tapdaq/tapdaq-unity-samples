//
//  PAFileDownloadManager.h
//  Pods
//
//  Created by Michael Tang on 2018/9/5.
//  Copyright © 2018年 Michael Tang. All rights reserved.
//

#import "PAUtils.h"
#import <Foundation/Foundation.h>

@interface PAFileDownloadManager : NSObject

+ (instancetype)stdFileDownloadManager;

- (void)downloadFileWith:(NSString *)fileUrl
              atFileType:(PAExportFileType)fileType
                 success:(void (^)(NSString *filePath))success
                 failure:(void (^)(NSError *error))failure;

@end

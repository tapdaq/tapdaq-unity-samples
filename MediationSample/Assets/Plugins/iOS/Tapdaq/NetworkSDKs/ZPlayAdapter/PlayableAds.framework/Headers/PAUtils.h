//
//  PAUtils.h
//  Pods
//
//  Created by d on 19/7/2017.
//
//

#import <Foundation/Foundation.h>

static NSString *const PANativeFileResourcesPath = @"PANativeFileResourcesPath";
//导出视频类型
typedef NS_ENUM(NSUInteger, PAExportFileType) {
    // default
    PAExportFileTypeMp4 = 10,
    PAExportFileTypeMp3,
    PAExportFileTypePng,
    PAExportFileTypeJpg,
    PAExportFileTypeWav,
    PAExportFileTypeCaf,
    PAExportFileTypeHtml,
};

#define SYSTEM_VERSION_LESS_THAN(v)                                                                                    \
    ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)

#define SCREEN_SIZE [UIScreen mainScreen].bounds.size
#define SCREEN_WIDTH SCREEN_SIZE.width
#define SCREEN_HEIGHT SCREEN_SIZE.height

NS_ASSUME_NONNULL_BEGIN

@interface PAUtils : NSObject

@property (nonatomic, readonly, assign) int screenScale;
@property (nonatomic, readonly, assign) int screenWidth;
@property (nonatomic, readonly, assign) int screenHeight;
@property (nonatomic, assign, readonly) int dpi;

@property (nonatomic, readonly) NSString *userAgent;
@property (nonatomic, readonly) NSString *deviceModel;
@property (nonatomic, readonly) NSString *deviceType;
@property (nonatomic, readonly) NSString *idfa;
@property (nonatomic, readonly) NSString *idfv;
@property (nonatomic, readonly) NSString *plmn;
@property (nonatomic, readonly) NSString *osVersion;
@property (nonatomic, readonly) NSString *language;
@property (nonatomic, readonly) NSString *networkConnectionType;

@property (nonatomic, readonly) NSString *appVersion;
@property (nonatomic, readonly) NSString *bundleID;
@property (nonatomic, readonly) NSString *appName;

@property (nonatomic, readonly, assign) double longitude;
@property (nonatomic, readonly, assign) double latitude;
@property (nonatomic, readonly, assign) double horizontalAccuracy;
@property (nonatomic, readonly, assign) double verticalAccuracy;

+ (instancetype)sharedUtils;

- (BOOL)isInterfaceOrientationPortrait;

- (NSString *)md5:(NSString *)data;

+ (UIViewController *)topMostViewController;

- (CGFloat)adaptedValue6:(CGFloat)size;
- (UIFont *)adaptedFont6:(CGFloat)fontSize;
- (NSBundle *)resourcesBundleWithBundleName:(NSString *)bundleName;
- (BOOL)iSiPhoneX;
- (BOOL)isiPhone;
- (BOOL)isiPad;
- (BOOL)isiPod;
- (BOOL)isSimulator;
- (CGFloat)getTransformAngleWith:(UIView *)view
                   vcOrientation:(UIInterfaceOrientationMask)vcOrientation
         playablePageOrientation:(UIInterfaceOrientationMask)paOrientation;
// download file
- (NSString *)downloadFilePath:(NSString *)fileUrl atFileType:(PAExportFileType)fileType;
- (NSString *)saveFileDirectory;
- (BOOL)iSSimplifiedChinese;

@end

NS_ASSUME_NONNULL_END

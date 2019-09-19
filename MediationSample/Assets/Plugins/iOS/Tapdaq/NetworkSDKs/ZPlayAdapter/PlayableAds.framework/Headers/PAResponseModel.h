//
//  PAResponseModel.h
//  Pods
//
//  Created by d on 19/7/2017.
//
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    kNativeAdType_html = 1 << 1,
    kNativeAdType_material = 1 << 2,
} kNativeAdType;

typedef enum : NSUInteger {
    kSourceType_editor = 0,
    kSourceType_notFromEditor = 1,
} kSourceType;

NS_ASSUME_NONNULL_BEGIN

@interface PANativeMaterialModel : NSObject

@property (nonatomic) NSString *iconUrl;
@property (nonatomic, assign) double ratios;
@property (nonatomic) NSString *imageUrl;
@property (nonatomic) NSString *title;
@property (nonatomic) NSString *adDescription;
@property (nonatomic) NSString *videoUrl;
@property (nonatomic) NSString *playableButtonUrl;

@end

@interface PANativeHtmlModel : NSObject

@property (nonatomic, assign) double ratios;
@property (nonatomic) NSString *htmlString;

@end

@interface PAResponseNativeModel : NSObject

@property (nonatomic) NSString *creativesID;
@property (nonatomic, assign) kNativeAdType nativeType;
@property (nonatomic) PANativeMaterialModel *material;
@property (nonatomic) PANativeHtmlModel *html;
@property (nonatomic) NSArray *nativePresentTrackers;
@property (nonatomic) NSArray *clickTriggerPlayableTrackers;
@property (nonatomic) NSArray *clickFromNativeTrackers;
@property (nonatomic) NSString *nativeLandingHtml;

@end

@interface PAResponseRetryIntervalModel : NSObject

// retry time Interval
@property (nonatomic, assign) NSInteger defaultInterval;
@property (nonatomic, assign) NSInteger noContentInterval;

@end

@interface PAResponseModel : NSObject

@property (nonatomic, assign) BOOL isLandscape;

@property (nonatomic) NSString *videoURL;
@property (nonatomic) NSArray<NSString *> *videoStartPlayingTrackers;
@property (nonatomic) NSArray<NSString *> *videoEndedPlayingTrackers;
@property (nonatomic) NSNumber *showCloseButton;
@property (nonatomic) NSNumber *showInstallButton;

@property (nonatomic) NSString *landingPageURL;
@property (nonatomic) NSArray<NSString *> *landingPagePresentedTrackers;
@property (nonatomic) NSArray<NSString *> *landingPageDismissedTrackers;

@property (nonatomic) NSNumber *itunesID;
@property (nonatomic) NSString *itunesLink;

@property (nonatomic) NSArray<NSString *> *clickFromVideoPageTrackers;
@property (nonatomic) NSArray<NSString *> *clickFromLandingPageTrackers;

@property (nonatomic) PAResponseRetryIntervalModel *interval;
// download  resources tracker
@property (nonatomic) NSString *resourcesStartDownloadingTracker;
@property (nonatomic) NSString *resourcesEndedDownloadTracker;
// video  force close
@property (nonatomic) NSString *videoForceCloseTracker;
@property (nonatomic, assign) int showForceCloseButtonInterval; // -1 是不显示，0以上表示显示的延迟时间
@property (nonatomic) NSString *userBehaviorTracker;
@property (nonatomic) NSArray<NSString *> *videoDidFailLoadingTrackers;

// native
@property (nonatomic) PAResponseNativeModel *native;

// show_replay_button
@property (nonatomic, assign) BOOL isShowReplayButtonInLandingPage;

// 2.4.0
@property (nonatomic) NSArray<NSString *> *presentTrackers;
// 0=> editor 1 =>not from editor
@property (nonatomic, assign) kSourceType sourceType;
@property (nonatomic) NSString *needAppendHtmlScript;

@end

NS_ASSUME_NONNULL_END

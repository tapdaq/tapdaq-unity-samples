//
//  PAVideoViewController.h
//  Pods
//
//  Created by d on 13/7/2017.
//
//

#import "PAAppStore.h"
#import "PAResponseModel.h"
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN
@class PAVideoViewController;
@protocol PAVideoDelegate <NSObject>

- (void)videoDidEndLoading;
- (void)videoDidStartPlaying;
- (void)videoDidEndPlaying:(BOOL)isShowLandingPage;
- (void)videoDidClick;
- (void)videoDidTriggerClose;
- (void)videoDidDismissScreen;
- (void)videoDidFailedToLoadWithError:(NSError *)error;

- (void)landingPageDidClick;
- (void)landingPageDidTriggerClose;
- (void)doRewardUser;

@optional
- (void)landingPageDidEndLoading;
@end

@interface PAVideoViewController : UIViewController

- (instancetype)initWithAppStore:(PAAppStore *)appStore;

@property (nonatomic, weak) id<PAVideoDelegate> delegate;
@property (nonatomic) PAResponseModel *ad;
@property (nonatomic, nullable) WKWebView *landingWeb;
@property (nonatomic, assign) BOOL isFromNative;

- (void)loadRemoteURL:(NSURL *)url;
- (void)loadRemoteURL2:(NSURL *)url;
- (void)loadLocalURL:(NSURL *)htmlFileURL assetsDirectoryURL:(NSURL *)assetsDirectoryURL;
- (void)loadLocalURL2:(NSURL *)htmlFileURL assetsDirectoryURL:(NSURL *)assetsDirectoryURL;

- (void)listeningMuteSwitchBtn;

@end

NS_ASSUME_NONNULL_END

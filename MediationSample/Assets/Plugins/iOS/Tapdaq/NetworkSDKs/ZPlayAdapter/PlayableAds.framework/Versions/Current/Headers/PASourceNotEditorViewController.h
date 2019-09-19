//
//  PASourceNotEditorViewController.h
//  PlayableAds
//
//  Created by Michael Tang on 2018/12/19.
//

#import "PAAppStore.h"
#import "PAResponseModel.h"
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PASourceNotEditorViewControllerDelegate <NSObject>

- (void)sourceNotEditorDidClick;
- (void)sourceNotEditorDidDismissScreen;
- (void)sourceNotEditorDidFailedToLoadWithError:(NSError *)error;

- (void)sourceNotEditorDidRewardUser;

@end

@interface PASourceNotEditorViewController : UIViewController <NSCopying>

- (instancetype)initWithAppStore:(PAAppStore *)appStore;

@property (nonatomic, weak) id<PASourceNotEditorViewControllerDelegate> delegate;
@property (nonatomic) PAResponseModel *ad;

- (void)loadRemoteURL:(NSURL *)url;
- (void)loadLocalURL:(NSURL *)htmlFileURL assetsDirectoryURL:(NSURL *)assetsDirectoryURL;

@end

NS_ASSUME_NONNULL_END

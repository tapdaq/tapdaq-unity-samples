//
//  PlayableAdsPreviewer.h
//  Pods
//
//  Created by d on 18/8/2017.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PlayableAdsPreviewer : NSObject

- (void)presentFromRootViewController:(UIViewController *)rootViewController
                             withAdID:(NSString *)adID
                              success:(void (^)(void))success
                              dismiss:(void (^)(void))dismiss
                              failure:(void (^)(NSError *error))failure;

- (void)presentFromRootViewController:(UIViewController *)rootViewController
                              withURL:(NSString *)url
                       isInterstitial:(BOOL)isInterstitial
                        isLandingPage:(BOOL)isLandingPage
                             itunesID:(NSNumber *)itunesID
                              success:(void (^)(void))success
                              dismiss:(void (^)(void))dismiss
                              failure:(void (^)(NSError *error))failure;
// set preview  ad format
- (void)setPreviewAdFormatWithAdStatus:(BOOL)isInterstitial;

@end

NS_ASSUME_NONNULL_END

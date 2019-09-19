//
//  WKWebView+PA_JavaScriptBridge.h
//  Pods
//
//  Created by 王泽永 on 2018/7/25.
//

#import <WebKit/WebKit.h>

@interface WKWebView (PA_JavaScriptBridge)

- (void)PA_startAd_evaluateJavaScriptWithCompletionHandler:
    (void (^_Nullable)(_Nullable id, NSError *_Nullable error))completionHandler;

- (void)PA_setSDKVersionNumber_evaluateJavaScriptWithCompletionHandler:
    (void (^_Nullable)(_Nullable id, NSError *_Nullable error))completionHandler;

- (void)PA_setiOSVersion_evaluateJavaScriptWithCompletionHandler:
    (void (^_Nullable)(_Nullable id, NSError *_Nullable error))completionHandler;

- (void)PA_muteSound_evaluateJavaScriptWithState:(BOOL)state
                               completionHandler:
                                   (void (^_Nullable)(_Nullable id, NSError *_Nullable error))completionHandler;

- (void)PA_getOrientation_evaluateJavaScriptWithCompletionHandler:
    (void (^_Nullable)(_Nullable id, NSError *_Nullable error))completionHandler;

- (void)PA_getEvents_evaluateJavaScriptWithCompletionHandler:
    (void (^_Nullable)(_Nullable id, NSError *_Nullable error))completionHandler;

// native
- (void)PA_playNativeVideo_evaluateJavaScriptWithCompletionHandler:
    (void (^_Nullable)(_Nullable id, NSError *_Nullable error))completionHandler;
// show replay button
- (void)PA_showReplayButton_evaluateJavaScriptWithCompletionHandler:
    (void (^_Nullable)(_Nullable id, NSError *_Nullable error))completionHandler;

// restartAd
- (void)PA_restartAd_evaluateJavaScriptWithCompletionHandler:
    (void (^_Nullable)(_Nullable id, NSError *_Nullable error))completionHandler;
@end

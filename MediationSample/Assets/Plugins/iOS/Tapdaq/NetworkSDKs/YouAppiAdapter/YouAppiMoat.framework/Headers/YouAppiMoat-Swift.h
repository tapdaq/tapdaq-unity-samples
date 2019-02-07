// Generated by Apple Swift version 4.2 effective-4.1.50 (swiftlang-1000.11.37.1 clang-1000.11.45.1)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if __has_feature(modules)
@import CoreGraphics;
@import CoreLocation;
@import Foundation;
@import ObjectiveC;
@import UIKit;
@import WebKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="YouAppiMoat",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

typedef SWIFT_ENUM(NSInteger, AdState, closed) {
  AdStateNone = 0,
  AdStateLoadingStarted = 1,
  AdStateLoadingFinished = 2,
};

typedef SWIFT_ENUM(NSInteger, AdType, closed) {
  AdTypeNone = 0,
  AdTypeCardAd = 1,
  AdTypeRewardedVideo = 2,
  AdTypeInterstitialVideo = 3,
};


SWIFT_CLASS("_TtC11YouAppiMoat4Moat")
@interface Moat : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat11MoatDetails")
@interface MoatDetails : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end




@interface NSString (SWIFT_EXTENSION(YouAppiMoat))
- (NSTimeInterval)formattedTimeInterval SWIFT_WARN_UNUSED_RESULT;
- (BOOL)isValidAsUnitID SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nullable)fileExtension SWIFT_WARN_UNUSED_RESULT;
@end

@class NSCoder;

SWIFT_CLASS("_TtC11YouAppiMoat11SlidingView")
@interface SlidingView : UIView
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)drawRect:(CGRect)rect;
@end







@class NSXMLParser;

SWIFT_CLASS("_TtC11YouAppiMoat10VastParser")
@interface VastParser : NSObject <NSXMLParserDelegate>
- (void)parserDidStartDocument:(NSXMLParser * _Nonnull)parser;
- (void)parser:(NSXMLParser * _Nonnull)parser didStartElement:(NSString * _Nonnull)elementName namespaceURI:(NSString * _Nullable)namespaceURI qualifiedName:(NSString * _Nullable)qName attributes:(NSDictionary<NSString *, NSString *> * _Nonnull)attributeDict;
- (void)parser:(NSXMLParser * _Nonnull)parser foundCharacters:(NSString * _Nonnull)string;
- (void)parser:(NSXMLParser * _Nonnull)parser didEndElement:(NSString * _Nonnull)elementName namespaceURI:(NSString * _Nullable)namespaceURI qualifiedName:(NSString * _Nullable)qName;
- (void)parser:(NSXMLParser * _Nonnull)parser parseErrorOccurred:(NSError * _Nonnull)parseError;
- (void)parserDidEndDocument:(NSXMLParser * _Nonnull)parser;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat25ViewabilityTrackerManager")
@interface ViewabilityTrackerManager : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class YAAdRequest;

SWIFT_CLASS("_TtC11YouAppiMoat4YAAd")
@interface YAAd : NSObject
@property (nonatomic, weak) id _Nullable delegate;
@property (nonatomic, copy) NSString * _Null_unspecified adUnitID;
@property (nonatomic) enum AdType adType;
@property (nonatomic, strong) YAAdRequest * _Nullable adRequest;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (BOOL)isAvailable SWIFT_WARN_UNUSED_RESULT;
- (void)show;
- (BOOL)load;
@end


SWIFT_CLASS("_TtC11YouAppiMoat8YAAdCard")
@interface YAAdCard : YAAd
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, weak) id _Nullable delegate;
- (void)show;
- (BOOL)load;
@end


SWIFT_CLASS("_TtC11YouAppiMoat9YAElement")
@interface YAElement : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat17YAAdConfiguration")
@interface YAAdConfiguration : YAElement
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * _Nonnull debugDescription;
@end

enum YAErrorCode : NSInteger;

SWIFT_PROTOCOL("_TtP11YouAppiMoat12YAAdDelegate_")
@protocol YAAdDelegate
@optional
- (void)onLoadFailureWithAdUnitID:(NSString * _Nonnull)adUnitID errorCode:(enum YAErrorCode)errorCode error:(NSError * _Nullable)error;
- (void)onShowFailureWithAdUnitID:(NSString * _Nonnull)adUnitID errorCode:(enum YAErrorCode)errorCode error:(NSError * _Nullable)error;
- (void)onAdLeftApplicationWithAdUnitID:(NSString * _Nonnull)adUnitID;
@end


SWIFT_PROTOCOL("_TtP11YouAppiMoat26YAAdInterstitialAdDelegate_")
@protocol YAAdInterstitialAdDelegate <YAAdDelegate>
@optional
- (void)onAdStartedWithAdUnitID:(NSString * _Nonnull)adUnitID;
- (void)onAdEndedWithAdUnitID:(NSString * _Nonnull)adUnitID;
- (void)onAdClickWithAdUnitID:(NSString * _Nonnull)adUnitID;
- (void)onLoadSuccessWithAdUnitID:(NSString * _Nonnull)adUnitID;
- (void)onCardShowWithAdUnitID:(NSString * _Nonnull)adUnitID;
- (void)onCardCloseWithAdUnitID:(NSString * _Nonnull)adUnitID;
@end


SWIFT_CLASS("_TtC11YouAppiMoat21YAAdInterstitialVideo")
@interface YAAdInterstitialVideo : YAAd
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, weak) id _Nullable delegate;
- (void)show;
- (BOOL)load;
- (BOOL)isAvailable SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_PROTOCOL("_TtP11YouAppiMoat17YAAdVideoDelegate_")
@protocol YAAdVideoDelegate <YAAdDelegate>
@optional
- (void)onVideoStartedWithAdUnitID:(NSString * _Nonnull)adUnitID;
- (void)onVideoEndedWithAdUnitID:(NSString * _Nonnull)adUnitID;
@end


SWIFT_PROTOCOL("_TtP11YouAppiMoat29YAAdInterstitialVideoDelegate_")
@protocol YAAdInterstitialVideoDelegate <YAAdInterstitialAdDelegate, YAAdVideoDelegate>
@end

@protocol YALoggerDelegate;

SWIFT_CLASS("_TtC11YouAppiMoat10YAAdLogger")
@interface YAAdLogger : NSObject
@property (nonatomic, weak) id <YALoggerDelegate> _Nullable delegate;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat11YAAdRequest")
@interface YAAdRequest : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat17YAAdRewardedVideo")
@interface YAAdRewardedVideo : YAAd
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, weak) id _Nullable delegate;
- (void)show;
- (BOOL)load;
- (BOOL)isAvailable SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_PROTOCOL("_TtP11YouAppiMoat25YAAdRewardedVideoDelegate_")
@protocol YAAdRewardedVideoDelegate <YAAdInterstitialVideoDelegate>
@optional
- (void)onRewardedWithAdUnitID:(NSString * _Nonnull)adUnitID;
@end



SWIFT_CLASS("_TtC11YouAppiMoat15YAApiDispatcher")
@interface YAApiDispatcher : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat12YAApiManager")
@interface YAApiManager : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat18YABatteryUtilities")
@interface YABatteryUtilities : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat9YAProduct")
@interface YAProduct : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (BOOL)isEqual:(id _Nullable)object SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly, copy) NSString * _Nonnull debugDescription;
@end


SWIFT_CLASS("_TtC11YouAppiMoat8YACardAd")
@interface YACardAd : YAProduct
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * _Nonnull debugDescription;
- (BOOL)isEqual:(id _Nullable)object SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC11YouAppiMoat14YAProductLogic")
@interface YAProductLogic : YAElement
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)reachabilityChanged:(NSNotification * _Nonnull)note;
@end


SWIFT_CLASS("_TtC11YouAppiMoat13YACardAdLogic")
@interface YACardAdLogic : YAProductLogic
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat9YAClicker")
@interface YAClicker : UIButton
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)didMoveToSuperview;
@end


SWIFT_CLASS("_TtC11YouAppiMoat11YADebugView")
@interface YADebugView : UIView
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, YADeviceOrientation, closed) {
  YADeviceOrientationUnknown = 0,
  YADeviceOrientationPortrait = 1,
  YADeviceOrientationLandscape = 2,
};


SWIFT_CLASS("_TtC11YouAppiMoat15YADownloadCache")
@interface YADownloadCache : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat14YADownloadInfo")
@interface YADownloadInfo : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC11YouAppiMoat12YADownloader")
@interface YADownloader : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


typedef SWIFT_ENUM(NSInteger, YAErrorCode, closed) {
  YAErrorCodeNO_LOAD = 0,
  YAErrorCodeNO_FILL = 1,
  YAErrorCodeINVALID_TOKEN = 2,
  YAErrorCodeAD_UNIT_INACTIVE = 3,
  YAErrorCodeWARMING_UP = 4,
  YAErrorCodeSERVER_ERROR = 5,
  YAErrorCodePRELOAD_ERROR = 6,
  YAErrorCodeAD_IS_ALREADY_SHOWING = 7,
  YAErrorCodePLAYBACK_ERROR = 8,
  YAErrorCodeOTHER = 9,
  YAErrorCodeINVALID_AD_UNIT_ID = 10,
  YAErrorCodeVAST_ERROR = 11,
};


SWIFT_CLASS("_TtC11YouAppiMoat17YAEventDispatcher")
@interface YAEventDispatcher : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat9YAVideoAd")
@interface YAVideoAd : YAProduct
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * _Nonnull debugDescription;
@end


SWIFT_CLASS("_TtC11YouAppiMoat19YAInterstitialVideo")
@interface YAInterstitialVideo : YAVideoAd
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * _Nonnull debugDescription;
- (BOOL)isEqual:(id _Nullable)object SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC11YouAppiMoat16YAVideoAdAdLogic")
@interface YAVideoAdAdLogic : YAProductLogic
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat26YAInterstitialVideoAdLogic")
@interface YAInterstitialVideoAdLogic : YAVideoAdAdLogic
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat14YAObjectParser")
@interface YAObjectParser : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat18YAJsonObjectParser")
@interface YAJsonObjectParser : YAObjectParser
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat17YALearnMoreButton")
@interface YALearnMoreButton : UIButton
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)didMoveToSuperview;
@end

typedef SWIFT_ENUM(NSInteger, YALogLevel, closed) {
  YALogLevelNone = 1,
  YALogLevelAll = 2,
  YALogLevelDebug = 3,
  YALogLevelInfo = 4,
  YALogLevelWarning = 5,
  YALogLevelError = 6,
  YALogLevelAssert = 7,
};

typedef SWIFT_ENUM(NSInteger, YALogTag, closed) {
  YALogTagApi = 0,
  YALogTagCallback = 1,
  YALogTagSdk = 2,
};


SWIFT_CLASS("_TtC11YouAppiMoat8YALogger")
@interface YALogger : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)appDidEnterBackground;
@end

@class YouAppi;

SWIFT_PROTOCOL("_TtP11YouAppiMoat16YALoggerDelegate_")
@protocol YALoggerDelegate
@optional
- (void)logDidReceivedInformationWithYouAppi:(YouAppi * _Nonnull)youAppi tag:(enum YALogTag)tag logLevel:(enum YALogLevel)logLevel message:(NSString * _Nonnull)message error:(NSError * _Nullable)error;
@end

@class NSBundle;

SWIFT_CLASS("_TtC11YouAppiMoat22YALoggerViewController")
@interface YALoggerViewController : UIViewController
- (void)viewDidLoad;
@property (nonatomic, readonly) BOOL prefersStatusBarHidden;
- (void)viewDidAppear:(BOOL)animated;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat14YALogicManager")
@interface YALogicManager : NSObject <CLLocationManagerDelegate>
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)appDidEnterBackground;
- (void)appWillEnterForeground;
@end


SWIFT_CLASS("_TtC11YouAppiMoat11YAMediaFile")
@interface YAMediaFile : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat12YAMuteButton")
@interface YAMuteButton : UIButton
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)didMoveToSuperview;
@end

@class NSURLSession;
@class NSURLSessionDownloadTask;
@class NSURLAuthenticationChallenge;
@class NSURLCredential;
@class NSHTTPURLResponse;

SWIFT_CLASS("_TtC11YouAppiMoat16YANetworkManager")
@interface YANetworkManager : NSObject <NSURLSessionDownloadDelegate>
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didCompleteWithError:(NSError * _Nullable)error;
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didFinishDownloadingToURL:(NSURL * _Nonnull)location;
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didWriteData:(int64_t)bytesWritten totalBytesWritten:(int64_t)totalBytesWritten totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didResumeAtOffset:(int64_t)fileOffset expectedTotalBytes:(int64_t)expectedTotalBytes;
- (void)URLSession:(NSURLSession * _Nonnull)session didReceiveChallenge:(NSURLAuthenticationChallenge * _Nonnull)challenge completionHandler:(void (^ _Nonnull)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task willPerformHTTPRedirection:(NSHTTPURLResponse * _Nonnull)response newRequest:(NSURLRequest * _Nonnull)request completionHandler:(void (^ _Nonnull)(NSURLRequest * _Nullable))completionHandler;
@end


@class CLLocationManager;
@class CLLocation;

SWIFT_CLASS("_TtC11YouAppiMoat24YAOneShotLocationManager")
@interface YAOneShotLocationManager : NSObject <CLLocationManagerDelegate>
- (void)locationManager:(CLLocationManager * _Nonnull)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;
- (void)locationManager:(CLLocationManager * _Nonnull)manager didFailWithError:(NSError * _Nonnull)error;
- (void)locationManager:(CLLocationManager * _Nonnull)manager didUpdateLocations:(NSArray<CLLocation *> * _Nonnull)locations;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat15YAPrivacyButton")
@interface YAPrivacyButton : UIView
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)didMoveToSuperview;
@end


SWIFT_PROTOCOL("_TtP11YouAppiMoat23YAPrivacyButtonDelegate_")
@protocol YAPrivacyButtonDelegate
@optional
- (void)privacyButtonDidClick;
- (void)privacyViewDidClick;
@end




SWIFT_CLASS("_TtC11YouAppiMoat15YARewardedVideo")
@interface YARewardedVideo : YAInterstitialVideo
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * _Nonnull debugDescription;
- (BOOL)isEqual:(id _Nullable)object SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC11YouAppiMoat22YARewardedVideoAdLogic")
@interface YARewardedVideoAdLogic : YAInterstitialVideoAdLogic
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat10YATracking")
@interface YATracking : YAElement
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * _Nonnull debugDescription;
@end


SWIFT_CLASS("_TtC11YouAppiMoat11YAUtilities")
@interface YAUtilities : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



@class NSNotification;

SWIFT_CLASS("_TtC11YouAppiMoat19YAVideoAdPlayerView")
@interface YAVideoAdPlayerView : UIView <YAPrivacyButtonDelegate>
- (nonnull instancetype)init;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (void)layoutSubviews;
- (void)hideButtons;
- (void)skipButtonClicked;
- (void)onMute;
- (void)onLearnMore;
- (void)privacyButtonDidClick;
- (void)privacyViewDidClick;
- (void)playerItemDidReachEndWithNotification:(NSNotification * _Nonnull)notification;
- (void)playerItemFailedToPlayEndTimeWithNotification:(NSNotification * _Nonnull)notification;
- (void)playerItemPlaybackStallWithNotification:(NSNotification * _Nonnull)notification;
- (void)playerItemEnterBackgroundWithNotification:(NSNotification * _Nonnull)notification;
- (void)playerItemEnterForegroundWithNotification:(NSNotification * _Nonnull)notification;
- (void)audioSessionChangedWithNotification:(NSNotification * _Nonnull)notification;
- (void)handleAudioSessionInterruptionWithNotification:(NSNotification * _Nonnull)notification;
- (void)observeValueForKeyPath:(NSString * _Nullable)keyPath ofObject:(id _Nullable)object change:(NSDictionary<NSKeyValueChangeKey, id> * _Nullable)change context:(void * _Nullable)context;
- (void)reconnectFunc;
@end


SWIFT_CLASS("_TtC11YouAppiMoat29YAVideoAdPlayerViewController")
@interface YAVideoAdPlayerViewController : UIViewController
- (void)viewDidLoad;
@property (nonatomic, readonly) UIInterfaceOrientationMask supportedInterfaceOrientations;
@property (nonatomic, readonly) BOOL prefersStatusBarHidden;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat21YAVideoAdProgressView")
@interface YAVideoAdProgressView : UIView
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)didMoveToSuperview;
- (void)layoutSubviews;
@end


SWIFT_CLASS("_TtC11YouAppiMoat20YAVideoConfiguration")
@interface YAVideoConfiguration : YAElement
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (BOOL)isEqual:(id _Nullable)object SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly, copy) NSString * _Nonnull debugDescription;
@end


SWIFT_CLASS("_TtC11YouAppiMoat13YAViewManager")
@interface YAViewManager : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class WKWebView;
@class WKNavigation;
@class WKNavigationAction;
@class UIGestureRecognizer;
@class UITouch;

SWIFT_CLASS("_TtC11YouAppiMoat19YAWebViewController")
@interface YAWebViewController : UIViewController <UIGestureRecognizerDelegate, WKNavigationDelegate>
- (void)viewDidLoad;
- (void)viewDidAppear:(BOOL)animated;
@property (nonatomic, readonly) BOOL prefersStatusBarHidden;
- (void)registerBackgroundTask;
- (void)endBackgroundTask;
- (void)webView:(WKWebView * _Nonnull)webView didFailNavigation:(WKNavigation * _Null_unspecified)navigation withError:(NSError * _Nonnull)error;
- (void)webView:(WKWebView * _Nonnull)webView didFailProvisionalNavigation:(WKNavigation * _Null_unspecified)navigation withError:(NSError * _Nonnull)error;
- (void)webView:(WKWebView * _Nonnull)webView didStartProvisionalNavigation:(WKNavigation * _Null_unspecified)navigation;
- (void)webView:(WKWebView * _Nonnull)didFinishwebView didFinishNavigation:(WKNavigation * _Null_unspecified)navigation;
- (void)webView:(WKWebView * _Nonnull)webView decidePolicyForNavigationAction:(WKNavigationAction * _Nonnull)navigationAction decisionHandler:(void (^ _Nonnull)(WKNavigationActionPolicy))decisionHandler;
- (BOOL)gestureRecognizer:(UIGestureRecognizer * _Nonnull)gestureRecognizer shouldReceiveTouch:(UITouch * _Nonnull)touch SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11YouAppiMoat7YouAppi")
@interface YouAppi : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) YouAppi * _Nonnull sharedInstance;)
+ (YouAppi * _Nonnull)sharedInstance SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, copy) NSString * _Nonnull environment;
@property (nonatomic, copy) NSString * _Nonnull accessToken;
@property (nonatomic) BOOL userConsent;
@property (nonatomic) BOOL ageRestrictedUser;
+ (void)initializeWithAccessToken:(NSString * _Nonnull)accessToken userConsent:(BOOL)userConsent;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic) BOOL isInitialized;
- (YAAdCard * _Nullable)interstitialAd:(NSString * _Nonnull)adUnitID;
- (YAAdRewardedVideo * _Nullable)rewardedVideo:(NSString * _Nonnull)adUnitID SWIFT_WARN_UNUSED_RESULT;
- (YAAdInterstitialVideo * _Nullable)interstitialVideo:(NSString * _Nonnull)adUnitID SWIFT_WARN_UNUSED_RESULT;
- (YAAdLogger * _Nullable)log SWIFT_WARN_UNUSED_RESULT;
- (void)logLevel:(enum YALogLevel)logLevel;
- (NSString * _Null_unspecified)version SWIFT_WARN_UNUSED_RESULT SWIFT_DEPRECATED_MSG("please use YouAppi.sdkVersion() method instead");
+ (NSString * _Nonnull)sdkVersion SWIFT_WARN_UNUSED_RESULT;
- (void)showLog;
+ (NSString * _Nonnull)getBuildType SWIFT_WARN_UNUSED_RESULT;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
//
//  TapdaqUnityIOS.m
//  TapdaqUnity
//
//  Created by Rheo Violenes on 05/05/15.
//  Copyright (c) 2015 Nerd. All rights reserved.
//
#import "TapdaqUnityIOS.h"
#import "TapdaqDelegates.h"
#import "TapdaqStandardAd.h"
#import "JsonHelper.h"

static NSString *const kTapdaqLogPrefix = @"[TapdaqUnity]";

// Helper method to create C string copy
char* makeStringCopy (const char* string)
{
    if (string == NULL)
        return NULL;
    
    char* res = (char*)malloc(strlen(string) + 1);
    strcpy(res, string);
    return res;
}

void _ConfigureTapdaq(const char* appIdChar,
                      const char* clientKeyChar,
                      const char* testDevicesChar,
                      bool isDebugMode,
                      bool autoReloadAds,
                      const char* pluginVersion,
                      int isUserSubjectToGDPR,
                      int isConsentGiven,
                      int isAgeRestrictedUser,
                      const char* userIdChar,
                      bool forwardUserId) {
    
    bool isValid = true;
    
    if (_isEmpty(appIdChar)) {
        NSLog(@"%@ iOS App ID is empty", kTapdaqLogPrefix);
        isValid = false;
    }
    
    if (_isEmpty(clientKeyChar)) {
        NSLog(@"%@ iOS Client Key is empty", kTapdaqLogPrefix);
        isValid = false;
    }
    
    if (!isValid) {
        NSLog(@"%@ Tapdaq did not initialise", kTapdaqLogPrefix);
        return;
    }
    
    NSString *appId = [[NSString stringWithUTF8String:appIdChar] copy];
    NSString *clientKey = [[NSString stringWithUTF8String:clientKeyChar] copy];
    NSString *testDevices = [[NSString stringWithUTF8String:testDevicesChar] copy];
    NSString *version = [[NSString stringWithUTF8String:pluginVersion] copy];
    
    NSString *userId = nil;
    
    if (!_isEmpty(userIdChar)) {
        userId = [[NSString stringWithUTF8String:userIdChar] copy];
    }
    
    [[TapdaqUnityIOS sharedInstance] initWithApplicationId:appId
                                                 clientKey:clientKey
                                               testDevices:testDevices
                                               isDebugMode:isDebugMode
                                             autoReloadAds:autoReloadAds
                                             pluginVersion:version
                                       isUserSubjectToGDPR:isUserSubjectToGDPR
                                            isConsentGiven:isConsentGiven
                                       isAgeRestrictedUser:isAgeRestrictedUser
                                                    userId:userId
                                       shouldForwardUserId:forwardUserId];
    
}

void _SetDelegate() {
    [[TapdaqUnityIOS sharedInstance] setDelegate];
}

bool _IsInitialised() {
    return  [[TapdaqUnityIOS sharedInstance] IsInitialised];
}

void _SetUserSubjectToGDPR(int userSubjectToGDPR) {
    [[TapdaqUnityIOS sharedInstance] setUserSubjectToGDPR:userSubjectToGDPR];
}

int _UserSubjectToGDPR() {
    return (int)[[TapdaqUnityIOS sharedInstance] userSubjectToGDPR];
}

void _SetGdprConsent(int gdprConsent) {
    [[TapdaqUnityIOS sharedInstance] setGdprConsent:gdprConsent];
}

int _GdprConsent() {
    return (int)[[TapdaqUnityIOS sharedInstance] gdprConsent];
}

void _SetAgeRestrictedUser(int ageRestrictedUser) {
    [[TapdaqUnityIOS sharedInstance] setAgeRestrictedUser:ageRestrictedUser];
}

int _AgeRestrictedUser() {
    return (int)[[TapdaqUnityIOS sharedInstance] ageRestrictedUser];
}

void _SetUserSubjectToUSPrivacy(int userSubjectToUSPrivacy) {
    [[TapdaqUnityIOS sharedInstance] setUserSubjectToUSPrivacy:userSubjectToUSPrivacy];
}

int _UserSubjectToUSPrivacy() {
    return (int)[[TapdaqUnityIOS sharedInstance] userSubjectToUSPrivacy];
}

void _SetUSPrivacy(int usPrivacy) {
    [[TapdaqUnityIOS sharedInstance] setUSPrivacy:usPrivacy];
}

int _USPrivacy() {
    return (int)[[TapdaqUnityIOS sharedInstance] usPrivacy];
}

void _SetAdMobContentRating(const char * rating) {
    NSString *ratingStr = [[NSString stringWithUTF8String:rating] copy];
    [[TapdaqUnityIOS sharedInstance] setAdMobContentRating:ratingStr];
}

const char * _GetAdMobContentRating() {
    NSString * ratingStr = [[[TapdaqUnityIOS sharedInstance] getAdMobContentRating] copy];
    return makeStringCopy([ratingStr UTF8String]);
}

void _SetUserId(const char * userId) {
    NSString *userStr = nil;
    if (!_isEmpty(userId)) {
        userStr = [[NSString stringWithUTF8String:userId] copy];
    }
    [[TapdaqUnityIOS sharedInstance] setUserId:userStr];
}

const char * _GetUserId() {
    NSString * userIdStr = [[[TapdaqUnityIOS sharedInstance] getUserId] copy];
    return makeStringCopy([userIdStr UTF8String]);
}

void _SetForwardUserId(bool forwardUserId) {
    [[TapdaqUnityIOS sharedInstance] setForwardUserId:forwardUserId];
}

bool _ShouldForwardUserId() {
    return (bool)[[TapdaqUnityIOS sharedInstance] shouldForwardUserId];
}

void _SetMuted(bool muted) {
    [[TapdaqUnityIOS sharedInstance] setMuted:muted];
}

bool _IsMuted() {
    return (bool)[[TapdaqUnityIOS sharedInstance] isMuted];
}

void _SetUserDataString(const char* key, const char* value) {
    NSString *keyStr = nil;
    NSString *valueStr = nil;
    if (!_isEmpty(key) && !_isEmpty(value)) {
        keyStr = [[NSString stringWithUTF8String:key] copy];
        valueStr = [[NSString stringWithUTF8String:value] copy];
    }
    [[TapdaqUnityIOS sharedInstance] setUserDataString:valueStr forKey:keyStr];
}

void _SetUserDataInteger(const char* key, int value) {
    NSString *keyStr = nil;
    if (!_isEmpty(key)) {
        keyStr = [[NSString stringWithUTF8String:key] copy];
    }
    
    [[TapdaqUnityIOS sharedInstance] setUserDataInteger:value forKey:keyStr];
}

void _SetUserDataBoolean(const char* key, bool value) {
    NSString *keyStr = nil;
    if (!_isEmpty(key)) {
        keyStr = [[NSString stringWithUTF8String:key] copy];
    }
    
    [[TapdaqUnityIOS sharedInstance] setUserDataBoolean:value forKey:keyStr];
}

const char* _GetUserDataString(const char* key) {
    NSString *keyStr = nil;
    if (!_isEmpty(key)) {
        keyStr = [[NSString stringWithUTF8String:key] copy];
    }
    
    NSString * dataStr = [[[TapdaqUnityIOS sharedInstance] userDataStringForKey:keyStr] copy];
    return makeStringCopy([dataStr UTF8String]);
}

int _GetUserDataInteger(const char* key) {
    NSString *keyStr = nil;
    if (!_isEmpty(key)) {
        keyStr = [[NSString stringWithUTF8String:key] copy];
    }
    
    return (int)[[TapdaqUnityIOS sharedInstance] userDataIntegerForKey:keyStr];
}

bool _GetUserDataBoolean(const char* key) {
    NSString *keyStr = nil;
    if (!_isEmpty(key)) {
        keyStr = [[NSString stringWithUTF8String:key] copy];
    }
    
    return (bool)[[TapdaqUnityIOS sharedInstance] userDataBooleanForKey:keyStr];
}

const char* _GetAllUserData() {
    NSString * dataStr = [[[TapdaqUnityIOS sharedInstance] userData] copy];
    return makeStringCopy([dataStr UTF8String]);
}

void _RemoveUserData(const char* key) {
    NSString *keyStr = nil;
    if (!_isEmpty(key)) {
        keyStr = [[NSString stringWithUTF8String:key] copy];
    }
    
    [[TapdaqUnityIOS sharedInstance] removeUserDataForKey:keyStr];
}

#pragma mark - Banner (Bridge)

void _LoadBannerForSize(const char* tagChar, const char* sizeChar) {
    
    if (_isEmpty(sizeChar)) {
        NSLog(@"%@ No banner size specified, cannot load banner", kTapdaqLogPrefix);
        return;
    }
    
    NSString *tagStr = [[NSString stringWithUTF8String:tagChar] copy];
    NSString *sizeStr = [[NSString stringWithUTF8String:sizeChar] copy];
    
    [[TapdaqBannerAd sharedInstance] loadForPlacementTag:tagStr withSize:sizeStr];
}

void _LoadBannerWithSize(const char* tagChar, int width, int height) {
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, cannot load banner", kTapdaqLogPrefix);
        return;
    }
    
    NSString *tagStr = [[NSString stringWithUTF8String:tagChar] copy];
    CGSize size = CGSizeMake(width, height);
    
    [[TapdaqBannerAd sharedInstance] loadForPlacementTag:tagStr withCustomSize:size];
}

bool _IsBannerReady(const char* tagChar) {
    NSString *tagStr = [[NSString stringWithUTF8String:tagChar] copy];
    return (bool) [[TapdaqBannerAd sharedInstance] isReadyForPlacementTag:tagStr];
    
}

void _ShowBanner(const char* tagChar, const char* position) {
    
    if (_isEmpty(position)) {
        NSLog(@"%@ No banner position given, failed to show banner", kTapdaqLogPrefix);
        return;
    }
    NSString *tagStr = [[NSString stringWithUTF8String:tagChar] copy];
    [[TapdaqBannerAd sharedInstance] showForPlacementTag:tagStr withPosition:position];
    
}

void _ShowBannerWithPosition(const char* tagChar, int x, int y) {
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to show banner", kTapdaqLogPrefix);
        return;
    }
    NSString *tagStr = [[NSString stringWithUTF8String:tagChar] copy];
    [[TapdaqBannerAd sharedInstance] showForPlacementTag:tagStr atPositionX:x atPositionY:y];
}

void _HideBanner(const char* tagChar) {
    NSString *tagStr = [[NSString stringWithUTF8String:tagChar] copy];
    [[TapdaqBannerAd sharedInstance] hideForPlacementTag:tagStr];
}

void _DestroyBanner(const char* tagChar) {
    NSString *tagStr = [[NSString stringWithUTF8String:tagChar] copy];
    [[TapdaqBannerAd sharedInstance] destroyForPlacementTag:tagStr];
}

#pragma mark - Interstitial (Bridge)

void _LoadInterstitialWithTag(const char *tagChar) {
    
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to load interstitial", kTapdaqLogPrefix);
        return;
    }
    
    NSString *tag = [NSString stringWithUTF8String:tagChar];
    
    [[TapdaqInterstitialAd sharedInstance] loadForPlacementTag:tag];
    
}

bool _IsInterstitialReadyWithTag(const char *tagChar) {
    
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to check if interstitial is ready", kTapdaqLogPrefix);
        return false;
    }
    
    NSString *tag = [NSString stringWithUTF8String:tagChar];
    
    return (bool) [[TapdaqInterstitialAd sharedInstance] isReadyForPlacementTag:tag];
    
}

const char *_GetInterstitialFrequencyCapError(const char* tag) {
    NSString *placementTag = [NSString stringWithUTF8String:tag];
    TDError* error = [[Tapdaq sharedSession] interstitialCappedForPlacementTag:placementTag];
    
    NSString* result = [JsonHelper toJsonString:@{
        @"code": @(error.code),
        @"message": (error.localizedDescription == nil ? @"" : error.localizedDescription)
    }];
    
    return makeStringCopy([result UTF8String]);
}

void _ShowInterstitialWithTag(const char* tagChar) {
    
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to show interstitial", kTapdaqLogPrefix);
        return;
    }
    
    NSString *tag = [NSString stringWithUTF8String:tagChar];
    
    [[TapdaqInterstitialAd sharedInstance] showForPlacementTag:tag];
    
}

#pragma mark - Video (Bridge)

void _LoadVideoWithTag(const char *tagChar) {
    
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to load video", kTapdaqLogPrefix);
        return;
    }
    
    NSString *tag = [NSString stringWithUTF8String:tagChar];
    
    [[TapdaqVideoAd sharedInstance] loadForPlacementTag:tag];
    
}

bool _IsVideoReadyWithTag(const char *tagChar) {
    
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to check if video is ready", kTapdaqLogPrefix);
        return false;
    }
    
    NSString *tag = [NSString stringWithUTF8String:tagChar];
    
    return (bool) [[TapdaqVideoAd sharedInstance] isReadyForPlacementTag:tag];
    
}

const char *_GetVideoFrequencyCapError(const char* tag) {
    NSString *placementTag = [NSString stringWithUTF8String:tag];
    TDError* error = [[Tapdaq sharedSession] videoCappedForPlacementTag:placementTag];
    
    NSString* result = [JsonHelper toJsonString:@{
        @"code": @(error.code),
        @"message": (error.localizedDescription == nil ? @"" : error.localizedDescription)
    }];
    
    return makeStringCopy([result UTF8String]);
}

void _ShowVideoWithTag(const char* tagChar) {
    
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to show video", kTapdaqLogPrefix);
        return;
    }
    
    NSString *tag = [NSString stringWithUTF8String:tagChar];
    
    [[TapdaqVideoAd sharedInstance] showForPlacementTag:tag];
    
}

#pragma mark - Rewarded Video (Bridge)

void _LoadRewardedVideoWithTag(const char *tagChar) {
    
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to load rewarded video", kTapdaqLogPrefix);
        return;
    }
    
    NSString *tag = [NSString stringWithUTF8String:tagChar];
    
    [[TapdaqRewardedVideoAd sharedInstance] loadForPlacementTag:tag];
    
}

bool _IsRewardedVideoReadyWithTag(const char *tagChar) {
    
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to check if rewarded video is ready", kTapdaqLogPrefix);
        return false;
    }
    
    NSString *tag = [NSString stringWithUTF8String:tagChar];
    
    return (bool) [[TapdaqRewardedVideoAd sharedInstance] isReadyForPlacementTag:tag];
    
}

const char *_GetRewardedVideoFrequencyCapError(const char* tag) {
    NSString *placementTag = [NSString stringWithUTF8String:tag];
    TDError* error = [[Tapdaq sharedSession] rewardedVideoCappedForPlacementTag:placementTag];
    
    NSString* result = [JsonHelper toJsonString:@{
        @"code": @(error.code),
        @"message": (error.localizedDescription == nil ? @"" : error.localizedDescription)
    }];
    
    return makeStringCopy([result UTF8String]);
}

void _ShowRewardedVideoWithTag(const char* tagChar, const char* hashedUserIdChar) {
    
    if (_isEmpty(tagChar)) {
        NSLog(@"%@ No tag given, failed to show rewarded video", kTapdaqLogPrefix);
        return;
    }
    
    NSString *tag = [NSString stringWithUTF8String:tagChar];
    NSString *hashedUserId = (hashedUserIdChar != nil ? [NSString stringWithUTF8String:hashedUserIdChar] : nil);
    
    [[TapdaqRewardedVideoAd sharedInstance] showForPlacementTag:tag withHashedUserId:hashedUserId];
    
}

#pragma mart - Stats

void _SendIAP(const char* transationId, const char* productId, const char* name, double price, const char* currency, const char* locale) {
    NSString *transactionIdString;
    NSString *productIdString;
    NSString *currencyString;
    NSString *nameString;
    NSString *localeString;
    
    if (transationId != NULL) {
        transactionIdString = [NSString stringWithUTF8String:transationId];
    }
    
    if (productId != NULL) {
        productIdString = [NSString stringWithUTF8String:productId];
    }
    
    if (currency != NULL) {
        currencyString = [NSString stringWithUTF8String:currency];
    }
    
    if (name != NULL) {
        nameString = [NSString stringWithUTF8String:name];
    }
    
    if (locale != NULL) {
        localeString = [NSString stringWithUTF8String:locale];
    }
    
    [[Tapdaq sharedSession] trackPurchaseForProductName:nameString
                                                  price:price
                                            priceLocale:localeString
                                               currency:currencyString
                                          transactionId:transactionIdString
                                              productId:productIdString];
}

const char *_GetRewardId(const char* tag) {
    NSString *placementTag = [NSString stringWithUTF8String:tag];
    NSString *rewardId = [[Tapdaq sharedSession] rewardIdForPlacementTag:placementTag];
    return [rewardId cStringUsingEncoding:NSUTF8StringEncoding];
}

void _LaunchMediationDebugger() {
    [[Tapdaq sharedSession] presentDebugViewController];
}

bool _isEmpty(const char* str) {
    return str == NULL;
}

@implementation TapdaqUnityIOS

+ (instancetype)sharedInstance
{
    static dispatch_once_t once;
    static id sharedInstance;
    dispatch_once(&once, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

+ (void)load
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(createPlugin:) name:UIApplicationDidFinishLaunchingNotification object:nil];
}

+ (void)createPlugin:(NSNotification *)notification
{
    [TapdaqUnityIOS sharedInstance];
}

// Init
//Configure Tapdaq with credentials and ad settings
- (void)initWithApplicationId:(NSString *)appID
                    clientKey:(NSString *)clientKey
                  testDevices:(NSString *)testDevices
                  isDebugMode:(bool)isDebugMode
                autoReloadAds:(bool)autoReloadAds
                pluginVersion:(NSString *)pluginVersion
          isUserSubjectToGDPR:(int)isUserSubjectToGDPR
               isConsentGiven:(int)isConsentGiven
          isAgeRestrictedUser:(int)isAgeRestrictedUser
                       userId:(NSString *)userId
                shouldForwardUserId:(bool)forwardUserId
{
    TDProperties *properties = [TDProperties defaultProperties];
    [properties setPluginVersion:pluginVersion];
    properties.isDebugEnabled = isDebugMode;
    properties.logLevel = isDebugMode ? TDLogLevelDebug : TDLogLevelInfo;
    [properties setAutoReloadAds:autoReloadAds];
    properties.userId = userId;
    properties.forwardUserId = forwardUserId;

    if (isConsentGiven != 2) {
        properties.isConsentGiven = (BOOL)isConsentGiven;
    }
    if (isAgeRestrictedUser != 2) {
        properties.isAgeRestrictedUser = isAgeRestrictedUser;
    }
    properties.userSubjectToGDPR = isUserSubjectToGDPR;
    
    [self setTestDevices: testDevices toProperties:properties];
    
    [[Tapdaq sharedSession] setApplicationId:appID
                                   clientKey:clientKey
                                  properties:properties];
}
    
- (void) setDelegate {
    [[Tapdaq sharedSession] setDelegate: [TapdaqDelegates sharedInstance]];
}

- (BOOL) IsInitialised
{
    return [[Tapdaq sharedSession] isInitialised];
}

- (void) setUserSubjectToGDPR:(int)userSubjectToGDPR {
    [[[[Tapdaq sharedSession] properties] privacySettings] setUserSubjectToGdpr:userSubjectToGDPR];
}

- (int) userSubjectToGDPR {
    return (int)[[[[Tapdaq sharedSession] properties] privacySettings] userSubjectToGdpr];
}

- (void) setGdprConsent:(int)gdprConsent
{
    [[[[Tapdaq sharedSession] properties] privacySettings] setGdprConsentGiven:gdprConsent];
}

- (int) gdprConsent
{
    return (int)[[[[Tapdaq sharedSession] properties] privacySettings] gdprConsentGiven];
}

- (void) setAgeRestrictedUser:(int)ageRestrictedUser
{
    [[[[Tapdaq sharedSession] properties] privacySettings] setAgeRestrictedUser:ageRestrictedUser];
}

- (int) ageRestrictedUser
{
    return (int)[[[[Tapdaq sharedSession] properties] privacySettings] ageRestrictedUser];
}

- (void) setUserSubjectToUSPrivacy:(int)userSubjectToUSPrivacy
{
    [[[[Tapdaq sharedSession] properties] privacySettings] setUserSubjectToUSPrivacy:userSubjectToUSPrivacy];
}

- (int) userSubjectToUSPrivacy
{
    return (int)[[[[Tapdaq sharedSession] properties] privacySettings] userSubjectToUSPrivacy];
}

- (void) setUSPrivacy:(int)usPrivacy
{
    [[[[Tapdaq sharedSession] properties] privacySettings] setUsPrivacyDoNotSell:usPrivacy];
}

- (int) usPrivacy
{
    return (int)[[[[Tapdaq sharedSession] properties] privacySettings] usPrivacyDoNotSell];
}

- (void) setAdMobContentRating:(NSString*)rating
{
    [[Tapdaq sharedSession] setAdMobContentRating:rating];
}

- (NSString*) getAdMobContentRating
{
    return [[Tapdaq sharedSession] adMobContentRating];
}

- (void) setUserId:(NSString*)userId
{
     [[Tapdaq sharedSession] setUserId:userId];
}

- (NSString*) getUserId
{
    return [[Tapdaq sharedSession] userId];
}

- (void) setForwardUserId:(BOOL)forwardUserId
{
   [[Tapdaq sharedSession] setForwardUserId:forwardUserId];
}

- (BOOL) shouldForwardUserId
{
   return [[Tapdaq sharedSession] forwardUserId];
}

- (void) setMuted:(BOOL)muted
{
    [[[Tapdaq sharedSession] properties] setMuted:muted];
}

- (BOOL) isMuted
{
   return [[[Tapdaq sharedSession] properties] isMuted];
}

- (void) setUserDataString:(NSString*)value forKey:(NSString*)key
{
    [[[Tapdaq sharedSession] properties] setUserDataString:value forKey:key];
}
    
- (void) setUserDataBoolean:(BOOL)value forKey:(NSString*)key
{
    [[[Tapdaq sharedSession] properties] setUserDataBool:value forKey:key];
}

- (void) setUserDataInteger:(NSInteger)value forKey:(NSString*)key
{
    [[[Tapdaq sharedSession] properties] setUserDataInteger:value forKey:key];
}

- (NSString*) userDataStringForKey:(NSString*) key {
    return [[[Tapdaq sharedSession] properties] userDataStringForKey:key];
}

- (NSInteger) userDataIntegerForKey:(NSString*) key {
    return [[[Tapdaq sharedSession] properties] userDataIntegerForKey:key];
}

- (BOOL) userDataBooleanForKey:(NSString*) key {
    return [[[Tapdaq sharedSession] properties] userDataBoolForKey:key];
}

- (NSString*) userData {
    return [JsonHelper toJsonString:[[[Tapdaq sharedSession] properties] userData]];
}

- (void) removeUserDataForKey:(NSString*) key {
    [[[Tapdaq sharedSession] properties] removeUserDataForKey:key];
}

- (void) setTestDevices:(NSString *)testDevicesJson toProperties:(TDProperties *)properties
{
    NSData *data = [testDevicesJson dataUsingEncoding:NSUTF8StringEncoding];
    
    NSError *error = nil;
    NSDictionary *testDevicesDictionary = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
    
    if(error == nil) {
        NSArray* amArray = testDevicesDictionary[@"adMobDevices"];
        NSArray* fbArray = testDevicesDictionary[@"facebookDevices"];
        
        if(amArray != nil) {
            TDTestDevices *amTestDevices = [[TDTestDevices alloc] initWithNetwork:@"admob" testDevices:amArray];
            [properties registerTestDevices: amTestDevices];
        }
        
        if(fbArray != nil) {
            TDTestDevices *fbTestDevices = [[TDTestDevices alloc] initWithNetwork:@"facebook" testDevices:fbArray];
            [properties registerTestDevices: fbTestDevices];
        }
    }
}

@end

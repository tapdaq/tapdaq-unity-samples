#import <Foundation/Foundation.h>
#import <Tapdaq/Tapdaq.h>
#import "TDUnityDelegateBase.h"

@interface TapdaqStandardAd : TDUnityDelegateBase <TDAdRequestDelegate, TDDisplayableAdRequestDelegate, TDClickableAdRequestDelegate>

- (NSString*) type;
- (BOOL)isReady;
- (void)show;
- (void)load;

- (void)loadForPlacementTag:(NSString *)tag;
- (BOOL)isReadyForPlacementTag:(NSString *)tag;
- (void)showForPlacementTag:(NSString *)tag;
- (void)showForPlacementTag:(NSString *) tag withHashedUserId:(NSString *) hashedUserId;

@end

@interface TapdaqVideoAd : TapdaqStandardAd
@end

@interface TapdaqRewardedVideoAd : TapdaqStandardAd<TDRewardedVideoAdRequestDelegate>
@end

@interface TapdaqInterstitialAd : TapdaqStandardAd
@end

@interface TapdaqBannerAd : TapdaqStandardAd<TDBannerAdRequestDelegate>

- (void)loadForPlacementTag:(NSString*)tag withSize:(NSString *)sizeStr;
- (void)loadForPlacementTag:(NSString*)tag withCustomSize:(CGSize)size;
- (void)hideForPlacementTag:(NSString*)tag;
- (void)destroyForPlacementTag:(NSString*)tag;
- (void)showForPlacementTag:(NSString*)tag withPosition:(const char *)position;
- (void)showForPlacementTag:(NSString*)tag atPositionX:(int)x atPositionY:(int)y;

@end

//
//  TDAdTypePlacement.h
//  Tapdaq
//
//  Created by Tapdaq <support@tapdaq.com>
//  Copyright (c) 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TDAdTypeEnum.h"
#import "TDNativeAdTypeEnum.h"

// Default.
extern NSString *const TDPTagDefault;
// Bootup - Initial bootup of game.
extern NSString *const TDPTagBootup;
// Home Screen - Home screen the player first sees.
extern NSString *const TDPTagHomeScreen;
// Main Menu - Menu that provides game options.
extern NSString *const TDPTagMainMenu;
// Pause - Pause screen.
extern NSString *const TDPTagPause;
// Level Start - Start of the level.
extern NSString *const TDPTagLevelStart;
// Level Complete - Completion of the level.
extern NSString *const TDPTagLevelComplete;
// Game Center - After a user visits the Game Center.
extern NSString *const TDPTagGameCenter;
// IAP Store - The store where the player pays real money for currency or items.
extern NSString *const TDPTagIAPStore;
// Item Store - The store where a player buys virtual goods.
extern NSString *const TDPTagItemStore;
// Game Over - The game over screen after a player is finished playing.
extern NSString *const TDPTagGameOver;
// Leaderboard - List of leaders in the game.
extern NSString *const TDPTagLeaderBoard;
// Settings - Screen where player can change settings such as sound.
extern NSString *const TDPTagSettings ;
// Quit - Screen displayed right before the player exits a game.
extern NSString *const TDPTagQuit;

@interface TDPlacement : NSObject <NSCopying>

@property (nonatomic, readonly) TDAdTypes adTypes;
@property (nonatomic, readonly) NSString *tag;

+ (instancetype)defaultPlacementForAdTypes:(TDAdTypes)adTypes;
+ (instancetype)placementWithAdTypes:(TDAdTypes)adTypes tag:(NSString *)tag;

- (instancetype)initWithAdTypes:(TDAdTypes)adTypes forTag:(NSString *)tag;
- (instancetype)initWithDefaultPlacementForAdTypes:(TDAdTypes)adTypes;

+ (BOOL)isValidTag:(NSString *)tag;
@end

@interface TDPlacement (NativeAds)
+ (instancetype)defaultPlacementForNativeAdType:(TDNativeAdType)nativeAdType;
+ (instancetype)placementWithNativeAdType:(TDNativeAdType)nativeAdType tag:(NSString *)tag;

- (instancetype)initWithNativeAdType:(TDNativeAdType)nativeAdType forTag:(NSString *)tag;
- (instancetype)initWithDefaultPlacementForNativeAdType:(TDNativeAdType)nativeAdType;
@end

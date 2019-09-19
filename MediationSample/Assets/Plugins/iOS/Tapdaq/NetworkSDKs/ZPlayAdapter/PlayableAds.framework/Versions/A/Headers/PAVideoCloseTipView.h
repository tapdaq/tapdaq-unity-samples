//
//  PAVideoCloseTipView.h
//  PlayableAds
//
//  Created by Michael Tang on 2018/5/30.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, PAVideoActionState) {
    kPAVideoActionClose = 1 << 0,
    kPAVideoActionContinue = 1 << 1,
};

typedef void (^PAVideoActionStateBlock)(PAVideoActionState);

@interface PAVideoCloseTipView : UIView

- (void)implementClickAction:(PAVideoActionStateBlock)actionStateBlock;
// 旋转bgview
- (void)setBgViewAffineTransform:(UIInterfaceOrientationMask)vcOrientation
         playablePageOrientation:(UIInterfaceOrientationMask)paOrientation;
- (void)resumeRotation;

@end

//
//  PACountdownCloseView.h
//  Pods
//
//  Created by Michael Tang on 2018/7/4.
//

#import <UIKit/UIKit.h>

typedef void (^CloseActionBlock)(void);

@interface PACountdownCloseView : UIView

- (void)handleAction:(CloseActionBlock)completed;
- (void)layoutSubviewUI;
- (void)showCountdownLabel:(int)interval;
- (void)setCountdownLabelAffineTransform:(UIInterfaceOrientationMask)vcOrientation
                 playablePageOrientation:(UIInterfaceOrientationMask)paOrientation;

@end

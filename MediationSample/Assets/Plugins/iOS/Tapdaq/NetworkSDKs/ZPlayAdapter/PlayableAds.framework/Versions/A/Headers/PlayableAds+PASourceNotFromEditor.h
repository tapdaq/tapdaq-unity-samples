//
//  PlayableAds+PASourceNotFromEditor.h
//  PlayableAds
//
//  Created by Michael Tang on 2018/12/19.
//

#import "PlayableAds.h"

@class PASourceNotEditorViewController;

@interface PlayableAds (PASourceNotFromEditor)

- (void)cacheAdHtmlIfNotEditor;
- (void)presentIfNotEditor;

@end

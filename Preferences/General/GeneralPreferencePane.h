//
//  PreferencePane.h
//  Preferences
//
//  Created by Vincent Spader on 9/4/06.
//  Copyright 2006 Vincent Spader. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PreferencePanePlugin.h"

@interface GeneralPreferencePane : NSObject <PreferencePane> {
	NSView *view;
	
	NSString *title;
	NSImage *icon;
}

+ (GeneralPreferencePane *)preferencePaneWithView:(NSView *)v title:(NSString *)t iconNamed:(NSImageName)i;
@property (strong) IBOutlet NSView *view;
@property (copy) NSString *title;
@property (strong) NSImage *icon;

@end

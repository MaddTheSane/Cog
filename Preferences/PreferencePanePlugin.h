//
//  PreferencePanePlugin.h
//  Cog
//
//  Created by Vincent Spader on 3/7/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@protocol PreferencePane;
@protocol PreferencePanePlugin <NSObject> 
@required

// An array of PrefPaneController instances that the plugin has available
+ (NSArray<id<PreferencePane>> *)preferencePanes;

@end

@protocol PreferencePane <NSObject>
@required

@property (readonly, strong) NSView *view;
@property (readonly, copy) NSString *title;
@property (readonly, strong) NSImage *icon;

@end

//
//  PreferencePane.m
//  Preferences
//
//  Created by Vincent Spader on 9/4/06.
//  Copyright 2006 Vincent Spader. All rights reserved.
//

#import "GeneralPreferencePane.h"


@implementation GeneralPreferencePane

+ (GeneralPreferencePane *)preferencePaneWithView:(NSView *)v title:(NSString *)t iconNamed:(NSString *)n
{
	GeneralPreferencePane *pane = [[GeneralPreferencePane alloc] init];
	if (pane)
	{
		[pane setView:v];
		[pane setTitle:t];

		NSImage *i = [[NSBundle bundleForClass:[self class]] imageForResource:n];
		[pane setIcon:i];
	}
	
	return pane;
}

@synthesize view;
@synthesize title;
@synthesize icon;

@end

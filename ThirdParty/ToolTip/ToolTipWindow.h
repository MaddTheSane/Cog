//
//  ToolTip.h
//  Cog
//
//  Created by Vincent Spader on 2/8/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

// From http://www.cocoadev.com/index.pl?ToolTip

#import <AppKit/AppKit.h>

@interface ToolTipWindow : NSWindow
{
	id closeTimer;
    id tooltipObject;

//	NSColor *backgroundColor;
	NSDictionary *textAttributes;
}

// returns the approximate window size needed to display the tooltip string.
- (NSSize)suggestedSizeForTooltip:(id)tooltip;

// setting and getting the bgColor
//@property (copy) NSColor *backgroundColor;

- (instancetype)init;

@property (nonatomic, strong) id toolTip;

- (void)orderFront;
- (void)orderFrontForDuration:(NSTimeInterval)duration;

@end


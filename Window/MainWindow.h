//
//  MainWindow.h
//  Cog
//
//  Created by Vincent Spader on 2/22/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "DualWindow.h"

@interface MainWindow : DualWindow {
    IBOutlet NSMenuItem * itemLionSeparator;
    IBOutlet NSMenuItem * itemLionFullscreenToggle;
}

@end

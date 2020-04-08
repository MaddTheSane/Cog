///**********************************************************************************************************************************
///  GCWindowMenu.h
///  GCDrawKitUI
///
///  Created by graham on 27/03/07.
///  Released under the Creative Commons license 2006 Apptree.net.
///
/// 
///  This work is licensed under the Creative Commons Attribution-ShareAlike 2.5 License.
///  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/2.5/ or send a letter to
///  Creative Commons, 543 Howard Street, 5th Floor, San Francisco, California, 94105, USA.
///
///**********************************************************************************************************************************

#import <Cocoa/Cocoa.h>


@interface GCWindowMenu : NSWindow
{
	NSView*			_mainView;
	BOOL			_passFirstClick;
	BOOL			_oneShotTracking;
}

+ (GCWindowMenu*)	windowMenu;
+ (GCWindowMenu*)   windowMenuWithContentView:(NSView*) view;

- (void)			popUpAtPoint:(NSPoint) p withEvent:(NSEvent*) event;
- (void)			popUpWithEvent:(NSEvent*) event;

- (void)			setMainView:(NSView*) aView sizeToFit:(BOOL) stf;
@property (readonly, retain) NSView *mainView;

/*!
 * Sets whether the main view should receive a mouse down on entry to the tracking loop
 *
 * @discussion normally should be YES (the default). However views such as NSControl derivatives that implement
 * their own tracking should set NO. If NO, the popup can only be operated by clicking to open, then
 * clicking and dragging within - the continuous click to open, drag through and release operation
 * wont work because the control doesn't get a mouse down to start with.
 */
@property BOOL mainViewWantsFirstClick;

/*!
 * Sets whether popup should close or remain visible after main view completes its own tracking.
 * @discussion this affects tracking with views that implement their own tracking, such as NSControl. If YES, you
 * get one shot at the control - after operating it, it will be hidden. If NO, the control may be
 * changed as often as you want but you must manually click outside the menu to close it.
 */
@property BOOL shouldCloseWhenViewTrackingReturns;

@end


@interface NSEvent (GCAdditions)

@property (readonly, getter=isMouseEventType) BOOL mouseEventType;

@end

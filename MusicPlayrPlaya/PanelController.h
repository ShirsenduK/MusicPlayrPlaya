#import "BackgroundView.h"
#import "StatusItemView.h"
#import "MPWebView.h"
#import <WebKit/WebKit.h>
#import <AppKit/AppKit.h>

@class PanelController;

@protocol PanelControllerDelegate <NSObject>

@optional

- (StatusItemView *)statusItemViewForPanelController:(PanelController *)controller;

@end

#pragma mark -

@interface PanelController : NSWindowController <NSWindowDelegate, WebPolicyDecisionListener, NSMenuDelegate>
{
    BOOL _hasActivePanel;
    BackgroundView *_backgroundView;
    id<PanelControllerDelegate> _delegate;
    NSButton *_button;
    MPWebView *_webview;
    IBOutlet NSMenu *statusMenu;
    NSStatusItem * statusItem;
    
}

@property (assign) IBOutlet BackgroundView *backgroundView;
@property (assign) IBOutlet NSButton *button;
@property (assign) IBOutlet MPWebView *webview;

- (void)openMenu;
@property (nonatomic, assign) BOOL hasActivePanel;
@property (nonatomic, readonly) id<PanelControllerDelegate> delegate;

- (id)initWithDelegate:(id<PanelControllerDelegate>)delegate;

- (void)openPanel;
- (void)closePanel;
- (NSRect)statusRectForWindow:(NSWindow *)window;
-(IBAction) refreshClicked: (id) sender;
-(void) refreshWebsite;
@end

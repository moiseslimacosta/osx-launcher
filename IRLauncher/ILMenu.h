//
//  ILMenu.h
//  IRLauncher
//
//  Created by Masakazu Ohtsuka on 2014/01/30.
//  Copyright (c) 2014年 Masakazu Ohtsuka. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ILMenuCheckboxView.h"
#import "ILMenuButtonView.h"

@protocol ILMenuDelegate;

@interface ILMenu : NSMenu<NSMenuDelegate, ILMenuButtonViewDelegate>

@property (nonatomic, weak) id<ILMenuCheckboxViewDelegate> checkboxDelegate;
@property (nonatomic, weak) id<ILMenuDelegate> menuDelegate;

- (void)setSignalHeaderTitle:(NSString*)title animating:(BOOL)animating;
- (void)setPeripheralHeaderTitle:(NSString*)title animating:(BOOL)animating;
- (void)setUSBHeaderTitle:(NSString*)title animating:(BOOL)animating;
- (void)setQuicksilverIntegrationTitle:(NSString*)title
                        alternateTitle:(NSString*)alternateTitle
                           buttonTitle:(NSString*)buttonTitle
                  alternateButtonTitle:(NSString*)alternateButtonTitle
                                action:(void (^)(id sender, NSCellStateValue value))action;
- (void)setQuicksilverIntegrationButtonState:(NSCellStateValue)state;
- (void)setStartAtLoginTitle:(NSString*)title
              alternateTitle:(NSString*)alternateTitle
                      action:(void (^)(id sender, NSCellStateValue value))action;
- (void)setStartAtLoginState:(NSCellStateValue)state;

- (void)addSignalMenuItem: (NSMenuItem*)item;
- (void)addPeripheralMenuItem: (NSMenuItem*)item;
- (void)addUSBMenuItem: (NSMenuItem*)item;
- (void)removeUSBMenuItemAtIndex: (NSUInteger)index;

@end

@protocol ILMenuDelegate <NSObject>

@required
- (void) menuWillOpen: (ILMenu*)menu;
- (void) menuDidClose: (ILMenu*)menu;

@end


//
//  PMREvents.h - Copyright © 2016 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Primer Notifications

/// Posted when a Primer event is being fired.
extern NSString * const PMREventFiredNotification;

/// User info dictionary key for the event's name.
extern NSString * const PMREventNotificationNameKey;

/// User info dictionary key for the event's properties.
extern NSString * const PMREventNotificationParametersKey;

/// User info dictionary key for the event's type.
extern NSString * const PMREventNotificationTypeKey;

#pragma mark - Primer Events

/// Fired when a new session has started.
extern NSString * const PMRSessionStartedEvent;

/// Fired when a user gets signed up.
extern NSString * const PMRSignupEvent;

/// Fired when a user gets logged in.
extern NSString * const PMRLoginEvent;

/// Fired when a user gets logged out.
extern NSString * const PMRLogoutEvent;

/// Fired when a Primer Flow has started.
extern NSString * const PMRFlowStartedEvent;

/// Fired when a Primer Flow has completed.
extern NSString * const PMRFlowCompletedEvent;

/// Fired when a Primer Flow's screen gets displayed.
extern NSString * const PMRScreenDisplayedEvent;

/// Fired when an action is tapped on a Primer Flow's screen.
extern NSString * const PMRActionTappedEvent;

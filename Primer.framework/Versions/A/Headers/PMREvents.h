//
//  Copyright (c) 2015 Primer, Inc. All rights reserved.
//  Primer SDK
//

#import <Foundation/Foundation.h>

#pragma mark - Primer Notifications

/// Posted when a Primer event is being fired.
extern NSString * const PrimerEventFiredNotification;

/// User info dictionary key for the event's name.
extern NSString * const PrimerEventNotificationNameKey;

/// User info dictionary key for the event's type.
extern NSString * const PrimerEventNotificationTypeKey;

/// User info dictionary key for the event's properties.
extern NSString * const PrimerEventNotificationPropertiesKey;

#pragma mark - Primer Events

///----------------
/// @name User System Events
///----------------

/// Fired when a user gets logged in.
extern NSString * const PMRLoginUserEvent;

/// Fired when a user gets logged out.
extern NSString * const PMRLogoutUserEvent;

///----------------
/// @name Flow Events
///----------------

/// Fired when a Primer Flow has started.
extern NSString * const PMRFlowStartedEvent;

/// Fired when a Primer Flow has completed.
extern NSString * const PMRFlowCompletedEvent;

///----------------
/// @name Flow Screen Events
///----------------

/// Fired when a Primer Flow screen gets displayed.
extern NSString * const PMRFlowScreenDisplayedEvent;

/// Fired when an action is tapped on a Primer Flow screen.
extern NSString * const PMRFlowScreenActionTappedEvent;

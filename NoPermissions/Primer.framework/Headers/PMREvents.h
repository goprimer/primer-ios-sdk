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

/// Fired when a Facebook user gets logged in.
extern NSString * const PMRFacebookLoginEvent;

/// Fired when a user gets logged out.
extern NSString * const PMRLogoutEvent;

/// Fired when a Primer Flow has started.
extern NSString * const PMRFlowStartedEvent;

/// Fired when a Primer Flow has completed.
extern NSString * const PMRFlowCompletedEvent;

/// Fired when a Primer Flow is skipped.
extern NSString * const PMRFlowSkippedEvent;

/// Fired when a Primer Flow's screen gets displayed.
extern NSString * const PMRScreenDisplayedEvent;

/// Fired when an action is tapped on a Primer Flow's screen.
extern NSString * const PMRActionTappedEvent;

/// Fired when a permission is requested.
extern NSString * const PMRPermissionRequestedEvent;

/// Fired when a permission gets granted.
extern NSString * const PMRPermissionGrantedEvent;

/// Fired when a permission gets denied.
extern NSString * const PMRPermissionDeniedEvent;

/// Fired when a restriction blocks a permission request.
extern NSString * const PMRPermissionRestrictedEvent;

/// Fired when an In-App Purchase product is purchased.
extern NSString * const PMRPurchasedEvent;

/// Fired when an In-App Purchase subscription is purchased.
extern NSString * const PMRSubscribedEvent;

/// Fired when an In-App Purchase is cancelled.
extern NSString * const PMRInAppPurchaseCancelledEvent;

/// Fired when a restriction blocks an In-App Purchase.
extern NSString * const PMRInAppPurchaseRestrictedEvent;

/// Fired when an In-App Purchase fails.
extern NSString * const PMRInAppPurchaseFailedEvent;

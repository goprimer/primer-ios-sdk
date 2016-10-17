//
//  Primer.h - Copyright © 2016 Primer. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PMRAttribution.h"
#import "PMREvents.h"
#import "PMRExperienceDelegate.h"
#import "PMRExperienceSettings.h"
#import "PMRLoggingLevel.h"
#import "PMRPurchaseDelegate.h"
#import "PMRUser.h"
#import "PMRUserABNTest.h"
#import "PMRValidationResult.h"

FOUNDATION_EXPORT double PrimerVersionNumber;
FOUNDATION_EXPORT const unsigned char PrimerVersionString[];

NS_ASSUME_NONNULL_BEGIN

/// The key of the deferred App Link URL launch option.
extern NSString * const PMRLaunchOptionsDeferredAppLinkURLKey;

/**
 `Primer` is the primary interface of the SDK, providing access to all major features, and importing all public headers.
 */
@interface Primer : NSObject

#pragma mark - Initialization

/**
 Initializes the SDK.
 
 You need to set the SDK Token in your `Info.plist` under the `PrimerToken` key.
 
 @note You can optionally provide the SDK Token as a parameter.
 
 @see +startWithToken:
 */
+ (void)start;

/**
 Initializes the SDK with the given Token.
 
 @note You can optionally provide the Token in your `Info.plist`.
 
 @see +start
 
 @param token The SDK Token to use for the initialization.
 */
+ (void)startWithToken:(NSString *)token;

/**
 Whether the SDK is initialized.
 
 @return `YES` if the SDK was properly started, and `NO` otherwise.
 */
+ (BOOL)isInitialized;

/**
 Sets whether the SDK launch is delayed.
 
 @note Default value is `NO`. If you set this to `YES`, make sure to call +launchDelayedWithOptions: in a timely manner after application launch.
 
 @see +launchDelayedWithOptions:
 
 @warning Make sure to call this method before starting the SDK.
 
 @param enabled The value to be set.
 */
+ (void)setDelayedLaunchEnabled:(BOOL)enabled;

/**
 Launches the SDK delayed, with the given options, if any.
 
 @note Delayed launch has to be enabled for this to function.
 
 @see +setDelayedLaunchEnabled:
 
 @param options The dictionary of launch options.
 */
+ (void)delayedLaunchWithOptions:(nullable NSDictionary *)options;

#pragma mark - Onboarding

/**
 Sets the experiences' delegate.
 
 @note The SDK holds a weak reference to the delegate.
 
 @param delegate The delegate for presented experiences.
 */
+ (void)setExperienceDelegate:(id <PMRExperienceDelegate>)delegate;

/**
 Presents the automatic experience with the default settings.
 */
+ (void)presentExperience;

/**
 Presents an experience with the given settings.
 
 @param settings The settings to use for the presentation.
 */
+ (void)presentExperienceWithSettings:(PMRExperienceSettings *)settings;

/**
 Presents the automatic experience with the default settings.
 
 @param completion The callback that gets called when the presentation is done.
 */
+ (void)presentExperienceWithCompletion:(void (^)(BOOL success))completion;

/**
 Presents an experience with the given settings.
 
 @param settings The settings to use for the presentation.
 
 @param completion The callback that gets called when the presentation is done.
 */
+ (void)presentExperienceWithSettings:(PMRExperienceSettings *)settings andCompletion:(void (^)(BOOL success))completion;

/**
 Whether an experience is currently presented or not.
 
 @return `YES` if an experience is currently presented, and `NO` otherwise.
 */
+ (BOOL)isPresentingExperience;

/**
 Dismisses the currently presented experience if there's one.
 */
+ (void)dismissExperience;

/**
 Dismisses the currently presented experience if there's one.
 
 @param completion The callback that gets called when the dismissal is done.
 */
+ (void)dismissExperienceWithCompletion:(void (^)(BOOL success))completion;

/**
 Loads the automatic experience and returns its view controller in a completion block.
 
 @param completion The callback that gets called when loading is done.
 */
+ (void)loadExperienceWithCompletion:(void (^)(UIViewController * _Nullable viewController))completion;

/**
 Loads a given type of experience and returns its view controller in a completion block.
 
 @param type The type of the experience.
 
 @param completion The callback that gets called when loading is done.
 */
+ (void)loadExperienceType:(PMRExperienceType)type withCompletion:(void (^)(UIViewController * _Nullable viewController))completion;

/**
 Displays the screen after the current one if there's an experience presented.
 
 @note Validates the current screen before going forward.
 */
+ (void)goToNextExperienceScreen;

#pragma mark - User Management

/**
 Sets the purchase delegate.
 
 @note The SDK holds a weak reference to the delegate.
 
 @param delegate The delegate for In-App Purchases.
 */
+ (void)setPurchaseDelegate:(id <PMRPurchaseDelegate>)delegate;

/**
 Sets whether the application requires login.
 
 @note Default value is `YES`.
 
 @param requiresLogin The value to be set.
 */
+ (void)setRequiresLogin:(BOOL)requiresLogin;

/**
 The current user.
 */
+ (PMRUser *)currentUser;

/**
 Signs up the current user.
 
 @see +signUpUserWithID:
 */
+ (void)signUpUser;

/**
 Signs up the current user with the given unique identifier.
 
 @param userID Unique identifier of the current user.
 
 @see +signUpUser
 */
+ (void)signUpUserWithID:(NSString *)userID;

/**
 Logs in the current user.
 
 @see +logInUserWithID:
 */
+ (void)logInUser;

/**
 Logs in the current user with the given unique identifier.
 
 @param userID Unique identifier of the current user.
 
 @see +logInUser
 */
+ (void)logInUserWithID:(NSString *)userID;

/**
 Logs out the current user.
 */
+ (void)logOutUser;

/**
 Appends user specific properties to the current user.
 
 @note These are also attached to all events, and used for dynamic replacements in experiences.
 
 @param userProperties A dictionary of values to be permanently attached to the user.
 */
+ (void)appendUserProperties:(NSDictionary<NSString *, id> *)userProperties;

/**
 Lets the SDK know that the types of local and remote notifications that can be used to get the user’s attention changed.
 */
+ (void)applicationDidRegisterUserNotificationSettings;

#pragma mark - Event Tracking

/**
 Sends a custom event (in the next batch) with optional parameters.
 
 @param name The name of the event.
 
 @param parameters The optional parameters of the event.
 */
+ (void)trackEventWithName:(NSString *)name parameters:(nullable NSDictionary<NSString *, id> *)parameters;

#pragma mark - Attribution

/**
 Allows the SDK to determine if the app was launched from a Smart link.
 
 @param userActivity The activity that caused the app to be opened.
 
 @return `YES` if the SDK can handle the activity, `NO` otherwise.
 */
+ (BOOL)continueUserActivity:(NSUserActivity *)userActivity;

/**
 Retrieves a Smart Link from the server for the given targeting.
 
 @param targeting The key of the targeting to get the link for.
 
 @param parameters The parameters to be attached to the link.
 
 @param completion The block that gets called with the link, or with `nil` if one cannot be retrieved.
 */
+ (void)getLinkForTargeting:(NSString *)targeting withParameters:(nullable NSDictionary<NSString *, id> *)parameters completion:(void(^)(NSString * _Nullable link))completion;

/**
 Returns the install attribution information as soon as it's available.
 
 @param completion The block to be called when the information is available.
 */
+ (void)getInstallAttributionWithCompletion:(void(^)(PMRAttribution *attribution))completion;

/**
 Returns the latest attribution information as soon as it's available.
 
 @param completion The block to be called when the information is available.
 */
+ (void)getLatestAttributionWithCompletion:(void(^)(PMRAttribution *attribution))completion;

/**
 Sets whether the SDK should use the IDFA provided by the AdSupport framework.
 
 @note Default value is `YES`.
 
 @param shouldUseIDFA The value to set.
 */
+ (void)setShouldUseIDFA:(BOOL)shouldUseIDFA;

/**
 Sets whether the SDK should use cookie attribution.
 
 @note Default value is `NO`.
 
 @warning Please link the SafariServices framework when enabling this feature.
 
 @param cookieAttributionEnabled The value to set.
 */
+ (void)setCookieAttributionEnabled:(BOOL)cookieAttributionEnabled;

#pragma mark - Logging

/**
 Sets the level of logging to be displayed.
 
 @note The default logging level is `PMRLoggingLevelNone` for live environments, and `PMRLoggingLevelWarning` otherwise.
 
 @param loggingLevel The level to be applied.
 */
+ (void)setLoggingLevel:(PMRLoggingLevel)loggingLevel;

#pragma mark - Version

/**
 The version of the SDK.
 */
+ (NSString *)version;

@end

NS_ASSUME_NONNULL_END

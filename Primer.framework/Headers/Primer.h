//
//  Primer.h - Copyright © 2016 Primer. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <Primer/PMRAttribution.h>
#import <Primer/PMREvents.h>
#import <Primer/PMRExperienceDelegate.h>
#import <Primer/PMRExperienceSettings.h>
#import <Primer/PMRLoggingLevel.h>
#import <Primer/PMRUser.h>
#import <Primer/PMRUserABNTest.h>
#import <Primer/PMRValidationResult.h>

FOUNDATION_EXPORT double PrimerVersionNumber;
FOUNDATION_EXPORT const unsigned char PrimerVersionString[];

NS_ASSUME_NONNULL_BEGIN

/**
 `Primer` is the main public interface of the SDK, surfacing core functionality.
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

#pragma mark - Onboarding

/**
 Sets the experiences' delegate.
 
 @note The Primer SDK holds a weak reference to the delegate.
 
 @param delegate The delegate for experiences.
 */
+ (void)setExperienceDelegate:(id <PMRExperienceDelegate>)delegate;

/**
 Presents the automatic experience with the default settings.
 */
+ (void)presentExperience;

/**
 Presents an experience with the given settings.
 
 @param settings The experience settings.
 */
+ (void)presentExperienceWithSettings:(PMRExperienceSettings *)settings;

/**
 Presents the automatic experience with the default settings.
 
 @param completion The callback that gets called when the presentation is done.
 */
+ (void)presentExperienceWithCompletion:(void (^)(BOOL success))completion;

/**
 Presents an experience with the given settings.
 
 @param settings The experience settings.
 
 @param completion The callback that gets called when the presentation is done.
 */
+ (void)presentExperienceWithSettings:(PMRExperienceSettings *)settings andCompletion:(void (^)(BOOL success))completion;

/**
 Whether an experience is currently presented or not.
 
 @return `YES` if an experience is currently presented, and `NO` otherwise.
 */
+ (BOOL)isPresentingExperience;

/**
 Dismisses the currently presenting experience if there's one.
 
 @note Has no effect if you loaded an experience with one of the `loadExperience...` methods and presented it yourself.
 */
+ (void)dismissExperience;

/**
 Dismisses the currently presenting experience if there's one.
 
 @note Has no effect if you loaded an experience with one of the `loadExperience...` methods and presented it yourself.
 
 @param completion The callback that gets called when the dismissal is done.
 */
+ (void)dismissExperienceWithCompletion:(void (^)(BOOL success))completion;

/**
 Loads the automatic experience and returns it's view controller in a completion block.
 
 @param completion The callback that gets called when the experience is loaded.
 */
+ (void)loadExperienceWithCompletion:(void (^)(UIViewController * _Nullable viewController))completion;

/**
 Loads a given type of experience and returns it's view controller in a completion block.
 
 @param type The type of the experience.
 
 @param completion The callback that gets called when the experience is loaded.
 */
+ (void)loadExperienceType:(PMRExperienceType)type withCompletion:(void (^)(UIViewController * _Nullable viewController))completion;

#pragma mark - User Management

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
 
 @see signUpUserWithID
 */
+ (void)signUpUser;

/**
 Signs up the current user with the given unique identifier.
 
 @param userID Unique identifier of the current user.
 
 @see signUpUser
 */
+ (void)signUpUserWithID:(NSString *)userID;

/**
 Logs in the current user.
 
 @see logInUserWithID
 */
+ (void)logInUser;

/**
 Logs in the current user with the given unique identifier.
 
 @param userID Unique identifier of the current user.
 
 @see logInUser
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
+ (void)appendUserProperties:(NSDictionary<NSString *,id> *)userProperties;

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
 
 @param completion The block that gets called with the retrieved link, or with `nil` if one cannot be retrieved.
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
 Whether the SDK should use the IDFA provided by the AdSupport framework.
 
 @note Default value is `YES`.
 */
+ (BOOL)shouldUseIDFA;

/**
 Sets whether the SDK should use the IDFA provided by the AdSupport framework.
 
 @note Default value is `YES`.
 */
+ (void)setShouldUseIDFA:(BOOL)shouldUseIDFA;

#pragma mark - Logging

/**
 Sets the level of logging to be displayed.
 
 @note The default logging level is `PMRLoggingLevelNone` for live environments, and `PMRLoggingLevelWarning` otherwise.
 
 @param loggingLevel The level to be applied.
 */
+ (void)setLoggingLevel:(PMRLoggingLevel)loggingLevel;

#pragma mark - Version

/**
 The SDK version.
 */
+ (NSString *)version;

@end

NS_ASSUME_NONNULL_END

//
//  Copyright (c) 2015 Primer, Inc. All rights reserved.
//  Primer SDK
//

#import <UIKit/UIKit.h>

#import "PrimerDelegate.h"
#import "PMRContact.h"
#import "PMROnboardDelegate.h"
#import "PMRValidityResult.h"

/*!
 * @brief The @c PMRReferralBlock is called by the token registration and attribution.
 *
 * @param success Returns YES if the SDK was initialized with attribution.
 * @param attributionParams Any parameters associated with attribution.
 * @param clickParams Any parameters associated with the install click.
 * @param targeting The targeting that the user installed from.
 * @param source The source that the user installed from.
 * @param phoneNumber The phone number of the current user if known.
 * @param deepLink The deep link the current user would have/has been sent to if they had the app installed.
 * @param senders Array of PMRContact objects who referred the current installing user.
 */
typedef void(^PMRReferralBlock)(BOOL success, NSDictionary *attributionParams, NSDictionary *clickParams, NSString *targeting, NSString *source, NSString *phoneNumber, NSString *deepLink, NSArray *senders);

/*!
 * @brief The @c PMRReferrerBlock is called by the token registration. Used with the params dictionary keys.
 *
 * @param params Any parameters associated with the install referrer.
 * @param successful Returns YES if the SDK was initialized with attribution.
 */
typedef void(^PMRReferrerBlock)(NSDictionary *params, BOOL successful);

#pragma mark - Referrer Params Dictionary Keys

/// Referrer Params key for the targeting
extern NSString * const PMR_REFERRER_PARAMS_KEY_TARGETING;

/// Referrer Params key for the source
extern NSString * const PMR_REFERRER_PARAMS_KEY_SOURCE;

/// Referrer Params key for the current users phone number if available
extern NSString * const PMR_REFERRER_PARAMS_KEY_PHONE_NUMBER;

/// Referrer Params key for the intended deeplink if available
extern NSString * const PMR_REFERRER_PARAMS_KEY_DEEPLINK;

/// Referrer Params key for the PMRContact of the sender if available
extern NSString * const PMR_REFERRER_PARAMS_KEY_SENDER;

/*!
 * @brief The Primer class defines the Primer SDK interface.
 *
 * The Primer SDK is organized around a singleton, accessible via the sharedInstance method.
 *
 * To register a static function, call PMRRegisterFunctionName before it:
 * @code
 *PMRRegisterFunctionName(@"To Main Screen", MyViewController, DoSomething);
 *+(void) DoSomething {
 *    ...
 *}
 * @endcode
 */
@interface Primer : NSObject

/// @brief The targeting key.
@property (nonatomic, strong) NSString *targetingKey;

/// @brief The campaign key.
@property (nonatomic, strong) NSString *campaignKey DEPRECATED_MSG_ATTRIBUTE("Use targetingKey instead.");

/// @brief The deep link path.
@property (nonatomic, strong) NSString *deepLinkPath;

/// @brief The referral code.
@property (nonatomic, strong) NSString *referralCode;

/// @brief The additional parameters.
@property (nonatomic, strong) NSDictionary *additionalParams;

/// @brief The delegate.
@property (nonatomic, weak) UIViewController *delegate;

/// @brief The inviter delegate.
@property (nonatomic, weak) id<PrimerDelegate> inviteDelegate;

/*!
 * @brief The onboarding delegate.
 *
 * @warning This is a strong reference.
 */
@property (nonatomic, strong) id<PMROnboardDelegate> onboardDelegate;

/*!
 * @brief Set this to YES to enable developer features and developer events.
 *
 * @warning Please wrap this in an #ifdef DEBUG check.
 */
@property (nonatomic, assign) BOOL debugMode;

/*!
 * @brief Set this to @c YES to enable developer logging.
 *
 * This will print @c PMRLog: lines to console.
 */
@property (nonatomic, assign) BOOL verboseLogging;

/*!
 * @brief Set this to @c YES to always show install / signup screens until a user is logged in.
 *
 * @warning JSON overrides this setting.
 */
@property (nonatomic, assign) BOOL requiresLogin;

/*!
 * @brief Set this to @c YES to delay automatic launch screens from displaying until app is fully loaded.
 *
 * @note Refer to @c appLaunchComplete for more information.
 */
@property (nonatomic, assign) BOOL delayAutomaticLaunch;

/*!
 * @brief Provides access to the Primer singleton.
 */
+ (Primer *)sharedInstance;

/*!
 * @brief Activates the Primer framework, registers the client, performs install attribution and shows any screens necessary.
 *
 * This method attempts to fetch any attribution information for the current user.
 * It uses a configurable timeout of three seconds, blocking the main thread until the data is returned.
 * In the case of a timeout and when no attribution information or updated screen is available, any defaults stored locally or cached will be used.
 *
 * @param token The token of your app on Primer.
 * @param referralBlock If this @c PMRReferralBlock is provided, it will be called with any attribution information available for the current user.
 */
- (void)registerClientWithToken:(NSString *)token andReferralBlock:(PMRReferralBlock)referralBlock DEPRECATED_MSG_ATTRIBUTE("Use registerClientWithToken:andReferrerBlock: instead.");

/*!
 * @brief Activates the Primer framework, registers the client, performs install attribution and shows any screens necessary.
 *
 * This method attempts to fetch any attribution information for the current user.
 * It uses a configurable timeout of three seconds, blocking the main thread until the data is returned.
 * In the case of a timeout and when no attribution information or updated screen is available, any defaults stored locally or cached will be used.
 *
 * @param token The token of your app on Primer.
 * @param referrerBlock If this @c PMRReferrerBlock is provided, it will be called with any attribution information available for the current user.
 */
- (void)registerClientWithToken:(NSString *)token andReferrerBlock:(PMRReferrerBlock)referrerBlock;

/*!
 * @brief Activates the Primer framework, registers the client, performs install attribution and shows any screens necessary.
 *
 * This method attempts to fetch any attribution information for the current user.
 * It uses a configurable timeout of three seconds, blocking the main thread until the data is returned.
 * In the case of a timeout and when no attribution information or updated screen is available, any defaults stored locally or cached will be used.
 *
 * @param token The token of your app on Primer.
 * @param newInstall Whether an install is a brand new user to your app.
 * @param referralBlock If this @c PMRReferralBlock is provided, it will be called with any attribution information available for the current user.
 */
- (void)registerClientWithToken:(NSString *)token isNewInstall:(BOOL)newInstall andReferralBlock:(PMRReferralBlock)referralBlock DEPRECATED_MSG_ATTRIBUTE("Use registerClientWithToken:isNewInstall:andReferrerBlock instead.");

/*!
 * @brief Activates the Primer framework, registers the client, performs install attribution and shows any screens necessary.
 *
 * This method attempts to fetch any attribution information for the current user.
 * It uses a configurable timeout of three seconds, blocking the main thread until the data is returned.
 * In the case of a timeout and when no attribution information or updated screen is available, any defaults stored locally or cached will be used.
 *
 * @param token The token of your app on Primer.
 * @param newInstall Whether an install is a brand new user to your app.
 * @param referrerBlock If this @c PMRReferrerBlock is provided, it will be called with any attribution information available for the current user.
 */
- (void)registerClientWithToken:(NSString *)token isNewInstall:(BOOL)newInstall andReferrerBlock:(PMRReferrerBlock)referrerBlock;

/*!
 * @brief Calling this activates any screen queued for the current user to see on app launch.
 *
 * @warning This method only works when @c delayAutomaticLaunch is set to @c YES.
 *
 * @note Only use both this call and @c delayAutomaticLaunch when your application loads multiple view controllers.
 */
- (void)appLaunchComplete;

/*!
 * @brief Sends a custom tracking event.
 *
 * @param event The name of the event tracked to analytics.
 */
- (void)track:(NSString *)event;

/*!
 * @brief Sends a custom tracking event with optional parameters.
 *
 * @param event The name of the event tracked to analytics.
 * @param param Dictionary of @c NSString : @c NSString key/values describing the event.
 */
- (void)track:(NSString *)event parameters:(NSDictionary *)param DEPRECATED_MSG_ATTRIBUTE("Use track:properties: instead.");

/*!
 * @brief Sends a custom tracking event with optional properties.
 *
 * @param event The name of the event tracked to analytics.
 * @param prop Dictionary of @c NSString : @c NSString key/values describing the event.
 */
- (void)track:(NSString *)event properties:(NSDictionary *)prop;

/*!
 * @brief Logs in the current user with a unique user ID.
 *
 * This call will by default asynchronously load any User Properties associated with the current user.
 *
 * @param userID Unique identifier for the current user on the current app.
 */
- (void)loginUser:(NSString *)userID;

/*!
 * @brief Logs in the current user with a unique userID.
 *
 * This call will by default asynchronously load any User Properties associated with the current user.
 *
 * @param userID Unique identifier for the current user on the current app.
 * @param useUI If set to @c YES, shows a spinner while User Properties are being loaded.
 * @param completionBlock This block will be called once User Properties for the current user are loaded remotely.
 */
- (void)loginUser:(NSString *)userID withUI:(BOOL)useUI completionBlock:(void(^)())completionBlock;

/*!
 * @brief Logs out the current user.
 *
 * It will NOT show the welcome screen automatically.
 */
- (void)logoutUser;

/*!
 * @brief Shows the welcome screen for the logged out user.
 *
 * This call is used to show the onboarding experience and prompt the user to signup or login again.
 */
- (void)showLogoutScreen;

/*!
 * @brief Appends a dictionary of user specific variables.
 *
 * These are associated with the current user and attached to all events.
 * These are also used for dynamic replacements in any experience screens.
 * User Properties are stored on the server and synced at launch with the application.
 * User Properties MUST be @c NSString : @c NSString key-value pairs.
 *
 * User Authentication Flows will automatically add User Properties at the end of a flow.
 * Refer to the specific flow for what properties are provided by default.

 @param newProperties A dictionary of @c NSString : @c NSString pairs to be permanently attached to the user.
 */
- (void)appendUserProperties:(NSDictionary *)newProperties;

/*!
 * @brief Starts the invite flow with built in ViewController.
 *
 * @param viewController The view controller that the ViewControllers will be presented on.
 * @param campaignKey Campaign to send invites from.
 * @param deepLinkPath Optional deep link path for directing the receiver.
 * @param additionalParams Optional dictionary of @c NSString : @c NSString values to be included with the invite.
 * @param blacklist Optional array of @c NSString phonenumbers to hide from the contacts list.
 */
- (void)presentInviterExperienceOn:(UIViewController *)viewController referralCode:(NSString *)referralCode campaignKey:(NSString *)campaignKey deepLinkPath:(NSString *)deepLinkPath additionalParams:(NSDictionary *)additionalParams blacklist:(NSArray *)blacklist DEPRECATED_MSG_ATTRIBUTE("Use presentInviterExperienceOn with the targetingKey parameter instead.");

/*!
 * @brief Starts the invite flow with built in ViewController.
 *
 * @param viewController The view controller that the ViewControllers will be presented on.
 * @param targetingKey Targeting to send invites from.
 * @param deepLinkPath Optional deep link path for directing the receiver.
 * @param additionalParams Optional dictionary of @c NSString : @c NSString values to be included with the invite.
 * @param blacklist Optional array of @c NSString phonenumbers to hide from the contacts list.
 */
- (void)presentInviterExperienceOn:(UIViewController *)viewController referralCode:(NSString *)referralCode targetingKey:(NSString *)targetingKey deepLinkPath:(NSString *)deepLinkPath additionalParams:(NSDictionary *)additionalParams blacklist:(NSArray *)blacklist;

/*!
 * @brief Sends invites to a list of contacts.
 *
 * Will show Message Controller if there are local invites to send.
 *
 * @param viewController The view controller that the SMS MessageController will be presented on
 * @param phoneNumbers An array of PMRContact objects that contain the name and phone number of each contact
 * @param referralCode Optional referral code to associate with invites
 * @param campaignKey Campaign to send invites from
 * @param deepLinkPath Optional deep link path for directing the receiver
 * @param additionalParams Optional dictionary of NSString : NSString values to be included with the invite
 */
- (void)sendInvitesOn:(UIViewController *)viewController phoneNumbers:(NSArray *)phoneNumbers referralCode:(NSString *)referralCode campaignKey:(NSString *)campaignKey deepLinkPath:(NSString *)deepLinkPath additionalParams:(NSDictionary *)additionalParams DEPRECATED_MSG_ATTRIBUTE("Use sendInvitesOn with the targetingKey parameter instead.");

/*!
 * @brief Sends invites to a list of contacts.
 *
 * Will show Message Controller if there are local invites to send.
 *
 * @param viewController The view controller that the SMS MessageController will be presented on
 * @param phoneNumbers An array of PMRContact objects that contain the name and phone number of each contact
 * @param referralCode Optional referral code to associate with invites
 * @param targetingKey Targeting to send invites from
 * @param deepLinkPath Optional deep link path for directing the receiver
 * @param additionalParams Optional dictionary of NSString : NSString values to be included with the invite
 */
- (void)sendInvitesOn:(UIViewController *)viewController phoneNumbers:(NSArray *)phoneNumbers referralCode:(NSString *)referralCode targetingKey:(NSString *)targetingKey deepLinkPath:(NSString *)deepLinkPath additionalParams:(NSDictionary *)additionalParams;

/*!
 * @brief Returns invite copy for a specific campaign.
 *
 * @param referralCode Optional referral code.
 * @param campaignKey Campaign to send invites from.
 * @param deepLinkPath Optional path for this campaign's configured deep link.
 * @param additionalParams Optional dictionary of @c NSString : @c NSString values to be included with the invite.
 * @param completionBlock Block that's called with the copy returned from the server.
 */
- (void)getInviteCopyForReferralCode:(NSString *)referralCode campaignKey:(NSString *)campaignKey deepLinkPath:(NSString *)deepLinkPath additionalParams:(NSDictionary *)additionalParams completionBlock:(void(^)(NSString *copy))completionBlock DEPRECATED_MSG_ATTRIBUTE("Use getInviteCopyForReferralCode with the targetingKey parameter instead.");

/*!
 * @brief Returns invite copy for a specific targeting.
 *
 * @param referralCode Optional referral code.
 * @param targetingKey Targeting to send invites from.
 * @param deepLinkPath Optional path for this targeting's configured deep link.
 * @param additionalParams Optional dictionary of @c NSString : @c NSString values to be included with the invite.
 * @param completionBlock Block that's called with the copy returned from the server.
 */
- (void)getInviteCopyForReferralCode:(NSString *)referralCode targetingKey:(NSString *)targetingKey deepLinkPath:(NSString *)deepLinkPath additionalParams:(NSDictionary *)additionalParams completionBlock:(void(^)(NSString *copy))completionBlock;

/*!
 * @brief Returns a smart link for a specific campaign.
 *
 * @param referralCode Optional referral code.
 * @param campaignKey Campaign to get smart link from.
 * @param deepLinkPath Optional path for this campaign's configured deep link.
 * @param additionalParams Optional dictionary of @c NSString : @c NSString values to be included with the invite.
 * @param completionBlock Block that's called with the smart link returned from the server.
 */
- (void)getTrackingLinkForReferralCode:(NSString *)referralCode campaignKey:(NSString *)campaignKey deepLinkPath:(NSString *)deepLinkPath additionalParams:(NSDictionary *)additionalParams completionBlock:(void(^)(NSString *link))completionBlock DEPRECATED_MSG_ATTRIBUTE("Use getTrackingLinkForTargetingKey instead.");

/*!
 * @brief Returns a smart link for a specific targeting.
 *
 * @param targetingKey Targeting to get smart link from.
 * @param params Optional dictionary of @c NSString : @c NSString values to be included with the invite.
 * @param completionBlock Block that's called with the smart link returned from the server.
 */
- (void)getTrackingLinkForTargetingKey:(NSString *)targetingKey withParameters:(NSDictionary *)parameters andCompletionBlock:(void(^)(NSString *link))completionBlock;

/*!
 * @brief Sends an event to complete the referral cycle.
 */
- (void)trackReferralComplete;

/*!
 * @brief Registers the invite event delegate
 *
 * @param inviteDelegate Class instance that implements @c PrimerDelegate.
 */
- (void)setEventDelegate:(id<PrimerDelegate>)inviteDelegate;

/*!
 * @brief Checks if an experience screen with the given key is available.
 *
 * @param experienceKey The key of the experience to check.
 *
 * @return @c YES if an experience screen exists with the given key, @c NO otherwise.
 */
- (BOOL)hasExperience:(NSString *)experienceKey;

/*!
 * @brief Shows an experience screen if it is loaded and available.
 *
 * @param experienceKey The key of the experience screen to show.
 *
 * @return @c YES if the experience screen is succesfully shown, @c NO otherwise.
 */
- (BOOL)showExperience:(NSString *)experienceKey;

/*!
 * @brief Checks if an experience screen is currently showing.
 *
 * @return @c YES if the experience screen is currently showing, @c NO otherwise.
 */
- (BOOL)isShowingExperience;

/*!
 * @brief Closes any open experience screens.
 *
 * @param animated If set to @c YES, any default animations will play when hiding the experience screens.
 */
- (void)closeAllExperiencesAnimated:(BOOL)animated;

/*!
 * @brief Starts an experience flow, if available.
 *
 * @param experienceKey The key of the flow to start.
 *
 * @return @c YES if the experience flow is succesfully started, @c NO otherwise.
 */
- (BOOL)startExperienceFlow:(NSString *)experienceKey DEPRECATED_MSG_ATTRIBUTE("Use showExperience: instead.");

/*!
 * @brief Checks if an experience flow with the given key is available.
 *
 * @param experienceKey The key of the experience flow to check.
 *
 * @return @c YES if an experience flow exists with the given key, @c NO otherwise.
 */
- (BOOL)hasExperienceFlow:(NSString *)experienceKey DEPRECATED_MSG_ATTRIBUTE("Use hasExperience: instead.");

/*!
 * @brief Checks if a flow is currently showing.
 *
 * @return @c YES if the experience flow is currently showing, @c NO otherwise.
 */
- (BOOL)isShowingExperienceFlow DEPRECATED_MSG_ATTRIBUTE("Use isShowingExperience instead.");

/*!
 * @brief If currently in a flow, jump to the next screen in the flow.
 *
 * @note If any unique variables are on the current flow experience screen, validation will occur first.
 */
- (void)nextFlowScreen DEPRECATED_MSG_ATTRIBUTE("Use nextExperienceScreen instead.");

/*!
 * @brief If currently in a flow, jump to the next screen in the flow.
 *
 * @note If any unique variables are on the current flow experience screen, validation will occur first.
 */
- (void)nextExperienceScreen;

/*!
 * @brief Sets the current user's name.
 *
 * Will be keyed as @c pmr_name in User Properties.
 *
 * @param name The name of the current user.
 */
- (void)setName:(NSString *)name;

/*!
 * @brief Gets the current user's ID.
 *
 * @return The current user's ID.
 */
- (NSString *)getUserID;

/*!
 * @brief Gets the current user's phone number.
 *
 * @return The current user's phone number.
 */
- (NSString *)getPhoneNumber;

/*!
 * @brief Gets the current user's name.
 *
 * @return The current user's name.
 */
- (NSString *)getName;

/*!
 * @brief Gets the dictionary of user specific variables.
 *
 * User Properties are stored on the server and synced at launch with the application.
 * User Properties are @c NSString : @c NSString key-value pairs.
 *
 * @return A dictionary of user specific variables.
 */
- (NSDictionary *)getUserProperties;

/*!
 * @brief Gets the array of the active A/B/N tests.
 *
 * @return An array of the active A/B/N tests.
 */
- (NSArray *)getActiveABNTests;

/*!
 * @brief Whether it is a referral.
 */
- (BOOL)isReferral;

/*!
 * @brief Gets the referrer attributed with the current user installing the app.
 */
- (PMRContact *)installReferrer;

/*!
 * @brief Gets the campaign attributed with the current user installing the app.
 */
- (NSString *)getInstallCampaign DEPRECATED_MSG_ATTRIBUTE("Use getInstallTargeting instead.");

/*!
 * @brief Gets the targeting attributed with the current user installing the app.
 */
- (NSString *)getInstallTargeting;

/*!
 * @brief Gets the source attributed with the current user installing the app.
 */
- (NSString *)getInstallSource;

/*!
 * @brief Gets any link parameters from the click attributed with the current user installing the app.
 */
- (NSDictionary *)getInstallClickParams;

/*!
 * @brief Gets any attribution parameters attributed with the current user.
 */
- (NSDictionary *)getInstallAttributionParams;

/*!
 * @brief Gets the referrer attributed with the current user opening the app.
 */
- (PMRContact *)returningReferrer;

/*!
 * @brief Gets the campaign attributed with the current user opening the app.
 */
- (NSString *)getReturningCampaign DEPRECATED_MSG_ATTRIBUTE("Use getReturningTargeting instead.");

/*!
 * @brief Gets the targeting attributed with the current user opening the app.
 */
- (NSString *)getReturningTargeting;

/*!
 * @brief Gets the source attributed with the current user opening the app.
 */
- (NSString *)getReturningSource;

/*!
 * @brief Gets any link parameters from the click attributed with the current user opening the app.
 */
- (NSDictionary *)getReturningClickParams;

/*!
 * @brief Gets any attribution parameters attributed with the current user.
 */
- (NSDictionary *)getReturningAttributionParams;

/*!
 * @brief Returns the SDK version.
 */
- (NSString *)getSDKVersion;

/*!
 * @brief Set this to @c YES to disable automatic events used for experiences.
 */
@property BOOL disableAutomaticEventFowarding;

/*!
 * @brief Set this to @c YES to not use IDFA when the AdSupport framework is avaialble.
 */
@property BOOL noIDFA;

@end

/**
 * Call this as a line above any static function you want registered to be easily used by Experiences.
 * Registers a static function with a friendly name so that they can be used as actions.
 *
 * ex.
 * PMRRegisterFunctionName(@"To Main Screen", MyViewController, DoSomething);
 * +(void) DoSomething {
 *    ...
 * }
 *
 **/
#define PMRRegisterFunctionName(name, cName, fName); \
static void __attribute__((constructor)) PMRInit_ ## fName() { \
    @autoreleasepool { \
        [Primer registerFunctionName:name className:@#cName functionName:@#fName]; \
    } \
}

/**
 * These headers should not be called directly.
 * They are used for automatic Static Function Friendly Name registration.
 **/
@interface Primer (ReservedHeaders)

/**
 * Should not be called directly.
 * Registers a static function with a friendly name so that they can be used as button actions.
 **/
+ (void)registerFunctionName:(NSString *)name className:(NSString *)className functionName:(NSString *) functionName;

@end



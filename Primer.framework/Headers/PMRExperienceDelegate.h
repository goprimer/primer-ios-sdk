//
//  PMRExperienceDelegate.h - Copyright © 2017 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMRValidationResult;

NS_ASSUME_NONNULL_BEGIN

/**
 @typedef PMRUserValidationBlock
 
 The block that should be called when validation is done and a user can be logged in or signed up as a result.
 
 @param result The optional result of the validation.
 
 @param userID The optional ID of the user.
 */
typedef void(^PMRUserValidationBlock)(PMRValidationResult * _Nullable result, NSString * _Nullable userID);

/**
 @typedef PMRFacebookUserValidationBlock
 
 The block that should be called when validation is done and a Facebook user can be logged in or signed up as a result.
 
 @param result The optional result of the validation.
 
 @param userID The optional ID of the user.
 
 @param isSignup Whether the user is a new signup.
 */
typedef void(^PMRFacebookUserValidationBlock)(PMRValidationResult * _Nullable result, NSString * _Nullable userID, BOOL isSignup);

/**
 @typedef PMRValidationBlock
 
 The block that should be called when validation is done.
 
 @param result The optional result of the validation.
 */
typedef void(^PMRValidationBlock)(PMRValidationResult * _Nullable result);

/**
 @typedef PMRSuccessBlock
 
 The block that should be called when success is determined.
 
 @param success Whether the action was successful.
 */
typedef void(^PMRSuccessBlock)(BOOL success);

/**
 The delegate conforming to the `PMRExperienceDelegate` protocol is responsible for handling messages from the currently presented experience.
 
 It will be notified about the progress of your users, and receive the information they provide as an input.
 */
@protocol PMRExperienceDelegate <NSObject>

@optional

/**
 Called after fields are submitted.
 
 You should handle the fields and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK might display a loading overlay to the user.
 
 @note The completion block's parameter determines whether the success action will be executed, if any.
 
 @param fields The `key : value` pair of the submitted fields.
 
 @param completion The block to call when handling is finished.
 */
- (void)handleFields:(NSDictionary<NSString *, id> *)fields completion:(PMRSuccessBlock)completion;

/**
 Called after a screen is submitted with any fields on it.
 
 You should validate the fields and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK displays a loading overlay to the user.
 
 @param fields The `key : value` pair of the submitted screen's fields.
 
 @param completion The block to call when you finished validation.
 */
- (void)validateFields:(NSDictionary<NSString *, id> *)fields completion:(PMRValidationBlock)completion;

/**
 Called after the login flow is submitted.
 
 You should validate the fields and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK displays a loading overlay to the user.
 
 @param fields The `key : value` pair of the login flow's fields.
 
 @param completion The block to call when you finished validation.
 */
- (void)logInWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRUserValidationBlock)completion;

/**
 Called after the signup flow is submitted.
 
 You should validate the fields and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK displays a loading overlay to the user.
 
 @param fields The `key : value` pair of the signup flow's fields.
 
 @param completion The block to call when you finished validation.
 */
- (void)signUpWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRUserValidationBlock)completion;

/**
 Called after a Facebook authentication takes place.
 
 You should validate the fields and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK displays a loading overlay to the user.
 
 @param fields The `key : value` pair of fields that were received from Facebook.
 
 @param completion The block to call when you finished validation.
 */
- (void)validateFacebookUserWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRFacebookUserValidationBlock)completion;

/**
 Called after the password recovery flow is submitted.
 
 You should validate the fields and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK displays a loading overlay to the user.
 
 @param fields The `key : value` pair of the password recovery flow's fields.
 
 @param completion The block to call when you finished validation.
 */
- (void)recoverPasswordWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRValidationBlock)completion;

/**
 Called before the experience will be closed.
 
 @param fields The `key : value` pair of fields that were put in by the user up until this point in the flow.
 */
- (void)willCloseWithFields:(NSDictionary<NSString *, id> *)fields;

/**
 Called after a screen appeared.
 
 @param name The name of the screen.
 
 @param triggers The array of triggers that are available on the screen.
 */
- (void)screenDidAppearWithName:(NSString *)name triggers:(NSArray<NSString *> *)triggers;

#pragma mark - Deprecated

/**
 Called after a screen is submitted with any unique fields on it.
 
 You should validate the uniqueness of the fields and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK displays a loading overlay to the user.
 
 @param fields The `key : value` pair of the submitted screen's unique fields.
 
 @param completion The block to call when you finished validation.
 
 @deprecated This delegate method is deprecated starting in version 3.1, please use 'validateFields:completion:' instead.
 */
- (void)validateUniqueFields:(NSDictionary<NSString *, id> *)fields completion:(PMRValidationBlock)completion DEPRECATED_MSG_ATTRIBUTE("use 'validateFields:completion:' instead.");

/**
 Called after a Facebook authentication takes place.
 
 You should validate the fields and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK displays a loading overlay to the user.
 
 @param fields The `key : value` pair of fields that were received from Facebook.
 
 @param completion The block to call when you finished validation.
 
 @deprecated This delegate method is deprecated starting in version 3.2.3, please use 'validateFacebookUserWithFields:completion:' instead.
 */
- (void)authenticateFacebookWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRUserValidationBlock)completion DEPRECATED_MSG_ATTRIBUTE("use 'validateFacebookUserWithFields:completion:' instead.");

@end

NS_ASSUME_NONNULL_END

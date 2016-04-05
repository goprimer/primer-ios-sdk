//
//  PMRExperienceDelegate.h - Copyright © 2016 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMRValidationResult;

NS_ASSUME_NONNULL_BEGIN

/**
 @typedef PMRUserValidationBlock
 
 The block that should be called when validation is done and a user can be logged in as a result.
 
 @param result The result of the validation.
 
 @param userID The ID of the user that got logged in, when validation is successful.
 */
typedef void(^PMRUserValidationBlock)(PMRValidationResult * _Nullable result, NSString * _Nullable userID);

/**
 @typedef PMRValidationBlock
 
 The block that should be called when validation is done.
 
 @param result The result of the validation.
 */
typedef void(^PMRValidationBlock)(PMRValidationResult * _Nullable result);

/**
 The delegate conforming to the `PMRExperienceDelegate` protocol is responsible for handling messages from the currently presented experience.
 
 It will be notified about the progress of your users, and receive the information they provide as an input
 */
@protocol PMRExperienceDelegate <NSObject>

@optional

/**
 Called after a screen is submitted with any unique fields on it.
 
 You should validate the uniqueness of the fields and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK displays a loading overlay to the user.
 
 @param fields The `key : value` pair of the submitted screen's unique fields.
 
 @param completion The block to call when you finished validation.
 */
- (void)validateUniqueFields:(NSDictionary<NSString *, id> *)fields completion:(PMRValidationBlock)completion;

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
- (void)authenticateFacebookWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRUserValidationBlock)completion;

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

@end

NS_ASSUME_NONNULL_END

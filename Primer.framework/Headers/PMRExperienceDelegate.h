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
 `PMRExperienceDelegate` is responsible for handling messages from an experience.
 */
@protocol PMRExperienceDelegate <NSObject>

@optional

/**
 Called when a screen submit unique fields.
 
 @note You should validate the fields and call the completion block as soon as possible.
 
 @param fields The `key : value` pair of fields that were put in by the user.
 
 @param completion The block to call when you finished validation.
 */
- (void)validateUniqueFields:(NSDictionary<NSString *, id> *)fields completion:(PMRValidationBlock)completion;

/**
 Called before the login flow completes.
 
 @note You should validate the fields and call the completion block as soon as possible.
 
 @param fields The `key : value` pair of fields that were put in by the user.
 
 @param completion The block to call when you finished validation.
 */
- (void)logInWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRUserValidationBlock)completion;

/**
 Called before the signup flow completes.
 
 @note You should validate the fields and call the completion block as soon as possible.
 
 @param fields The `key : value` pair of fields that were put in by the user.
 
 @param completion The block to call when you finished validation.
 */
- (void)signUpWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRUserValidationBlock)completion;

/**
 Called right after the Facebook authentication took place.
 
 @note You should validate the fields and call the completion block as soon as possible.
 
 @param fields The `key : value` pair of fields that were received from Facebook
 
 @param completion The block to call when you finished validation.
 */
- (void)authenticateFacebookWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRUserValidationBlock)completion;

/**
 Called before the password recovery flow completes.
 
 @note You should validate the fields and call the completion block as soon as possible.
 
 @param fields The `key : value` pair of fields that were put in by the user.
 
 @param completion The block to call when you finished validation.
 */
- (void)recoverPasswordWithFields:(NSDictionary<NSString *, id> *)fields completion:(PMRValidationBlock)completion;

/**
 Tells the delegate that the experience will be closed.
 
 @param fields The `key : value` pair of fields that were put in by the user.
 */
- (void)willCloseWithFields:(NSDictionary<NSString *, id> *)fields;

@end

NS_ASSUME_NONNULL_END

//
//  Copyright (c) 2015 Primer, Inc. All rights reserved.
//  Primer SDK
//

#import <Foundation/Foundation.h>

@class PMRValidityResult;

/*!
 * @brief The @c PMRValidityResultBlock should be called with the validity result to continue the flow.
 *
 * @param result The validity result.
 */
typedef void(^PMRValidityResultBlock)(PMRValidityResult *result);

@protocol PMROnboardDelegate <NSObject>

@optional

/*!
 * @brief Called when a signup-with-Facebook action completes.
 *
 * @param inputs A dictionary of keys to input values from the Facebook account.
 * @param completionBlock Call this with the validity result to continue the flow.
 */
- (void)authWithFacebook:(NSDictionary *)inputs completionBlock:(PMRValidityResultBlock)completionBlock;

/*!
 * @brief Called when any screen has unique inputs.
 *
 * @param inputs A dictionary of keys to unique input values from the form.
 * @param completionBlock Call this with the validity result to continue the flow.
 */
- (void)validateUniqueInputs:(NSDictionary *)inputs completionBlock:(PMRValidityResultBlock)completionBlock;

/*!
 * @brief Called at the end of a signup flow.
 *
 * @param inputs A dictionary of keys to input values from the complete form.
 * @param completionBlock Call this with the validity result to continue the flow.
*/
- (void)signupWithInputs:(NSDictionary *)inputs completionBlock:(PMRValidityResultBlock)completionBlock;

/*!
 * @brief Called at the end of a login flow.
 *
 * @param inputs A dictionary of keys to input values from the complete form.
 * @param completionBlock Call this with the validity result to continue the flow.
 */
- (void)loginWithInputs:(NSDictionary *)inputs completionBlock:(PMRValidityResultBlock)completionBlock;

/*!
 * @brief Called at the end of a recover flow.
 *
 * @param inputs A dictionary of keys to input values from the complete form.
 * @param completionBlock Call this with the validity result to continue the flow.
 */
- (void)recoverWithInputs:(NSDictionary *)inputs completionBlock:(PMRValidityResultBlock)completionBlock;

/*!
 * @brief Called at the end of a custom (not signup, login, or recover) flow.
 *
 * @param inputs A dictionary of keys to input values from the complete form.
 * @param completionBlock Call this with the validity result to continue the flow.
 */
- (void)endWithInputs:(NSDictionary *)inputs completionBlock:(PMRValidityResultBlock)completionBlock;

@end

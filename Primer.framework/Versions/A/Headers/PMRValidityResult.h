//
//  Copyright (c) 2015 Primer, Inc. All rights reserved.
//  Primer SDK
//

#import <Foundation/Foundation.h>

/*!
 * @c PMRValidityResult contains information about the result of a validation.
 */
@interface PMRValidityResult : NSObject

/*!
 * @brief Return if the delegate action was successful.
 *
 * @attention Required.
 */
@property BOOL isValid;

/*!
 * @brief Return a custom error message if any keys fail validation.
 *
 * @note Optional.
 */
@property (nonatomic, strong) NSString *errorMessage;

/*!
 * @brief Return this to us if an account is registered and you use userIDs.
 *
 * @note Optional.
 */
@property (nonatomic, strong) NSString *userID;

/*!
 * @brief Return the dictionary keys that failed validation.
 *
 * @note Optional.
 */
@property (nonatomic, strong) NSArray *invalidFields;

@end

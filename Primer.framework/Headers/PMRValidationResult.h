//
//  PMRValidationResult.h - Copyright © 2016 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `PMRValidationResult` is responsible for holding information about the result of a validation.
 */
@interface PMRValidationResult : NSObject

#pragma mark - Validation

/**
 Invalidates the result with an error message attached.
 
 @note Any fields invalidated without an error message will display this message.
 
 @param errorMessage The error message to be displayed.
 */
- (void)invalidateWithErrorMessage:(NSString *)errorMessage;

/**
 Invalidates a given field.
 
 @param field The key of the invalid field.
 */
- (void)invalidateField:(NSString *)field;

/**
 Invalidates a given field with an error message attached.
 
 @param field The key of the invalid field.
 
 @param errorMessage The error message to be attached.
 */
- (void)invalidateField:(NSString *)field withErrorMessage:(NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END

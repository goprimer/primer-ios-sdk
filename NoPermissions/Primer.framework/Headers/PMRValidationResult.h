//
//  PMRValidationResult.h - Copyright © 2018 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `PMRValidationResult` is responsible for holding information about the result of a validation.
 
 A new instance is considered to be valid until you call one of the invalidation methods.
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
 Invalidates the given field.
 
 @param field The key of the invalid field.
 */
- (void)invalidateField:(NSString *)field;

/**
 Invalidates the given field with an error message attached.
 
 @param field The key of the invalid field.
 
 @param errorMessage The error message to be attached.
 */
- (void)invalidateField:(NSString *)field withErrorMessage:(NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END

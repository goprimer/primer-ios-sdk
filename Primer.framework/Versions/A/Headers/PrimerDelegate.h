//
//  Copyright (c) 2015 Primer, Inc. All rights reserved.
//  Primer SDK
//

#import <Foundation/Foundation.h>

/*!
 * @typedef PMRResult
 *
 * @brief List of all possible return states from the inviter.
 */
typedef NS_ENUM(NSInteger, PMRResult)
{
    /// Closed
    PMRResultClosed,
    
    /// Cancelled
    PMRResultCancelled,
    
    /// Sent
    PMRResultSent,
    
    /// Failed
    PMRResultFailed
};

/*!
 * @brief Defines the delegate callbacks for the Inviter Experience.
 */
@protocol PrimerDelegate <NSObject>

@optional

/*!
 * @brief Called when inviter is closed.
 *
 * @param result Result of inviter.
 * @param contactsList A list of PMRContact objects.
 */
- (void)inviterDidFinishWithResult:(PMRResult)result invitedContacts:(NSArray *)contactsList;

/*!
 * @brief Called when a name is entered in the inviter.
 *
 * @param name Name entered by the user.
 */
- (void)nameEntered:(NSString *)name;

@end

//
//  Copyright (c) 2015 Primer, Inc. All rights reserved.
//  Primer SDK
//

#import <Foundation/Foundation.h>

/*!
 * @typedef PMRSendType
 *
 * @brief A list of all possible invite send types.
 */
typedef NS_ENUM(NSInteger, PMRSendType)
{
    /// The type is unkown.
    PMRSendTypeUnknown = 0,
    
    /// The invite comes from native.
    PMRSendTypeNative,
    
    /// The invite comes from server.
    PMRSendTypeServer
};

/*!
 * @brief Contains relevant information about a contact or referral.
 */
@interface PMRContact : NSObject

/// The name of the contact.
@property (nonatomic, copy) NSString *contactName;

/// The phone number of the contact.
@property (nonatomic, copy) NSString *phoneNumber;

/// The userID of the contact.
@property (nonatomic, copy) NSString *userID;

/// The deviceID of the contact's device.
@property (nonatomic, copy) NSString *deviceID;

/// The referral code.
@property (nonatomic, copy) NSString *referralCode;

/// The deep link path.
@property (nonatomic, copy) NSString *deepLinkPath;

/// The name of the contact as it appears in the phonebook.
@property (nonatomic, copy) NSString *phonebookName;

/// The invite send type.
@property (nonatomic, assign) PMRSendType sendType;

/// The related user properties.
@property (nonatomic, copy) NSDictionary *userProperties;

/// The additional parameters.
@property (nonatomic, copy) NSDictionary *additionalParams;

@end

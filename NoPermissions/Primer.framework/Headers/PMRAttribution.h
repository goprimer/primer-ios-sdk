//
//  PMRAttribution.h - Copyright © 2016 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `PMRAttribution` is responsible for holding all information about an attribution.
 */
@interface PMRAttribution : NSObject <NSCopying>

/// Whether it is a referral.
@property (nonatomic, assign, readonly, getter=isReferral) BOOL referral;

/// The deep link.
@property (nonatomic, strong, readonly, nullable) NSString *deepLink;

/// The name of the static link.
@property (nonatomic, strong, readonly, nullable) NSString *linkName;

/// The parameters attached to the attribution.
@property (nonatomic, strong, readonly) NSDictionary<NSString *, id> *parameters;

/// The user properties of the sender.
@property (nonatomic, strong, readonly) NSDictionary<NSString *, id> *sender;

/// The name of the source.
@property (nonatomic, strong, readonly, nullable) NSString *sourceName;

/// The key of the targeting.
@property (nonatomic, strong, readonly, nullable) NSString *targetingKey;

/// The name of the targeting.
@property (nonatomic, strong, readonly, nullable) NSString *targetingName;

#pragma mark - Equality

/**
 Returns a Boolean value that indicates whether a given attribution is equal to the receiver.
 
 @param attribution The attribution with which to compare the receiver.
 
 @return `YES` if the attribution is equivalent to the receiver, `NO` otherwise.
 */
- (BOOL)isEqualToAttribution:(PMRAttribution *)attribution;

@end

NS_ASSUME_NONNULL_END

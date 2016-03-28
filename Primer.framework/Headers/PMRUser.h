//
//  PMRUser.h - Copyright © 2016 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMRUserABNTest;

NS_ASSUME_NONNULL_BEGIN

/**
 `PMRUser` is responsible for holding all information about a user.
 */
@interface PMRUser : NSObject

/// Unique identifier of the user.
@property (nonatomic, strong, nullable, readonly) NSString *userID;

/// Name of the user.
@property (nonatomic, strong, nullable) NSString *name;

/// Properties of the user.
@property (nonatomic, strong, readonly) NSDictionary<NSString *, id> *properties;

/// Active A/B/N tests of the user.
@property (nonatomic, strong, readonly) NSArray<PMRUserABNTest *> *activeABNTests;

/// Last viewed variation of the user.
@property (nonatomic, strong, nullable, readonly) NSString *lastViewedVariation;

@end

NS_ASSUME_NONNULL_END

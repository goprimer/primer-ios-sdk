//
//  PMRUser.h - Copyright © 2017 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMRUserABNTest;

NS_ASSUME_NONNULL_BEGIN

/**
 `PMRUser` is responsible for holding all information about a user.
 */
@interface PMRUser : NSObject

/// The unique identifier of the user.
@property (nonatomic, strong, nullable, readonly) NSString *userID;

/// The name of the user.
@property (nonatomic, strong, nullable) NSString *name;

/// The properties attached to the user.
@property (nonatomic, strong, readonly) NSDictionary<NSString *, id> *properties;

/// The active A/B/N tests the user participates in.
@property (nonatomic, strong, readonly) NSArray<PMRUserABNTest *> *activeABNTests;

/// Th last viewed variation of the user.
@property (nonatomic, strong, nullable, readonly) NSString *lastViewedVariation;

@end

NS_ASSUME_NONNULL_END

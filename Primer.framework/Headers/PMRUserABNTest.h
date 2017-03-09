//
//  PMRUserABNTest.h - Copyright © 2017 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `PMRUserABNTest` is responsible for holding all information about an A/B/N test.
 */
@interface PMRUserABNTest : NSObject

/// The name of the test.
@property (nonatomic, strong, readonly, nullable) NSString *name;

/// The variation of the test.
@property (nonatomic, strong, readonly, nullable) NSString *variation;

@end

NS_ASSUME_NONNULL_END

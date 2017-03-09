//
//  PMRPurchaseDelegate.h - Copyright © 2017 Primer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @typedef PMRProductsAvailabilityBlock
 
 The block that should be called when availability of products is determined.
 
 @param unavailableIdentifiers The optional array of product identifiers unavailable for purchase.
 */
typedef void(^PMRProductsAvailabilityBlock)(NSArray<NSString *> * _Nullable unavailableIdentifiers);

/**
 The delegate conforming to the `PMRPurchaseDelegate` protocol is responsible for handling messages related to In-App Purchases.
 */
@protocol PMRPurchaseDelegate <NSObject>

/**
 Called before an In-App Purchase screen is presented.
 
 You should determine the availability of the products and call the completion block as soon as possible.
 
 @attention Always call the `completion` block, even if in an asynchronous manner. Until you do so, the SDK displays a loading overlay to the user.

 @param identifiers The array of product identifiers.

 @param completion A block to call when you determined product availability.
 */
- (void)areProductsAvailableWithIdentifiers:(NSArray<NSString *> *)identifiers completion:(PMRProductsAvailabilityBlock)completion;

@end

NS_ASSUME_NONNULL_END

//
//  PMRExperienceSettings.h - Copyright © 2016 Primer. All rights reserved.
//

#import <UIKit/UIkit.h>

/**
 Experience types available when presenting an experience.
 */
typedef NS_ENUM(NSInteger, PMRExperienceType)
{
    /// The automatically determined experience.
    PMRExperienceTypeAutomatic,
    
    /// The install experience.
    PMRExperienceTypeInstall,
    
    /// The logged out experience.
    PMRExperienceTypeLoggedOut,
    
    /// The login experience.
    PMRExperienceTypeLogin,
    
    /// The recover password experience.
    PMRExperienceTypeRecoverPassword,
    
    /// The signup experience.
    PMRExperienceTypeSignup
};

NS_ASSUME_NONNULL_BEGIN

/**
 `PMRExperienceSettings` is responsible for holding all settings of an experience.
 */
@interface PMRExperienceSettings : NSObject

/// The type of the experience. @see PMRExperienceType
@property (nonatomic, assign) PMRExperienceType experienceType;

/// Whether the presentation of the experience should be animated.
@property (nonatomic, assign) BOOL shouldPresentAnimated;

/// Whether the dismissal of the experience should be animated.
@property (nonatomic, assign) BOOL shouldDismissAnimated;

/// The view controller that should be presenting the experience.
@property (nonatomic, strong, nullable) UIViewController *presentingViewController;

#pragma mark - Creation

/**
 Creates and returns a default settings instance.
 
 @return A new settings instance with default values.
 */
+ (instancetype)settings;

@end

NS_ASSUME_NONNULL_END

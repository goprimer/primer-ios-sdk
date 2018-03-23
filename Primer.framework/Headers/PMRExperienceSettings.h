//
//  PMRExperienceSettings.h - Copyright © 2018 Primer. All rights reserved.
//

#import <UIKit/UIkit.h>

/**
 The experience types available when presenting an experience.
 
 The automatic type behaves like the automatic presentation method, as in the SDK determines if an experience needs to be presented at all, using the user state information.
 The other options will show the appropriate experience, regardless of the user's logged-in status.
 */
typedef NS_ENUM(NSInteger, PMRExperienceType)
{
    /// The automatically determined experience.
    PMRExperienceTypeAutomatic,
    
    /// The new user experience.
    PMRExperienceTypeNewUser,
    
    /// The login experience.
    PMRExperienceTypeLogin,
    
    /// The recover password experience.
    PMRExperienceTypeRecoverPassword,
    
    /// The install experience.
    PMRExperienceTypeInstall DEPRECATED_MSG_ATTRIBUTE("use 'PMRExperienceTypeNewUser' instead.") = PMRExperienceTypeNewUser,
    
    /// The logged out experience.
    PMRExperienceTypeLoggedOut DEPRECATED_MSG_ATTRIBUTE("use 'PMRExperienceTypeNewUser' instead.") = PMRExperienceTypeNewUser,
    
    /// The signup experience.
    PMRExperienceTypeSignup DEPRECATED_MSG_ATTRIBUTE("use 'PMRExperienceTypeNewUser' instead.") = PMRExperienceTypeNewUser
};

NS_ASSUME_NONNULL_BEGIN

/**
 `PMRExperienceSettings` is responsible for holding all tweakable parameters of an experience presentation.
 */
@interface PMRExperienceSettings : NSObject

/// The type of the experience. See `PMRExperienceType` for possible values.
@property (nonatomic, assign) PMRExperienceType experienceType;

/// Whether the presentation should use a wrapper window.
@property (nonatomic, assign) BOOL shouldUseWindowBasedPresentation;

/// Whether the presentation of the experience should be animated.
@property (nonatomic, assign) BOOL shouldPresentAnimated;

/// Whether the dismissal of the experience should be animated.
@property (nonatomic, assign) BOOL shouldDismissAnimated;

/// The view controller that should be presenting the experience.
@property (nonatomic, strong, nullable) UIViewController *presentingViewController;

/// The name of the specific screen that should be presented.
@property (nonatomic, strong, nullable) NSString *screenName;

#pragma mark - Creation

/**
 Creates and returns a default settings instance.
 
 @return A new settings instance with default values.
 */
+ (instancetype)settings;

@end

NS_ASSUME_NONNULL_END

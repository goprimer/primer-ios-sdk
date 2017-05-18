# Primer iOS SDK

[![CocoaPods Compatible](https://img.shields.io/badge/CocoaPods-3.3.1-5BA7E9.svg?style=flat)](https://cocoapods.org)
[![Carthage Compatible](https://img.shields.io/badge/Carthage-Compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![Platform](https://img.shields.io/badge/Platform-iOS-lightgrey.svg?style=flat)]()

Instantly deploy native screens without writing code. Primer enables you to design and test new user experiences, and personalize them for each user.

The Primer iOS SDK requires a free account to be created at https://goprimer.com, and your app to have a deployment target of at least iOS 8.

## Get Started

* We have a [Quick Start Guide](http://ios.goprimer.com/docs/quick-start) to help you get Primer up and running in your iOS app in less than 10 minutes.

* If your app uses user account follow up with our [Quick Authentication Guide](http://ios.goprimer.com/docs/quick-authentication-guide) to get account authentication with Primer tied into your app's user system.

* Upgrading from v2? We have an [Upgrade Guide](http://ios.goprimer.com/docs/upgrade-guide) to cover you.

## Installation

##### CocoaPods

To integrate using CocoaPods, add the necessary sources and the Primer pod to your `Podfile`:

```ruby
pod 'Primer', '~> 3.3'
```

##### Carthage

To integrate using Carthage, add the following to your `Cartfile`:

```ruby
github "goprimer/primer-ios-sdk" "~> 3.3"
```

Don't forget to add the path to the framework under "Input Files" for the `copy-frameworks` script Build Phase:

```
$(SRCROOT)/Carthage/Build/iOS/Primer.framework
```

Then add the `AdSupport.framework` in the `Linked Frameworks and Libraries` section of the `General` tab of your app target's settings.

##### Manually

To integrate manually please take a look at the Manual Integration section of our [Quick Start Guide](http://ios.goprimer.com/docs/quick-start).

## Integration

iOS 9 introduced [App Transport Security](https://developer.apple.com/library/content/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html#//apple_ref/doc/uid/TP40009251-SW33) that impacts your app and the Primer iOS SDK integration. To finish your integration you need to whitelist the Primer domains in your app by adding the following to your application's info plist.

```xml
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSExceptionDomains</key>
    <dict>
        <key>goprimer.com</key>
        <dict>
            <key>NSIncludesSubdomains</key>
            <true/>
            <key>NSThirdPartyExceptionAllowsInsecureHTTPLoads</key>
            <true/>
        </dict>
    </dict>
</dict>
```

## Usage

##### Start the SDK
First import Primer by adding #import <Primer/Primer.h> ( or import Primer for Swift) at the top of your application's delegate. Then in your -application:didFinishLaunchingWithOptions: implementation call our start method with your SDK token (you can find it in your [Project Settings](http://goprimer.com/dashboard#/project//edit)).

```objc
#import <Primer/Primer.h>

- (BOOL)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Initialize the Primer SDK
    [Primer startWithToken:@"YOUR_APP_TOKEN"];
    return YES;
}
```

##### Present Onboarding

The most common time to present an onboarding experience is right when the application launches. The best way of doing this in most of the applications is by calling the presentation method in the -viewDidLoad of your first view controller to be presented to the user on app load.

To let the SDK automatically present an onboarding experience just simply call the +presentExperience method.

```objc
#import <Primer/Primer.h>
  
- (void)viewDidLoad {
    [super viewDidLoad];
    // Present the Primer onboarding experience
    [Primer presentExperience];
}
```

## Contact Us

Need help or have questions? Please contact us at success@goprimer.com and we will provide you personal support to guarantee success in your app!

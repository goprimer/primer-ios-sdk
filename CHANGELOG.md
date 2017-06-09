# Change Log

## [3.4.0](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.4.0) (06/09/2017)

##### New Features

* Added support for required screens.
* Added support for triggers.
* Added support for three new actions.

##### Enhancements

* Improved data encryption logic.

## [3.3.1](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.3.1) (05/18/2017)

##### Bug Fixes

* Fixed toggle button validation behavior.

## [3.3.0](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.3.0) (05/08/2017)

##### New Features

* Added support for field value inheritance.
* Added optional HTTPS support.
* Added support for auto focus on text inputs.
* Added font size adjusting support to labels.

##### Enhancements

* Improved returning user tracking.
* Deprecated cookie attribution.

##### Bug Fixes

* Suggestion toolbar suffixing behavior.

## [3.2.4](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.2.4) (03/09/2017)

##### New Features

* Added support for line height multiplier.

##### Enhancements

* Improved image downloading and preloading logic.
* Tweaked event request data handling.

## [3.2.3](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.2.3) (01/31/2017)

##### New Features

* Added support for field value inheritance.

##### Enhancements

* Improved tracking of Facebook signups.
* Tweaked Facebook login action handling.
* Improved Facebook value handling.
* Updated launch time tracking.

##### Bug Fixes

* Fixed an issue with button icons being repeated.
* Fixed a rare issue with validation item type checking.

## [3.2.2](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.2.2) (12/20/2016)

##### Enhancements

* Improved error message displaying.
* Overhauled image preloading system.
* Improved dynamic variable handling.
* Updated picker placeholder support.
* Tweaked events related error handling.
* Improved flow pause logic.

##### Bug Fixes

* Fixed input position getting reset.

## [3.2.1](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.2.1) (11/22/2016)

##### New Features

* Input value syncing based on user property name.

##### Enhancements

* Improved flow related event tracking.
* Improved value validation system.

##### Bug Fixes

* Fixed inline validation behaviour on Submit Fields screens.

## [3.2.0](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.2.0) (10/27/2016)

##### New Features

* Pausing and resuming experiences is now possible.
* New field submission option for the experience delegate.
* Added support for specific screen presentation via screen name.

##### Bug Fixes

* Fixed an issue with Facebook login related loading overlays.

## [3.1.7](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.1.7) (10/17/2016)

##### New Features

* Added support for a delayed SDK launch.
* Added a way to provide existing attribution data on launch.

##### Bug Fixes

* Fixed a rare issue with flow related memory management.

## [3.1.6](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.1.6) (10/11/2016)

##### Enhancements

* Added support for secure input keys.
* Improved attribution parameter parsing.

## [3.1.5](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.1.5) (09/16/2016)

##### Enhancements

* Added integration option without permissions support.

## [3.1.4](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.1.4) (09/15/2016)

##### Enhancements

* Added support for iOS 10.
* Added support for platform-specific features.
* Improved permission tracking.
* Improved handling of the return key on inputs.

## [3.1.3](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.1.3) (08/25/2016)

##### Enhancements

* Support pulling Facebook App ID from FBSDKSettings.
* Improved tracking with new Facebook Login event.
* Improved button text alignment by adding more customization.
* Improved tracking by adding more flow and screen metadata.
* Improved tracking by collecting more device model details.
* Improved handling of screens with incorrect In-App Purchase Product Identifiers.

##### Bug Fixes

* Fixed formatting of local event forwarding user info.

## [3.1.2](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.1.2) (08/09/2016)

##### Enhancements

* Improved SDK initialization logic.
* Improved layout handling.
* Improved suggestions toolbar behaviour.
* Improved revenue tracking.
* Improved internal events.
* Improved input placeholder handling.

##### Bug Fixes

* Fixed a minor and rare event tracking issue.

## [3.1.1](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.1.1) (07/27/2016)

##### Enhancements

* Improved image loading logic.
* Improved action handling.

##### Bug Fixes

* Fixed a return key handling issue.

## [3.1.0](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.1.0) (07/19/2016)

This is our first big update to the third major version of our SDK, introducing support for built-in user permissions, automatic In-App Purchase handling, an improved flow structure, a custom suggestion toolbar, and cookie attribution, along with many other smaller changes and fixes. Please take a look at our [Upgrade Guide](http://docs.goprimer.com/v3.1.0/docs/upgrade-guide) for more information on what changed and how to update your integration.

## [3.0.1](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.0.1) (06/07/2016)

##### Enhancements

* Improved documentation.
* Improved attribution reliability.
* Improved thread safety handling.
* Improved error handling.
* Improved data migration.
* Improved event handling.
* Improved data handling.

##### Bug Fixes

* Fixed an attribution info mutation bug.
* Fixed a rare migration issue.

## [3.0.0](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.0.0) (04/13/2016)

We re-architectured and rewrote our whole SDK to make it even better, more stable, and future proof. While doing so we cleaned up the public interface in a major way. Please take a look at our [Upgrade Guide](http://docs.goprimer.com/v3.0.0/docs/upgrade-guide) for more information on what changed and how to update your integration.

## [3.0.0 Beta 6](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.0.0-beta.6) (04/05/2016)

##### Enhancements

* Improved server response value parsing.
* Improved header documentation.
* Improved notification handling.

##### Removals

* Deleted the `shouldUseIDFA` getter from the public interface.

## [3.0.0 Beta 5](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.0.0-beta.5) (03/31/2016)

##### New Features

* Added support for navigation to the next screen.

##### Bug Fixes

* Fixed a bug with dynamic variable replacement.

## [3.0.0 Beta 4](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.0.0-beta.4) (03/28/2016)

##### Enhancements

* Improved custom presentation behaviour.
* Improved public header documentation.
* Improved experience override key handling.
* Improved deep link handling.
* Improved dynamic variable replacement.

##### Bug Fixes

* Fixed Bitcode exporting with Xcode 7.3.
* Fixed occasional keyboard flashing glitch.

## [3.0.0 Beta 3](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.0.0-beta.3) (03/18/2016)

##### New Features

* Added support for navigation pop gesture.

##### Enhancements

* Improved header documentation.
* Improved server response value parsing.

##### Bug Fixes

* Fixed a bug with self closing button actions.

## [3.0.0 Beta 2](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.0.0-beta.2) (03/16/2016)

##### Enhancements

* Improved user property handling when syncing with the Primer servers.
* Improved error message display after a delegate callback.

##### Bug Fixes

* Fixed a rare UI glitch when showing the keyboard and an error message at the same time.

## [3.0.0 Beta 1](https://github.com/goprimer/primer-ios-sdk/releases/tag/3.0.0-beta.1) (03/15/2016)

The first beta of v3.0.0, containing all the changes since v2.

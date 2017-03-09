//
//  PMRLoggingLevel.h - Copyright © 2017 Primer. All rights reserved.
//

/**
 The level of logging that should be visible in the console.
 
 Error logs are about events that have a high impact, possible blocking the SDK from functioning.
 They help you know when the integration is not set up properly.
 
 Warning logs are important messages that influence the intended and correct behaviour of the SDK.
 They help you know when you could improve the way you use the SDK.
 
 Info logs are shedding light on the internal actions of the SDK.
 They help you know what is happening at all moments.
 
 Debug logs are revealing verbose information about the internal actions of the SDK.
 They help you debug specific issues around SDK behaviour.
 */
typedef NS_ENUM(NSInteger, PMRLoggingLevel)
{
    /// No logs are visible.
    PMRLoggingLevelNone,
    
    /// Only error logs are visible.
    PMRLoggingLevelError,
    
    /// Warning and error logs are visible.
    PMRLoggingLevelWarning,
    
    /// Info, warning and error logs are visible.
    PMRLoggingLevelInfo,
    
    /// Debug, info, warning and error logs are visible.
    PMRLoggingLevelDebug
};

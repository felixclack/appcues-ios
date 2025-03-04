//
//  Appcues.h
//  Appcues
//
//  Copyright (c) 2013 Appcues, Inc. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/** This is the interface for the Appcues iOS SDK.  From here you can begin and end sessions, track, update or increment attributes
 that you can use to create filters and segments out of on the web.

 @note This product is currently in beta as we add more features to it.
 */

@interface Appcues : NSObject

//=========================================================================================================
/** @name Connecting to Appcues. */
//=========================================================================================================
/*!
 Prior to sending any data to Appcues, the SDK must be initialized with a valid `apiKey` and `appId`.
 These can be found in the configuration section of your application's
 settings page.

 This should be placed in the iOS application delegate like so;

    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:
                         (NSDictionary *)launchOptions
    {
        // Override point for customization after application launch
        [Appcues setApiKey:@"my_api_key" forAppId:@"my_app_id"];
        return YES;
    }

 @param apiKey The api key required to communicate with your Appcues application.
 @param appId The app id of your Appcues application.
 @since Available since version 1.0
 */

+ (void)setApiKey:(NSString *)apiKey forAppId:(NSString *)appId;

//=========================================================================================================
/** @name Session control. */
//=========================================================================================================

/*!
 Begins a session for the specified user with both an email address and a unique identifier.  Only use this
 method if both pieces of information are present.
 @note Sessions only need to begin on authentication success.  Appcues listens for `UIApplication` state
 changes so endSession doesn't need to be implemented in any additional locations other than a logout method.
 @param userId A unqiue identifier representing the user..
 @param email The user's email address.
 @since Available since version 1.0
 */
+ (void)beginSessionForUserWithUserId:(NSString *)userId andEmail:(NSString *)email;

/*!
 Ends a session for a user. Typically used while logged a user out. All other changes of application state
 are managed for you so there is no need to implement this in your application's delegate.
 @note Only implement endSession when logging a user out of your application.  You will not need to implement it
 anywhere else as Appcues listens for changes in UIApplication state and calculates sessions based on those actions.
 @since Available since version 1.0
 */
+ (void)endSession;

//=========================================================================================================
/** @name Working with attributes. */
//=========================================================================================================
/*!
 Incrementing an attribute will add a value of `1` to the key of your choice.

 In the example below, the attribute `sent_support_request` is incremented by a value of `1` every time.

    [Appcues incrementAttribute:@"sent_support_request"];

 @param attribute The name for which the attribute will be recorded under.
 @since Available since version 1.0
 */
+ (void)incrementAttribute:(NSString *)attribute;

/*!
 Updating attributes allows for the submission of multiple attributes with custom values. Attribute values can
 also be decremented by using a negative operator.

 For example, the following dictionary can be sent;

    [Appcues updateAttributes:@{ @"increments" : @{ @"made_in_app_purchase" : @1 }, @"last_purchase_date" : @12345678 }];

 Where `made_in_app_purchase` is incremented with a value of 1 and `last_purchase_date` is simply updated with
 the timestamp `12345678`.

 @param attributes This is a dictionary containing key/value pairs for multiple attributes.
 @warning Attributes may be either a `string`, `integer`, `double`, `unix timestamp` or `bool`.
 @note Note that to set custom incremental values, the syntax is { @"increments" : @{ @"made_in_app_purchase" : @1 } }
 @since Available since version 1.0

 */
+ (void)updateAttributes:(NSDictionary *)attributes;

//=========================================================================================================
/** @name Logging. */
//=========================================================================================================
/*!
 The Appcues iOS SDK has a logging mode that you can use to see if sessions are being created and messages are being delivered.

 Enable logging by simply calling

        [Appcues loggingEnabled:YES];

 in your application delegate under where the api-key and app-id are set. Disable this for release builds should you wish to mute the SDK's output.
 @param logging A boolean value for enabling or disabling logging throughout the SDK.
 @note Logging is turned off by default. To see logs, please enable it in your application's delegate.
 @since Available since version 1.1.4
 */

+ (void)loggingEnabled:(BOOL)logging;

//=========================================================================================================
/** @name Troubleshooting a statusbar offset. */
//=========================================================================================================
/*!
 Depending on the composition of your rootViewController, sometimes in messages appear to be offset by 20 pixels, the height of the status bar.
 This is due to Apple's expectation of navigation controllers being used as top level contructs and not beind children of UIViewControllers.

 If messages being displayed in your apps appear 20 pixels out of place, call

    [Appcues requiresDisplayOffset:YES];

 and the SDK will force messages to draw 20 pixels higher.

 By default, this is set to NO.

 @param offset A boolean value determining if the offset should be applied. NO by default.
 @note This bug has only been observed in iOS 6. In iOS 7 the display offset is ignored.
 @since Available since version 1.1.4
 */
+ (void)requiresDisplayOffset:(BOOL)offset;

@end
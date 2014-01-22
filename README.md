# Appcues iOS SDK [Beta]
The Appcues iOS SDK currently supports **iOS 5.0 and greater**, and only portrait mode.

## How to Install

1. Copy `Appcues.h` and `libAppcues.a` to your Xcode project. B sure to include `Appcues.h` in your precompiled header (.pch) file. The library is a fat binary, so will work on both the iOS simulator and devices.
2. Under your target's build settings in Xcode, include the `-ObjC` & `-all_load` flags under `Other Linker Flags`.
![Other linker flags](https://www.dropbox.com/s/je9ph4bd16kmipk/Screenshot%202014-01-22%2013.57.35.png)
3. Include the `QuartzCore` framework in your app
![Quartz](https://www.dropbox.com/s/3u2xy7lglks39hs/Screenshot%202014-01-22%2013.58.18.png)

### Initializing Appcues

In order to initialize Appcues in your iOS app, copy your iOS API key and App ID from the API keys page in Appcues. Then, add the following line to your application delegate:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch
    [Appcues setApiKey:@"your-api-key" forAppId:@"your-app-id"];

    return YES;
}
```

### Identifying Users
Appcues only tracks users who are logged in to your app.  With this in mind, you should begin a session for a user at the point in your app where authentication is confirmed.  Don't worry if Appcues hasn't seen a user before, that user will be created when the session begins.

Appcues requires a user ID and email address, but you can replace one of them with a static value. The important thing is to create a persistent, unique identifier.

3. **Both.** Should you have an ID you would like to couple with an email address, you can send them both;
`[Appcues beginSessionForUserWithUserId:@"12345" andEmail:@"appcues@github.com"];`

Once a session has begun, Appcues will track UIApplication state changes for you, so you won't need to explicity start and stop a session. Start on login and end on logout, we'll do the rest.

### End a session
End a session when your user successfully logs out of your application by adding `[Appcues endSession];` at that point.

## Working with attributes
You can send any data you like to Appcues. Typically our customers see a lot of value in sending data that relates to customer development, such as price plan, value of purchases, etc. Once these have been sent to Appcues you can then apply filters based on these attributes.

You do not have to create attributes in Appcues beforehand. If one hasn't been seen before, it will be created for you.

#### Custom attributes
You can send a `NSDictionary` containing multiple attributes also. Note that attribute values may be either a `string`, `integer`, `double`, `unix timestamp` or `bool`.

`[Appcues updateAttributes:@{ @"last_purchase_date" : @12345678, @"fullName" : "Chuck Norris" }];`

## Showing Onboarding Flows
With the iOS SDK you can now publish onboarding flows to your iOS apps from your Appcues account. The Appcues SDK requires that you have a `rootViewController` at the end of application launch in order to use messaging features.

#### How does it work

Just log into your Appcues account and choose the flow you want to publish. You can filter it to specific users depending on their attributes, session count, feature usage, etc.


## Logging
By default the Appcues iOS SDK has logging disabled. Should you wish to enable it, simply call `[Appcues loggingEnabled:YES];` in your application's `didFinishLaunchingWithOptions:` method.

## Questions and Support

Have questions? Get in touch with us at [support@appcues.com](mailto:support@appcues.com). We're happy to help!

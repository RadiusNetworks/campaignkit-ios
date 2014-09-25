//  Copyright (c) 2014 Radius Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CKManagerDelegate.h"
#import "CKCampaign.h"


typedef NS_ENUM (NSInteger, CKAnalyticsType) {
    CKAnalyticsFound,
    CKAnalyticsViewed,
    CKAnalyticsFulfilled,
};


/** CKManager
 *
 * The `CKManager` class defines the interface for configuring the delivery of campaign related events to your application.
 *
 */
@interface CKManager : NSObject

/** getVersion
 *
 * Get the version string for the Campaign Kit Framework
 *
 */
+ (NSString *)getVersion;


/*! Returns a new instance of a `CKManager` that uses the supplied delegate to delivery events.

 Example usage:
 
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
    {
        self.campaignKitManager = [CKManager managerWithDelegate:self];
        [self.campaignKitManager start];
        return YES;
    }
 
 @see CKManagerDelegate
 */
+ (CKManager *)managerWithDelegate:(id <CKManagerDelegate> )delegate;

/**
 * returns an instance of CKCampaign with the given id.
 */
- (CKCampaign*)campaignWithId: (NSString*)idStr;

- (CKCampaign*)campaignFromNotification: (UILocalNotification*)notification;

/*!
 Sets up the manager and synchronizes data with the server.
 */
- (void)start;

/*!
 Unregister regions and beacons and stop automatic syncing.

 While the CKManager is stopped, if `sync` is called the API will be called
 and data downloaded and synced. However, any regions will not be
 registered with CoreLocation.
 */
- (void)stop;

/*!
 Force a sync with the server. This is not normally required.
 */
- (void)sync;

/*! syncWithCompletionHandler

 Same as `-sync`, but it works synchronously (it returns when complete) and it
 accepts a block for the sync callback. This is
 particularly useful for updating the ProximityKit data when the
 application in in the background.
 To take advantage of this you need to implement
 `application:performFetchWithCompletionHandler:` in your
 application delegate. Then within that method you can simply call
 `syncWithCompletionHandler` and pass it the completion block:

    - (void) application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
    {
       // ...
       [ckManager syncWithCompletionHandler: completionHandler];
    }


 Be sure to set the fetch interval in your didFinishLaunching method:


    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
    {
       // ...
       [application setMinimumBackgroundFetchInterval:UIApplicationBackgroundFetchIntervalMinimum];
       return YES;
    }


 Finally make sure you add `UIBackgroundModes` to your info plist with a string set to 'fetch'

 */
- (void)syncWithCompletionHandler:(void ( ^ ) ( UIBackgroundFetchResult ))completionHandler;

/*!
 Add a campaign to the list of current campaigns
 */
- (void)addCampaign:(CKCampaign*)campaign;

/*!
 Remove a campaign from the list of current campaigns
 */
- (void)removeCampaign:(CKCampaign*)campaign;

/*!
 Remove expired campaigns from the list
 */
- (void)pruneExpiredCampaigns;

/*!
 * Sets the partner identifer string for analytics.
 *
 * Limited to 255 characters.
 *
 */
- (void)setPartnerIdentifier:(NSString *)identifier;

/*!
 Record an analytics event which references a campaign and a place
 */
- (void)recordAnalytics:(CKAnalyticsType)eventType forCampaign:(CKCampaign *)campaign atPlace:(CKPlace *)place;

/*!
 Record an analytics event which references a campaign and a place
 */
- (void)recordAnalytics:(CKAnalyticsType)eventType forCampaign:(CKCampaign *)campaign atPlaceId:(NSInteger)placeId;

/*!
 Record an analytics event which references a campaign
 */
- (void)recordAnalytics:(CKAnalyticsType)eventType forCampaign:(CKCampaign *)campaign;

@property (assign) id <CKManagerDelegate> delegate;

/*!
 Contains a list of all the campaigns that the app has found.
 
 This can be used to populate a TableView with all currently active campaigns that the app has encountered.
 */
@property (readonly) NSArray *campaigns;

@end

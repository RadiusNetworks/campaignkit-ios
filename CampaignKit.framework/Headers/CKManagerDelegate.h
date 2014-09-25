//  Copyright (c) 2014 Radius Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CKCampaign.h"
#import "CKPlace.h"

@class CKManager;

typedef NS_ENUM (NSInteger, CKEventType) {
    CKEventDidRangeBeacons,
    CKEventDidEnterRegion,
    CKEventDidExitRegion,
    CKEventDidDetectStateInside,
    CKEventDidDetectStateOutside,
    CKEventDidDetectStateUnknown,
};


/*!
 The base delegate for Campaign Kit callbacks.
 */
@protocol CKManagerDelegate <NSObject>

@required

/*!
 Invoked when a beacon or geofence is detected that is associated with an active campaign
 
 @discussion This callback can be used to take an action when a campaign is detected.  Below is an
 example which triggers an alert view or local notification:
 
     - (void)campaignKit:(CKManager *)manager didFindCampaign:(CKCampaign *)campaign
     {
        UIApplication* app = [UIApplication sharedApplication];
        if (app.applicationState != UIApplicationStateActive)
        {
            // if in background, pop the notification
            [app presentLocalNotificationNow:[campaign buildLocalNotification]];
            app.applicationIconBadgeNumber = 1;
            NSLog(@"Notification Displayed");
        } else {
            // else if app is open, show alert view
            [CKCampaignAlertView showWithCampaign:campaign andCompletion:^{
                // TODO: show the campaign here
            }];
            NSLog(@"AlertView Displayed");
        }
     }
 
 @see CKCampaign
 @see CKCampaignAlertView
 
 */
- (void)campaignKit:(CKManager*) manager didFindCampaign:(CKCampaign*) campaign;


@optional

/*!
 Invoked when an error has occurred
 */
- (void)campaignKit:(CKManager *)manager didFailWithError:(NSError *)error;

/*!
  Invoked after a sync has completed
 */
- (void) campaignKitDidSync:(CKManager *)manager;

/*!
 Invoked when a place is detected
 */
- (void)campaignKit:(CKManager *)manager didDetectPlace:(CKPlace *)place onEvent:(CKEventType)event;

@end

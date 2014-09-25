//
//  CKCampaignAlertView.h
//  CampaignKit
//
//  Created by Scott Yoder on 7/15/14.
//  Copyright (c) 2014 Radius Networks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CKCampaign.h"

/** CKCampaignAlertView
 *
 * Subclass of UIAlertView that can be initialized with a CKCampaign in order to display an
 * alert related to that campaign.
 *
 */
@interface CKCampaignAlertView : UIAlertView


/** initializes a new CKCampaignAlertView with information from the specified campaign. */
- (id) initWithCampaign:(CKCampaign*)campaign andDelegate:(id<UIAlertViewDelegate>)delegate;

/*!
 Creates a CKCampaignAlertView, shows it, and calls the completion block if & when the user
 presses the "View Details" button.

 Example usage:

     [CKCampaignAlertView showWithCampaign:campaign andCompletion:^{
         // TODO: take action here to display the campaign
     }];
 
 @see CKCampaign
 */
+ (void) showWithCampaign:(CKCampaign*)campaign andCompletion:(void(^)()) block;

@end

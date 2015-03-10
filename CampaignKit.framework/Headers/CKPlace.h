//
//  CKPlace.h
//  CampaignKit
//
//  Created by Scott Yoder on 8/13/14.
//  Copyright (c) 2014 Radius Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class RPKRegion;

typedef NS_ENUM (NSInteger, CKPlaceType) {
    CKPlaceTypeBeacon,
    CKPlaceTypeGeofence,
};

/*!
 CKPlace objects can be returned when a kit's places are detected using the
 [CKManagerDelegate campaignKit:didDetectPlace:onEvent:] callback.
 */
@interface CKPlace : NSObject<NSCoding>

/** The name, as set in the portal */
@property (readonly) NSString* name;

/**  */
@property (readonly) NSInteger id;

/*!
 place type
 
 @see CKPlaceType
 */
@property (readonly) CKPlaceType type;

/** For beacon places, this is the proximity to the beacon */
@property (readonly) CLProximity proximity;

/** For beacon places, this is the one sigma horizontal accuracy in meters */
@property (readonly) CLLocationAccuracy accuracy;

/** For beacon places, this is the received signal strength of the beacon, measured in decibels */
@property (readonly) NSNumber *rssi;


- (CKPlace *)initWithRegion:(RPKRegion *)region;
- (CKPlace *)initWithDict:(NSDictionary *)dict;
- (id)initWithCoder:(NSCoder *)coder;
- (void)encodeWithCoder:(NSCoder *)coder;

+ (NSArray *)parsePlaceIds:(NSString *)placeIds;

@end

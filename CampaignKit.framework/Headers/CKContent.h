//  Copyright (c) 2014 Radius Networks. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/** CKContent contains all the data related to content. */
@interface CKContent : NSObject<NSCoding>

/** The content's id */
@property (strong, nonatomic) NSString *id;

/** The content's alert title */
@property (strong, nonatomic) NSString *alertTitle;

/** The content's alert message */
@property (strong, nonatomic) NSString *alertMessage;

/** The content's html body */
@property (strong, nonatomic) NSString *body;

/** The key value attributes for the content */
@property (strong, nonatomic) NSDictionary *attributes;

@property (readonly) NSData *hashValue;

-(id)initWithCoder:(NSCoder *)coder;
-(void)encodeWithCoder:(NSCoder *)coder;

- (id)initWithDictionary:(NSDictionary*) dictionary;
- (void)updateWithDictionary:(NSDictionary*) dictionary;
- (void)startPreloadingImages;


@end
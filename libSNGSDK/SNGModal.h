//
//  SNGModal.h
//  SNGSDK
//
//  Created by xu huijun on 14-1-23.
//  Copyright (c) 2014年 sina. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RecommendInfo : NSObject
@property (nonatomic, strong) NSString *app_logo_url;
@property (nonatomic, strong) NSString *app_name;
@property (nonatomic, strong) NSString *download_url;
@property (nonatomic, strong) NSString *user_total;
@property (nonatomic, strong) NSString *app_desc;
@property (nonatomic, strong) NSString *appkey;
@property (nonatomic, strong) NSString *link;
@property (nonatomic, strong) NSString *weibo_url;
@property (nonatomic, strong) NSString *package;


+ (NSMutableArray *)recommendListWithDic:(NSDictionary *)dic;

@end

@interface InvitationInfo : NSObject

@property (nonatomic, strong) NSString *invitation_image;
@property (nonatomic, strong) NSString *invitation_name;
@property (nonatomic, strong) NSString *invitation_userid;
@property (nonatomic, strong) NSString *invitation_Character;
@property (nonatomic) BOOL invitation_isSelected;

+ (NSMutableArray *)invitationListWithDic:(NSDictionary *)dic;

@end


@interface CoreDataInfo : NSObject

@property (nonatomic, strong) NSString *invitation_userid;
@property (nonatomic, strong) NSString *invitation_time;

+ (NSMutableArray *)coreDataListWithDic:(NSDictionary *)dic;

@end
//
//  SNGUsersViewController.h
//  SNGSDK
//
//  Created by xu huijun on 14-7-18.
//  Copyright (c) 2014年 sina. All rights reserved.
//

#import <UIKit/UIKit.h>

#define NotificationName_InvitationUsers @"InvitationUsers"

@protocol SNGUsersViewControllerDelegate <NSObject>

-(void)usersViewBackSelected:(NSMutableArray *)users;

@end

typedef NS_ENUM(NSInteger, InvitationStyle)
{
    InvitationStyleNoBilateralApp       = 0,//还未使用某应用的互粉好友
    InvitationStyleBilateralApp         = 1,//使用某应用的互粉好友
    InvitationStyleBilateral            = 2,//所有互粉好友
    
};


@interface SNGUsersViewController : UIViewController

@property(nonatomic,strong)id<SNGUsersViewControllerDelegate> delegate;

@property(nonatomic)int invitationCount;
@property(nonatomic,assign)InvitationStyle invitationStyle;

@end

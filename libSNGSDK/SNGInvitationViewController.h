//
//  SNGInvitationViewController.h
//  SNGSDK
//
//  Created by xu huijun on 14-1-22.
//  Copyright (c) 2014年 sina. All rights reserved.
//

#import <UIKit/UIKit.h>

#define NotificationName_InvitationSuccess @"invitationSuccess"
#define NotificationName_InvitationFailure @"invitationFailure"


@protocol SNGInvitationViewControllerDelegate <NSObject>

-(void)invitationBackSelected;
@end

@interface SNGInvitationViewController : UIViewController

@property(nonatomic,strong)NSString *invitationDescription;

@property(nonatomic,strong)id<SNGInvitationViewControllerDelegate> delegate;

@end

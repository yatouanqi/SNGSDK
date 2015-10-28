//
//  SNGNotice.h
//  SNGSDK
//
//  Created by xu huijun on 14-7-24.
//  Copyright (c) 2014年 sina. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SNGNotice : UIView


+ (void)loadNoticeHtml;//下载公告

+ (BOOL)isHaveNotice;//是否有新的公告

//展示公告
+ (SNGNotice *)showNoticeAddedTo:(UIView *)view
        withInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

//隐藏公告
+ (BOOL)hideNoticeForView:(UIView *)view;

@end

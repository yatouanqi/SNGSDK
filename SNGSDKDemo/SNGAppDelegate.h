//
//  SNGAppDelegate.h
//  SNGSDKDemo
//
//  Created by huijun xu on 13-11-18.
//  Copyright (c) 2013年 sina. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface SNGAppDelegate : UIResponder <UIApplicationDelegate,SNGWeiboSDKDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, strong) NSString* wbtoken;

@end

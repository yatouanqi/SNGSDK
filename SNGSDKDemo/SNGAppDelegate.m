//
//  SNGAppDelegate.m
//  SNGSDKDemo
//
//  Created by huijun xu on 13-11-18.
//  Copyright (c) 2013年 sina. All rights reserved.
//

#import "SNGAppDelegate.h"
#import "SNGFunctionListViewController.h"

@implementation SNGAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
     [[UIApplication sharedApplication] setStatusBarHidden:YES];
    
    [SNGWeiboSDK enableDebugMode:YES];
    [SNGWeiboSDK registerApp:kAppKey
                 redirectURI:kRedirectURI
                       appid:@"8888"
                        IDFA:@"9999"
                         mac:nil];
        
    SNGFunctionListViewController *fun = [[SNGFunctionListViewController alloc] init];
    
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:fun];
//    self.window.rootViewController = nav;

    self.window.rootViewController = fun;
    
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    return YES;
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    return [SNGWeiboSDK handleOpenURL:url delegate:self];
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

//这个方法定义的是当应用程序退到后台时将执行的方法，按下home键执行（通知中心来调度）
//实现此方法的目的是将托管对象上下文存储到数据存储区，防止程序退出时有未保存的数据
- (void)applicationWillTerminate:(UIApplication *)application
{
//    NSError *error;
//    if (managedObjectContext != nil) {
//        //hasChanges方法是检查是否有未保存的上下文更改，如果有，则执行save方法保存上下文
//        if ([managedObjectContext hasChanges] && ![managedObjectContext save:&error]) {
//            NSLog(@"Error: %@,%@",error,[error userInfo]);
//            abort();
//        }
//    }
}

#pragma mark - SNGWeiboSDKDelegate

- (void)didReceiveSNGWeiboRequest:(SNGWBBaseRequest *)request
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"didReceiveSNGWeiboRequest"
                                                    message:@"do something you want"
                                                   delegate:nil
                                          cancelButtonTitle:@"确定"
                                          otherButtonTitles:nil];
    
    
    [alert show];
}

- (void)didReceiveSNGWeiboResponse:(SNGWBBaseResponse *)response
{
    TTLog(@"[SNGWeiboSDK shared].userID = %@",[SNGWeiboSDK shared].userID);
    TTLog(@"statusCode = %d",[response statusCode]);

    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"didReceiveSNGWeiboResponse"
                                                    message:@"do something you want"
                                                   delegate:nil
                                          cancelButtonTitle:@"确定"
                                          otherButtonTitles:nil];
    
    
    [alert show];

}



@end

//
//  SNGSDKTest.m
//  SNGSDKDemo
//
//  Created by huijun xu on 13-12-10.
//  Copyright (c) 2013年 sina. All rights reserved.
//

#import "SNGSDKTest.h"


#define friendshipsBilateral @"http://open.weibo.com/wiki/2/friendships/friends/bilateral"

@implementation SNGSDKTest

+(void)getFriendshipsBilateralWithSource:(NSString *)source
                                     uid:(NSString *)uid
                                   count:(int)count
                                    page:(int)page
                                    sort:(int)sort
                                 success:(void (^)(id JSON))success
                                 failure:(void (^)(id JSON))failure
{
    NSMutableDictionary *params = [NSMutableDictionary dictionary];
    [params setObject:source forKey:@"source"];
    [params setObject:[SNGWeiboSDK shared].accessToken forKey:@"access_token"];
    [params setObject:uid  forKey:@"uid"];
    [params setObject:[NSNumber numberWithInt:count] forKey:@"count"];
    [params setObject:[NSNumber numberWithInt:page] forKey:@"page"];
    [params setObject:[NSNumber numberWithInt:sort] forKey:@"sort"];
    
    [self openAPIGetFromPath:friendshipsBilateral
                      params:params
                     success:success
                     failure:failure];
}

@end

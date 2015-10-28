//
//  SNGSDKTest.h
//  SNGSDKDemo
//
//  Created by huijun xu on 13-12-10.
//  Copyright (c) 2013年 sina. All rights reserved.
//

#import "SNGSDK.h"

@interface SNGSDKTest : SNGSDK

+(void)getFriendshipsBilateralWithSource:(NSString *)source
                                     uid:(NSString *)uid
                                   count:(int)count
                                    page:(int)page
                                    sort:(int)sort
                                 success:(void (^)(id JSON))success
                                 failure:(void (^)(id JSON))failure;
@end

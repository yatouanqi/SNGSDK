//
//  SNGFunctionListViewController.m
//  SNGSDKDemo
//
//  Created by huijun xu on 13-11-18.
//  Copyright (c) 2013年 sina. All rights reserved.
//

#import "SNGFunctionListViewController.h"
#import "SNGRecommendViewController.h"
#import "SNGInvitationViewController.h"
#import "SNGUsersViewController.h"

#import "NSStringAdditions.h"

#import "SNGNotice.h"
#import "SNGModal.h"


@interface SNGFunctionListViewController ()<SNGWBHttpRequestDelegate,SNGInvitationViewControllerDelegate,SNGUsersViewControllerDelegate>
{
    NSDictionary *dataDic;
    NSDictionary *dataHeaderDic;
}
@end

@implementation SNGFunctionListViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
//   self.navigationController.navigationBar.translucent = NO;

    
    NSArray * dataArr0 = @[@"邀请好友界面"
                           ,@"推荐游戏列表"
                           ,@"选择你支持的明星战队（竖版）"
                           ,@"选择你支持的明星战队（横版）"
                           ,@"退出战队(流程重试)"
                           ,@"开启应用，启动明星策略(竖版)"
                           ,@"选择用户"
                           ,@"公告"
                           ,@"设备激活"];
    
    NSArray * dataArr1 = @[@"获取排名列表"
                           ,@"获取我的排名列表"
                           ,@"查询排名接口"
                           ,@"开始游戏接口"
                           ,@"更新分数接口"
                           ,@"更新多个分数接口"
                           ,@"更新分数，为明星增加贡献值"];
    
    NSArray * dataArr2 = @[@"同步体力值接口"
                           ,@"增加或消耗体力接口"];
    NSArray * dataArr3 = @[@"获取当前用户礼物接口"
                           ,@"赠送礼物接口"
                           ,@"赠送礼物通知接口"
                           ,@"批量收取礼物接口"];
    NSArray * dataArr4 = @[@"获取存档接口"
                           ,@"更新存档文件接口"];
    NSArray * dataArr5 = @[@"获取使用某应用的互粉好友信息"
                           ,@"获取还未使用某应用的互粉好友信息"
                           ,@"*获取最近联系的互粉好友"
                           ,@"发送邀请接口"
                           ,@"私信炫耀接口"];
    
    NSArray * dataArr6 = @[@"读取用户某款游戏信息接收状态接口"
                           ,@"读取用户礼物接收状态接口"
                           ,@"更新用户信息接收状态接口"
                           ,@"更新用户礼物接收状态接口"];
    
    NSArray * dataArr7 = @[@"获取明星活动接口"
                           ,@"获取明星排行接口"
                           ,@"更新用户信息接收状态接口"];
    
    NSArray * dataArr8 = @[@"获取个人资料"
                           ,@"*获取互粉好友信息列表"
                           ,@"*获取互粉好友ID列表"
                           ,@"*获取粉丝列表"
                           ,@"*获取活跃粉丝列表"
                           ,@"*判断两个ID是否互粉"
                           ,@"*获取地理位置"
                           ,@"*获取用户最新照片列表"
                           ,@"*批量查看照片信息"
                           ,@"发送微博"
                           ,@"上传图片并发送微博"
                           ,@"加关注"
                           ,@"获取用户关注接口"];
    
    
    NSArray * dataArr9 = @[@"获取系统消息接口"
                           ,@"检查更新接口"
                           ,@"*获取应用列表接口"
                           ,@"*应用详情接口"
                           ,@"推荐应用接口"
                           ,@"签到接口"
                           ,@"提交建议接口"
                           ,@"*发送通知/公告接口"
                           ,@"*日志上传接口"
                           ,@"*应用信息变更接口"
                           ,@"*同步应用接口"];
    NSArray * dataArr10 = @[@"*获取全部游戏列表接口"
                           ,@"*获取使用某应用的用户信息"
                           ,@"*获取我的游戏列表接口"
                           ,@"*获取顶部推荐游戏列表接口"
                           ,@"*设置banner图"];


    dataDic = @{@"0": dataArr0
                ,@"1":dataArr1
                ,@"2":dataArr2
                ,@"3":dataArr3
                ,@"4":dataArr4
                ,@"5":dataArr5
                ,@"6":dataArr6
                ,@"7":dataArr7
                ,@"8":dataArr8
                ,@"9":dataArr9
                ,@"10":dataArr10};
    
    dataHeaderDic = @{@"0": @"内置页面"
                      ,@"1":@"排名接口"
                      ,@"2":@"体力值接口"
                      ,@"3":@"游戏礼物接口"
                      ,@"4":@"存档接口"
                      ,@"5":@"互动接口"
                      ,@"6":@"用户设置接口"
                      ,@"7":@"明星接口"
                      ,@"8":@"微博接口"
                      ,@"9":@"SDK系统接口"
                      ,@"10":@"*游戏中心接口"};
    
    
    
    [[NSNotificationCenter defaultCenter] addObserver: self
                                             selector: @selector(invitaionNotice:)
                                                 name: NotificationName_InvitationSuccess
                                               object: nil];
    
    [[NSNotificationCenter defaultCenter] addObserver: self
                                             selector: @selector(invitaionNotice:)
                                                 name: NotificationName_InvitationFailure
                                               object: nil];
    
    [[NSNotificationCenter defaultCenter] addObserver: self
                                             selector: @selector(invitaionNotice:)
                                                 name: NotificationName_InvitationUsers
                                               object: nil];

    
}

-(void)invitaionNotice:(NSNotification *) notification
{
    //邀请成功/失败的回调//被邀请的人
    
//    //以下为选择用户回调处理
//    InvitationInfo *userinfo = [notification.object objectAtIndex:0];
//    
//    NSLog(@"notification = %@",userinfo.invitation_name);
}

#pragma mark- SNGInvitationViewControllerDelegate

-(void)invitationBackSelected
{
    [self showAlert:@"邀请返回"];
}

#pragma mark- SNGUsersViewControllerDelegate

-(void)usersViewBackSelected:(NSMutableArray *)users
{
    [self showAlert:users];
}


#pragma mark - UITableViewDataSource

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return  [dataHeaderDic objectForKey:[NSString stringWithFormat:@"%ld",(long)section]];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [[dataDic objectForKey:[NSString stringWithFormat:@"%ld",(long)section]] count];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [dataHeaderDic count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *cellIdentifier = @"cellIdentifier";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
    }
    cell.textLabel.text = [[dataDic objectForKey:[NSString stringWithFormat:@"%ld",(long)indexPath.section]] objectAtIndex:indexPath.row];
    cell.textLabel.font = [UIFont systemFontOfSize:12];
    cell.textLabel.textColor = [UIColor darkGrayColor];
    return cell;
}



#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 40;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    if (indexPath.section == 0) {
        
//        NSString *bgImagePath = [[NSBundle mainBundle] pathForResource:@"游戏背景图" ofType:@"jpg"];
        
        if (indexPath.row == 0) {
            SNGInvitationViewController * invitation = [[SNGInvitationViewController alloc] init];
            invitation.invitationDescription = @"亲，一起来玩儿吧!";
            UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:invitation];
            [self presentModalViewController:nav animated:YES];
            invitation.delegate = self;
            
          }else if (indexPath.row == 1){
              
            SNGRecommendViewController * recommend = [[SNGRecommendViewController alloc] init];
              UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:recommend];
              [self presentModalViewController:nav animated:YES];
//            [self.navigationController pushViewController:recommend animated:YES];
        }else if (indexPath.row == 2)
        {

        }else if (indexPath.row == 3)
        {

        }else if (indexPath.row == 4)
        {
            
        }else if (indexPath.row == 5)
        {

        }else if (indexPath.row == 6)
        {
            SNGUsersViewController * usersVC = [[SNGUsersViewController alloc] init];
            usersVC.invitationCount = 10;
            usersVC.invitationStyle = InvitationStyleBilateral;
            usersVC.delegate = self;
            UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:usersVC];
            [self presentModalViewController:nav animated:YES];
            
        }else if (indexPath.row == 7)
        {
            if ([SNGNotice isHaveNotice]) {
                [SNGNotice showNoticeAddedTo:self.view
                    withInterfaceOrientation:UIInterfaceOrientationPortrait];
            }
        }else if (indexPath.row == 8)
        {
            [SNGSDK interfaceDevicesActivationSuccess:^(id JSON) {
                [self showAlert:JSON];
            } failure:^(id JSON) {
                [self showNeworkAlert:JSON];
            }];
        }
        
    }else if (indexPath.section == 1) {
        if (indexPath.row == 0) {
            [SNGSDK getRankingListWithRankKey:kRankKey
                                    rankGroup:kGroup
                                        scope:1
                                       myRank:1
                                       period:0
                                   giftStatus:1
                                        count:100
                                         page:1
                                      success:^(id JSON) {
                                          
                                          [self showAlert:JSON];
                                      }
                                      failure:^(id JSON) {
                                          [self showNeworkAlert:JSON];
                                      }];
            
        }else if (indexPath.row == 1)
        {
            [SNGSDK getMyRankListWithRankKey:kRankKey
                                   rankGroup:kGroup
                                       scope:2
                                      period:0
                                  giftStatus:1
                                     success:^(id JSON) {
                                         [self showAlert:JSON];
                                     }
                                     failure:^(id JSON) {
                                         [self showNeworkAlert:JSON];
                                     }];
        }else if (indexPath.row == 2)
        {
            [SNGSDK getRankOrderWithRankKey:kRankKey
                                  rankGroup:kGroup
                                      scope:1
                                      score:0
                                     period:0
                                 giftStatus:1
                                    success:^(id JSON) {
                                        [self showAlert:JSON];
                                    }
                                    failure:^(id JSON) {
                                        [self showNeworkAlert:JSON];
                                    }];
        }else if (indexPath.row == 3)
        {
            [SNGSDK startAppWithNeedPower:0
                                  success:^(id JSON) {
                                      [[NSUserDefaults standardUserDefaults] setObject:[JSON objectForKey:@"game_id"] forKey:@"sng_gameid"];
                                      [[NSUserDefaults standardUserDefaults] synchronize];
                                      

                                      [self showAlert:JSON];
                                  }
                                  failure:^(id JSON) {
                                      [self showNeworkAlert:JSON];
                                  }];
        }else if (indexPath.row == 4)
        {
            NSString *gameid = [[NSUserDefaults standardUserDefaults] objectForKey:@"sng_gameid"];
            
            [SNGSDK updateDataWithRankKey:kRankKey
                                rankGroup:kGroup
                                   gameId:gameid
                                     data:2
                                    token:stringLogQuery(@{@"gameid": gameid})
                                   option:NO
                                  success:^(id JSON) {
                                      [self showAlert:JSON];
                                      
                                  } failure:^(id JSON) {
                                      [self showNeworkAlert:JSON];
                                      
                                  }];
 
        }else if (indexPath.row == 5)
        {
            NSString *dataStr = @"[{\"score\":1200,\"rank_group\":1,\"rank_key\":5555},{\"score\":13,\"rank_group\":2,\"rank_key\":1}]";
            NSString *gameid = [[NSUserDefaults standardUserDefaults] objectForKey:@"sng_gameid"];

            [SNGSDK updateMultiDataWithGameId:gameid
                                         data:dataStr
                                        token:stringLogQuery(@{@"gameid": gameid})
                                       option:NO
                                      success:^(id JSON) {
                                          [self showAlert:JSON];
                                      }
                                      failure:^(id JSON) {
                                          [self showNeworkAlert:JSON];
                                      }];
        }else if (indexPath.row == 6)
        {
            NSString *gameid = [[NSUserDefaults standardUserDefaults] objectForKey:@"sng_gameid"];
            [SNGSDK updateDataWithRankKey:kRankKey
                                rankGroup:kGroup
                                   gameId:gameid
                               activityId:1
                                     data:20
                                    token:stringLogQuery(@{@"gameid": gameid})
                                   option:NO
                                  success:^(id JSON) {
                                      [self showAlert:JSON];
                                  }
                                  failure:^(id JSON) {
                                      [self showNeworkAlert:JSON];
                                      
                                  }];
        }
    }else if (indexPath.section == 2)
    {
        if (indexPath.row == 0) {
            [SNGSDK syncPowerWithPowerKey:1
                                  success:^(id JSON) {
                                      [self showAlert:JSON];
                                  }
                                  failure:^(id JSON) {
                                      [self showNeworkAlert:JSON];
                                  }];
        }else if (indexPath.row == 1)
        {
            [SNGSDK updatePowerWithPowerKey:1
                                  increment:1
                                    success:^(id JSON) {
                                        [self showAlert:JSON];
                                    } failure:^(id JSON) {
                                        [self showNeworkAlert:JSON];
                                    }];
        }
    }
    else if (indexPath.section == 3)
    {
        if (indexPath.row == 0) {
            [SNGSDK showGiftWithGiftKey:10001
                                 status:1
                                  count:10
                                   page:1
                                success:^(id JSON) {
                                    [self showAlert:JSON];
                                } failure:^(id JSON) {
                                    [self showNeworkAlert:JSON];
                                }];
        }else if (indexPath.row == 1)
        {
            [SNGSDK giveGiftWithGiftKey:10001
                             targerUser:@"3508971941"
                            description:@"我礼物很多，可怜你一下吧！"
                                  count:1
                           notification:0
                             notifyData:nil
                                success:^(id JSON) {
                                    [self showAlert:JSON];
                                }
                                failure:^(id JSON) {
                                    [self showNeworkAlert:JSON];
                                }];
        }else if (indexPath.row == 2)
        {
            [SNGSDK giveGiftNotifyWithGiftId:@"1208"
                                     content:@"谢谢你哦，嘿嘿！"
                                     success:^(id JSON) {
                                         [self showAlert:JSON];
                                     } failure:^(id JSON) {
                                         [self showNeworkAlert:JSON];
                                     }];
        }
        else if (indexPath.row == 3)
        {
            [SNGSDK receiveBatchGiftWithGiftIds:@"2699"
                                        success:^(id JSON) {
                                            [self showAlert:JSON];
                                        }
                                        failure:^(id JSON) {
                                            [self showNeworkAlert:JSON];
                                        }];
        }
    }else if (indexPath.section == 4)
    {
        if (indexPath.row == 0) {
            [SNGSDK getArchiveWithArchiveKey:@"1"
                                     success:^(id JSON) {
                                         [self showAlert:JSON];
                                     } failure:^(id JSON) {
                                         [self showNeworkAlert:JSON];
                                     }];
        }else if (indexPath.row == 1)
        {
            [SNGSDK updateArchiveWithArchiveKey:@"1"
                                        content:@"1"
                                        success:^(id JSON) {
                                            [self showAlert:JSON];
                                        } failure:^(id JSON) {
                                            [self showNeworkAlert:JSON];
                                        }];
        }
    }else if (indexPath.section == 5)
    {
        if (indexPath.row == 0) {
            [SNGSDK bilateralAppWithCount:1
                                     page:1
                                  success:^(id JSON) {
                                      [self showAlert:JSON];
                                  } failure:^(id JSON) {
                                      [self showNeworkAlert:JSON];
                                  }];
        }else if (indexPath.row == 1)
        {
            [SNGSDK noBilateralAppWithCount:1
                                       page:1
                                    success:^(id JSON) {
                                        [self showAlert:JSON];
                                    } failure:^(id JSON) {
                                        [self showNeworkAlert:JSON];
                                    }];
        }else if (indexPath.row == 2)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 3)
        {
            NSString *dataStr = @"{\"text\":\"你好1\"}";
            
            [SNGSDK inviteFriendWithUids:@"3508971941"
                                    data:dataStr
                                 success:^(id JSON) {
                                     [self showAlert:JSON];
                                 } failure:^(id JSON) {
                                     [self showNeworkAlert:JSON];
                                 }];
        }else if (indexPath.row == 4)
        {
            NSString *dataStr = @"{\"text\":\"你好2\"}";

            [SNGSDK showoffFriendWithUids:@"3508971941"
                                     data:dataStr
                                  success:^(id JSON) {
                                      [self showAlert:JSON];
                                  } failure:^(id JSON) {
                                      [self showNeworkAlert:JSON];
                                  }];
        }
    }else if (indexPath.section == 6)
    {
        if (indexPath.row == 0) {
            [SNGSDK showReceiveMessageByUserSettingSuccess:^(id JSON) {
                [self showAlert:JSON];
            } failure:^(id JSON) {
                [self showNeworkAlert:JSON];
            }];
        }else if (indexPath.row == 1)
        {
            [SNGSDK showReceiveGiftByUserSettingSuccess:^(id JSON) {
                [self showAlert:JSON];
            }
                                                failure:^(id JSON) {
                                                    [self showNeworkAlert:JSON];
                                                }];
        }else if (indexPath.row == 2)
        {
            [SNGSDK updateReceiveMessageByUserSettingWithSettingValue:0
                                                              success:^(id JSON) {
                                                                  [self showAlert:JSON];
                                                              } failure:^(id JSON) {
                                                                  [self showNeworkAlert:JSON];
                                                              }];
        }else if (indexPath.row == 3)
        {
            [SNGSDK updateReceiveGiftByUserSettingWithSettingValue:1
                                                           success:^(id JSON) {
                                                               [self showAlert:JSON];
                                                           } failure:^(id JSON) {
                                                               [self showNeworkAlert:JSON];
                                                           }];
        }
    }else if (indexPath.section == 7)
    {
        if (indexPath.row == 0) {

        }else if (indexPath.row == 1)
        {
            
        }else if (indexPath.row == 2)
        {
        }

    }else if (indexPath.section == 8)
    {
        if (indexPath.row == 0) {
            [SNGSDK getUserInfoSuccess:^(id JSON) {
                [self showAlert:JSON];
            }
                               failure:^(id JSON) {
                                   [self showNeworkAlert:JSON];
                               }];
        }else if (indexPath.row == 1)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 2)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 3)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 4)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 5)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 6)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 7)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 8)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 9)
        {
            [SNGSDK sendWeiboWithStatus:@"我喜欢看《爸爸去哪儿》，喜欢kimi，哈哈！"
                                success:^(id JSON) {
                                    [self showAlert:JSON];
                                } failure:^(id JSON) {
                                    [self showNeworkAlert:JSON];
                                }];
        }else if (indexPath.row == 10)
        {
            [SNGSDK sendWeiboWithPic:[UIImage imageNamed:@"9VI5Q1555O1Q0005.jpg"]
                              status:@"发个美图，喜欢不？"
                             success:^(id JSON) {
                                 [self showAlert:JSON];
                             } failure:^(id JSON) {
                                 [self showNeworkAlert:JSON];
                             }];
        }else if (indexPath.row == 11)
        {
            [SNGSDK createFriendshipsWithUid:@"3508971941"
                                  screenName:nil
                                     success:^(id JSON) {
                                         [self showAlert:JSON];
                                     } failure:^(id JSON) {
                                         [self showNeworkAlert:JSON];
                                     }];
        }else if(indexPath.row == 12)
        {
            [SNGSDK getFriendshipsWithUid:[SNGWeiboSDK shared].userID
                               screenName:nil
                                    count:10
                                   cursor:0
                               trimStatus:0
                                  success:^(id JSON) {
                                      [self showAlert:JSON];
                                  }
                                  failure:^(id JSON) {
                                      [self showNeworkAlert:JSON];
                                  }];
        }
        
    }else if (indexPath.section == 9)
    {
        if (indexPath.row == 0) {
            [SNGSDK showNotificationWithType:1
                                       maxId:1
                                       count:1
                                        page:1
                                     success:^(id JSON) {
                                         [self showAlert:JSON];
                                     } failure:^(id JSON) {
                                         [self showNeworkAlert:JSON];
                                     }];
        }else if (indexPath.row == 1)
        {
            [SNGSDK checkForUpdateWithVersionCode:1
                                    versionName:@"1.0.0"
                                    packageName:@"com.sina.sng"
                                        success:^(id JSON) {
                                            [self showAlert:JSON];
                                        } failure:^(id JSON) {
                                            [self showNeworkAlert:JSON];
                                        }];

        }else if (indexPath.row == 2)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 3)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 4)
        {
            [SNGSDK getRecommendGameSuccess:^(id JSON) {
                [self showAlert:JSON];

            } failure:^(id JSON) {
                [self showNeworkAlert:JSON];
            }];
        }else if (indexPath.row == 5)
        {
            [SNGSDK signinWithAppVersion:2
                                 netInfo:nil
                                 success:^(id JSON) {
                                     [self showAlert:JSON];
                                 } failure:^(id JSON) {
                                     [self showNeworkAlert:JSON];
                                 }];
        }else if (indexPath.row == 6)
        {
            [SNGSDK suggestWithContent:@"111"
                                mobile:@"111"
                               success:^(id JSON) {
                                   [self showAlert:JSON];
                               } failure:^(id JSON) {
                                   [self showNeworkAlert:JSON];
                               }];
        }else if (indexPath.row == 7)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 8)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 9)
        {
            [self showErrorAlert];

        }else if (indexPath.row == 10)
        {
            [self showErrorAlert];
        }
    }else if(indexPath.section == 10){
        if (indexPath.row == 0) {
            
        }else if (indexPath.row == 1)
        {
            
        }else if (indexPath.row == 2)
        {
            
        }else if (indexPath.row == 3)
        {
            
        }else if (indexPath.row == 4)
        {
            
        }
        [self showErrorAlert];
    }else{
        
    }
    
}

- (void)showErrorAlert
{
    NSString *title = @"接口尚未实现";
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title
                                                    message:nil
                                                   delegate:nil
                                          cancelButtonTitle:@"确定"
                                          otherButtonTitles:nil];
    [alert show];
}

- (void)showAlert:(id)result
{
    NSString *title = @"发送结果";
    NSString *message = [NSString stringWithFormat:@"响应数据:%@",result];
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title
                                                    message:message
                                                   delegate:nil
                                          cancelButtonTitle:@"确定"
                                          otherButtonTitles:nil];
    [alert show];
}

- (void)showNeworkAlert:(id)result
{
    NSString *title = @"发送结果";
    NSString *message = [NSString stringWithFormat:@"响应数据:%@",[result objectForKey:@"error"]];
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title
                                                    message:message
                                                   delegate:nil
                                          cancelButtonTitle:@"确定"
                                          otherButtonTitles:nil];
    [alert show];
}

- (IBAction)ssoOutAction:(id)sender
{
    [SNGWeiboSDK logOutWithDelegate:self];
}

- (IBAction)ssoAction:(id)sender
{
    [SNGWeiboSDK login];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



#pragma mark - SNGWBHttpRequestDelegate

- (void)request:(SNGWBHttpRequest *)request didSNGReceiveResponse:(NSURLResponse *)response
{
    NSLog(@"SNGWBHttpRequest = %@",request);
}

- (void)request:(SNGWBHttpRequest *)request didSNGFailWithError:(NSError *)error
{
    
}

- (void)request:(SNGWBHttpRequest *)request didSNGFinishLoadingWithResult:(NSString *)result
{
    
}

- (void)request:(SNGWBHttpRequest *)request didSNGFinishLoadingWithDataResult:(NSData *)data
{
    
}


@end

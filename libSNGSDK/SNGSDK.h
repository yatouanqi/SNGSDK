//
//  SNGEngine.h
//  SNGSDKDemo
//
//  Created by huijun xu on 13-11-18.
//  Copyright (c) 2013年 sina. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SNGSDK : NSObject

+ (void)cancelRequestWithMethod:(NSString *)method path:(NSString *)path;

+ (void)openAPIPostToPath:(NSString *)path
                   params:(NSDictionary *)params
                  success:(void (^)(id JSON))success
                  failure:(void (^)(id JSON))failure;

+ (void)openAPIGetFromPath:(NSString *)path
                    params:(NSDictionary *)params
                   success:(void (^)(id JSON))success
                   failure:(void (^)(id JSON))failure;

#pragma mark -----------------------------method----------------------------------------------

/**
 获取排名列表接口
 调用此接口后，返回最新的排名信息
 
 @param rank_key 需要获取的排名的key值，为0时表示获取总分排名
 @param rank_group 需要获取的具体的分组，可以与rank_key配合使用，也可以单独使用，0或者不传，表示忽略分组
 @param scope 获取排名的范围， 0为好友中，1,为全部用户，2,为关注的用户中，默认为0,好友中
 @param 增加my_rank参数（是否返回自己的排名信息 0:不返回,默认为0 1:返回）
 @param period 计分周期，不传表示获取最新期的排名
 @param receive_gift_status 是否返回送礼物开关 0 不返回，1 返回  默认为0 不返回
 @param count 单页返回的记录条数，默认为50。
 @param page 返回结果的页码，默认为1。
 */
+ (void)getRankingListWithRankKey:(int)rank_key
                        rankGroup:(int)rank_group
                            scope:(int)scope
                           myRank:(int)myRank
                           period:(int)period
                       giftStatus:(int)receive_gift_status
                            count:(int)count
                             page:(int)page
                          success:(void (^)(id JSON))success
                          failure:(void (^)(id JSON))failure;

/**
 获取我的排名列表接口
 返回最新的排名信息，此接口需要传入用户信息，根据当前用户的排名，列出用户附件的排名，暂定如果用户排名在20名以后 ，则列出前10名，再加上用户前面的10名和后面的5名，如果在20之内 ，则直接取出前25名，接口不需要分页，一次返回
 
 @param rank_key 需要获取的排名的key值，为0时表示获取总分排名
 @param rank_group 需要获取的具体的分组，可以与rank_key配合使用，也可以单独使用，0或者不传，表示忽略分组
 @param scope 获取排名的范围， 0为好友中，1,为全部用户，2,为关注的用户中，默认为0,好友中
 @param period 计分周期，不传表示获取最新期的排名
 @param receive_gift_status 是否返回送礼物开关 0 不返回，1 返回  默认为0 不返回
 */
+ (void)getMyRankListWithRankKey:(int)rank_key
                       rankGroup:(int)rank_group
                           scope:(int)scope
                          period:(int)period
                      giftStatus:(int)receive_gift_status
                         success:(void (^)(id JSON))success
                         failure:(void (^)(id JSON))failure;

/**
 查询排名接口
 返回某用户或者某分数的排名
 
 @param rank_key 需要获取的排名的key值，为0时表示获取总分排名
 @param rank_group 需要获取的具体的分组，可以与rank_key配合使用，也可以单独使用，0或者不传，表示忽略分组
 @param scope 获取排名的范围， 0为好友中，1,为全部用户，2,为关注的用户中，默认为0,好友中
 @param score 要查询排名的分数，如果不传，则查询此用户的排名
 @param period 计分周期，不传表示获取最新期的排名
 @param receive_gift_status 是否返回送礼物开关 0 不返回，1 返回  默认为0 不返回
 */
+ (void)getRankOrderWithRankKey:(int)rank_key
                      rankGroup:(int)rank_group
                          scope:(int)scope
                          score:(int)score
                         period:(int)period
                     giftStatus:(int)receive_gift_status
                        success:(void (^)(id JSON))success
                        failure:(void (^)(id JSON))failure;

/**
 开始游戏接口
 开始游戏接口，此接口用于校验游戏是否可以开始，如果体力和其他开发商设定的条件都满足，则返回此局游戏的唯一标识 game_id，和其他一些游戏需要的参数。
 
 @param need_power 开始一局游戏需要的体力值，不传或者0表示不需要扣减体力
 */
+ (void)startAppWithNeedPower:(int)need_power
                      success:(void (^)(id JSON))success
                      failure:(void (^)(id JSON))failure;

/**
 更新分数接口
 更新某用户的某项游戏的分数，返回新分数的好友排名，这里需要增加判断，如果当前存储的分数大于新上传的分数，则不做更新。
 
 @param rank_key 需要获取的排名的key值，为0时表示获取总分排名
 @param rank_group 需要获取的具体的分组，可以与rank_key配合使用，也可以单独使用，0或者不传，表示忽略分组
 @param game_id  每局游戏的唯一标识，由系统分配，与用户和游戏对应，更新分数前先确定sequence是否存在，且只能使用一次
 @param score 要更新的分数
 @param gameidSignature 参数校验，对gameid进行ASC加密@{@"gameid":game_id}
 @param option 更新分数时的参数选择，YES 为强制更新，低分数会覆盖高分数
 */

+ (void)updateDataWithRankKey:(int)rank_key
                    rankGroup:(int)rank_group
                       gameId:(NSString *)game_id
                         data:(int)score
                        token:(NSString *)gameidSignature
                       option:(BOOL)option
                      success:(void (^)(id JSON))success
                      failure:(void (^)(id JSON))failure;


/**
 更新分数接口（有明星活动时）
 更新某用户的某项游戏的分数，且在有活动时，为所在的明星团队增加贡献值
 @param activityId 为明星增加贡献值，活动id
 @param gameidSignature 参数校验，对gameid进行ASC加密@{@"gameid":game_id}
 @param option 更新分数时的参数选择，YES 为强制更新，低分数会覆盖高分数

 */

+ (void)updateDataWithRankKey:(int)rank_key
                    rankGroup:(int)rank_group
                       gameId:(NSString *)game_id
                   activityId:(int)activityId
                         data:(int)score
                        token:(NSString *)gameidSignature
                       option:(BOOL)option
                      success:(void (^)(id JSON))success
                      failure:(void (^)(id JSON))failure;

/**
 更新多个分数接口
 更新某用户的某项游戏的分数，返回新分数的好友排名，这里需要增加判断，如果当前存储的分数大于新上传的分数，则不做更新。

 @param game_id  每局游戏的唯一标识，由系统分配，与用户和游戏对应，更新分数前先确定sequence是否存在，且只能使用一次
 @param data 要更新的分数数据，为json字串的形式，必须做URLEncode，采用UTF-8编码。内容为rank_key,rank_group,score 的json数组,如
 [{"score":100,"rank_group":1,"rank_key":1},{"score":13,"rank_group":2,"rank_key":1}]
 @param gameidSignature 参数校验，对gameid进行ASC加密@{@"gameid":game_id}
 @param option 更新分数时的参数选择，YES 为强制更新，低分数会覆盖高分数

 */

+ (void)updateMultiDataWithGameId:(NSString *)game_id
                             data:(NSString *)data
                            token:(NSString *)gameidSignature
                           option:(BOOL)option
                          success:(void (^)(id JSON))success
                          failure:(void (^)(id JSON))failure;


///////

/**
 同步体力值接口
 返回用户的体力值信息， 当体力值大于等于自增最大值时，直接返回当前值，如果当前值小于最大值，需要把最后更新时间与当前时间比对，再根据更新频率，计算出当前的体力值，并更新最后更新时间，最后更新时间应该是更新体力值的那个时间点，而不是当前时间。
 
 @param power_key  需要获取的体力的key值，不传则取系统默认值1
 */
+ (void)syncPowerWithPowerKey:(int)power_key
                      success:(void (^)(id JSON))success
                      failure:(void (^)(id JSON))failure;

/**
 同增加或消耗体力接口
 更新某用户的某项游戏的体力值，返回最新的体力值，在更新前，如果体力值不是满体力，需要先同步一次，如果是满体力，切操作时扣减，那么需要更新最后更新时间字段。
 
 @param power_key  需要获取的体力的key值，不传则取系统默认值1
 @param increment  要改变的值，正数为增加体力值，负数为消耗体力值
 */
+ (void)updatePowerWithPowerKey:(int)power_key
                      increment:(int)increment
                        success:(void (^)(id JSON))success
                        failure:(void (^)(id JSON))failure;
///////

/**
 获取当前用户礼物接口
 返回用户接收的有效期内的礼物信息
 
 @param gift_key 礼物的key，为空则取所有的礼物
 @param status 为0或者不传，表示获取所有状态，1,为未接收，2，为已接收
 @param count 单页返回的记录条数，默认为50。
 @param page 返回结果的页码，默认为1。
  */
+ (void)showGiftWithGiftKey:(int)gift_key
                     status:(int)status
                      count:(int)count
                       page:(int)page
                    success:(void (^)(id JSON))success
                    failure:(void (^)(id JSON))failure;

/**
 赠送礼物接口
 用于用户向好友赠送礼物。
 
 @param gift_key 需要更新的的key值，不传则使用系统默认值1 (10001 为系统保留字段，用于体力的赠送）
 @param targer_user 受赠者用户ID
 @param description 送礼物的描述信息
 @param count 数量，默认1。
 @param notification 0,不发送通知  1，发送微博私信通知，默认为0
 @param notify_data 发送通知时的内容，为json字串的形式，必须做URLEncode，采用UTF-8编码，data支持的字段有text，url，invite_logo
 */
+ (void)giveGiftWithGiftKey:(int)gift_key
                 targerUser:(NSString *)targer_user
                description:(NSString *)description
                      count:(int)count
               notification:(int)notification
                 notifyData:(NSString *)notify_data
                    success:(void (^)(id JSON))success
                    failure:(void (^)(id JSON))failure;

/**
 发送礼物通知接口
 用于用户向好友发送通知
 
 @param gift_id 礼物的id
 @param content 通知内容
 */
+ (void)giveGiftNotifyWithGiftId:(NSString *)gift_id
                         content:(NSString *)content
                         success:(void (^)(id JSON))success
                         failure:(void (^)(id JSON))failure;

/**
 批量收取礼物接口
 用于用户批量确认收取礼物。
 
 @param gift_ids 需要收取的礼物id，逗号分隔
 */
+ (void)receiveBatchGiftWithGiftIds:(NSString *)gift_ids
                            success:(void (^)(id JSON))success
                            failure:(void (^)(id JSON))failure;

//////////

/**
 获取存档接口
 获取用户的存档。
 
 @param archive_key 具体存档的key值
 */
+ (void)getArchiveWithArchiveKey:(NSString *)archive_key
                         success:(void (^)(id JSON))success
                         failure:(void (^)(id JSON))failure;

/**
 更新存档文件接口
 更新某用户的某个存档
 
 @param archive_key 具体存档的key值
 @param content 要保存的存档内容，需要做urlencode
 */
+ (void)updateArchiveWithArchiveKey:(NSString *)archive_key
                            content:(NSString *)content
                            success:(void (^)(id JSON))success
                            failure:(void (^)(id JSON))failure;


//////////


+ (void)friendBilateralWithCount:(int)count
                            page:(int)page
                         success:(void (^)(id JSON))success
                         failure:(void (^)(id JSON))failure;

/**
 获取使用某应用的互粉好友信息
 返回使用了某应用的互粉好友的信息列表。默认全部返回，客户端做分栏处理。
 
 @param count 单页返回的记录条数，默认为全部返回。
 @param page 返回结果的页码，默认为1。
 */
+ (void)bilateralAppWithCount:(int)count
                         page:(int)page
                      success:(void (^)(id JSON))success
                      failure:(void (^)(id JSON))failure;

/**
 获取还未使用某应用的互粉好友信息
 返回使用了某应用的互粉好友的信息列表。默认全部返回，客户端做分栏处理。
 
 @param count 单页返回的记录条数，默认为全部返回。
 @param page 返回结果的页码，默认为1。
 */
+ (void)noBilateralAppWithCount:(int)count
                           page:(int)page
                        success:(void (^)(id JSON))success
                        failure:(void (^)(id JSON))failure;


/**
 发送邀请接口
 指定uid集合发送邀请，邀请只限于互粉之间，非互粉无法接到邀请，一个账号每天只能邀请60个不同的人，同一个被邀请人一天只能被邀请一次
 
 @param uids 被邀请人，多个之间用逗号分隔，最多5个，游戏邀请有单次限制，每日上限20
 @param data 邀请数据。必须为json字串的形式，必须做URLEncode，采用UTF-8编码。data支持的字段有text，url，invite_logo，url和invite_logo可以不传，接口会取应用默认的地址和logo图片
 */
+ (void)inviteFriendWithUids:(NSString *)uids
                        data:(NSString *)data
                     success:(void (^)(id JSON))success
                     failure:(void (^)(id JSON))failure;

/**
 私信炫耀接口
 指定uid集合发送炫耀信息，只限于互粉之间，非互粉无法收到，一个账号每天只能邀请60个不同的人
 
 @param uids 被邀请人，多个之间用逗号分隔，最多5个，游戏邀请有单次限制，每日上限20
 @param data 邀请数据。必须为json字串的形式，必须做URLEncode，采用UTF-8编码。data支持的字段有text，url，invite_logo，url和invite_logo可以不传，接口会取应用默认的地址和logo图片
 */
+ (void)showoffFriendWithUids:(NSString *)uids
                         data:(NSString *)data
                      success:(void (^)(id JSON))success
                      failure:(void (^)(id JSON))failure;

+ (void)appsvcWithBizid:(int)bizid
                     pt:(int)pt
                success:(void (^)(id JSON))success
                failure:(void (^)(id JSON))failure;

////////////////

/**
 读取用户某款游戏信息接收状态接口
 获取用户信息接收的状态。
 */
+ (void)showReceiveMessageByUserSettingSuccess:(void (^)(id JSON))success
                                       failure:(void (^)(id JSON))failure;

/**
 读取用户礼物接收状态接口
 获取用户礼物接收的状态。
 */
+ (void)showReceiveGiftByUserSettingSuccess:(void (^)(id JSON))success
                                    failure:(void (^)(id JSON))failure;

/**
 更新用户信息接收状态接口
 更新当前用户信息接收的状态。
 
 @param setting_value 接收信息的状态值1接收，0不接收
 */
+ (void)updateReceiveMessageByUserSettingWithSettingValue:(int)setting_value
                                                  success:(void (^)(id JSON))success
                                                  failure:(void (^)(id JSON))failure;

/**
 更新用户礼物接收状态接口
 更新当前用户礼物接收的状态。
 
 @param setting_value 接收信息的状态值1接收，0不接收
 */
+ (void)updateReceiveGiftByUserSettingWithSettingValue:(int)setting_value
                                               success:(void (^)(id JSON))success
                                               failure:(void (^)(id JSON))failure;

//////////////// 微博接口 ///////

/**
 获取个人资料
 */
+ (void)getUserInfoSuccess:(void (^)(id JSON))success
                   failure:(void (^)(id JSON))failure;

/**
 发送微博
 
 @param status 文字发送内容，限140
 */
+ (void)sendWeiboWithStatus:(NSString *)status
                    success:(void (^)(id JSON))success
                    failure:(void (^)(id JSON))failure;

/**
 发送微博
 
 @param pic 图片
 @param status 文字发送内容，限140
 */
+ (void)sendWeiboWithPic:(UIImage *)pic
                  status:(NSString *)status
                 success:(void (^)(id JSON))success
                 failure:(void (^)(id JSON))failure;

/**
 关注
 关注某用户
 
 @param uid 需要关注的用户id
 @param screen_name 需要关注的用户名称
 */
+ (void)createFriendshipsWithUid:(NSString *)uid
                      screenName:(NSString *)screen_name
                         success:(void (^)(id JSON))success
                         failure:(void (^)(id JSON))failure;

/////////////////

/**
 获取系统消息接口
 获取还未过期的，置顶消息和用户还未获取的普通消息。
 
 @param type 消息类型，0为获取所有类别，默认为0
 @param max_id 用户本地以获取的，最大id，不传默认为0
 @param count 单页返回的记录条数，默认为50。
 @param page 返回结果的页码，默认为1
 */
+ (void)showNotificationWithType:(int)type
                           maxId:(int)max_id
                           count:(int)count
                            page:(int)page
                         success:(void (^)(id JSON))success
                         failure:(void (^)(id JSON))failure;

/**
 推荐应用接口
 推荐游戏接口，提供给开发商作为游戏内互推使用，后台需支持对接入游戏进行选择是否为推荐游戏、按权重排序。
  */
+ (void)getRecommendGameSuccess:(void (^)(id JSON))success
                        failure:(void (^)(id JSON))failure;

/**
 签到接口
 每次打开客户端时调用，将客户端基础信息传给服务器
 
 @param app_version 客户端版本号
 @param net_info 网络信息，空时表示不限制
 @param channelid 客户端渠道号，用于区分不同的安装包。
 */
+ (void)signinWithAppVersion:(int)app_version
                     netInfo:(NSString *)net_info
                     success:(void (^)(id JSON))success
                     failure:(void (^)(id JSON))failure;

/**
 提交建议接口
 用户提交建议给服务器
 
 @param content 建议内容
 @param mobile 手机号
 */
+ (void)suggestWithContent:(NSString *)content
                    mobile:(NSString *)mobile
                   success:(void (^)(id JSON))success
                   failure:(void (^)(id JSON))failure;

/**
 检查更新接口
 
 @param channelid 渠道号id
 @param versionCode 版本号
 @param versionName 版本名称
 @param packageName 包名

 */
+ (void)checkForUpdateWithVersionCode:(int)versionCode
                        versionName:(NSString *)versionName
                        packageName:(NSString *)packageName
                            success:(void (^)(id JSON))success
                            failure:(void (^)(id JSON))failure;

/**
  积分墙
 */

+ (void)interfaceDevicesActivationSuccess:(void (^)(id JSON))success
                                  failure:(void (^)(id JSON))failure;


/**
 日志接口
 每次打开客户端时调用，将客户端基础信息传给服务器
 
 @param action 日志类型（首次激活 active，打开  open，登陆  login）
 @param uid 登陆成功的用户需要传，还未授权的用户传0
 @param appkey 游戏的key，用于区分不同的游戏
 @param phoneid 终端的唯一编号，根据硬件信息生成
 @param mac 设备mac地址
 @param rom 当前设备系统的版本
 @param ua 设备型号
 @param app_versioncode 客户端版本号
 @param app_versionname 客户端版本名称
 @param package 游戏包名，ios为bundle id
 @param channelid 客户端渠道号，用于区分不同的安装包
 @param net_info 网络类型 ，2g,3g,4g wifi，等

 */

+ (void)reportLogWithAction:(NSString *)action
                        uid:(NSString *)uid
                     appkey:(NSString *)appkey
                    phoneid:(NSString *)phoneid
                        mac:(NSString *)mac
                        rom:(NSString *)rom
                         ua:(NSString *)ua
            app_versioncode:(int)app_versioncode
            app_versionname:(NSString *)app_versionname
                    package:(NSString *)package
                   net_info:(NSString *)net_info
                    success:(void (^)(id JSON))success
                    failure:(void (^)(id JSON))failure;

/**20141009*/

/**
 获取用户关注接口
 
 @param uid	 需要查询的用户uid
 @param screen_name 需要查询的用户昵称
 @param count 单页返回的记录条数，默认为50，最大不超过200
 @param cursor 返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0
 @param trim_status	 返回值中user字段中的status字段开关，0：返回完整status字段、1：status字段仅返回status_id，默认为1。

 ** 参数uid与screen_name二者必选其一，且只能选其一
 */

+ (void)getFriendshipsWithUid:(NSString *)uid
                   screenName:(NSString *)screenName
                        count:(int)count
                       cursor:(int)cursor
                   trimStatus:(int)trimStatus
                      success:(void (^)(id JSON))success
                      failure:(void (^)(id JSON))failure;


/**20141110*/

/**
 微游戏接收cp通知设备激活接口
 
 @param idfa	 设备idfa（与mac必选其一）
 @param mac      设备mac（与idfa必选其一）
 @param appId    应用ID（itunes connect）

*/

+ (void)getActivateDeviceWithIDFA:(NSString *)idfa
                              mac:(NSString *)mac
                            appId:(NSString *)appId
                          success:(void (^)(id JSON))success
                          failure:(void (^)(id JSON))failure;

/**
 登录成功接口
 
 @param idfa	 设备idfa（与mac必选其一）
 @param mac      设备mac（与idfa必选其一）
 @param appId    应用ID（itunes connect）
 
 */

+ (void)getloginSuccessWithIDFA:(NSString *)idfa
                              mac:(NSString *)mac
                            appId:(NSString *)appId
                       login_time:(NSString *)login_time
                          success:(void (^)(id JSON))success
                          failure:(void (^)(id JSON))failure;

@end

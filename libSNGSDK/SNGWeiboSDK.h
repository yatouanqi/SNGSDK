//
//  SNGWeiboSDK.h
//  SNGSDK
//
//  Created by huijun xu on 13-11-21.
//  Copyright (c) 2013年 sina. All rights reserved.
//


typedef NS_ENUM(NSInteger, SNGWeiboSDKResponseStatusCode)
{
    SNGWeiboSDKResponseStatusCodeSuccess               = 0,//成功
    SNGWeiboSDKResponseStatusCodeUserCancel            = -1,//用户取消发送
    SNGWeiboSDKResponseStatusCodeSentFail              = -2,//发送失败
    SNGWeiboSDKResponseStatusCodeAuthDeny              = -3,//授权失败
    SNGWeiboSDKResponseStatusCodeUserCancelInstall     = -4,//用户取消安装微博客户端
    SNGWeiboSDKResponseStatusCodeUnsupport             = -99,//不支持的请求
    SNGWeiboSDKResponseStatusCodeUnknown               = -100,
};

@protocol SNGWeiboSDKDelegate;
@protocol SNGWBHttpRequestDelegate;

@class SNGWBBaseRequest;
@class SNGWBBaseResponse;
@class SNGWBHttpRequest;
@class SNGWBAuthorizeResponse;

@interface SNGWeiboSDK : NSObject

@property (nonatomic, strong) NSString* userID;
@property (nonatomic, strong) NSString* accessToken;
@property (nonatomic, strong) NSDate* expirationDate;
@property (nonatomic, strong) NSString* appKey;

/**
 @return SNGWeiboSDK 单例
 */

+(SNGWeiboSDK *)shared;

/**
 判断登录是否有效，当已登录并且登录未过期时为有效状态
 @return YES为有效；NO为无效
 */
+ (BOOL)isAuthValid;

/**
 检查用户是否安装了微博客户端程序
 @return 已安装返回YES，未安装返回NO
 */
+ (BOOL)isWeiboAppInstalled;

/**
 打开微博客户端程序
 @return 成功打开返回YES，失败返回NO
 */
+ (BOOL)openWeiboApp;

/**
 获取微博客户端程序的itunes安装地址
 @return 微博客户端程序的itunes安装地址
 */
+ (NSString *)getWeiboAppInstallUrl;

/**
 获取当前微博客户端程序所支持的SDK最高版本
 @return 当前微博客户端程序所支持的SDK最高版本号，返回 nil 表示未安装微博客户端
 */
+ (NSString *)getWeiboAppSupportMaxSDKVersion __attribute__((deprecated));

/**
 获取当前微博SDK的版本号
 @return 当前微博SDK的版本号
 */
+ (NSString *)getSDKVersion;

/**
 向微博客户端程序注册第三方应用
 @param appKey 微博开放平台第三方应用appKey
 @param redirectURI 微博开放平台第三方应用redirectURI
 @param idfa	 设备idfa（与mac必选其一）
 @param mac      设备mac（与idfa必选其一）
 @param appId    应用ID（itunes connect）
 @return 注册成功返回YES，失败返回NO
 */
+ (BOOL)registerApp:(NSString *)appKey
        redirectURI:(NSString *)redirectURI
              appid:(NSString *)appid
               IDFA:(NSString *)idfa
                mac:(NSString *)mac;

/**
 处理微博客户端程序通过URL启动第三方应用时传递的数据
 
 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用
 @param url 启动第三方应用的URL
 @param delegate WeiboSDKDelegate对象，用于接收微博触发的消息
 @see WeiboSDKDelegate
 */
+ (BOOL)handleOpenURL:(NSURL *)url delegate:(id<SNGWeiboSDKDelegate>)delegate;

/**
 发送请求给微博客户端程序，并切换到微博
 
 请求发送给微博客户端程序之后，微博客户端程序会进行相关的处理，处理完成之后一定会调用 [WeiboSDKDelegate didReceiveWeiboResponse:] 方法将处理结果返回给第三方应用
 
 @param request 具体的发送请求
 
 @see [WeiboSDKDelegate didReceiveWeiboResponse:]
 @see WBBaseResponse
 */
+ (BOOL)sendRequest:(SNGWBBaseRequest *)request;

/**
 收到微博客户端程序的请求后，发送对应的应答给微博客户端端程序，并切换到微博
 
 第三方应用收到微博的请求后，异步处理该请求，完成后必须调用该函数将应答返回给微博
 
 @param response 具体的应答内容
 @see WBBaseRequest
 */
+ (BOOL)sendResponse:(SNGWBBaseResponse *)response;

/**
 设置WeiboSDK的调试模式
 
 当开启调试模式时，WeiboSDK会在控制台输出详细的日志信息，开发者可以据此调试自己的程序。默认为 NO
 @param enabled 开启或关闭WeiboSDK的调试模式
 */
+ (void)enableDebugMode:(BOOL)enabled;

/**
 授权接口
 */
+ (void)login;

/**
 取消授权，登出接口
 调用此接口后，token将失效
 @param token 第三方应用之前申请的Token
 @param delegate WeiboSDKJSONDelegate对象，用于接收微博SDK对于发起的接口请求的请求的响应
 
 */
+ (void)logOutWithDelegate:(id<SNGWBHttpRequestDelegate>)delegate;

/**
 邀请好友使用应用
 调用此接口后，将发送私信至好友，成功将返回微博标准私信结构
 @param data 邀请数据。必须为json字串的形式，必须做URLEncode，采用UTF-8编码。
 data参数支持的参数：
 参数名称	值的类型	是否必填	说明描述
 text	string	true	要回复的私信文本内容。文本大小必须小于300个汉字。
 url	string	false	邀请点击后跳转链接。默认为当前应用地址。
 invite_logo	string	false	邀请Card展示时的图标地址，大小必须为80px X 80px，仅支持PNG、JPG格式。默认为当前应用logo地址。
 @param uid  被邀请人，需为当前用户互粉好友。
 @param access_token 第三方应用之前申请的Token
 @param delegate WeiboSDKJSONDelegate对象，用于接收微博SDK对于发起的接口请求的请求的响应
 @param tag 用户自定义TAG,将通过回调WBHttpRequest实例的tag属性返回
 */
+(void)inviteFriend:(NSString* )data
           delegate:(id<SNGWBHttpRequestDelegate>)delegate
                tag:(NSString *)tag;

@end

@protocol SNGWeiboSDKDelegate <NSObject>
@optional
/**
 收到一个来自微博客户端程序的请求
 
 收到微博的请求后，第三方应用应该按照请求类型进行处理，处理完后必须通过 [WeiboSDK sendResponse:] 将结果回传给微博
 @param request 具体的请求对象
 */
- (void)didReceiveSNGWeiboRequest:(SNGWBBaseRequest *)request;

/**
 收到一个来自微博客户端程序的响应
 
 收到微博的响应后，第三方应用可以通过响应类型、响应的数据和 WBBaseResponse.userInfo 中的数据完成自己的功能
 @param response 具体的响应对象
 */
- (void)didReceiveSNGWeiboResponse:(SNGWBBaseResponse *)response;

@end

/**
 接收并处理来自微博sdk对于网络请求接口的调用响应 以及openAPI
 如inviteFriend、logOutWithToken的请求
 */
@protocol SNGWBHttpRequestDelegate <NSObject>
@optional
/**
 收到一个来自微博Http请求的响应
 
 @param response 具体的响应对象
 */
- (void)request:(SNGWBHttpRequest *)request didSNGReceiveResponse:(NSURLResponse *)response;

/**
 收到一个来自微博Http请求失败的响应
 
 @param error 错误信息
 */
- (void)request:(SNGWBHttpRequest *)request didSNGFailWithError:(NSError *)error;

/**
 收到一个来自微博Http请求的网络返回
 
 @param result 请求返回结果
 */
- (void)request:(SNGWBHttpRequest *)request didSNGFinishLoadingWithResult:(NSString *)result;

/**
 收到一个来自微博Http请求的网络返回
 
 @param data 请求返回结果
 */
- (void)request:(SNGWBHttpRequest *)request didSNGFinishLoadingWithDataResult:(NSData *)data;


@end



@interface SNGWBHttpRequest : NSObject
{
    NSString                        *url;
    NSString                        *httpMethod;
    NSDictionary                    *params;
    
    NSURLConnection                 *connection;
    NSMutableData                   *responseData;
    
    id<SNGWBHttpRequestDelegate>    delegate;
}

/**
 用户自定义TAG
 
 用于区分回调Request
 */
@property (nonatomic, retain) NSString* tag;

@end

#pragma mark - DataTransferObject and Base Request/Response

/**
 微博客户端程序和第三方应用之间传输数据信息的基类
 */
@interface SNGWBDataTransferObject : NSObject

/**
 自定义信息字典，用于数据传输过程中存储相关的上下文环境数据
 
 第三方应用给微博客户端程序发送 request 时，可以在 userInfo 中存储请求相关的信息。
 
 @warning userInfo中的数据必须是实现了 `NSCoding` 协议的对象，必须保证能序列化和反序列化
 @warning 序列化后的数据不能大于10M
 */
@property (nonatomic, retain) NSDictionary *userInfo;


/**
 发送该数据对象的SDK版本号
 
 如果数据对象是自己生成的，则sdkVersion为当前SDK的版本号；如果是接收到的数据对象，则sdkVersion为数据发送方SDK版本号
 */
@property (nonatomic, readonly) NSString *sdkVersion;


/**
 当用户没有安装微博客户端程序时是否提示用户打开微博安装页面
 
 如果设置为YES，当用户未安装微博时会弹出Alert询问用户是否要打开微博App的安装页面。默认为YES
 */
@property (nonatomic, assign) BOOL shouldOpenWeiboAppInstallPageIfNotInstalled;

@end


/**
 微博SDK所有请求类的基类
 */
@interface SNGWBBaseRequest : SNGWBDataTransferObject

/**
 返回一个 WBBaseRequest 对象
 
 @return 返回一个*自动释放的*WBBaseRequest对象
 */
//+ (id)request;

@end


/**
 微博SDK所有响应类的基类
 */
@interface SNGWBBaseResponse : SNGWBDataTransferObject

/**
 对应的 request 中的自定义信息字典
 
 如果当前 response 是由微博客户端响应给第三方应用的，则 requestUserInfo 中会包含原 request.userInfo 中的所有数据
 
 @see WBBaseRequest.userInfo
 */
@property (nonatomic, readonly) NSDictionary *requestUserInfo;

/**
 响应状态码
 
 第三方应用可以通过statusCode判断请求的处理结果
 */
@property (nonatomic, assign) SNGWeiboSDKResponseStatusCode statusCode;

/**
 返回一个 WBBaseResponse 对象
 
 @return 返回一个*自动释放的*WBBaseResponse对象
 */
//+ (id)response;

@end

#pragma mark - Authorize Response

/**
 微博客户端处理完第三方应用的认证申请后向第三方应用回送的处理结果
 
 SNGWBAuthorizeResponse 结构中仅包含常用的 userID 、accessToken 和 expirationDate 信息，其他的认证信息（比如部分应用可以获取的 refresh_token 信息）会统一存放到 userInfo 中
 */
@interface SNGWBAuthorizeResponse : SNGWBBaseResponse

/**
 用户ID
 */
@property (nonatomic, retain) NSString *userID;

/**
 认证口令
 */
@property (nonatomic, retain) NSString *accessToken;

/**
 认证过期时间
 */
@property (nonatomic, retain) NSDate *expirationDate;

@end



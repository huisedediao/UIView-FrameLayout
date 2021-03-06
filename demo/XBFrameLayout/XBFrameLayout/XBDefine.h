//
//  XBDefine.h
//  XBExtensionTest
//
//  Created by luoxj on 16/5/10.
//  Copyright © 2016年 XXB. All rights reserved.
//

#ifndef XBDefine_h
#define XBDefine_h


/********************枚举********************/
typedef enum
{
    XBLCRSideCenter=0,   //居中
    XBLCRSideLeft,       //左
    XBLCRSideRight       //右
    
}XBLCRSide;

typedef enum
{
    XBSideTop = 0,    //上
    XBSideBottom,     //下
    XBSideLeft,       //左
    XBSideRight       //右
    
}XBSide;
/********************枚举********************/



/********************打印方法********************/

/****不打印当前所在方法****/
#ifdef DEBUG //处于调试阶段,打印
#define NSLog(...) NSLog(__VA_ARGS__)
#else   //发布阶段,不打印
#define NSLog(...)
#endif
/****不打印当前所在方法****/

/****打印当前所在方法****/
#ifdef DEBUG //处于调试阶段,打印
#define XBFlog(...) NSLog(@"\n%s\n %@\n\n",__func__,[NSString stringWithFormat:__VA_ARGS__])
#else   //发布阶段,不打印
#define XBFlog(...)
#endif
/****打印当前所在方法****/

/********************打印方法********************/


/**********************************宏**********************************/
//字符串是否为空
#define StringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )

//数组是否为空
#define ArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)

//字典是否为空
#define DictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)

//是否是空对象
#define ObjectIsEmpty(_object) (_object == nil \|| [_object isKindOfClass:[NSNull class]] \|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

//UserDefault
#define UserDefault [NSUserDefaults standardUserDefaults]
//Application
#define Application        [UIApplication sharedApplication]
//KeyWindow
#define KeyWindow          [UIApplication sharedApplication].keyWindow
//CurrentAppDelegate
#define CurrentAppDelegate        [UIApplication sharedApplication].delegate
//FileManager
#define FileManager  [NSFileManager defaultManager]

//屏幕宽高
#define ScreenWidth [UIScreen mainScreen].bounds.size.width
#define ScreenHeight [UIScreen mainScreen].bounds.size.height

//随机色
#define RandColor [UIColor colorWithRed:arc4random()%256/255.0 green:arc4random()%256/255.0 blue:arc4random()%256/255.0 alpha:1.0]

//RGB颜色
#define ColorRGBA(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]



//状态栏高度
#define StatusBarHeight    [[UIApplication sharedApplication] statusBarFrame].size.height
//导航栏高度
#define NavigationBarHeight    self.navigationController.navigationBar.frame.size.height
//顶部状态栏+导航栏
#define TopBarHeight StatusBarHeight + NavigationBarHeight

//系统版本
#define SystemVersion [[UIDevice currentDevice].systemVersion doubleValue]
//系统版本是否大于IOS7
#define IOS7 SystemVersion >= 7.0

//APP版本号
#define AppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

//获取当前语言
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//判断是否为iPhone
#define ISiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

//判断是否为iPad
#define ISiPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

// View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

//本地化相关
#define STR(x) NSLocalizedString(x,nil)

//角度转成弧度
#define Angle2Radian(angle) ((angle) / 180.0 * M_PI)
//由弧度转换角度
#define Radian2Angle(radian) (radian * 180.0) / (M_PI)

//获取一段时间间隔
#define StartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define EndTime   NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)

//设备判断
#define iPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

//block weak属性化self宏
#define WEAK_SELF __typeof(self) __weak weakSelf = self;

//可以操作
#define UserCanTouch   [[[UIApplication sharedApplication] keyWindow] setUserInteractionEnabled:YES];
//不可以操作
#define UserCanNotTouch [[[UIApplication sharedApplication] keyWindow] setUserInteractionEnabled:NO];

//获取沙盒Document路径
#define DocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

//获取沙盒temp路径
#define TempPath NSTemporaryDirectory()

//获取沙盒Cache路径
#define CachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//判断是真机还是模拟器
#if TARGET_OS_IPHONE//真机
#endif
#if TARGET_IPHONE_SIMULATOR
//模拟器
#endif

/**********************************宏**********************************/

/**********************************常用方法(小括号中为返回值)**********************************/

//根据传入的文字、宽度和字体计算出合适的size (CGSize)
#define getAdjustSizeWith_text_width_font(text,width,font) ({[text boundingRectWithSize:CGSizeMake(width, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName :font} context:NULL].size;})

//根据传入的文字和字体获取宽度 (CGFloat)
#define getWidthWith_title_font(title,font) ({\
UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 1000, 0)];\
label.text = title;\
label.font = font;\
[label sizeToFit];\
label.frame.size.width;\
})

//判断某个路径是否存在 (BOOL)
#define isExistFileAtPath(path) [[NSFileManager defaultManager] fileExistsAtPath:path]

//获取当前时间戳 (NSTimeInterval)
#define getCurrentTimeInterval ({ \
NSDate* data = [NSDate dateWithTimeIntervalSinceNow:0];\
NSTimeInterval a=[data timeIntervalSince1970]; \
a;})

//移除字符串中的空格
//把strNeedChange中的currentStr替换成repalceStr (NSString)
#define replaceString_currentStr_To_repalceStr_For_strNeedChange(currentStr,repalceStr,strNeedChange)\
[strNeedChange stringByReplacingOccurrencesOfString:currentStr withString:repalceStr]

//判断某个view是否是另一个view的子view (BOOL)
#define isSubViewOfView_subV_fatherV(subV,fatherV)\
({\
    BOOL isSubView=NO;\
    NSArray *subViews=fatherV.subviews;\
    for (UIView *subView in subViews)\
    {\
        if (subView==subV)\
        {\
            isSubView=YES;\
            break;\
        }\
    }\
    isSubView;\
})

/**********************************常用方法**********************************/

#endif /* XBDefine_h */

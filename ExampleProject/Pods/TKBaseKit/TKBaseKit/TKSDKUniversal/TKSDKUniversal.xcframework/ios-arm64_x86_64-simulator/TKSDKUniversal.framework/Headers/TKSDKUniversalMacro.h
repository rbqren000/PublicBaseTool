//
//  TKSDKUniversalPch.h
//  TKSDKUniversal
//
//  Created by PC on 2018/10/18.
//  Copyright © 2018年 PC. All rights reserved.
//

#ifndef TKSDKUniversalPch_h
#define TKSDKUniversalPch_h

/**
 该文件用于定义一些常用的宏
 */


//BUG字符串是否输出t日志
#ifdef DEBUG
//#define TKLog(...) NSLog(__VA_ARGS__)
#define TKLog(FORMAT, ...) fprintf(stderr,"function:%s line:%d content:   %s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define TKLog(FORMAT, ...) nil
#endif



/** 将字符串为nil的处理为@""  **/
#define kNil(str)           str?str:@""
/** float转字符串-保留小数点后两位-用于金钱相关  */
#define kFloatStr(Float)    [NSString TKStringTwoWithFloat:Float]
/** 定义tableView section 高度为0.000001  */
#define kTableViewSectionHeightZero 0.000001



//多语言对应字符串获取   PS:如果对应的文件名不是InfoPlist,那么不能再里面设置APP的名字等基本属性(如：CFBundleDisplayName),如果要使用那么文件名必须是InfoPlist
#define TKString(key)       NSLocalizedStringFromTable(key,@"TKInfoPlist", nil)
//获取当前语言
#define kCurrentLanguage    [[NSLocale preferredLanguages] objectAtIndex:0]



//keyWindow
#define appWin              UIApplication.keyWindow
// 直接隐藏键盘
#define kHiddenKeyboard     [appWin endEditing:YES];


//判断设备为iPhone X（即是否有刘海屏）
#define kIsIPhoneX              [UIDevice TK_isFullScreen]


//屏幕相关尺寸
#define kScreenBounds           [UIScreen mainScreen].bounds
#define kScreenSize             [UIScreen mainScreen].bounds.size
#define kScreenWidth            [UIScreen mainScreen].bounds.size.width
#define kScreenHeight           [UIScreen mainScreen].bounds.size.height
//获取设备的物理分辨率
#define kScreenPhysicalBounds   [UIScreen mainScreen].nativeBounds



//获取状态栏frame,width,height
#define kStatusBarFrame     [UIDevice TK_getStatusBarFrame]
#define kStatusBarWidth     [UIDevice TK_getStatusBarFrame].size.width



//获取导航条区域高度
#define kNavHeight              44.0
//状态栏高度（顶部安全区域高度）
#define kStatusBarHeight        [UIDevice TK_getSafeTopAreaHeight]
//底部安全区域高度
#define kBottomSafeAreaHeight   [UIDevice TK_getSafeBottomAreaHeight]
//获取状态栏+导航条的高度
#define kNavStatusBarHeight     (kNavHeight + kStatusBarHeight)
//获取导航条，状态栏，底部凹凸区域的总高度
#define kNavAllSafeAreaHeight   (kNavStatusBarHeight + kBottomSafeAreaHeight)
//获取状态栏和底部安全区域的总高度
#define kAllSafeAreaHeight      (kStatusBarHeight + kBottomSafeAreaHeight)





/** 根据图片名称加载图片 */
#define kImageName(imageName)       [UIImage imageNamed:imageName]
/** 根据xibName创建UINib */
#define kNib(xibName)               [UINib nibWithNibName:xibName bundle:nil]
/** 根据storyName创建UIStoryBoard */
#define kStoryboard(storyName)      [UIStoryboard storyboardWithName:storyName bundle:nil]
/** 根据str创建URL */
#define kURL(str)                   [NSURL URLWithString:str]
/** 根据str创建URL,并且进行URL编码,解决中文问题 */
#define kURLEncoded(str)            [NSURL URLWithString:[NSString TKURLEncodedStringWith:str]]





//添加一个默认通知，不带参数
#define kNotifactionFunAdd(notifactionName,funcation)       [[NSNotificationCenter defaultCenter ] addObserver:self selector:@selector(funcation) name:notifactionName object:nil];
//发送一个通知，不带参数
#define kNotifactionFunPost(notifactionName)                [[NSNotificationCenter defaultCenter] postNotificationName:notifactionName object:nil];
//发送一个通知，带参数,userInfo为参数字典
#define kNotifactionFunPostInfo(notifactionName,userInfo)   [[NSNotificationCenter defaultCenter] postNotificationName:notifactionName object:nil userInfo:userInfo];
//移出一个指定通知
#define kNotifactionFunRemove(notifactionName)              [[NSNotificationCenter defaultCenter] removeObserver:self name:notifactionName object:nil];
//移出所用通知
#define kNotifactionFunRemoveAll                            [[NSNotificationCenter defaultCenter] removeObserver:self];





//RGB宏颜色: kRGBColor(223,224,225)
#define kRGBColor(r,g,b)                    [UIColor colorWithDecRed:r green:g blue:b]
#define kRGBColorAndAlpha(r,g,b,Alpha)      [UIColor colorWithDecRed:r green:g blue:b alpha:Alpha]
//HEX十六进制颜色（color:支持@“#123456”、 @“0X123456”、 @“123456”三种格式
#define kHEXColor(color)                    [UIColor colorWithHexString:color]
#define kHEXColorAndAlpha(color,Alpha)      [UIColor colorWithHexString:color alpha:Alpha]
//ios13动态颜色获取
#define kDyColor(lightColor,darkColor)      [UIColor colorWithLight:lightColor dark:darkColor]




//弱引用 --另外两种宏定义方式--用这种
#define WeakSelf        __weak typeof(self)weakSelf = self;
#define WeakObj(o)      __weak typeof(o) o##Weak = o;
//强引用 --另外两种宏定义方式--用这种
#define StrongSelf      __strong typeof(self)strongSelf =self;
#define StrongObj(o)    __strong typeof(o) o##Strong = o;




//---------------typedef一些常用的Block表达方式,都是带一个或者不带参数的------
//声明无参数,无返回类型的 block
typedef void(^Block)(void);
//声明无参数,有返回类型的 block
typedef id(^BlockBack)(void);
//声明有一个参数，无返回类型的 block
typedef void(^BlockValue)(id value);
//声明有一个参数，有返回类型的 block
typedef id(^BlockValueBack)(id value);
//声明SEL类型参数，返回无类型的 block
typedef void(^BlockSel)(SEL sel);
//声明void *类型参数，返回无类型的 block
typedef void (^BlockVoidP)(void * p);
//声明可变参数，无返回值的 block
typedef void(^BlockArgs)(id firstPar, ...);
//声明可变参数，有返回值的 block
typedef id(^BlockArgsBack)(id firstPar, ...);

/**
 可变参数block使用实例说明：

- (void)testBlock
{
    self.block = ^(id firstPar, ...) {
        //用于装载所有的传递的参数，依次装载
        NSMutableArray *argAry = @[].mutableCopy;
        if (firstPar) {//参数解析
            [argAry addObject:firstPar];
            id eachObject;
            va_list arguments;
            va_start(arguments, firstPar);
            while ((eachObject = va_arg(arguments, id))) {
                [argAry addObject:eachObject];
            }
            va_end(arguments);
        }
        NSLog(@"argAry:%@",argAry);
    };

    //至少有一个参数，并且参数以nil结尾
    self.block(@"11",@"22",nil);
}

**/




#endif /* TKSDKUniversalPch_h */

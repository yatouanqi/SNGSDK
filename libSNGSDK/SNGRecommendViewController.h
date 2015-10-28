//
//  SNGRecommendViewController.h
//  SNGSDK
//
//  Created by xu huijun on 14-1-22.
//  Copyright (c) 2014年 sina. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SNGRecommendViewControllerDelegate <NSObject>

-(void)recommendBackSelected;
@end

@interface SNGRecommendViewController : UIViewController
@property(nonatomic,strong)id<SNGRecommendViewControllerDelegate> delegate;

@end

# UIView-FrameLayout
<br>
####旧项目还是用frame布局的，计算数值太蛋疼了，所以弄了个frame相对布局
<br>
####注意：如果view1参考view2进行布局，则view1和view2必须是兄弟view或者父子view
<br><br><br>
###效果图：
<br><br>
![image](https://github.com/huisedediao/UIView-FrameLayout/raw/master/show.png)
<br><br>
###示例代码：
<br>
\#import "ViewController.h"<br>
\#import "UIView+FrameLayout.h"<br>
<br>
<br>
@implementation ViewController<br>
<br>
-(void)viewDidLoad {<br>
[super viewDidLoad];<br>
<br>
for (int i=0; i<10; i++)<br>
{<br>
UILabel *view=[UILabel new];<br>
[self.view addSubview:view];<br>
view.backgroundColor=RandColor;<br>
view.tag=i+101;<br>
view.text=[NSString stringWithFormat:@"%d",i];<br>
}<br>
<br>
<br>
//基本设置<br>
UILabel *view1=[self getViewWithTag:101];<br>
[view1 xb_left:20];//左<br>
[view1 xb_top:20];//上<br>
[view1 xb_height:30];//高<br>
[view1 xb_width:50];//宽<br>
<br>
<br>
//相对于view1布局<br>
UILabel *view2=[self getViewWithTag:102];<br>
//view2的左边到view1的右边的距离为10 （上下左右的设置相似）<br>
[view2 xb_leftSpace:10 toView:view1 side:XBSideRight];<br>
//view2的顶边和view1相等（上下左右的设置相似）<br>
[view2 xb_topEqualTo:view1];<br>
//view2的高度等于（view1的高度 * 3 - 15）（高度和宽度的设置相似）<br>
[view2 xb_heightEqualToView:view1 multiplier:3 constant:-15];<br>
//view2的宽度等于（view2的高度 * 1- 0）<br>
[view2 xb_widthEqualToHeightMultiplier:1.0 constant:0];<br>
<br>
<br>
UILabel *view3=[self getViewWithTag:103];<br>
//view3的size和view1相等<br>
[view3 xb_sizeEqualToView:view1];<br>
//view3的中心点的x和view2相等（view3和view2竖直方向中心点对齐）（中心点y的设置类似）<br>
[view3 xb_centerXEqualToView:view2];<br>
[view3 xb_topSpace:10 toView:view2 side:XBSideBottom];<br>
<br>
<br>
UILabel *view4=[self getViewWithTag:104];<br>
[view4 xb_sizeEqualToView:view1];<br>
//view4的中心点和view2的中心点相同<br>
[view4 xb_centerEqualToView:view2];<br>
<br>
<br>
//获取自身属性<br>
CGFloat view1Left=[view1 xb_left];//获取左边位置（最小x值）<br>
CGFloat view1Top=[view1 xb_top];//获取顶边位置（最小y值）<br>
CGFloat view1Right=[view1 xb_right];//获取右边位置（最大x值）<br>
CGFloat view1Bottom=[view1 xb_bottom];//获取底边位置（最大y值）<br>
CGFloat view1Height=[view1 xb_height];//获取高度<br>
CGFloat view1Width=[view1 xb_width];//获取宽度<br>
CGPoint view1Center=[view1 xb_center];//获取中心点位置<br>
CGSize   view1Size=[view1 xb_size];//获取size<br>
}<br>
<br>
-(UILabel *)getViewWithTag:(NSInteger)tag<br>
{<br>
return [self.view viewWithTag:tag];<br>
}<br>
@end<br>

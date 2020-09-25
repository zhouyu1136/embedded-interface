/*********************************************************************************************
* 文件：timer.c
* 作者：Meixin 2017.09.15
* 说明：定时器驱动代码    
* 修改：
* 注释：
*********************************************************************************************/

/*********************************************************************************************
* 头文件
*********************************************************************************************/
#include "timer.h"

/*********************************************************************************************
* 名称：xtal_init()
* 功能：CC2530时钟初始化
* 参数：无
* 返回：无
* 修改：
* 注释：
*********************************************************************************************/
void xtal_init(void)
{
  CLKCONCMD &= ~0x40;                                           //选择32MHz的外部晶振
  while(CLKCONSTA & 0x40);                                      //晶体振荡器开启且稳定
  CLKCONCMD &= ~0x07;                                           //选择32MH系统时钟
  CLKCONCMD &= ~0x38;                                           //选择32MH定时器时钟
}

/*********************************************************************************************
* 名称：time1_init()
* 功能：定时器1初始化
* 参数：无
* 返回：无
* 修改：
* 注释：
*********************************************************************************************/
void time1_init(void)
{
  T1CTL |= 0x06;                                                //8分频，模模式，从0计数到T1CC0
  T1CC0L = 0x40;                                                //定时器1通道 0捕获/比较值低位 
  T1CC0H = 0x9C;                                                //定时器1通道 0捕获/比较值高位   定义10ms进一次中断
  T1CCTL0 |= 0x44;                                              //定时器1 通0 捕获/比较控制
  T1IE = 1;                                                     //设定定时器1中断使能
  EA = 1;                                                       //设定总中断使能 
}
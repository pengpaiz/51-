#include <REGX52.H>



void Timer0_Init(void)		//@11.0592MHz
{
	 ET0 = 1;                 // 使能定时器 0 中断
   EA = 1;                  // 使能全局中断
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	PT0=0;          //优先级
}
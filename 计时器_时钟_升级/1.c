#include <REGX52.H>
#include "TIMER0.H"
#include "LCD1602.H"
#include "INTRINS.H"//_crol_和_cror_实现左移和右移



static unsigned int s,m,h;
//static:静止的

void main()
{
		P2_4=0;
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(2, 6, ":00:00:00");
	LCD_ShowString(2,1,"clock");
	LCD_ShowString(1,1,"HELLO,PNGPA1");
while(1)
    {
       LCD_ShowNum(2,13,s,2);
			LCD_ShowNum(2,10,m,2);
			LCD_ShowNum(2,7,h,2);
    }
}
void Timer0_Routine() interrupt 1
//跳转
{	
	static unsigned int T0count;
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	T0count++;
	if(T0count>=1000)
	{	
		T0count=0;
		s++;
			if(s>=60)
			{
				m++;
				s=0;
					if(m>=60)
					{
						h++;
						m=0;
					}
				}
			}
		if(s%2==1)
		{	
			P2_1=0;
			P2_2=1;
		}	
			else
		{		
			P2_1=1;
			P2_2=0;
		}
}
#include <REGX52.H>
#include "TIMER0.H"
#include "LCD1602.H"
#include "INTRINS.H"//_crol_和_cror_实现左移和右移
#include "KEY_JVZHENG.H"

static unsigned char s,min,h,d,m,y,w ;
//static:静止的

unsigned char key();
unsigned char timekey;
unsigned char mode;


void main()
{

	LCD_Init();
	Timer0_Init();
	LCD_ShowString(2, 6, ":00:00:00");
	LCD_ShowString(2,1,"clock");
	LCD_ShowString(1,1,"20  :  :");
	mode=0;
	y=1;
	m=1;
	d=1;
	
while(1)
    {
			
//	蔡勒公式（c=21）：w = ( y + y/4 + 26*(m+1)/10 + d - 36 ) % 7
		w= ( y + y/4 + 26*(m+1)/10 + d - 36 ) % 7;
		switch(w)
		{
				case 0: LCD_ShowString(1,14,"Sun");break;
				case 1: LCD_ShowString(1,14,"Mon");break;
				case 2: LCD_ShowString(1,14,"Tue");break;
				case 3: LCD_ShowString(1,14,"Wed");break;
				case 4: LCD_ShowString(1,14,"Thu");break;
				case 5: LCD_ShowString(1,14,"Fri");break;
				case 6: LCD_ShowString(1,14,"Sat");break;
		}
		
		
      LCD_ShowNum(2,13,s,2);
			LCD_ShowNum(2,10,min,2);
			LCD_ShowNum(2,7,h,2);
			LCD_ShowNum(1,9,d,2);
			LCD_ShowNum(1,6,m,2);
			LCD_ShowNum(1,3,y,2);
//			LED格式如下：
//			20yy:mm:dd
//			clock：hh:mm:ss
				timekey=key();
		if(mode==1||mode==0)
		{
			if(timekey==1)
			{
				y++;
			}
			if(timekey==2)
			{
				m++;
			}
			if(timekey==3)
			{
				d++;
			}
			if(timekey==4)
			{
				h++;
			}
			if(timekey==5)
			{
				min++;
			}
			if(timekey==6)
			{
				s++;
			}

		if(mode>=3)
		{
			if(timekey==1)
			{
				y--;
			}
			if(timekey==2)
			{
				m--;
			}
			if(timekey==3)
			{
				d--;
			}
			if(timekey==4)
			{
				h--;
			}
			if(timekey==5)
			{
				min--;
			}
			if(timekey==6)
			{
				s--;
			}
		}
	}
		
			
		
			if(timekey==15)
			{
					y=1;
					m=1;
					d=1;
					h=0;
					min=0;
					s=0;
			}
			
			//模式
				if(timekey == 16)//MODE0正常时钟，MODE1暂停，MODE2倒计时。
				{
						mode++;
						if(mode >= 3)
						{
								mode = 0;
								
						}
				}
			
		if(s >= 60) { s = 0; min++; }   
    if(min >= 60) { min = 0; h++; } 
    if(h >= 24) { h = 0; d++; }    
    if(d > 30) { d = 1; m++; }    
    if(m > 12) { m = 1; y++; }    
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
		if(mode==0)
		{
				T0count=0;
				s++;
					if(s>=60)
					{
						min++;
						s=0;
					}
							if(min>=60)
							{
								h++;
								min=0;
							}
							if(h>=24)
							{
								d++;
								h=0;
							}
								if(d>30)
								{
									min++;
									d=1;
								}
									if(m>=12)
									{
										y++;
										m=1;
									}
								}
		
									
							if(mode==1)
							{
								
								T0count=0;
							}
							if(mode==2)
							{
								T0count=0;
								if(s == 0)
					{
							s = 59;
							if(min == 0)
							{
									min = 59;
									if(h == 0)
									{
											h = 23;
											if(d <= 1)
											{
													d = 30;
													if(m <= 1)
													{
															m = 12;
															y--;
													}
													else
													{
															m--;
													}
											}
											else
											{
													d--;
											}
									}
									else
									{
											h--;
									}
							}
							else
							{
									min--;
							}
					}
					else
					{
							s--;
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
	
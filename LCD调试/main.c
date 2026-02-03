#include <REGX52.H>
#include "LCD1602.H"
#include "DELAY.H"
int num;
void main()
{
	num=1;
	LCD_Init();
	
	LCD_ShowString(2,1,"hell,word");
	
	while(1)
	{
		num++;
		Delay(1000);
		LCD_ShowNum(1,1,num,3);
	}
}

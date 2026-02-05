#include <REGX52.H>
#include "DELAY.H"
#include "LCD1602.H"
#include "KEY_JVZHENG.H"

unsigned char keynum;

void main()
{
	LCD_Init();		
	LCD_ShowString(1,1,"hello,word");
	while(1)
	{
		keynum=key();
			if(keynum)
			{
				LCD_ShowNum(2,1,keynum,2);
			}
	}
}
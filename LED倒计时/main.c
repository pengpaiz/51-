#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

unsigned char hour = 0;
unsigned char minute = 0;
unsigned char second = 0;
unsigned int count = 0;

void main()
{
    LCD_Init();
    
   
		LCD_ShowString(1,1,"hello,PNGPA1");
    
    while(1)
    {
        Delay(1);
        count++;
        
        if(count >= 1000)
        {
            count = 0;
            second++;
            
            if(second >= 60)
            {
                second = 0;
                minute++;
                
                if(minute >= 60)
                {
                    minute = 0;
                    hour++;
                    
                    if(hour >= 24)
                    {
                        hour = 0;
                    }
                }
            }
						LCD_ShowString(2,1,"Clock:");
            LCD_ShowNum(2,7,hour,2);
            LCD_ShowChar(2,9,':');
            LCD_ShowNum(2,10,minute,2);
            LCD_ShowChar(2,12,':');
            LCD_ShowNum(2,13,second,2);
    }
	}
}

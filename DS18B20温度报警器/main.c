#include <REGX52.H>
#include "LCD1602.h"
#include "DS18B20.h"
#include "Delay.h"

// ===== LED引脚定义（低电平亮） =====
sbit LED_20 = P2^0;   // 温度 > 20°C 时点亮
sbit LED_25 = P2^1;   // 温度 > 25°C 时点亮
sbit LED_30 = P2^2;   // 温度 > 30°C 时点亮

// ===== 蜂鸣器引脚定义（无源蜂鸣器，需要方波驱动） =====
sbit Buzzer = P2^5;

float T, TShow;

/**
  * @brief  无源蜂鸣器短延时
  * @param  无
  * @retval 无
  */
void Buzzer_Delay(void)
{
    unsigned char i;
    for(i = 0; i < 60; i++);
}

/**
  * @brief  根据温度控制三路LED（低电平亮）
  * @param  Temp 当前温度值
  * @retval 无
  */
void LED_Control(float Temp)
{
    if(Temp > 30.0)
    {
        LED_20 = 0;   // 三灯全亮（低电平）
        LED_25 = 0;
        LED_30 = 0;
    }
    else if(Temp > 25.0)
    {
        LED_20 = 0;   // 两灯亮
        LED_25 = 0;
        LED_30 = 1;
    }
    else if(Temp > 20.0)
    {
        LED_20 = 0;   // 一灯亮
        LED_25 = 1;
        LED_30 = 1;
    }
    else
    {
        LED_20 = 1;   // 全灭（高电平）
        LED_25 = 1;
        LED_30 = 1;
    }
}

/**
  * @brief  蜂鸣器控制（温度>30°C时发出报警声）
  *         使用无源蜂鸣器，需要方波脉冲驱动
  * @param  Temp 当前温度值
  * @retval 无
  */
void Buzzer_Control(float Temp)
{
    unsigned char j;
    
    if(Temp > 30.0)
    {
        // 产生一定数量的方波脉冲，发出间歇报警声
        for(j = 0; j < 100; j++)
        {
            Buzzer = 0;
            Buzzer_Delay();
            Buzzer = 1;
            Buzzer_Delay();
        }
    }
    else
    {
        Buzzer = 1;   // 蜂鸣器关闭（高电平）
    }
}

/**
  * @brief  LCD第二行显示报警状态
  *         注意：使用16个空格清空整行，避免残留字符
  * @param  Temp 当前温度值
  * @retval 无
  */
void LCD_ShowAlarmState(float Temp)
{
    // 先清空第二行（防止短字符串覆盖后残留字符）
    LCD_ShowString(2, 1, "                ");
    
    if(Temp > 30.0)
    {
        LCD_ShowString(2, 1, "Alarm: HIGH!   ");
    }
    else if(Temp > 25.0)
    {
        LCD_ShowString(2, 1, "Alarm: MIDDLE  ");
    }
    else if(Temp > 20.0)
    {
        LCD_ShowString(2, 1, "Alarm: LOW     ");
    }
    else
    {
        LCD_ShowString(2, 1, "Temp Normal    ");
    }
}

void main()
{
    // 上电先转换一次温度，防止第一次读数据错误
    DS18B20_ConvertT();
    Delay(1000);
    
    // 初始化所有输出
    LED_20 = 1;   // 初始熄灭
    LED_25 = 1;
    LED_30 = 1;
    Buzzer = 1;   // 蜂鸣器初始关闭
    
    LCD_Init();
    LCD_ShowString(1, 1, "Temp:");
    LCD_ShowString(2, 1, "Initializing...");
    Delay(500);
    
    while(1)
    {
        /* 温度读取 */
        DS18B20_ConvertT();      // 启动温度转换
        T = DS18B20_ReadT();     // 读取温度值
        
        /* LCD第一行显示温度 */
        if(T < 0)
        {
            LCD_ShowChar(1, 6, '-');
            TShow = -T;
        }
        else
        {
            LCD_ShowChar(1, 6, '+');
            TShow = T;
        }
        LCD_ShowNum(1, 7, (unsigned int)TShow, 3);            // 整数部分
        LCD_ShowChar(1, 10, '.');
        LCD_ShowNum(1, 11, (unsigned long)(TShow * 100) % 100, 2);  // 小数部分
        LCD_ShowChar(1, 13, 0xDF);   // 显示温度符号 °
        LCD_ShowChar(1, 14, 'C');
        
        /* LED分级报警控制 */
        LED_Control(T);
        
        /* LCD第二行显示报警状态（先清空再显示） */
        LCD_ShowAlarmState(T);
        
        /* 蜂鸣器控制（温度>30°C时发出方波报警声） */
        Buzzer_Control(T);
        
        Delay(200);  // 适度延时，避免刷新过快
    }
}

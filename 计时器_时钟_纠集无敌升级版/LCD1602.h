#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_Init();  
// LCD 初始化函数
// 例子：
// 上电后调用一次
// LCD_Init();
// 显示效果：LCD 被正确初始化，屏幕清空，准备显示内容
// ⚠️ 不调用，后面所有 Show 函数都可能无效或乱码


void LCD_ShowChar(unsigned char Line, unsigned char Column, char Char);
// 在指定 行 + 列 显示 单个字符
// 例子：
// LCD_ShowChar(1, 3, ':');
// 显示效果：
// 第 1 行第 3 列显示一个冒号 ':'
// 常用于：时间分隔符（12:30:45）、符号、闪烁显示单个字符


void LCD_ShowString(unsigned char Line, unsigned char Column, char *String);
// 显示字符串（以 '\0' 结尾）
// 例子：
// LCD_ShowString(1, 1, "Time");
// 显示效果：
// 第 1 行从第 1 列开始显示：Time
// 常用于：星期（Mon Tue）、模式提示（SET）、固定文本


void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
// 显示无符号十进制整数
// Length 指定显示位数，不足会补 0
// 例子：
// LCD_ShowNum(2, 1, 7, 2);
// 显示效果：
// 第 2 行第 1 列显示：07
// 非常适合：年 / 月 / 日 / 时 / 分 / 秒


void LCD_ShowSignedNum(unsigned char Line, unsigned char Column, int Number, unsigned char Length);
// 显示有符号十进制数（带正负号）
// 例子：
// LCD_ShowSignedNum(2, 1, -5, 2);
// 显示效果：
// 第 2 行第 1 列显示：-05
// 常见用途：温度、电压偏移等（你现在项目里不常用）


void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
// 显示十六进制数（0~9 A~F）
// 例子：
// LCD_ShowHexNum(1, 1, 255, 2);
// 显示效果：
// 第 1 行第 1 列显示：FF
// 常用于：调试寄存器值、端口状态（给“开发者看”）


void LCD_ShowBinNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
// 显示二进制数
// 例子：
// LCD_ShowBinNum(2, 1, 5, 4);
// 显示效果：
// 第 2 行第 1 列显示：0101
// 非常适合：
// - 调试 IO 口状态
// - 查看某个变量的每一位

#endif

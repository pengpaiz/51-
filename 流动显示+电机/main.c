#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"

/*==========================================
  5×7 ASCII字模（逐列式，每字5字节）
  索引: 0=空格, 1=A, 2=B ... 26=Z
==========================================*/
unsigned char code Font5x7[] = {
    // 0:空格
    0x00,0x00,0x00,0x00,0x00,
    // 1:A        2:B         3:C         4:D         5:E
    0x7C,0x12,0x11,0x12,0x7C, 0x7F,0x49,0x49,0x49,0x36,
    0x3E,0x41,0x41,0x41,0x22, 0x7F,0x41,0x41,0x22,0x1C,
    0x7F,0x49,0x49,0x49,0x41,
    // 6:F        7:G         8:H         9:I         10:J
    0x7F,0x09,0x09,0x09,0x01, 0x3E,0x41,0x49,0x49,0x7A,
    0x7F,0x08,0x08,0x08,0x7F, 0x00,0x41,0x7F,0x41,0x00,
    0x20,0x40,0x41,0x3F,0x01,
    // 11:K       12:L        13:M        14:N        15:O
    0x7F,0x08,0x14,0x22,0x41, 0x7F,0x40,0x40,0x40,0x40,
    0x7F,0x02,0x0C,0x02,0x7F, 0x7F,0x04,0x08,0x10,0x7F,
    0x3E,0x41,0x41,0x41,0x3E,
    // 16:P       17:Q        18:R        19:S        20:T
    0x7F,0x09,0x09,0x09,0x06, 0x3E,0x41,0x51,0x21,0x5E,
    0x7F,0x09,0x19,0x29,0x46, 0x46,0x49,0x49,0x49,0x31,
    0x01,0x01,0x7F,0x01,0x01,
    // 21:U       22:V        23:W        24:X        25:Y
    0x3F,0x40,0x40,0x40,0x3F, 0x1F,0x20,0x40,0x20,0x1F,
    0x3F,0x40,0x30,0x40,0x3F, 0x63,0x14,0x08,0x14,0x63,
    0x03,0x04,0x78,0x04,0x03,
    // 26:Z
    0x61,0x51,0x49,0x45,0x43
};

/*==========================================
  字母 → 字模索引转换
==========================================*/
unsigned char GetFontIndex(unsigned char ch)
{
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 1;
    return 0;
}

/*==========================================
  四段文本（直接用字符串定义）
==========================================*/
unsigned char code Text_Wait[]   = "PLEASE WAIT";
unsigned char code Text_Board[]  = "PLEASE BOARD";
unsigned char code Text_Repair[] = "UNDER REPAIR";
unsigned char code Text_Door[]   = "DOOR CLOSED";

// 指针与长度表
unsigned char code *pText[] = {Text_Wait, Text_Board, Text_Repair, Text_Door};
unsigned char code TextLen[] = {
    sizeof(Text_Wait) - 1,
    sizeof(Text_Board) - 1,
    sizeof(Text_Repair) - 1,
    sizeof(Text_Door) - 1
};

void main()
{
    unsigned char i, Select = 0, LastSelect = 1;
    unsigned char CharPos = 0, Count = 0;
    unsigned char idx;
    unsigned char *pFont;           // ← 移到函数开头
    
    MatrixLED_Init();
    
    while(1)
    {
        /*========== 按键检测 ==========*/
        if(P3_1 == 0) { Delay(20); while(P3_1 == 0); Delay(20); Select = 0; }
        if(P3_0 == 0) { Delay(20); while(P3_0 == 0); Delay(20); Select = 1; }
        if(P3_2 == 0) { Delay(20); while(P3_2 == 0); Delay(20); Select = 2; }
        if(P3_3 == 0) { Delay(20); while(P3_3 == 0); Delay(20); Select = 3; }
        
        // 切换文本时重置
        if(Select != LastSelect)
        {
            LastSelect = Select;
            CharPos = 0;
            Count = 0;
        }
        
        /*========== 显示当前字符 ==========*/
        idx = GetFontIndex(pText[Select][CharPos]);
        pFont = Font5x7 + idx * 5;
        
        // 左2列空白 + 5列字模 + 右1列空白
        MatrixLED_ShowColumn(0, 0x00);
        MatrixLED_ShowColumn(1, 0x00);
        for(i = 0; i < 5; i++)
            MatrixLED_ShowColumn(i + 2, pFont[i]);
        MatrixLED_ShowColumn(7, 0x00);
        
        /*========== 切换下一个字 ==========*/
        Count++;
        if(Count > 15)
        {
            Count = 0;
            CharPos++;
            if(CharPos >= TextLen[Select])
                CharPos = 0;
        }
    }
}

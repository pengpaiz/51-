#include <REGX52.H>


void Timer0_Init(void)   //@11.0592MHz
{
    TMOD &= 0xF0;        // 清除 T0 的模式位
    TMOD |= 0x01;        // ① 定时器0，模式1（16位）

    TL0 = 0x66;          // ② 1ms 定时初值
    TH0 = 0xFC;

    TF0 = 0;             // ③ 清中断标志
    ET0 = 1;             // ④ 使能 T0 中断
    EA  = 1;             // ⑤ 使能总中断
    PT0 = 0;             // ⑥ 中断优先级（低即可）

    TR0 = 1;             // ⑦ 启动定时器
}

#include <REGX52.H>
#include "DELAY.H"

unsigned char duli()
{
	unsigned char duli_num=0;
	
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);duli_num=1;}
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);duli_num=2;}//第二个按键为P2_0
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);duli_num=3;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);duli_num=4;}
	
	return duli_num;
}
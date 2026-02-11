#include <REGX52.H>
#include "DELAY.H"
unsigned char key()
{
	unsigned char keynum=0;
	
	//“¿¥Œ…®√Ë1£¨2£¨3¡–
	P1=0xFF;
	P1_3=0;                 
		if(P1_7==0)
		{Delay(20);while(P1_7==0);
			Delay(20);keynum=1;}
		if(P1_6==0)
		{Delay(20);while(P1_6==0);
			Delay(20);keynum=5;}
		if(P1_5==0)
		{Delay(20);while(P1_5==0);
			Delay(20);keynum=9;}
		if(P1_4==0)
		{Delay(20);while(P1_4==0);
			Delay(20);keynum=13;}
	P1=0xFF;
	P1_2=0;                 
		if(P1_7==0)
		{Delay(20);while(P1_7==0);
			Delay(20);keynum=2;}
		if(P1_6==0)
		{Delay(20);while(P1_6==0);
			Delay(20);keynum=6;}
		if(P1_5==0)
		{Delay(20);while(P1_5==0);
			Delay(20);keynum=10;}
		if(P1_4==0)
		{Delay(20);while(P1_4==0);
			Delay(20);keynum=14;}
	P1=0xFF;
	P1_1=0;                 
		if(P1_7==0)
		{Delay(20);while(P1_7==0);
			Delay(20);keynum=3;}
		if(P1_6==0)
		{Delay(20);while(P1_6==0);
			Delay(20);keynum=7;}
		if(P1_5==0)
		{Delay(20);while(P1_5==0);
			Delay(20);keynum=11;}
		if(P1_4==0)
		{Delay(20);while(P1_4==0);
			Delay(20);keynum=15;}
	P1=0xFF;
	P1_0=0;                 
		if(P1_7==0)
		{Delay(20);while(P1_7==0);
			Delay(20);keynum=4;}
		if(P1_6==0)
		{Delay(20);while(P1_6==0);
			Delay(20);keynum=8;}
		if(P1_5==0)
		{Delay(20);while(P1_5==0);
			Delay(20);keynum=12;}
		if(P1_4==0)
		{Delay(20);while(P1_4==0);
			Delay(20);keynum=16;}
	
	return keynum;
}
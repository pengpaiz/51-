#include <REGX52.H>


unsigned char nixieT[]={0x3F,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void Delay(unsigned int xms)//@11.0592MHz
{
	unsigned char	i, j;
	while(xms--)
	{
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	}
}	
void nixie(unsigned char loc,num)
{
	switch(loc)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=nixieT[num];
}
void main()
{	
	unsigned char i;
	while(1)
	{
		for(i=0;i<8;i++)
		nixie(8-i,i+1);
		Delay(10);
	}
}
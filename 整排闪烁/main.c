#include <REGX52.H>
#include <INTRINS.H>

void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()//Ð´µÄÀ¬»øÊ·É½
{
	while(1)
	{
		P2_0=0;
		Delay500ms();
		P2_0=1;
		P2_1=0;
		Delay500ms();
		P2_1=1;
		P2_2=0;
		Delay500ms();
		P2_2=1;
		P2_3=0;
		Delay500ms();
		P2_3=1;
		P2_4=0;
		Delay500ms();
		P2_4=1;
		P2_5=0;
		Delay500ms();
		P2_5=1;
		P2_6=0;
		Delay500ms();
		P2_6=1;
		P2_7=0;
		Delay500ms();
		P2_7=1;
		P2_0=0;
	}
}
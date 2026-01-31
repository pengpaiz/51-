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

void main()
{
	unsigned char LED= 0xFE;
	while(1)
	{
		P2=LED;
		Delay500ms();
		LED=(LED<< 1) | 0x01;
		if(LED== 0xFF) 
		{
						LED= 0xFE;    
		}
	}
}
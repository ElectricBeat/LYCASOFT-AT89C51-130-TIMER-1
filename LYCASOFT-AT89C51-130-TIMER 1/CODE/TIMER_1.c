#include<reg51.h>
void T1_delay(int i)
{
	int c=0;
	while(c<i)
	{
		TMOD = 0X10;		//Timer 1,mode 1(16 bit)
		TL1 = 0XFE;			//load TL1
		TH1 = 0XA5;			//load TH1
		TR1 = 1;				//turn on T1
		while(TF1==0);
		TR1 = 0;
		TF1 = 0;
		c++;
	}
}

void main()
{
	P2 = 0x00;
	while(1)
	{
		P2 = 0x01;
		T1_delay(20);
		P2 = 0x00;
		T1_delay(20);
	}
}
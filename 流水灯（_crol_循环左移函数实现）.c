#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
sbit beep=P1^4;

void delayms(int x)
{
int i,j;
for(i=x;i>0;i--)
	for(j=100;j>0;j--);									
}

void main()
{
	uchar a=0xfe;
	P1=a;
	delayms(500);
	while(1)
	{
	a=_crol_(a,1);
	P1=a;
	delayms(500);
	}
}

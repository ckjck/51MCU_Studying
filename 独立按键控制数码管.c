#include<reg52.h>
#define uchar unsigned char
	 
uchar code table[]={0xff,0xf9,0xa4,0xb0,0x99};
sbit key1=P3^1;
sbit key2=P3^2;
sbit key3=P3^3;
sbit key4=P3^5;
void initialize()
{
P3=0xff;	 //P3口全部置高
P1=0xff;	 //起初数码管不显示任何数
}		

void delay(int z)
{
	int x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void display(int num)
{
P1=table[num];
}

void main()
{
initialize();
	while(1)
	{
	
	if(key1==0)
	{
	delay(10);
		if(key1==0)
			{
			while(key1==0);
			display(1);
			}
	}
	
		if(key2==0)
	{
	delay(10);
		if(key2==0)
			{
			while(!key2);
			display(2);
			}
	}

		if(key3==0)
	{
	delay(10);
		if(key3==0)
			{
			while(!key3);
			display(3);
			}
	}

		if(key4==0)
	{
	delay(10);
		if(key4==0)
			{
			while(!key4);
			display(4);
			}
	}	

	

	}	
}

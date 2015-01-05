#include<reg52.h>
#define uchar unsigned char
uchar code table[]={
0x3f,~0x06,~0x5b,~0x4f,
~0x66,~0x6d,~0x7d,~0x07,
~0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,0};

void delay(int z)
{
int x,y;
for(x=z;x>0;x--)
	for(y=110;y>0;y--);
}


void initialize()
{
P1=0xff;	//起初数码管不显示任何数
}

void display()
{

P3=0xfd;
	if(P3!=0xfd)
	{
	delay(10);
		if(P3!=0xfd)
		{
		 	switch(P3)
		 	{
			case 0xed:while(P3==0xed);P1=table[1];
			break;
			case 0xdd:while(P3==0xdd);P1=table[2];
			break;
			case 0xbd:while(P3==0xbd);P1=table[3];
			break;
			case 0x7d:while(P3==0x7d);P1=table[4];
			break;
			}
		}
	}


P3=0xfb;
if(P3!=0xfb)
{
delay(10);
	if(P3!=0xfb)
	{
		switch(P3)
		{
		case 0xeb:while(P3==0xeb);P1=table[5];
		break;
		case 0xdb:while(P3==0xdb);P1=table[6];
		break;
		case 0xbb:while(P3==0xbb);P1=table[7];
		break;
		case 0x7b:while(P3==0x7b);P1=table[8];
		break;
		}	
	}
}

}


void main()
{
initialize();
	while(1)
	{
	display();
	}
}

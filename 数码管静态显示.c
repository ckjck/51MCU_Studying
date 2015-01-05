#include<reg52.h> 
#define uchar unsigned char 
uchar i;
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void delayms(int z);
void main()
{
	P0=0x00;
	while(1)
	{
		for(i=0;i<10;i++)
			{
				P1=table[i];
				delayms(300);	
			}
	}
}

void delayms(int z)
{
	int x,y;
	for(x=z;x>0;x--)
		for(y=100;y>0;y--);	
}






		

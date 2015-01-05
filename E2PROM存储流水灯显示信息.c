#include<reg52.h>

#include<intrins.h>

#define uchar unsigned char
sbit sda=P2^0;
sbit scl=P2^1;

void delayms(int x)
{
int i,j;
for(i=x;i>0;i--)
	for(j=110;j>0;j--);
}

void delay()
{;;}

void delay1(uchar x)
{
uchar i,j;
for(i=0;i<x;i++)
	for(j=0;j<110;j++);
}

void init()
{
scl=1;
sda=1;
}

void start()
{
sda=1;
delay();
scl=1;
delay();
sda=0;
delay();
}

void stop()
{
sda=0;
delay();
scl=1;
delay();
sda=1;
delay();
}

void write_byte(uchar byte)
{
uchar i,temp;
sda=1;
scl=0;
temp=byte;
	for(i=0;i<8;i++)
	{
	temp=temp<<1;
	sda=CY;
	scl=1;
	delay();
	scl=0;
	delay();
	}
}

uchar read_byte()
{
uchar i,j;
scl=0;
sda=1;
	for(j=0;j<8;j++)
	{
	i=sda|(i<<1);
	scl=1;
	delay();
	scl=0;
	}
return(i);
}

void response()
{
uchar i=0;
scl=1;
delay();
while((sda==1)&&(i<250))
i++;
scl=0;
}

void write_add(uchar add,uchar data1)
{
start();
write_byte(0xa0);		 //寻器件地址
response();					 
write_byte(add);		 //在哪个扇区地址写
response();
write_byte(data1);
response();
stop();
}

uchar read_add(uchar add)
{
uchar i;
start();
write_byte(0xa0);
response();
write_byte(add);
response();
start();
write_byte(0xa1);
response();
i=read_byte();
response();
stop();
return(i);
}

void main()
{
	uchar a=0xfe;
	init();					
	a=read_add(1);
	if((a!=0xfe)&&(a!=0xfd)&&(a!=0xfb)&&(a!=0xf7)&&(a!=0xef)&&(a!=0xdf)&&(a!=0xbf)&&(a!=0x7f))//防止第一次读取时出错
	a=0xfe;
	delay1(3);
	P1=a;
	delayms(500);
	while(1)
	{													
	a=_crol_(a,1);
	write_add(1,a);
	P1=a;
	delayms(500);
	}
}

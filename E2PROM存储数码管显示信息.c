#include<reg52.h>

#include<intrins.h>

#define uchar unsigned char
sbit sda=P2^0;
sbit scl=P2^1;

sbit D1=P0^0;

uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

int t;

void initialize()
{
D1=0;		//开启第一个数码管
TMOD=0x11;					//设置为16位定时计数器定时模式，且只由软件控制
EA=1;								//开启CPU中断总允许位
ET0=1;							//开启定时\计数器中断允许位
TR0=1;							//定时\计数器启动
TH0=(65536-50000)/256;		//设置定时器初值
TL0=(65536-50000)%256;		//设置定时器初值
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
write_byte(0xa0);
response();
write_byte(add);
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
uchar i;
init();
initialize();
i=0;
//P1=0x3f;				//设置数码管初态为0
i=read_add(1);
	if(i>=10)
	i=0;
delay1(3);
P1=i;
delay1(500);

	while(1)
	{
		if(t==20)
		{
		t=0;
		i++;
		write_add(1,i);
		if(i==10)
		i=0;
		P1=table[i];
		}
	}
}


void time() interrupt 1
{
TH0=(65536-50000)/256;	
TL0=(65536-50000)%256;
t++;	
}	

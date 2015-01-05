#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit lcden=P2^7;
sbit lcdrs=P2^6;
sbit lcdwr=P2^5;
uchar table[]={"abcdefg         "};


void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void write_com(uchar command)
{
lcdwr=0;//设置为写操作
lcdrs=0;//设置为写命令
P0=command;
delay(1);
lcden=1;
delay(2);
lcden=0;

}

void write_data1(uchar data1)
{
lcdwr=0;//设置为写操作
lcdrs=1;//设置为写数据
P0=data1;
delay(1);
lcden=1;
delay(2);
lcden=0;
}


void initialize()
{
write_com(0x38); 		//设置16X2显示，5X7点阵，8位数据接口
write_com(0x02);		//数据指针清零
write_com(0x0c);		//光标不显示而且不闪烁
write_com(0x07);		//地址指针和光标自动加一
write_com(0x80+0x50);	////从液晶第二行末端开始往后写（先不显示出来）

}																										

void main()
{
int i=0;
initialize();
	for(i=0;i<16;i++)
	{
	write_data1(table[i]);
	delay(100);
	}
while(1);		 //只使它从右往左移动一次，去掉此语句则循环移动
}

#include<reg52.h>

sbit SDA=P2^0;
sbit SCL=P2^1;
sbit wr=P2^5;
sbit rd=P2^6;

void initialize()
{
SDA=1;
wr=1;
}

void main()
{
initialize();
}

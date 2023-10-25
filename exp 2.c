#include <lpc214x.h>
int i,b;
int main()
{
IODIR0=0x000000FF;
IODIR0=~(1<<16)&~(1<<23);
while(1)
{
if((IOPIN0&(1<<16))==0)
{
for(b=0;b<8;b++)
{
IOSET0=(1<<b);
for(i=0;i<120000;i++);
IOCLR0=(1<<b); for(i=0;i<120000;i++);
}
}
else if((IOPIN0&(1<<23))==0)
{
for(b=7;b>=0;b--)
{
IOSET0=(1<<b); for(i=0;i<120000;i++);
IOCLR0=(1<<b); for(i=0;i<120000;i++);
}
}
else
{
IOCLR0=0x000000FF;
}
}
}
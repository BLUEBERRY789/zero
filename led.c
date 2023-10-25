#include"lpc214x.h" // lpc2148 header file for KIEL IDE
void delay(unsigned long int h) // delay function
{
unsigned long int i,j;
for(j=0;j<h; j++)
for(i=0;i<5000;i++);
}
int main()
{
IODIR0 = 0xFFFFFFFF; // making port 0 output port
IODIR1 = 0xFFFFFFFF; // making port 1 output port
while(1)
{
IOCLR0 = 0xFFFFFFFF; // making port 0 low
IOCLR1 = 0xFFFFFFFF; // making port 1 low
delay(1000);
IOSET0 = 0xFFFFFFFF; // making port 0 low
IOSET1 = 0xFFFFFFFF; // making port 1 low
delay(1000);
}
}
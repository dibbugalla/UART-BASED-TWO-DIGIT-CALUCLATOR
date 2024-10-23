#include<LPC21XX.h>
#include"header.h"
void uart0_init(unsigned int baud)
{
int a[]={15,60,30,15,15};
unsigned int result=0;
unsigned int PCLK=a[VPBDIV]*1000000;
result=PCLK/(16*baud);
PINSEL0|=0x05;
U0LCR=0X83;
U0DLL=result&0xFF;
U0DLM=(result>>8)&0xFF;
U0LCR=0X03;
}

#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
	while(RDR==0);
	return U0RBR;
}

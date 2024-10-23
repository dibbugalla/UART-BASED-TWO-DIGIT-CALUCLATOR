#include<LPC21XX.h>
#include"header.h"
#include<stdio.h>
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


#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}


#define THRE ((U0LSR>>5)&1)
void uart0_tx_string(char *ptr)
{
	while(*ptr!=0)
	{
		U0THR=*ptr;
		while(THRE==0);
		ptr++;
}
}
#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
	while(RDR==0);
	return U0RBR;
	
}

void uart0_tx_int(unsigned int num)
{
	char arr[10];
	sprintf(arr,"%d",num);
	uart0_tx_string(arr);
}

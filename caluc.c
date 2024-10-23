#include<LPC21XX.H>
#include"header.h"
int main(){
unsigned int n1,n2,r;
char op;
uart0_init(9600);
while(1){
uart0_tx_string("\r\nenter n1 val");
n1=uart0_rx();
uart0_tx(n1);
uart0_tx_string("\r\nenter op");
op=uart0_rx();
uart0_tx(op);
uart0_tx_string("\r\nenter n2 val");
n2=uart0_rx();
uart0_tx(n2);
while(uart0_rx()!='\r');
n1=n1-48;
n2=n2-48;
switch(op){
case'+' : r=n1+n2;
 uart0_tx_string("\r\nResult:");
uart0_tx((r/10)+48);
5
uart0_tx((r%10)+48);
break;
case'-' : r=n1-n2;
 uart0_tx_string("\r\nResult:");
uart0_tx((r/10)+48);
uart0_tx((r%10)+48);
 break;
default :uart0_tx_string("\r\nwrong choice");
 break;
}
}
}

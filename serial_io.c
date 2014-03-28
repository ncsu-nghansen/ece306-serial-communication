#include "functions.h"
#include "macros.h"
#include "msp430.h"

void TxByte(char c)
{
	UCA1TXBUF = c;	
        waitMsec(10);
}

void RxByte(char* c)
{
	*c = UCA1RXBUF;
}

void TxArray(char* array, int length)
{
	for(int i=0; i < length; i++)
		TxByte(array[i]);
}

void RxArray(char* array, int* i, int length)
{
	if(*i < 0)
		*i = -*i;
	*i %= length;
	RxByte(array+*i);
        *i++;
}
/*
 * File:   eusart.c
 * Author: liruya
 *
 */

#include "../inc/eusart.h"

#define TX_BUF_SIZE		32
uint8_t txTail;
uint8_t txRemain;
uint8_t txHead;
uint8_t txBuf[TX_BUF_SIZE];

EUSART_ReceiveInterruptHandler_t eusart_rcv_isr_handler;

/**
 * baudrate 9600@16MHz, rx isr disabled,
 */
void EUSART_Initialize_Default ( )
{
	PIE1bits.RCIE = 0;
	PIE1bits.TXIE = 0;
	BAUDCON = BAUDCON_BRG16;
	RCSTA = RCSTA_SPEN | RCSTA_CREN;
	TXSTA = TXSTA_TXEN | TXSTA_BRGH;
	SPBRG = BAUDRATE_16M_9600;

	//    PIE1bits.RCIE = 1;
	txTail = 0;
	txHead = 0;
	txRemain = sizeof (txBuf );
}

uint8_t EUSART_Write ( uint8_t byte )
{
	while ( 0 == txRemain );

	if ( !PIE1bits.TXIE )
	{
		TXREG = byte;
	}
	else
	{
		PIE1bits.TXIE = 0;
		txBuf[txHead++] = byte;
		if ( sizeof (txBuf ) <= txHead )
		{
			txHead = 0;
		}
		txRemain--;
	}
	PIE1bits.TXIE = 1;
	return byte;
}

void EUSART_Receive_ISR ( )
{
	uint8_t rcv = RCREG;
	if ( eusart_rcv_isr_handler )
	{
		eusart_rcv_isr_handler ( rcv );
	}
}

void EUSART_Transmit_ISR ( )
{
	if ( sizeof (txBuf ) > txRemain )
	{
		TXREG = txBuf[txTail++];
		if ( sizeof (txBuf ) <= txTail )
		{
			txTail = 0;
		}
		txRemain++;
	}
	else
	{
		PIE1bits.TXIE = 0;
	}
}

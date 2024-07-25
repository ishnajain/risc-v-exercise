#include <hal_uart.h>

void uart_en()
{
	//set Transmission Control register
	//TXEN: for enabling transmission
	//TXSB: for stop bits (one stop bit enabled)
	//TXCNT: for transmit watermark 
	MMIO32(BASE_ADDRESS + TXCTRL_OFFSET) |= ((1<<TXEN) | (0<<TX_SB) | (0<<TXCNT));
}

int check_tx_buffer()
{ 
	return (int)(MMIO32((BASE_ADDRESS + TXDATA)>>TX_FULL) ^ 1);
}

int  uart_tx(char  a)
{
	while(!check_tx_buffer());
	MMIO32(BASE_ADDRESS + TXDATA) = a;
	return 1;
}

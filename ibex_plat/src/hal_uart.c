#include <hal_uart.h>

int  uart_tx(char  a)
{
	MMIO32(BASE_ADDRESS + TXDATA) = a;
	return 1;
}

#include <lib_print.h>
#include <hal_uart.h>

void putc(char c)
{
	uart_tx(c);
}

void puts(char *str)
{
	while(*str)
	{
		putc(*str++);
	}
}

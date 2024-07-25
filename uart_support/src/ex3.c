#include <hal_uart.h>
#include <lib_print.h>
extern void update_vector();
extern int bootstrap();
int main()
{       update_vector();
	bootstrap();
	uart_en();
	puts("Hello\n");
	return 0;
}


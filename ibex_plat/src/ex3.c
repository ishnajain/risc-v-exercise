#include <hal_uart.h>
#include <lib_print.h>
extern int bootstrap();

void ecallhndlr()
{
	puts("ECALL exception\n");
}
void quit()
{
	MMIO32(0x20008) = 1;
}

int main()
{      
	bootstrap();
	puts("Hello\n");
	asm volatile("ecall");
	quit();
	return 0;
}


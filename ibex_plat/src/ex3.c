#include <hal_uart.h>
#include <hal_timer.h>
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
	delay_ms(1000);
	puts("delay 1s\n");
	quit();
	return 0;
}


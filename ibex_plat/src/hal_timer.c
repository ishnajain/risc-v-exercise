#include <hal_timer.h>

uint64_t  get_ticks()
{
	uint32_t temp, tl, th;
	do{
		temp = MMIO32(MTIMEH);
		tl = MMIO32(MTIMEL);
		th = MMIO32(MTIMEH);
	} while ( temp != th);

	return (((uint64_t)th << 32) | (uint64_t)tl);
}

static uint64_t ticks_per_ms(uint64_t ticks)
{
	return (ticks >> 9) ;
}

uint64_t get_time()
{
	uint64_t ticks = get_ticks();
	return ticks_per_ms(ticks);
}

void delay_ms(uint32_t n)
{
	uint64_t ticks = get_time();
	uint64_t t_elapsed = ticks + (uint64_t)n;
	while(t_elapsed > ticks)
		ticks = get_time();
}

void timer_start()
{
	MMIO32(MTIMEH) = 0;
	MMIO32(MTIMEL) = 0;
}

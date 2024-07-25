#pragma once
#include <mmio.h>
#define MTIMEL	0x30000
#define MTIMEH	0x30004

#define FT	2000000UL

uint64_t get_ticks();
uint64_t get_time();
void delay_ms(uint32_t n);
void timer_start();

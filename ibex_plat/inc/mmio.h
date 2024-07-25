#pragma once

typedef unsigned long long int uint64_t;
typedef unsigned int uint32_t;

#define MMIO32(X) (*(volatile uint32_t *)(X))

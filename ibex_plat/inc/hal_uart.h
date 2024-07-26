//Specifications for ibex simple system 
#ifndef HAL_UART_H
#define HAL_UART_H

#include <mmio.h>

#define TXDATA 0x0
#define BASE_ADDRESS 0x20000
int uart_tx(char a);

#endif

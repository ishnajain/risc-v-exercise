//Specifications for ibex simple system 
#ifndef HAL_UART_H
#define HAL_UART_H

typedef  unsigned int uint32_t;

#define TXDATA 0x0
#define BASE_ADDRESS 0x20000
#define MMIO32(X) (*(volatile uint32_t *)(X))

int uart_tx(char a);

#endif

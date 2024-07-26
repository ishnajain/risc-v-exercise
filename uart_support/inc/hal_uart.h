//Specifications from FE310_G002 
#ifndef HAL_UART_H
#define HAL_UART_H

typedef  unsigned int uint32_t;

#define TXDATA 0x0
#define TX_FULL 31
#define TXEN  0x0
#define TXCNT 0x16
#define TX_SB 0x1
#define TXCTRL_OFFSET 0x08
#define BASE_ADDRESS 0x10013000
#define BRDR 0x18		
#define MMIO32(X) (*(volatile uint32_t *)(X))

void uart_en();
int uart_tx(char a);

#endif

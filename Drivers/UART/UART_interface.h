#ifndef UART_INT_H_
#define UART_INT_H_

#include <stdint.h>

void UART_init(void);
unsigned char UART_checkFIFORX(void);
unsigned char UART_checkFIFOTX(void);
uint8_t UART_recByte(void);
void UART_sendByte(uint8_t data);

#endif

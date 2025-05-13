#ifndef UART_INT_H_
#define UART_INT_H_

#include <stdint.h>

void UART0_init(void);
unsigned char UART0_checkFIFORX(void);
unsigned char UART0_checkFIFOTX(void);
uint8_t UART0_recByte(void);
void UART0_sendByte(uint8_t data);

void UART1_init(void);
unsigned char UART1_checkFIFORX(void);
unsigned char UART1_checkFIFOTX(void);
uint8_t UART1_recByte(void);
void UART1_sendByte(uint8_t data);

#endif

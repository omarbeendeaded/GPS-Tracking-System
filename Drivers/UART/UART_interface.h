#ifndef UART_INT_H_
#define UART_INT_H_

void UART_init();
unsigned char UART_checkFIFORXFULL();
unsigned char UART_recByte();
unsigned char UART_checkFIFOTXEmpty();
unsigned char UART_sendByte(unsigned char b);

#endif
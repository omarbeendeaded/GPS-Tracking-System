#ifndef UART_H_
#define UART_H_

void init();
unsigned char checkFIFORXFULL();
unsigned char recByte();
unsigned char checkFIFOTXEmpty();
unsigned char sendByte(unsigned char b);

#endif
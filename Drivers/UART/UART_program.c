#include "UART_interface.h"
#include "UART_private.h"

// Assumes a 80 MHz bus clock, creates 9600 baud rate
void UART_init(void){
    // should be called only once
    SYSCTL_RCGCUART_R |= 0x00000002; // activate UART1
    SYSCTL_RCGCGPIO_R |= 0x00000004; // activate port C
    UART1_CTL_R &= ~0x00000001; // disable UART
    UART1_IBRD_R = 520; // IBRD int(80,000,000/(16*9600)) = int(520.83)
    UART1_FBRD_R = 53;  // FBRD round (0.83*64) = 53
    UART1_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOS
    UART1_CTL_R |= 0x00000301; // enable UART, TXE, RXE
    GPIO_PORTC_AFSEL_R |= 0x30; // enable alt funct on PC5-4
    GPIO_PORTC_DEN_R |= 0x30; // configure PC5-4 as UART1
    GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & 0xFF00FFFF) + 0x00220000;
    GPIO_PORTC_AMSEL_R &= ~0x30; // disable analog on PC5-4
}

// check if TX FIFO is full
unsigned char UART_checkFIFOTX(){
    return ((UART1_FR_R & 0x20)==0); // bit 5 = TXFF
}
// check if RX FIFO is empty
unsigned char UART_checkFIFORX(){
    return ((UART1_FR_R & 0x10)==0); // bit 4 = RXFE
}
// send one byte (blocking)
void UART_sendByte(uint8_t data){
    while (!UART_checkFIFOTX()); // wait until space in TX FIFO
    UART1_DR_R = data;
}
// receive one byte (blocking)
uint8_t UART_recByte(){
    while (!UART_checkFIFORX()); // wait until data in RX FIFO
    return (uint8_t)(UART1_DR_R & 0xFF);
}

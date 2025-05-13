#include "UART_interface.h"
#include "UART_private.h"

////////////////////////// UART 0 /////////////////////////////
void UART0_init(void){
    // should be called only once
    SYSCTL_RCGCUART_R |= 0x00000001; // activate UART0
    SYSCTL_RCGCGPIO_R |= 0x00000001; // activate port A
    UART0_CTL_R &= ~0x00000001; // disable UART
    UART0_IBRD_R = 104; 
    UART0_FBRD_R = 11; 
    UART0_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOS
    UART0_CTL_R |= 0x00000301; // enable UART, TXE, RXE
    GPIO_PORTA_AFSEL_R |= 0x03; // enable alt funct on PA1-0
    GPIO_PORTA_DEN_R |= 0x03; // configure PA1-0 as UART0
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) + 0x00000011;
    GPIO_PORTA_AMSEL_R &= ~0x03; // disable analog on PA1-0
}

// check if TX FIFO is full
unsigned char UART0_checkFIFOTX(){
    return ((UART0_FR_R & 0x20)==0); // bit 5 = TXFF
}
// check if RX FIFO is empty
unsigned char UART0_checkFIFORX(){
    return ((UART0_FR_R & 0x10)==0); // bit 4 = RXFE
}
// send one byte (blocking)
void UART0_sendByte(uint8_t data){
    while (!UART0_checkFIFOTX()); // wait until space in TX FIFO
    UART0_DR_R = data;
}
// receive one byte (blocking)
uint8_t UART0_recByte(){
    while (!UART0_checkFIFORX()); // wait until data in RX FIFO
    return (uint8_t)(UART0_DR_R & 0xFF);
}


////////////////////////// UART 1 /////////////////////////////
void UART1_init(void){
    // should be called only once
    SYSCTL_RCGCUART_R |= 0x00000002; // activate UART1
    SYSCTL_RCGCGPIO_R |= 0x00000004; // activate port C
    UART1_CTL_R &= ~0x00000001; // disable UART
    UART1_IBRD_R = 104;
    UART1_FBRD_R = 11;  
    UART1_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOS
    UART1_CTL_R |= 0x00000301; // enable UART, TXE, RXE
    GPIO_PORTC_AFSEL_R |= 0x30; // enable alt funct on PC5-4
    GPIO_PORTC_DEN_R |= 0x30; // configure PC5-4 as UART1
    GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & 0xFF00FFFF) + 0x00220000;
    GPIO_PORTC_AMSEL_R &= ~0x30; // disable analog on PC5-4
}

// check if TX FIFO is full
unsigned char UART1_checkFIFOTX(){
    return ((UART1_FR_R & 0x20)==0); // bit 5 = TXFF
}
// check if RX FIFO is empty
unsigned char UART1_checkFIFORX(){
    return ((UART1_FR_R & 0x10)==0); // bit 4 = RXFE
}
// send one byte (blocking)
void UART1_sendByte(uint8_t data){
    while (!UART1_checkFIFOTX()); // wait until space in TX FIFO
    UART1_DR_R = data;
}
// receive one byte (blocking)
uint8_t UART1_recByte(){
    while (!UART1_checkFIFORX()); // wait until data in RX FIFO
    return (uint8_t)(UART1_DR_R & 0xFF);
}

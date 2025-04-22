#include "UART_interface.h"
#include "UART_private.h"

// Assumes a 80 MHz bus clock, creates 9600 baud rate 
void UART_Init(void){ 
    // should be called only once 
    SYSCTL_RCGCUART_R |= 0x00000002; // activate UART1 
    SYSCTL_RCGCGPIO_R |= 0x00000004; // activate port C 
    UART1_CTL_R &= ~0x00000001; // disable UART 
    UART1_IBRD_R = 520; // IBRD int(80,000,000/(16*115,200)) = int(43.40278) 
    UART1_FBRD_R = 53; // FBRD round (0.40278*64) = 26 
    UART1_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOS 
    UART1_CTL_R |= 0x00000001; // enable UART 
    GPIO_PORTC_AFSEL_R = 0x30; // enable alt funct on PC5-4 
    GPIO_PORTC_DEN_R |= 0x30; // configure PC5-4 as UART1 
    GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R &0xFF00FFFF) + 0x00220000; 
    GPIO_PORTC_AMSEL_R &= ~0x30; // disable analog on PC5-4 
}
#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define UART1_CTL_R (*((volatile unsigned long *)0x4000D030))
#define UART1_IBRD_R (*((volatile unsigned long *)0x4000D024))
#define UART1_FBRD_R (*((volatile unsigned long *)0x4000D028))
#define UART1_LCRH_R (*((volatile unsigned long *)0x4000D02C))
#define UART1_FR_R (*((volatile unsigned long *)0x4000D018))
#define UART1_DR_R  (*((volatile unsigned long *)0x4000D000))

#define SYSCTL_RCGCUART_R (*((volatile unsigned long *)0x400FE618))
#define SYSCTL_RCGCGPIO_R (*((volatile unsigned long *)0x400FE608))
#define GPIO_PORTC_AFSEL_R (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_DEN_R (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_PCTL_R (*((volatile unsigned long *)0x4000652C))
#define GPIO_PORTC_AMSEL_R (*((volatile unsigned long *)0x40006528))

#endif

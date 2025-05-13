#ifndef GPIO_Private
#define GPIO_Private

//#define SYSTEM_CLOCK  80000000
#define RCGCGPIO			(*((volatile unsigned long*)0x400FE608))
#define PRGPIO				(*((volatile unsigned long*)0x400FEA08))

// Base address 
#define BASE_GPIO_PORTA_APB 		(0x40004000)
#define BASE_GPIO_PORTB_APB 		(0x40005000)
#define BASE_GPIO_PORTC_APB 		(0x40006000)
#define BASE_GPIO_PORTD_APB 		(0x40007000)
#define BASE_GPIO_PORTE_APB 		(0x40024000)
#define BASE_GPIO_PORTF_APB 		(0x40025000)

//direction
#define GPIO_PORTA_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x400)))
#define GPIO_PORTB_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x400)))
#define GPIO_PORTC_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x400)))
#define GPIO_PORTD_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x400)))
#define GPIO_PORTE_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x400)))
#define GPIO_PORTF_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x400)))
	
//Alternate function
#define GPIO_PORTA_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x420)))
#define GPIO_PORTB_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x420)))
#define GPIO_PORTC_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x420)))
#define GPIO_PORTD_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x420)))
#define GPIO_PORTE_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x420)))
#define GPIO_PORTF_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x420)))

//prepherial selection
#define GPIO_PORTA_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x52C)))
#define GPIO_PORTB_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x52C)))
#define GPIO_PORTC_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x52C)))
#define GPIO_PORTD_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x52C)))
#define GPIO_PORTE_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x52C)))
#define GPIO_PORTF_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x52C)))

//Pull UP
#define GPIO_PORTA_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x510)))
#define GPIO_PORTB_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x510)))
#define GPIO_PORTC_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x510)))
#define GPIO_PORTD_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x510)))
#define GPIO_PORTE_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x510)))
#define GPIO_PORTF_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x510)))

// GPIO Pull-Down Select
#define GPIO_PORTA_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x514)))
#define GPIO_PORTB_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x514)))
#define GPIO_PORTC_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x514)))
#define GPIO_PORTD_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x514)))
#define GPIO_PORTE_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x514)))
#define GPIO_PORTF_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x514)))
	
//Digital enable
#define GPIO_PORTA_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x51C)))
#define GPIO_PORTB_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x51C)))
#define GPIO_PORTC_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x51C)))
#define GPIO_PORTD_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x51C)))
#define GPIO_PORTE_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x51C)))
#define GPIO_PORTF_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x51C)))

//LOCK register
#define GPIO_PORTA_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x520)))
#define GPIO_PORTB_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x520)))
#define GPIO_PORTC_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x520)))
#define GPIO_PORTD_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x520)))
#define GPIO_PORTE_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x520)))
#define GPIO_PORTF_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x520)))

//Commit register
#define GPIO_PORTA_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x524)))
#define GPIO_PORTB_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x524)))
#define GPIO_PORTC_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x524)))
#define GPIO_PORTD_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x524)))
#define GPIO_PORTE_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x524)))
#define GPIO_PORTF_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x524)))

//Analog enable
#define GPIO_PORTA_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x528)))
#define GPIO_PORTB_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x528)))
#define GPIO_PORTC_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x528)))
#define GPIO_PORTD_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x528)))
#define GPIO_PORTE_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x528)))
#define GPIO_PORTF_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x528)))

//Data/READ/WRITE register
#define GPIO_PORTA_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB+0x3FC)))
#define GPIO_PORTB_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB+0x3FC)))
#define GPIO_PORTC_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB+0x3FC)))
#define GPIO_PORTD_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB+0x3FC)))
#define GPIO_PORTE_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB+0x3FC)))
#define GPIO_PORTF_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB+0x3FC)))

//Open-drain register
#define GPIO_PORTA_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB+0x50C)))
#define GPIO_PORTB_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB+0x50C)))
#define GPIO_PORTC_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB+0x50C)))
#define GPIO_PORTD_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB+0x50C)))
#define GPIO_PORTE_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB+0x50C)))
#define GPIO_PORTF_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB+0x50C)))
	
#define GPIO_LOCK_KEY					0x4C4F434B    


#define PIN_0							0
#define PIN_1							1
#define PIN_2							2
#define PIN_3							3
#define PIN_4							4
#define PIN_5							5
#define PIN_6							6
#define PIN_7							7
#define LOW						   	0
#define HIGH							1

#endif
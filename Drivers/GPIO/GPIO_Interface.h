#ifndef GPIO_Interface
#define GPIO_Interface
#include <stdint.h>

//enums for initing GPIO
typedef enum{
	PORTA,PORTB,PORTC,PORTD,PORTE,PORTF 
}GPIO_Port_Select;

//for init a pin
typedef enum{
	PullDown, PullUp, NoPull
}GPIO_Polarity;

typedef enum{
	INPUT, OUTPUT
}GPIO_Mode;

typedef enum{
	Low, High
}GPIO_Write;



void GPIO_Port_Init(GPIO_Port_Select GPIOSEL); // enable port as a digital GPIO 
void GPIO_Digital_PIN_MODE(GPIO_Port_Select GPIOSEL, uint8_t pin, GPIO_Mode Mode, GPIO_Polarity Polarity); //Choose input or output and polarity
void GPIO_Write_Pin(GPIO_Port_Select GPIOSEL, uint32_t pin, GPIO_Write data); // Write a value on a pin
uint8_t GPIO_Read_pin(GPIO_Port_Select GPIOSEL, uint32_t pin);  //Read the input data of a specific pin


void GPIO_WritePort(GPIO_Port_Select port, uint8_t data);   //Write on a port 
uint8_t GPIO_ReadPort(GPIO_Port_Select GPIOSEL);    //Read from a port 

// read port and write port function
#endif
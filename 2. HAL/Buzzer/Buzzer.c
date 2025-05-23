#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/GPIO/GPIO_Private.h"

void Buzzervoid_ON (uint8_t PORT, uint8_t PIN)
{
    GPIO_Port_Init(PORT); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, High);                                                     
}

void Buzzervoid_OFF (uint8_t PORT, uint8_t PIN)
{
    GPIO_Port_Init(PORT); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, Low);
}
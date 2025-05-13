
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "../../LIB/util.h"

void GPIO_Port_Init(GPIO_Port_Select GPIOSEL){
	switch(GPIOSEL){
		case PORTA:
			SET_BIT(RCGCGPIO, PORTA); 
			while((PRGPIO & (1 << PORTA)) == 0);
			GPIO_PORTA_LOCK = GPIO_LOCK_KEY;    //unlock GPIO
			GPIO_PORTA_CR = 0xFF; 
			GPIO_PORTA_AMSEL = 0x00;
			GPIO_PORTA_AFSEL = 0x00;
			GPIO_PORTA_PCTL = 0;
			GPIO_PORTA_DEN = 0xFF;
		break;
		
		case PORTB:
			SET_BIT(RCGCGPIO, PORTB);
			while((PRGPIO & (1 << PORTB)) == 0);
			GPIO_PORTB_LOCK = GPIO_LOCK_KEY;
			GPIO_PORTB_CR = 0xFF; 
			GPIO_PORTB_AMSEL = 0x00;
			GPIO_PORTB_AFSEL = 0x00;
			GPIO_PORTB_PCTL = 0;
			GPIO_PORTB_DEN = 0xFF;
		break;

		case PORTC:
			SET_BIT(RCGCGPIO, PORTC);
			while((PRGPIO & (1 << PORTC)) == 0);
			GPIO_PORTC_LOCK = GPIO_LOCK_KEY;
			GPIO_PORTC_CR = 0xFF; 
			GPIO_PORTC_AMSEL = 0x00;
			GPIO_PORTC_AFSEL = 0x00;
			GPIO_PORTC_PCTL = 0;
			GPIO_PORTC_DEN = 0xFF;
		break;

		case PORTD:
			SET_BIT(RCGCGPIO, PORTD);
			while((PRGPIO & (1 << PORTD)) == 0);
			GPIO_PORTD_LOCK = GPIO_LOCK_KEY;
			GPIO_PORTD_CR = 0xFF; 
			GPIO_PORTD_AMSEL = 0x00;
			GPIO_PORTD_AFSEL = 0x00;
			GPIO_PORTD_PCTL = 0;
			GPIO_PORTD_DEN = 0xFF;
		break;

		case PORTE:
			SET_BIT(RCGCGPIO, PORTE);
			while((PRGPIO & (1 << PORTE)) == 0);
			GPIO_PORTE_LOCK = GPIO_LOCK_KEY;
			GPIO_PORTE_CR = 0xFF; 
			GPIO_PORTE_AMSEL = 0x00;
			GPIO_PORTE_AFSEL = 0x00;
			GPIO_PORTE_PCTL = 0;
			GPIO_PORTE_DEN = 0xFF;
		break;

		case PORTF:
			SET_BIT(RCGCGPIO, PORTF);
			while((PRGPIO & (1 << PORTF)) == 0);
			GPIO_PORTF_LOCK = GPIO_LOCK_KEY;
			GPIO_PORTF_CR = 0xFF; 
			GPIO_PORTF_AMSEL = 0x00;
			GPIO_PORTF_AFSEL = 0x00;
			GPIO_PORTF_PCTL = 0;
			GPIO_PORTF_DEN = 0xFF;
		break;
	}
}
//

void GPIO_Digital_PIN_MODE(GPIO_Port_Select Port, uint8_t pin, GPIO_Mode Mode, GPIO_Polarity Polarity){
	switch(Port){
		case PORTA:
			if(Mode)
				SET_BIT(GPIO_PORTA_DIR, pin);
			else
				CLR_BIT(GPIO_PORTA_DIR, pin);
			if(Polarity == PullUp){
				SET_BIT(GPIO_PORTA_PUR,pin);
					}
			else if(Polarity == PullDown){
				SET_BIT(GPIO_PORTA_PDR,pin);
					}
			else{
				CLR_BIT(GPIO_PORTA_PUR,pin);
				CLR_BIT(GPIO_PORTA_PDR,pin);
					}
			 break;
						
		case PORTB:
			if(Mode)
				SET_BIT(GPIO_PORTB_DIR, pin);
			else
				CLR_BIT(GPIO_PORTB_DIR, pin);
			if(Polarity == PullUp){
				SET_BIT(GPIO_PORTB_PUR,pin);
					}
			else if(Polarity == PullDown){
				SET_BIT(GPIO_PORTB_PDR,pin);
					}
			else{
				CLR_BIT(GPIO_PORTB_PUR,pin);
				CLR_BIT(GPIO_PORTB_PDR,pin);
					}
		  break;
					
		case PORTC:
			 if(Mode)
				SET_BIT(GPIO_PORTC_DIR, pin);
			else
				CLR_BIT(GPIO_PORTC_DIR, pin);
			if(Polarity == PullUp){
				SET_BIT(GPIO_PORTC_PUR,pin);
				}
			else if(Polarity == PullDown){
				SET_BIT(GPIO_PORTC_PDR,pin);
					}
			else{
				CLR_BIT(GPIO_PORTC_PUR,pin);
				CLR_BIT(GPIO_PORTC_PDR,pin);
			}
		  break;
					
		case PORTD:
			if(Mode)
				SET_BIT(GPIO_PORTD_DIR, pin);
			else
				CLR_BIT(GPIO_PORTD_DIR, pin);
			if(Polarity == PullUp){
				SET_BIT(GPIO_PORTD_PUR,pin);
					}
			else if(Polarity == PullDown){
				SET_BIT(GPIO_PORTD_PDR,pin);
							}
			else{
				CLR_BIT(GPIO_PORTD_PUR,pin);
				CLR_BIT(GPIO_PORTD_PDR,pin);
							}
		 break;
			
		case PORTE:
			if(Mode)
				SET_BIT(GPIO_PORTE_DIR, pin);
			else
				CLR_BIT(GPIO_PORTE_DIR, pin);
			if(Polarity == PullUp){
				SET_BIT(GPIO_PORTE_PUR,pin);
							}
			else if(Polarity == PullDown){
				SET_BIT(GPIO_PORTE_PDR,pin);
							}
			else{
				CLR_BIT(GPIO_PORTE_PUR,pin);
				CLR_BIT(GPIO_PORTE_PDR,pin);
							}
		  break;
		
		case PORTF:
			if(Mode)
					SET_BIT(GPIO_PORTF_DIR, pin);
			else
					CLR_BIT(GPIO_PORTF_DIR, pin);
			if(Polarity == PullUp){
					SET_BIT(GPIO_PORTF_PUR,pin);
							}
			else if(Polarity == PullDown){
					SET_BIT(GPIO_PORTF_PDR,pin);
							}
			else{
					CLR_BIT(GPIO_PORTF_PUR,pin);
					CLR_BIT(GPIO_PORTF_PDR,pin);
							}
			break;
		} }
//
		
void GPIO_Write_Pin(GPIO_Port_Select GPIOSEL, uint32_t pin, GPIO_Write data) {
GPIO_Digital_PIN_MODE(GPIOSEL, pin, OUTPUT, NoPull);
switch(GPIOSEL){
	case PORTA:
		if(data)
					SET_BIT(GPIO_PORTA_DATA,pin);
		else	CLR_BIT(GPIO_PORTA_DATA,pin);
			break;
	case PORTB:
		if(data)
					SET_BIT(GPIO_PORTB_DATA,pin);
		else	CLR_BIT(GPIO_PORTB_DATA,pin);
			break;
	case PORTC:
		if(data)
					SET_BIT(GPIO_PORTC_DATA,pin);
		else	CLR_BIT(GPIO_PORTC_DATA,pin);
			break;
	case PORTD:
		if(data)
					SET_BIT(GPIO_PORTD_DATA,pin);
		else	CLR_BIT(GPIO_PORTD_DATA,pin);
			break;
	case PORTE:
			if(data)
					SET_BIT(GPIO_PORTE_DATA,pin);
		else	CLR_BIT(GPIO_PORTE_DATA,pin);
			break;
	case PORTF:
		if(data)
					SET_BIT(GPIO_PORTF_DATA,pin);
		else	CLR_BIT(GPIO_PORTF_DATA,pin);
			break;
		}
}

// 

uint8_t GPIO_Read_pin(GPIO_Port_Select GPIOSEL, uint32_t pin){	
	switch(GPIOSEL){
					case PORTA:
						return GET_BIT(GPIO_PORTA_DATA,pin);
					break;
					case PORTB:
						return GET_BIT(GPIO_PORTB_DATA,pin);
					break;
					case PORTC:
						return GET_BIT(GPIO_PORTC_DATA,pin);
					break;
					case PORTD:
						return GET_BIT(GPIO_PORTD_DATA,pin);
					break;
					case PORTE:
						return GET_BIT(GPIO_PORTE_DATA,pin);
					break;
					case PORTF:
						return GET_BIT(GPIO_PORTF_DATA,pin);
					break;
		}
}
//

void GPIO_Digital_Port_Mode(GPIO_Port_Select Port, GPIO_Mode Mode, GPIO_Polarity Polarity) {
    switch (Port) {
        case PORTA:
            GPIO_PORTA_DIR = (Mode == OUTPUT) ? 0xFF : 0x00;
				if(Polarity == PullUp){
					GPIO_PORTA_PUR = 0xFF;
						}
				else if(Polarity == PullDown){
					GPIO_PORTA_PDR = 0xFF;
						}
				else{
					GPIO_PORTA_PUR = 0x00;
					GPIO_PORTA_PDR = 0x00;
						}
            break;
						
        case PORTB:
            GPIO_PORTB_DIR = (Mode == OUTPUT) ? 0xFF : 0x00;
				if(Polarity == PullUp){
					GPIO_PORTB_PUR = 0xFF;
						}
				else if(Polarity == PullDown){
					GPIO_PORTB_PDR = 0xFF;
						}
				else{
					GPIO_PORTB_PUR = 0x00;
					GPIO_PORTB_PDR = 0x00;
						}
            break;
						
        case PORTC:
            GPIO_PORTC_DIR = (Mode == OUTPUT) ? 0xFF : 0x00;
				if(Polarity == PullUp){
					GPIO_PORTC_PUR = 0xFF;
						}
				else if(Polarity == PullDown){
					GPIO_PORTC_PDR = 0xFF;
						}
				else{
					GPIO_PORTC_PUR = 0x00;
					GPIO_PORTC_PDR = 0x00;
						}
            break;
						
        case PORTD:
            GPIO_PORTD_DIR = (Mode == OUTPUT) ? 0xFF : 0x00;
				if(Polarity == PullUp){
					GPIO_PORTD_PUR = 0xFF;
						}
				else if(Polarity == PullDown){
					GPIO_PORTD_PDR = 0xFF;
						}
				else{
					GPIO_PORTD_PUR = 0x00;
					GPIO_PORTD_PDR = 0x00;
						}
            break;
						
        case PORTE:
            GPIO_PORTE_DIR = (Mode == OUTPUT) ? 0xFF : 0x00;
				if(Polarity == PullUp){
					GPIO_PORTE_PUR = 0xFF;
						}
				else if(Polarity == PullDown){
					GPIO_PORTE_PDR = 0xFF;
						}
				else{
					GPIO_PORTE_PUR = 0x00;
					GPIO_PORTE_PDR = 0x00;
						}
            break;
						
        case PORTF:
            GPIO_PORTF_DIR = (Mode == OUTPUT) ? 0xFF : 0x00;
				if(Polarity == PullUp){
					GPIO_PORTF_PUR = 0xFF;
						}
				else if(Polarity == PullDown){
					GPIO_PORTF_PDR = 0xFF;
						}
				else{
					GPIO_PORTF_PUR = 0x00;
					GPIO_PORTF_PDR = 0x00;
						}
            break;
    }
}
// 

void GPIO_Write_Port(GPIO_Port_Select GPIOSEL, uint8_t data) {
	  GPIO_Digital_Port_Mode(GPIOSEL,OUTPUT,NoPull);
    switch(GPIOSEL){
        case PORTA:
            GPIO_PORTA_DATA = data;
            break;
        case PORTB:
            GPIO_PORTB_DATA = data;
            break;
        case PORTC:
            GPIO_PORTC_DATA = data;
            break;
        case PORTD:
            GPIO_PORTD_DATA = data;
            break;
        case PORTE:
            GPIO_PORTE_DATA = data;
            break;
        case PORTF:
            GPIO_PORTF_DATA = data;
            break;
    }
}
// 

uint8_t GPIO_Read_Port(GPIO_Port_Select GPIOSEL) {
    switch(GPIOSEL){
        case PORTA:
            return (uint8_t)GPIO_PORTA_DATA;
        case PORTB:
            return (uint8_t)GPIO_PORTB_DATA;
        case PORTC:
            return (uint8_t)GPIO_PORTC_DATA;
        case PORTD:
            return (uint8_t)GPIO_PORTD_DATA;
        case PORTE:
            return (uint8_t)GPIO_PORTE_DATA;
        case PORTF:
            return (uint8_t)GPIO_PORTF_DATA;
        default:
            return 0;   //invalid 
    }
}


#include "GPIO.h"
#include "util.h"

void MCAL_GPIO_Init(GPIO_Port_Select GPIOSEL){
    if (GPIOSEL == PORTA) {
        SET_BIT(SYSCTL_RCGCGPIO, PORTA);                        // Enable clock for Port A
        while ((SYSCTL_PRGPIO & (1 << PORTA)) == 0);            // Wait until ready
        GPIO_PORTA_LOCK = GPIO_LOCK_KEY;                 // Unlock Port A
    }
		else if (GPIOSEL == PORTF) {
        SET_BIT(SYSCTL_RCGCGPIO, PORTF);                        // Enable clock for Port A
        while ((SYSCTL_PRGPIO & (1 << PORTF)) == 0);            // Wait until ready
        GPIO_PORTF_LOCK = GPIO_LOCK_KEY;                 // Unlock Port A
    }
}

void MCAL_GPIO_Digital_INIT(GPIO_Port_Select GPIOSEL, uint32_t pin){
    if (GPIOSEL == PORTA) {
        SET_BIT(GPIO_PORTA_CR, pin);                     // Allow changes
        CLR_BIT(GPIO_PORTA_AMSEL, pin);                  // Disable analog
        CLR_BIT(GPIO_PORTA_AFSEL, pin);                  // Disable alternate
        GPIO_PORTA_PCTL &= ~(0xF << (pin * 4));          // Clear PCTL for pin
        SET_BIT(GPIO_PORTA_DEN, pin);                    // Enable digital
    }
		 else if (GPIOSEL == PORTF) {
        SET_BIT(GPIO_PORTF_CR, pin);                     // Allow changes
        CLR_BIT(GPIO_PORTF_AMSEL, pin);                  // Disable analog
        CLR_BIT(GPIO_PORTF_AFSEL, pin);                  // Disable alternate
        GPIO_PORTF_PCTL &= ~(0xF << (pin * 4));          // Clear PCTL for pin
        SET_BIT(GPIO_PORTF_DEN, pin);                    // Enable digital
    }
		
}

void MCAL_GPIO_Digital_PIN_MODE(GPIO_Port_Select Port, uint8_t pin, GPIO_Mode_Select Mode, GPIO_Polarity_Select Polarity){
    if (Port == PORTA) {
        if (Mode == Output) {
            SET_BIT(GPIO_PORTA_DIR, pin);
        } else {
            CLR_BIT(GPIO_PORTA_DIR, pin);
            if (Polarity == Pull_up) {
                SET_BIT(GPIO_PORTA_PUR, pin);
                CLR_BIT(GPIO_PORTA_PDR, pin);
            } else if (Polarity == Pull_down) {
                SET_BIT(GPIO_PORTA_PDR, pin);
                CLR_BIT(GPIO_PORTA_PUR, pin);
            } else {
                CLR_BIT(GPIO_PORTA_PUR, pin);
                CLR_BIT(GPIO_PORTA_PDR, pin);
            }
        }
    }
	else if (Port == PORTF) {
        if (Mode == Output) {
            SET_BIT(GPIO_PORTF_DIR, pin);
        } else {
            CLR_BIT(GPIO_PORTF_DIR, pin);
            if (Polarity == Pull_up) {
                SET_BIT(GPIO_PORTF_PUR, pin);
                CLR_BIT(GPIO_PORTF_PDR, pin);
            } else if (Polarity == Pull_down) {
                SET_BIT(GPIO_PORTF_PDR, pin);
                CLR_BIT(GPIO_PORTF_PUR, pin);
            } else {
                CLR_BIT(GPIO_PORTF_PUR, pin);
                CLR_BIT(GPIO_PORTF_PDR, pin);
            }
        }
    }
}

void MCAL_GPIO_Write_Pin(GPIO_Port_Select GPIOSEL, uint32_t pin, GPIO_Write_Select data){
	if (GPIOSEL == PORTA){
        if (data) {
            SET_BIT(GPIO_PORTA_DATA, pin);
        } else {
            CLR_BIT(GPIO_PORTA_DATA, pin);
        }
	}
	else if (GPIOSEL == PORTF){
        if (data) {
            SET_BIT(GPIO_PORTF_DATA, pin);
        } else {
            CLR_BIT(GPIO_PORTF_DATA, pin);
        }
	}
}

uint8_t MCAL_GPIO_Read_pin(GPIO_Port_Select GPIOSEL, uint32_t pin){
    if (GPIOSEL == PORTA) {
        return GET_BIT(GPIO_PORTA_DATA, pin);
    }
		else if (GPIOSEL == PORTF) {
        return GET_BIT(GPIO_PORTF_DATA, pin);
    }
		return 0;
}

void MCAL_GPIO_I2C_Init(I2C_Select Select){
    if (Select == I2C1) {
        GPIO_PORTA_CR    |=  (0x3 << 6);
        GPIO_PORTA_AMSEL &= ~(0x3 << 6);
        GPIO_PORTA_AFSEL |=  (0x3 << 6);
        GPIO_PORTA_PCTL  |=  (0x33 << (6 * 4));
        GPIO_PORTA_DEN   |=  (0x3 << 6);
        GPIO_PORTA_ODR   |=  (0x2 << 6);
    }
}

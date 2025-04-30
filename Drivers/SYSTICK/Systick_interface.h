#ifndef Systick_Interface
#define Systick_Interface

void SysTick_Init(void);
void Systick_delay(uint32_t delay);
void Systick_Wait_1ms(uint32_t delay);
void Systick_delay_1us(uint32_t delay);

#endif
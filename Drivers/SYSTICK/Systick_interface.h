#ifndef Systick_Interface
#define Systick_Interface

void Systick_Init(void);
void Systick_Wait(uint32_t delay);
void Systick_Wait_1ms(uint32_t delay);
void Systick_Wait_1us(uint32_t delay);

#endif
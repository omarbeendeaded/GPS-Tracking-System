#include <stdint.h>
#include "Systick_interface.h"
#include "Systick_private.h"

// for systick intialization:
void Systick_Init(){                  
NVIC_ST_CTRL_R = 0;                         //disable The SysTick
NVIC_ST_RELOAD_R = 0xFFFFFF;                //maximum reload value 
NVIC_ST_CURRENT_R = 0;                      //cleaning the current regiser " optional" 
NVIC_ST_CTRL_R = 0x05;                      //enable SysTick with the main clock & no interrupt 
} 

//for the making a delay 
void Systick_Wait (uint32_t delay){
NVIC_ST_RELOAD_R = delay-1;                 // number of counts from 0 ----> (2^2n)-1 
NVIC_ST_CURRENT_R = 0;                      //cleaning the current regiser " optional" 
while((NVIC_ST_CTRL_R&0x00010000)==0){}	    // wait for the count flag to be set
}
 

//for delay of 1ms using clock = 16 MHZ:
void Systick_Wait_1ms (uint32_t delay){
uint32_t i;
for(i=0; i<delay; i++) 
    Systick_Wait(16000);                   // 10^-3 * 16*10^6 = 16000
}

//for delay 1us using clock = 16 MHZ:
void Systick_Wait_1us (uint32_t delay){
uint32_t i;
for (i=0; i<delay; i++) 
    Systick_Wait(16);                       //106-6 * 16*10^6 = 16
}
#include "GPIO/GPIO_Interface.h"
#include "GPIO/GPIO_Private.h"
#include "SYSTICK/Systick_interface.h"
#include "SYSTICK/Systick_private.h"
#include "LCD/LCD_interface.h"
#include "LCD/LCD_private.h"
#include "UART/UART_interface.h"
#include "UART/UART_private.h"
#include "GPS/GPS.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define  EARTH_RADIUS 6371000
#define pi 3.14159265359
#define red 1
#define yellow 2
#define green 3


void SystemInit(){};



///////////////////////////////////////////////// Buzzer OP  //////////////////////////////////////////////////////////////

void Buzzervoid_ON (uint8_t PORT, uint8_t PIN)
{
    GPIO_Digital_PIN_MODE (PORT, PIN , OUTPUT, NoPull); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, High);                                                     
}

void Buzzervoid_OFF (uint8_t PORT, uint8_t PIN)
{
    GPIO_Digital_PIN_MODE (PORT, PIN, OUTPUT, NoPull); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, Low);
}

///////////////////////////////////////////////// LED OP  //////////////////////////////////////////////////////////////
void LEDvoid_ON (uint8_t PORT, uint8_t PIN)
{
    GPIO_Digital_PIN_MODE (PORT, PIN , OUTPUT, NoPull); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, High);                                                     
}

void LEDvoid_OFF (uint8_t PORT, uint8_t PIN)
{
    GPIO_Digital_PIN_MODE (PORT, PIN, OUTPUT, NoPull); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, Low);
}
///////////////////////////////////////////////// Distance Formatting  //////////////////////////////////////////////////////////////
   
float ToDegree (float angle){
	int degree = (int)angle/100 ; 
	float minutes = angle -(float)degree*100;
	return (degree + (minutes/60) );
}	


float ToRad(float angle){
	return angle * pi/180;
}
	
	// get angle from degree to rad 


float GetDistance (float currentLong,float currentLat, float destlong,float destlat){
  float currentLongRad = ToRad(currentLong);

	float currentLatRad = ToRad(currentLat);
	float destlongRad = ToRad(destlong);
	float destlatRad = ToRad(destlat);
	
	//get the difference  
	float longDiff = destlongRad - currentLongRad ;
	float latDiff  = destlatRad - currentLatRad ; 
	
	
	// calculate distance 
	float a;
	float c;
	//float x , y ,z  ,w;
	//z= cosf(destlatRad);
	LCD_Clear_Write_String("Hiiii");
	//w = sinf(latDiff)/2;
	
	LCD_Clear_Write_String("Hi");
	//x = cosf(currentLatRad);
	LCD_Clear_Write_String("Hii");
	//y= powf(sinf(longDiff)/2,2);
	
	
	
	//a = w + x*y*z;
	a = powf(sinf(latDiff)/2,2)+ cosf(currentLatRad)*cosf(destlatRad)*powf(sinf(longDiff)/2,2);// haversine formula a = sin2((qb-qa)/2)+ cos(qa)*cos(qb)*sin2((ib-ia)/2)
	//LCD_Clear_Write_String("Hi");
	c = 2*atan2f(sqrtf(a),sqrtf(1-a));
	//c = 2*asinf(sqrtf(a));
	LCD_Clear_Write_String("Hiii");
	return EARTH_RADIUS * c ; 
}

////////////////////////////////////////////////////////// Int to String //////////////////////////////////////////////////
void int2str(uint16_t num, char* str) {
	char buffer[16]; // Buffer to hold the reversed number
	int i = 0;
	int j;

	// Handle the case when the number is 0
	if (num == 0) {
		str[i++] = '0';
		} else {
		// Convert the number to string in reverse order
		while (num > 0) {
			buffer[i++] = (num % 10) + '0'; // Get the last digit and convert to ASCII
			num /= 10;
		}
	}

	// Reverse the string
	for (j = 0; j < i; j++) {
		str[j] = buffer[i - j - 1];
	}
	str[i] = '\0'; // Null-terminate the string
}

///////////////////////////////////////////////// Find The Closest Location ////////////////////////////////////////////////////////////

int compare_distance(double currentlong, double currentlat) {
		char buf[32];
    double longitude[5] = {30.0635867, 30.0637097, 30.0652334, 30.0655795, 30.0643141};
    double latitude[5] = {31.2785090, 31.2806015, 31.2801183, 31.2784068, 31.2777966};
    float min_distance = 20000;
		float distance;
    // char min_location;
		int k, i = 0 ;

    for ( k=0; k<4; k++) {
        distance = GetDistance (currentlong, currentlat, longitude[k], latitude[k]);
        /*if (min_distance > abs(distance)) {
        min_distance = distance;
				i = k;
        //min_location = location[k];
        }*/
			int2str((int)min_distance, buf);
			LCD_Clear_Write_String(buf);
    } return i; 
}

///////////////////////////////////////////////// Led Set On Distance //////////////////////////////////////////////////////////////

void Led_Set (float distance){
    if(distance >= 75) {
            LEDvoid_ON (PORTF, red); 
            LEDvoid_OFF (PORTF, yellow); 
            LEDvoid_OFF(PORTF, green);
            Buzzervoid_OFF(PORTE,2 );
    }
    else if (distance> 20 && distance<75) {
            LEDvoid_ON (PORTF, yellow); 
            LEDvoid_OFF (PORTF, red); 
            LEDvoid_OFF(PORTF, green);
            Buzzervoid_OFF(PORTE,2 );
    }
    else if (distance<=20){
        LEDvoid_ON (PORTF, green); 
            LEDvoid_OFF (PORTF, red); 
            LEDvoid_OFF(PORTF, yellow);
            Buzzervoid_ON (PORTE, 2);
    }
    }




///////////////////////////////////////////////// Main Program ////////////////////////////////////////////////////////////////////
int main(){
    float currentLat;
    float currentLong;
    float distance;
		int disss; 
		int k;
		char strDist[16];
    char location[5] = {0, 1, 2 , 3 , 4};
    float longitude[5] = {30.0635867, 30.0637097, 30.0652334, 30.0655795, 30.0643141};
    float latitude[5] = {31.2785090, 31.2806015, 31.2801183, 31.2784068, 31.2777966};
    float destlong;
    float destlat; 

    Systick_Init();
		LCD_Init();
		LCD_Send_String("Systick Init");
		LCD_Clear_Write_String("LCD Init");
		UART0_init();
    UART1_init();
		LCD_Clear_Write_String("UART Init");
    GPS_read();
		LCD_Clear_Write_String("GPS Init");
    while(1){
				GPS_read();
				LCD_Send_String(" IN ");
        Systick_Wait_1ms (2000);
        currentLat = GPSlat();
        currentLong = GPSlong();
        k = compare_distance (currentLong , currentLat);
        destlong = longitude[k];
        destlat= latitude[k];
        distance = GetDistance (currentLong,currentLat, destlong, destlat);
				int2str(distance, strDist);
				
        //Led_Set (distance);
				LCD_Clear_Write_String("Let's Start3");
				LCD_Send_Char(k+'0');	
				Systick_Wait_1ms (1000);
			  

        switch (k){
					
            case 0 :
            LCD_Clear_Write_String("Credit Building");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break;
            case 1 :
            LCD_Clear_Write_String("Hall C/D");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break;
            case 2 :
            LCD_Clear_Write_String("Library");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break;
            case 3 :
            LCD_Clear_Write_String("Fountain");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break;
            case 4 :
            LCD_Clear_Write_String("Civil Building");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break; }   
}}


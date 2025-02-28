/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           funct_led.h
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        High level led management functions
** Correlated files:    lib_led.c, funct_led.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "LPC17xx.h"
#include "led.h"

#define LED_NUM     8                   /* Number of user LEDs                */
const unsigned long led_mask[] = { 1UL<<0, 1UL<<1, 1UL<<2, 1UL<< 3, 1UL<< 4, 1UL<< 5, 1UL<< 6, 1UL<< 7 };

extern unsigned char led_value;

/*----------------------------------------------------------------------------
  Function that turns on requested LED
 *----------------------------------------------------------------------------*/

void LED_On(unsigned int num) {
 
  LPC_GPIO2->FIOPIN |= led_mask[num];
	led_value = LPC_GPIO2->FIOPIN;
}

/*----------------------------------------------------------------------------
  Function that turns off requested LED
 *----------------------------------------------------------------------------*/
/* Spegne l'i-esimo LED (valori da 0 a 7)*/ 
void LED_Off(unsigned int num) {

  LPC_GPIO2->FIOPIN &= ~led_mask[num];
	led_value = LPC_GPIO2->FIOPIN;
}

/*----------------------------------------------------------------------------
  Function that outputs value to LEDs
 *----------------------------------------------------------------------------*/

/* Riceve un intero e accende i LED che corrispondono al codice binario 
se il numero è maggiore di 255 considera il numero come num%255*/

void LED_Out(unsigned int value) {
  int i;
	
  for (i = 0; i < LED_NUM; i++) {
    if (value & (1<<i)) {
      LED_On (i);
    } else {
      LED_Off(i);
    }
  }
	led_value = LPC_GPIO2->FIOPIN;
	
}


void LED_Out_4_alti(unsigned int value) {
  int i;
	int offset = LED_NUM/2; 
  for (i =0 ; i < LED_NUM/2; i++) {
    if (value & (1<<i)) {
      LED_On (i+offset);
    } else {
      LED_Off(i+offset);
    }
  }
	led_value = LPC_GPIO2->FIOPIN;
	
}


void LED_Out_4_bassi(unsigned int value) {
  int i;
	
  for (i =0 ; i < LED_NUM/2; i++) {
    if (value & (1<<i)) {
      LED_On (i);
    } else {
      LED_Off(i);
    }
  }
	led_value = LPC_GPIO2->FIOPIN;
	
}




void LED_Out_Reverse(unsigned int value) {
  int i;
	
  for (i = 0; i<LED_NUM; i++) {
    if (value & (1<<i)) {
      LED_On (LED_NUM-1-i);
    } else {
      LED_Off(LED_NUM-1-i);
    }
  }
	led_value = LPC_GPIO2->FIOPIN;
	
}

void LED_Out_Not(unsigned int value) {
  int i;
	
  for (i = 0; i < LED_NUM; i++) {
    if (value & (1<<i)) {
      LED_Off (i);
    } else {
      LED_On(i);
    }
  }
	led_value = LPC_GPIO2->FIOPIN;
	
}

void LED_Out_Pari(){
		
	int i;
	for (i = 0; i < LED_NUM; i++) {
			if (i%2==0) {
				LED_On(i);
			} else {
				LED_Off(i);
			}
		}
		led_value = LPC_GPIO2->FIOPIN;


}


void LED_Out_Dispari(){
		
	int i;
	for (i = 0; i < LED_NUM; i++) {
			if (i%2==0) {
				LED_Off(i);
			} else {
				LED_On(i);
			}
		}
		led_value = LPC_GPIO2->FIOPIN;


}



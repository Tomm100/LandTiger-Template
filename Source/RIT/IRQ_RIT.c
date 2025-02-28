/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "../timer/timer.h"


/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
/* OCCORE DICHIARARLE GLOBALI IN QUANTO CONDIVISE CON I BUTTON
*/
volatile int INT0=0;
volatile int KEY1=0; 
volatile int KEY2=0;


void RIT_IRQHandler (void)
{					
	
	
	// VARIABILI DEL JOYSTICK
	
	static int up=0;
	static int down=0;
	static int left=0;
	static int right=0;
	static int sel=0;
	static int up_left=0;
	static int up_right=0;
	static int down_left=0;
	static int down_right=0;
	
	// ALTRE VARIABILI 
	//static int blink0=0;
	//static int blink1=0;
	//static int blink2=0;
	
	
	

	
	/* INT0 management 
	*/
	if(INT0>=1){ 
		if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){	/* INT0 pressed */
			switch(INT0){				
				case 2:				/* pay attention here: please see slides 19_ to understand value 2 */
				/*
				
				IMPLEMENTA QUI COSA FARE 
				
				if(blink0%2 == 0)
					//rendere lampeggiante alla prima pressione di INT0
					enable_timer(0)
				else 	
					//rendere fisso alla seconda pressione di INT0
					disable_timer(0)
				blink0++;
				*/
				
				default:
					break;
			}
			INT0++;
		}
		else {	/* button released */
			INT0=0;			
			NVIC_EnableIRQ(EINT0_IRQn);							 /* enable Button interrupts			*/
			LPC_PINCON->PINSEL4    |= (1 << 20);     /* External interrupt 0 pin selection */
		}
	}

	/* KEY1 management
	
	*/
	
		if(KEY1>=1){ 
		if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){	/* KEY1 pressed */
			switch(KEY1){				
				case 2:				/* pay attention here: please see slides 19_ to understand value 2 */
				/*
				
				IMPLEMENTA QUI COSA FARE 
				
				if(blink1%2 == 0)
					//rendere lampeggiante alla prima pressione di KEY1
					enable_timer(0)
				else 	
					//rendere fisso alla seconda pressione di KEY1
					disable_timer(0)
				blink1++;
				*/
				
				default:
					break;
			}
			KEY1++;
		}
		else {	/* button released */
			KEY1=0;			
			NVIC_EnableIRQ(EINT1_IRQn);							 /* enable Button interrupts			*/
			LPC_PINCON->PINSEL4    |= (1 << 22);     /* External interrupt 0 pin selection */
		}
	}
		
	/* KEY2 management
	*/
		if(KEY2>=1){ 
		if((LPC_GPIO2->FIOPIN & (1<<12)) == 0){	/* KEY2 pressed */
			switch(KEY2){				
				case 2:				/* pay attention here: please see slides 19_ to understand value 2 */
				/*
				
				IMPLEMENTA QUI COSA FARE 
				
				if(blink2%2 == 0)
					//rendere lampeggiante alla prima pressione di KEY2
					enable_timer(0)
				else 	
					//rendere fisso alla seconda pressione di KEY2
					disable_timer(0)
				blink2++;
				*/
				
				default:
					break;
			}
			KEY2++;
		}
		else {	/* button released */
			KEY2=0;			
			NVIC_EnableIRQ(EINT2_IRQn);							 /* enable Button interrupts			*/
			LPC_PINCON->PINSEL4    |= (1 << 24);     /* External interrupt 0 pin selection */
		}
	}
	
	/* ******************************************************************************************************************************************************************************************* */
	/* ******************************************************************************************************************************************************************************************* */
	/* ******************************************************************************************************************************************************************************************* */
	/* ******************************************************************************************************************************************************************************************* */
	/* ******************************************************************************************************************************************************************************************* */
	/* ******************************************************************************************************************************************************************************************* */
	/* ******************************************************************************************************************************************************************************************* */
	/* ******************************************************************************************************************************************************************************************* */
	/* ******************************************************************************************************************************************************************************************* */
	
	
	
	
	/* UP management
	*/
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	
		/* Joytick UP pressed */
		up++;
		switch(up){
			case 1:
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			case 60:	//3sec = 3000ms/50ms = 60 (Valore modificabile)
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			default:
				break;
		}
	}
	else{
			up=0;
	}
	
	
		
	/* DOWN management
	*/
	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){	
		/* Joytick DOWN pressed */
		down++;
		switch(down){
			case 1:
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			case 60:	//3sec = 3000ms/50ms = 60 (Valore modificabile)
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			default:
				break;
		}
	}
	else{
			down=0;
	}
	
	
	
	
	/* RIGHT management
	*/
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		/* Joytick RIGHT pressed */
		right++;
		switch(right){
			case 1:
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			case 60:	//3sec = 3000ms/50ms = 60 (Valore modificabile)
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			default:
				break;
		}
	}
	else{
			right=0;
	}
	
	
	
	
	
	/* LEFT management
	*/
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytick LEFT pressed */
		left++;
		switch(left){
			case 1:
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			case 60:	//3sec = 3000ms/50ms = 60 (Valore modificabile)
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			default:
				break;
		}
	}
	else{
			left=0;
	}
	
	
	/* SEL management
	*/
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){	
		/* Joytick SEL pressed */
		sel++;
		switch(sel){
			case 1:
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			case 60:	//3sec = 3000ms/50ms = 60 (Valore modificabile)
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			default:
				break;
		}
	}
	else{
			sel=0;
	}
	
	
	/* UP-LEFT management
	*/
		if(((LPC_GPIO1->FIOPIN & (1<<29)) == 0) && (LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytick SEL pressed */
		up_left++;
		switch(up_left){
			case 1:
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			case 60:	//3sec = 3000ms/50ms = 60 (Valore modificabile)
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			default:
				break;
		}
	}
	else{
			up_left=0;
	}
	

	
	/* UP-RIGHT management
	*/
		if(((LPC_GPIO1->FIOPIN & (1<<29)) == 0) && (LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		/* Joytick SEL pressed */
		up_right++;
		switch(up_right){
			case 1:
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			case 60:	//3sec = 3000ms/50ms = 60 (Valore modificabile)
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			default:
				break;
		}
	}
	else{
			up_right=0;
	}
	
	
	
	/* DOWN-LEFT management
	*/
		if(((LPC_GPIO1->FIOPIN & (1<<26)) == 0) && (LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytick SEL pressed */
		down_left++;
		switch(down_left){
			case 1:
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			case 60:	//3sec = 3000ms/50ms = 60 (Valore modificabile)
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			default:
				break;
		}
	}
	else{
		down_left=0;
	}
	
	
	/* DOWN-RIGHT management
	*/
		if(((LPC_GPIO1->FIOPIN & (1<<26)) == 0) && (LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		/* Joytick SEL pressed */
		down_right++;
		switch(down_right){
			case 1:
				 
				/*
				INSERISCI QUI LA TUA FUNZIONE
			      
				*/
				break;
			case 60:	//3sec = 3000ms/50ms = 60 (Valore modificabile)
				/*
				INSERISCI QUI LA TUA FUNZIONE
				*/
				break;
			default:
				break;
		}
	}
	else{
		down_right=0;
	}
	
	
	
	
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/

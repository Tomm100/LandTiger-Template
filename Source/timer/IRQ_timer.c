/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "timer.h"
#include "../led/led.h"

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
extern unsigned char led_value;					/* defined in funct_led								*/
extern int position;										/* definita in IRQ_RIT --> Relativa alla posizione dei LED*/

void TIMER0_IRQHandler (void)
{
	
	
	
  if(LPC_TIM0->IR & (1<<0)) { 
	//MR0 Interrupt
    
	LPC_TIM0->IR = (1<<0); 		//clear interrupt flag
		
 } if(LPC_TIM0->IR & (1<<1)) { 
	 //MR1 Interrupt
	 
    LPC_TIM0->IR = (1<<1);   //clear interrupt flag
	 
 } if(LPC_TIM0->IR & (1<<2)) { 
	 //MR2 Interrupt
	 
    LPC_TIM0->IR = (1<<2);   //clear interrupt flag
	 
 } if(LPC_TIM0->IR & (1<<3)) { 
	 
	 //MR3 Interrupt
	 
    LPC_TIM0->IR = (1<<3);   //clear interrupt flag
 }

	
  			/* clear interrupt flag */
  return;
}



/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
	
 if(LPC_TIM1->IR & (1<<0)) { 
	//MR0 Interrupt
    
	LPC_TIM1->IR = (1<<0); 		//clear interrupt flag
		
 } if(LPC_TIM1->IR & (1<<1)) { 
	 //MR1 Interrupt
	 
    LPC_TIM1->IR = (1<<1);   //clear interrupt flag
	 
 } if(LPC_TIM1->IR & (1<<2)) { 
	 //MR2 Interrupt
	 
    LPC_TIM1->IR = (1<<2);   //clear interrupt flag
	 
 } if(LPC_TIM1->IR & (1<<3)) { 
	 
	 //MR3 Interrupt
	 
    LPC_TIM1->IR = (1<<3);   //clear interrupt flag
 }

  return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Timer/Counter 2 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER2_IRQHandler (void)
{
	
	
 if(LPC_TIM2->IR & (1<<0)) { 
	//MR0 Interrupt
    
	LPC_TIM2->IR = (1<<0); 		//clear interrupt flag
		
 } if(LPC_TIM2->IR & (1<<1)) { 
	 //MR1 Interrupt
	 
    LPC_TIM2->IR = (1<<1);   //clear interrupt flag
	 
 } if(LPC_TIM2->IR & (1<<2)) { 
	 //MR2 Interrupt
	 
    LPC_TIM2->IR = (1<<2);   //clear interrupt flag
	 
 } if(LPC_TIM2->IR & (1<<3)) { 
	 
	 //MR3 Interrupt
	 
    LPC_TIM2->IR = (1<<3);   //clear interrupt flag
 }

  return;
}

/******************************************************************************
** Function name:		Timer3_IRQHandler
**
** Descriptions:		Timer/Counter 3 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER3_IRQHandler (void)
{
	
	
  if(LPC_TIM3->IR & (1<<0)) { 
	//MR0 Interrupt
    
	LPC_TIM3->IR = (1<<0); 		//clear interrupt flag
		
 } if(LPC_TIM3->IR & (1<<1)) { 
	 //MR1 Interrupt
	 
    LPC_TIM3->IR = (1<<1);   //clear interrupt flag
	 
 } if(LPC_TIM3->IR & (1<<2)) { 
	 //MR2 Interrupt
	 
    LPC_TIM3->IR = (1<<2);   //clear interrupt flag
	 
 } if(LPC_TIM3->IR & (1<<3)) { 
	 
	 //MR3 Interrupt
	 
    LPC_TIM3->IR = (1<<3);   //clear interrupt flag
 }

  return;
}
/******************************************************************************
**                            End Of File
******************************************************************************/

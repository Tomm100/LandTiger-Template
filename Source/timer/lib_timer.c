/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           lib_timer.h
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        atomic functions to be used by higher sw levels
** Correlated files:    lib_timer.c, funct_timer.c, IRQ_timer.c
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "timer.h"

/******************************************************************************
** Function name:		enable_timer
**
** Descriptions:		Enable timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
**
******************************************************************************/
void enable_timer( uint8_t timer_num )
{
  if ( timer_num == 0 ) 
		{
	  LPC_TIM0->TCR = 1;
		}
  else if (timer_num ==1 ) 
		{
	LPC_TIM1->TCR = 1;
	  }
	else if (timer_num ==2) 
    {
		LPC_TIM2->TCR =1;
		}
	else if (timer_num ==3) 
    {
		LPC_TIM3->TCR=1;
		}
  return;
}

/******************************************************************************
** Function name:		disable_timer
**
** Descriptions:		Disable timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
**
******************************************************************************/
void disable_timer( uint8_t timer_num )
{
  if ( timer_num == 0 )
  {
	LPC_TIM0->TCR = 0;
  }
  if (timer_num ==1)
  {
	LPC_TIM1->TCR = 0;
  }
	if ( timer_num ==2)
	{
	LPC_TIM2->TCR = 0;
	}
	if ( timer_num ==3)
	{
	LPC_TIM3->TCR = 0;
	}
  return;
}

/******************************************************************************
** Function name:		reset_timer
**
** Descriptions:		Reset timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
**
******************************************************************************/
void reset_timer( uint8_t timer_num )
{
  uint32_t regVal;

  if ( timer_num == 0 )
  {
	regVal = LPC_TIM0->TCR;
	regVal |= 0x02;
	LPC_TIM0->TCR = regVal;
  }
  if( timer_num ==1)
  {
	regVal = LPC_TIM1->TCR;
	regVal |= 0x02;
	LPC_TIM1->TCR = regVal;
  }
	if( timer_num ==2)
  {
	regVal = LPC_TIM2->TCR;
	regVal |= 0x02;
	LPC_TIM2->TCR = regVal;
  }
	if( timer_num ==3)
  {
	regVal = LPC_TIM3->TCR;
	regVal |= 0x02;
	LPC_TIM3->TCR = regVal;
  }
  return;
}

uint32_t init_timer ( uint8_t timer_num, uint32_t TimerInterval )
{
  if ( timer_num == 0 )
  {
	LPC_TIM0->MR0 = TimerInterval;

// <<< Use Configuration Wizard in Context Menu >>>
// <h> timer0 MCR
//   <e.0> MR0I
//	 <i> 1 Interrupt on MR0: an interrupt is generated when MR0 matches the value in the TC. 0
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.1> MR0R
//	 <i> 1 Reset on MR0: the TC will be reset if MR0 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.2> MR0S
//	 <i> 1 Stop on MR0: the TC and PC will be stopped and TCR[0] will be set to 0 if MR0 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.3> MR1I
//	 <i> 1 Interrupt on MR1: an interrupt is generated when MR0 matches the value in the TC. 0
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.4> MR1R
//	 <i> 1 Reset on MR1: the TC will be reset if MR0 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.5> MR1S
//	 <i> 1 Stop on MR1: the TC and PC will be stopped and TCR[1] will be set to 0 if MR1 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.6> MR2I
//	 <i> 1 Interrupt on MR2: an interrupt is generated when MR2 matches the value in the TC.
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.7> MR2R
//	 <i> 1 Reset on MR2: the TC will be reset if MR2 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.8> MR2S
//	 <i> 1 Stop on MR2: the TC and PC will be stopped and TCR[2] will be set to 0 if MR2 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.9> MR3I
//	 <i> 1 Interrupt on MR3: an interrupt is generated when MR3 matches the value in the TC.
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.10> MR3R
//	 <i> 1 Reset on MR3: the TC will be reset if MR3 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.11> MR3S
//	 <i> 1 Stop on MR3: the TC and PC will be stopped and TCR[3] will be set to 0 if MR3 matches the TC
//	 <i> 0 Feature disabled.
//   </e>


/* -------- MATCH REGISTERS ----------*/

	LPC_TIM0->MCR = 3;
	
	// MR01 --> 1 -> Scatena Interrupt 
	// MR0R --> 1 -> Si resetta allo scattare del Timer
	// MR0S --> 1 -> Il timer si arresta allo scadere del Delay da noi impostato
	
	
// </h>


	NVIC_EnableIRQ(TIMER0_IRQn);
	/*NVIC_SetPriority(TIMER0_IRQn, 4);*/		/* less priority than buttons */
	NVIC_SetPriority(TIMER0_IRQn, 0);		/* more priority than buttons */
	return (1);
  }
  else if ( timer_num == 1 )
  {
		LPC_TIM1->MR0 = TimerInterval;
// <h> timer1 MCR
//   <e.0> MR0I
//	 <i> 1 Interrupt on MR0: an interrupt is generated when MR0 matches the value in the TC. 0
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.1> MR0R
//	 <i> 1 Reset on MR0: the TC will be reset if MR0 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.2> MR0S
//	 <i> 1 Stop on MR0: the TC and PC will be stopped and TCR[0] will be set to 0 if MR0 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.3> MR1I
//	 <i> 1 Interrupt on MR1: an interrupt is generated when MR0 matches the value in the TC. 0
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.4> MR1R
//	 <i> 1 Reset on MR1: the TC will be reset if MR0 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.5> MR1S
//	 <i> 1 Stop on MR1: the TC and PC will be stopped and TCR[1] will be set to 0 if MR1 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.6> MR2I
//	 <i> 1 Interrupt on MR2: an interrupt is generated when MR2 matches the value in the TC.
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.7> MR2R
//	 <i> 1 Reset on MR2: the TC will be reset if MR2 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.8> MR2S
//	 <i> 1 Stop on MR2: the TC and PC will be stopped and TCR[2] will be set to 0 if MR2 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.9> MR3I
//	 <i> 1 Interrupt on MR3: an interrupt is generated when MR3 matches the value in the TC.
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.10> MR3R
//	 <i> 1 Reset on MR3: the TC will be reset if MR3 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.11> MR3S
//	 <i> 1 Stop on MR3: the TC and PC will be stopped and TCR[3] will be set to 0 if MR3 matches the TC
//	 <i> 0 Feature disabled.
//   </e>

/* -------- MATCH REGISTERS ----------*/

	LPC_TIM1->MCR = 3;
	
	
	// MR01 --> 1 -> Scatena Interrupt 
	// MR0R --> 1 -> Si resetta allo scattare del Timer
	// MR0S --> 1 -> Il timer si arresta allo scadere del Delay da noi impostato
	
// </h>
			

	NVIC_EnableIRQ(TIMER1_IRQn);
	NVIC_SetPriority(TIMER1_IRQn, 0);	/* less priority than buttons and timer0*/
	return (1);
  }
	if (timer_num ==2){
		LPC_TIM2->MR0 = TimerInterval;
		
// <h> timer2 MCR
//   <e.0> MR0I
//	 <i> 1 Interrupt on MR0: an interrupt is generated when MR0 matches the value in the TC. 0
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.1> MR0R
//	 <i> 1 Reset on MR0: the TC will be reset if MR0 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.2> MR0S
//	 <i> 1 Stop on MR0: the TC and PC will be stopped and TCR[0] will be set to 0 if MR0 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.3> MR1I
//	 <i> 1 Interrupt on MR1: an interrupt is generated when MR0 matches the value in the TC. 0
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.4> MR1R
//	 <i> 1 Reset on MR1: the TC will be reset if MR0 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.5> MR1S
//	 <i> 1 Stop on MR1: the TC and PC will be stopped and TCR[1] will be set to 0 if MR1 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.6> MR2I
//	 <i> 1 Interrupt on MR2: an interrupt is generated when MR2 matches the value in the TC.
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.7> MR2R
//	 <i> 1 Reset on MR2: the TC will be reset if MR2 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.8> MR2S
//	 <i> 1 Stop on MR2: the TC and PC will be stopped and TCR[2] will be set to 0 if MR2 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.9> MR3I
//	 <i> 1 Interrupt on MR3: an interrupt is generated when MR3 matches the value in the TC.
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.10> MR3R
//	 <i> 1 Reset on MR3: the TC will be reset if MR3 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.11> MR3S
//	 <i> 1 Stop on MR3: the TC and PC will be stopped and TCR[3] will be set to 0 if MR3 matches the TC
//	 <i> 0 Feature disabled.
//   </e>

/* -------- MATCH REGISTERS ----------*/

	LPC_TIM2->MCR = 3;
	
	// MR01 --> 1 -> Scatena Interrupt 
	// MR0R --> 1 -> Si resetta allo scattare del Timer
	// MR0S --> 1 -> Il timer si arresta allo scadere del Delay da noi impostato
	
// </h>

	NVIC_EnableIRQ(TIMER2_IRQn);
	
	NVIC_SetPriority(TIMER2_IRQn, 0);		/* more priority than buttons */
	return (1);
	}
	if (timer_num ==3){
		LPC_TIM3->MR0 = TimerInterval;
		
// <h> timer3 MCR
//   <e.0> MR0I
//	 <i> 1 Interrupt on MR0: an interrupt is generated when MR0 matches the value in the TC. 0
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.1> MR0R
//	 <i> 1 Reset on MR0: the TC will be reset if MR0 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.2> MR0S
//	 <i> 1 Stop on MR0: the TC and PC will be stopped and TCR[0] will be set to 0 if MR0 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.3> MR1I
//	 <i> 1 Interrupt on MR1: an interrupt is generated when MR0 matches the value in the TC. 0
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.4> MR1R
//	 <i> 1 Reset on MR1: the TC will be reset if MR0 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.5> MR1S
//	 <i> 1 Stop on MR1: the TC and PC will be stopped and TCR[1] will be set to 0 if MR1 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.6> MR2I
//	 <i> 1 Interrupt on MR2: an interrupt is generated when MR2 matches the value in the TC.
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.7> MR2R
//	 <i> 1 Reset on MR2: the TC will be reset if MR2 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.8> MR2S
//	 <i> 1 Stop on MR2: the TC and PC will be stopped and TCR[2] will be set to 0 if MR2 matches the TC
//	 <i> 0 Feature disabled.
//   </e>
//   <e.9> MR3I
//	 <i> 1 Interrupt on MR3: an interrupt is generated when MR3 matches the value in the TC.
//	 <i> 0 This interrupt is disabled
//   </e>
//   <e.10> MR3R
//	 <i> 1 Reset on MR3: the TC will be reset if MR3 matches it.
//	 <i> 0 Feature disabled.
//   </e>
//   <e.11> MR3S
//	 <i> 1 Stop on MR3: the TC and PC will be stopped and TCR[3] will be set to 0 if MR3 matches the TC
//	 <i> 0 Feature disabled.
//   </e>

/* -------- MATCH REGISTERS ----------*/

	LPC_TIM3->MCR = 1;
	
	// MR01 --> 1 -> Scatena Interrupt 
	// MR0R --> 1 -> Si resetta allo scattare del Timer
	// MR0S --> 1 -> Il timer si arresta allo scadere del Delay da noi impostato
	
// </h>
// <<< end of configuration section >>>

	NVIC_EnableIRQ(TIMER3_IRQn);
	NVIC_SetPriority(TIMER3_IRQn, 0);		/* more priority than buttons */
	return (1);
	}
  return (0);
}




//mi restituisce il valore corrente del timer timer_num
uint32_t  getTimerCounter( uint8_t timer_num){

			if(timer_num==0){
				return LPC_TIM0->TC;
			
			}
			if(timer_num==1){
				return LPC_TIM1->TC;
			
			}
			if(timer_num==2){
				return LPC_TIM2->TC;
			
			}
			if(timer_num==3){
				return LPC_TIM3->TC;
			
			}
			return 0;

}

uint32_t init_ComplexTimer (uint8_t timer_num, uint32_t varMCR ,uint32_t varMR0, uint32_t varMR1, uint32_t varMR2, uint32_t varMR3 ){ 
	
	int i;
  switch(timer_num){  
  case 0:    
					if(varMR0 != 0) LPC_TIM0->MR0=varMR0;
					if(varMR1 != 0) LPC_TIM0->MR1=varMR1;    
					if(varMR2 != 0) LPC_TIM0->MR2=varMR2;
					if(varMR3 != 0) LPC_TIM0->MR3=varMR3;  
					LPC_TIM0->MCR=varMCR; 
					NVIC_EnableIRQ(TIMER0_IRQn);    
					NVIC_SetPriority(TIMER0_IRQn,0); //Priorita 
      break;   
  case 1:    
					if(varMR0 != 0) LPC_TIM1->MR0=varMR0;
					if(varMR1 != 0) LPC_TIM1->MR1=varMR1;    
					if(varMR2 != 0) LPC_TIM1->MR2=varMR2;
					if(varMR3 != 0) LPC_TIM1->MR3=varMR3;  
					LPC_TIM1->MCR=varMCR;  
					NVIC_EnableIRQ(TIMER1_IRQn);    
					NVIC_SetPriority(TIMER1_IRQn,0); //Priorita 
      break;  
  case 2:    
		  if(varMR0 != 0) LPC_TIM2->MR0=varMR0;
      if(varMR1 != 0) LPC_TIM2->MR1=varMR1;    
	    if(varMR2 != 0) LPC_TIM2->MR2=varMR2;
      if(varMR3 != 0) LPC_TIM2->MR3=varMR3;  
      LPC_TIM2->MCR=varMCR;  
      NVIC_EnableIRQ(TIMER2_IRQn);    
	    NVIC_SetPriority(TIMER2_IRQn,0); //Priorita 
      break;    
  case 3:    
					 if(varMR0 != 0)  LPC_TIM3->MR0=varMR0;
					 if(varMR1 != 0) LPC_TIM3->MR1=varMR1;    
					 if(varMR2 != 0) LPC_TIM3->MR2=varMR2;
					 if(varMR3 != 0) LPC_TIM3->MR3=varMR3;   
					 LPC_TIM3->MCR=varMCR;  
					 NVIC_EnableIRQ(TIMER3_IRQn);   
	         NVIC_SetPriority(TIMER3_IRQn,0); //Priorita 
      break;  
  default:     
		return (0);
    break;  
 } return (1);
}




/******************************************************************************
**                            End Of File
******************************************************************************/

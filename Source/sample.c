/*----------------------------------------------------------------------------
 * Name:    sample.c
 * Purpose: 
 *		to control led11 and led 10 through EINT buttons (similarly to project 03_)
 *		to control leds9 to led4 by the timer handler (1 second - circular cycling)
 * Note(s): this version supports the LANDTIGER Emulator
 * Author: 	Paolo BERNARDI - PoliTO - last modified 15/12/2020
 *----------------------------------------------------------------------------
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2017 Politecnico di Torino. All rights reserved.
 *----------------------------------------------------------------------------*/

                  
#include <stdio.h>
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"

/* Led external variables from funct_led */
extern unsigned char led_value;					/* defined in lib_led								*/
#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif
/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
 

int main (void) {
  	
	
	
	
	SystemInit();  												/* System Initialization (i.e., PLL)  */
  LED_init();                           /* LED Initialization                 */
  BUTTON_init();												/* BUTTON Initialization. In BUTTON_init() possibilità di modificare le priorità. Implementa le ISR nel IRQ_button.c  */
	joystick_init();											/*	JOYSTICK Initialization */
	/* ----------- L'INIZIALIZZAZIONE DEI TIMER NON VA FATTA PER FORZA QUI (Copiare e incollare ove più oppurtuno , con i valori desiderati)----------------------*/
	
	
	/* ----------- TUTTI I TIMER LAVORANO A UNA FREQUENZA DI 25MHz, PER SETTARE CORRETTAMENTE UN TIMER OCCORE USARE LA FORMULA : count =  t [s]  *  F [Hz] 
	*/
		
	/* Possiamo anche eventualmente andare a modificare la frequenza a cui lavorano i timer (100KHZ,50KHz, 25KHZ)		
			Recarsi in system_LPC17xx.c --> Aprire configuration Wizard --> Peripheral Clock Selection Register 1 (PCLKSEL0) --> TIMER0, TIMER1 	  	OPPURE 																																--> Peripheral Clock Selection Register 1 (PCLKSEL1) --> TIMER2, TIMER3
	*/
	
	
	
	
	// init_timer(0,0xBEBC20);  /*	INIZIALIZZO TIMER0 AL VALORE INDICATO. Entra dentro per modificare eventuali priorità o settings dei match register*/				
	// init_timer(1,0x017D7840);	/*	INIZIALIZZO TIMER1 AL VALORE INDICATO. Entra dentro per modificare eventuali priorità o settings dei match register*/
	// init_timer(2,0x017D7840);	/*	INIZIALIZZO TIMER2 AL VALORE INDICATO. Entra dentro per modificare eventuali priorità o settings dei match register*/ 																		
	// init_timer(3,0x017D7840);	/*	INIZIALIZZO TIMER3 AL VALORE INDICATO. Entra dentro per modificare eventuali priorità o settings dei match register*/





	/*POSSIBILITA' DENTRO INIT_TIMER DI MODIFICARE LE PRIORITA' DEI VARI TIMER E DI MODIFICARE I SETTINGS DEL MATCH REGISTER TRAMITE CONFIGURATION WIZARD
	*/
	
	
	// enable_timer(0);  					/*	FACCIO PARTIRE IL TIMER0 */
	// enable_timer(1);						/*	FACCIO PARTIRE IL TIMER1 */
	// enable_timer(2);						/*	FACCIO PARTIRE IL TIMER2 */
	// enable_timer(3);						/*	FACCIO PARTIRE IL TIMER3 */
	
	
	
	
	/* 	ATTENZIONE !!! I TIMER2 E TIMER3 POTREBBERO ESSERE DISATTIVATI (Magari dall'emulatore sembra che funzioni tutto, ma sulla scheda non funziona)
	Per attivarli andare in system_LPC17xx.c 
	Andare in :
	Configuration Wizard >> Clock Configuration >> Power Control for Peripherals Register (PCONP) >> PCTIM2 enable e PCTIM3 enable

	*/
	
	
	
	/* *********************************************************************************** */
	init_RIT(0x004C4B40);  // Inizializzo il RIT con dealy di 50ms . RICORDA IL RIT LAVORA A UNA FREQUENZA DI 100MHz
	enable_RIT(); // Abilito il RIT
	
	
	
	
	LPC_SC->PCON |= 0x1;									/* porto il sistema in power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);							
		
  while (1) {                           /* Loop forever                       */	
		__ASM("wfi");
  }

}

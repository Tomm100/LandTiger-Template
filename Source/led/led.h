																			 /*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           timer.h
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_led, funct_led .c files
** Correlated files:    lib_led.c, funct_led.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

/* lib_led */
void LED_init(void);
void LED_deinit(void);

/* funct_led */
void LED_On (unsigned int num);           // accende il LED num
void LED_Off (unsigned int num);          // spegne il LED num
void LED_Out(unsigned int value);         // calcola value %mod 255 -> accende i bit a 1 corrispondenti
void LED_Out_4_alti(unsigned int value);  // stessa cosa di LED_Out ma con i 4 LED alti
void LED_Out_4_bassi(unsigned int value); // Stessa cosa di LED_Out ma con i 4 LED bassi

void LED_Out_Reverse(unsigned int value); // stessa cosa di LED_Out ma in reverse 

void LED_Out_Not(unsigned int value);     // accende i bit a 0 e spegne quelli a 1

void LED_Out_Pari();    // accende i led pari (da destra 0 acceso, 1 spento, 2 acceso ... ) 
void LED_Out_Dispari(); // accende i led dispari (da destra 0 spento, 1 acceso, 2 spento ... )
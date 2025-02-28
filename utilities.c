#include "LPC17xx.h"

//estrae i bit da start a end e ritorna il risultato su 8 bit
// il bit più a destra è start, quello più a sinistra
char estrai_bits(int numero, int start, int end) {
    // Verifica che i valori start ed end siano validi
    if (start < 0 || end < 0 || start > 31 || end > 31 || start > end) {
        return -1;  // valore di errore
    }

    // Calcola la maschera per i bit tra start e end
    int lunghezza = end - start + 1;
    int maschera = (1 << lunghezza) - 1;  // crea una maschera con i bit da start a end a 1

    // Estrai i bit tra start ed end
    int estrazione = (numero >> start) & maschera;

    // Restituisci il risultato come un valore di 8 bit (char)
    return (char) estrazione; 
}


 
/****************************************************************************** 
** Function name:  extract_bits 
  Estrazione di un numero specifico di bit da una posizione 
 
    ***Esempio utilizzo*** 
   uint32_t num = 0xABCD1234; // 0b10101011110011010001001000110100 
    uint32_t result = extract_bits(num, 8, 8); // Estrae 8 bit da posizione 8 
    printf("Extracted bits: 0x%X\n", result); // Output: 0x12 
 
******************************************************************************/ 
uint32_t extract_bits(uint32_t value, int pos, int n) { 
    return (value >> pos) & ((1U << n) - 1); 
} 
/****************************************************************************** 
** Function name:  set_bit 
** caratteristiche: impostare un bit specifico a 1 
 
  uint32_t num = 0b00001111; 
    num = set_bit(num, 7); // Imposta il bit 7 a 1 
    printf("Set bit: 0x%X\n", num); // Output: 0x8F (0b10001111) 
 
******************************************************************************/ 
uint32_t set_bit(uint32_t value, int bit) { 
    return value | (1U << bit); 
} 
/****************************************************************************** 
** Function name:  clear_bit 
** caratteristiche: resettare un bit specifico a 0 
 
  uint32_t num = 0b11111111; 
    num = clear_bit(num, 3); // Pone a 0 il bit 3 
    printf("Cleared bit: 0x%X\n", num); // Output: 0xF7 (0b11110111) 
******************************************************************************/ 
uint32_t clear_bit(uint32_t value, int bit) { 
    return value & ~(1U << bit); 
} 
/****************************************************************************** 
** Function name:  toggle_bit 
** caratteristiche: Invertire un bit specifico 
 
  uint32_t num = 0b10101010; 
    num = toggle_bit(num, 2); // Inverte il bit 2 
    printf("Toggled bit: 0x%X\n", num); // Output: 0xA6 (0b10100110) 
 
******************************************************************************/ 
uint32_t toggle_bit(uint32_t value, int bit) { 
    return value ^ (1U << bit); 
} 
/****************************************************************************** 
** Function name:  count_set_bits 
** caratteristiche: contare il numero di bit impostati a 1 
 
  uint32_t num = 0b10101010; 
    int count = count_set_bits(num); 
    printf("Set bits count: %d\n", count); // Output: 4 
 
******************************************************************************/ 
int count_set_bits(uint32_t value) { 
    int count = 0; 
    while (value) { 
        count += value & 1; 
        value >>= 1; 
    } 
    return count; 
} 
/****************************************************************************** 
** Function name:  is_bit_set 
** caratteristiche: Verifica se un bit è settato 
 
  uint32_t num = 0b10001000; 
    int isSet = is_bit_set(num, 3); 
    printf("Bit 3 is %s\n", isSet ? "set" : "not set"); // Output: not se 
 
******************************************************************************/ 
int is_bit_set(uint32_t value, int bit) { 
    return (value >> bit) & 1; 
} 
/****************************************************************************** 
** Function name:  rotate_left 
          rotate_right 
** caratteristiche: ruotare un valore(o un gruppo di bit) verso destra o sinistra 
 
  uint32_t num = 0x12345678; 
  uint32_t left = rotate_left(num, 4); 
    uint32_t right = rotate_right(num, 4); 
    printf("Rotated left: 0x%X\n",


eft(num, 4); 
    uint32_t right = rotate_right(num, 4); 
    printf("Rotated left: 0x%X\n", left);  // Output: 0x23456781 
    printf("Rotated right: 0x%X\n", right); // Output: 0x81234567 
 
******************************************************************************/ 
uint32_t rotate_left(uint32_t value, int n) { 
    return (value << n) | (value >> (32 - n)); 
} 
 
uint32_t rotate_right(uint32_t value, int n) { 
    return (value >> n) | (value << (32 - n)); 
} 
/****************************************************************************** 
** Function name:  modify_bits 
** caratteristiche: modificare una sequenza di bit 
 
  uint32_t num = 0xABCD1234; // 0b10101011110011010001001000110100 
    num = modify_bits(num, 8, 4, 0b1111); // Modifica i 4 bit da posizione 8 con 0b1111 
    printf("Modified bits: 0x%X\n", num); // Output: 0xABCD1F34 
 
******************************************************************************/ 
uint32_t modify_bits(uint32_t value, int pos, int n, uint32_t new_bits) { 
    uint32_t mask = ((1U << n) - 1) << pos;  // Creazione della maschera 
    return (value & ~mask) | ((new_bits << pos) & mask); 
} 
 
/****************************************************************************** 
                             OPERAZIONI LOGICHE 
******************************************************************************/ 
 
/****************************************************************************** 
** Function name: 
** caratteristiche: AND tra 2 valori 
 
  uint8_t a = 0b11001100;  // 204 in decimale 
    uint8_t b = 0b10101010;  // 170 in decimale 
    uint8_t result = bitwise_and(a, b); 
    printf("AND: 0x%X\n", result); // Output: 0x80 (0b10001000) 
 
******************************************************************************/ 
uint8_t bitwise_and(uint8_t a, uint8_t b) { 
    return a & b; 
} 
/****************************************************************************** 
** Function name: bitwise_or 
** caratteristiche: OR tra 2 valori 
 
  uint8_t a = 0b11001100; 
    uint8_t b = 0b10101010; 
    uint8_t result = bitwise_or(a, b); 
    printf("OR: 0x%X\n", result); // Output: 0xFE (0b11111110) 
******************************************************************************/ 
uint8_t bitwise_or(uint8_t a, uint8_t b) { 
    return a | b; 
} 
/****************************************************************************** 
** Function name: bitwise_xor 
** caratteristiche: XOR tra 2 valori 
 
  uint8_t a = 0b11001100; 
    uint8_t b = 0b10101010; 
    uint8_t result = bitwise_xor(a, b); 
    printf("XOR: 0x%X\n", result); // Output: 0x7E (0b01110110 
******************************************************************************/ 
uint8_t bitwise_xor(uint8_t a, uint8_t b) { 
    return a ^ b; 
} 
/****************************************************************************** 
** Function name: bitwise_not 
** caratteristiche: NOT tra 2 valori 
 
  uint8_t a = 0b11001100; 
    uint8_t result = bitwise_not(a); 
    printf("NOT: 0x%X\n", result); // Output: 0x33 (0b00110011) 
******************************************************************************/ 
uint8_t bitwise_not(uint8_t a) { 
    return ~a; 
} 
/****************************************************************************** 
** Function name: shift_left 
         shift_right 
** caratteristiche: SHIFT a sinistra/destra 
 
  uint8_t a = 0b00001111; 
    uint8_t result = shift_left(a, 2); 
    printf("Shift Left: 0x%X\n", result); // Output: 0x3C (0b00111100) 
 
  uint8_t a = 0b11110000; 
    uint8_t result = shift_right(a, 2); 
    printf("Shift Right: 0x%X\n", result); // Output: 0x3C (0b00111100) 
******************************************************************************/ 
uint8_t shift_left(uint8_t value, int n) { 
    return value << n; 
} 
uint8_t shift_right(uint8_t value, int n) { 
    return value >> n; 
} 
/****************************************************************************** 
                             Funzioni utili 
******************************************************************************/ 
 
/****


********************************************************************** 
** Function name: is_power_of_two 
          
** caratteristiche: Verifica se è una potenza di 2 
 
  uint8_t x = 8;  // 0b00001000 
    printf("Is power of two? %s\n", is_power_of_two(x) ? "Yes" : "No"); // Output: Yes 
 
   
******************************************************************************/ 
int is_power_of_two(uint8_t num) { 
    return num && !(num & (num - 1)); 
} 
/****************************************************************************** 
** Function name: lowest_set_bit 
          
** caratteristiche: Isolare il bit meno significativo impostato a 1 
 
  uint8_t x = 0b10110000; // 176 decimale 
    printf("Lowest set bit: 0x%X\n", lowest_set_bit(x)); // Output: 0x10 (0b00010000) 
   
******************************************************************************/ 
uint8_t lowest_set_bit(uint8_t num) { 
    return num & -num; 
} 
/****************************************************************************** 
** Function name: has_even_parity 
          
** caratteristiche: Verifica se un numero ha un numero pari di bit a 1 
 
  uint8_t x = 0b10101010;  // 170 decimale, ha 4 bit a 1 (pari) 
    printf("Has even parity? %s\n", has_even_parity(x) ? "Yes" : "No"); // Output: Yes 
******************************************************************************/ 
int has_even_parity(uint8_t num) { 
    num ^= num >> 4; 
    num ^= num >> 2; 
    num ^= num >> 1; 
    return !(num & 1); 
} 
/****************************************************************************** 
** Function name: max_consecutive_ones 
          
** caratteristiche: contare il numero max di bit consecutivi a 1 
 
   uint8_t x = 0b11100110; // 230 decimale 
    printf("Max consecutive ones: %d\n", max_consecutive_ones(x)); // Output: 3 
   
******************************************************************************/ 
int max_consecutive_ones(uint8_t num) { 
    int max_count = 0, count = 0; 
    while (num) { 
        if (num & 1) count++; 
        else count = 0; 
        if (count > max_count) max_count = count; 
        num >>= 1; 
    } 
    return max_count; 
} 
/****************************************************************************** 
** Function name: swap_bits 
          
** caratteristiche: Swap tra bit specifici 
 
  uint8_t x = 0b11001100; 
    printf("Swapped bits: 0x%X\n", swap_bits(x, 2, 5)); // Output: 0xB4 
******************************************************************************/ 
uint8_t swap_bits(uint8_t num, int pos1, int pos2) { 
    uint8_t bit1 = (num >> pos1) & 1; 
    uint8_t bit2 = (num >> pos2) & 1; 
 
    if (bit1 != bit2) { 
        num ^= (1U << pos1) | (1U << pos2); 
    } 
    return num; 
} 
/****************************************************************************** 
** Function name: first_set_bit_position 
          
** caratteristiche: trova la posizione del primo bit impostato a 1 
 
  uint8_t x = 0b10010000; 
    printf("First set bit position: %d\n", first_set_bit_position(x)); // Output: 4 
   
******************************************************************************/ 
int first_set_bit_position(uint8_t num) { 
    if (num == 0) return -1; 
    int pos = 0; 
    while (!(num & 1)) { 
        num >>= 1; 
        pos++; 
    } 
    return pos; 
} 
/****************************************************************************** 
** Function name: reverse_bits_8 
          
** caratteristiche:  
 
  uint8_t x = 0b11010010; // 210 in decimale 
    uint8_t reversed = reverse_bits_8(x);   
******************************************************************************/ 
uint8_t reverse_bits_8(uint8_t num) { 
    num = (num & 0xF0) >> 4 | (num & 0x0F) << 4; 
    num = (num & 0xCC) >> 2 | (num & 0x33) << 2; 
    num = (num & 0xAA) >> 1 | (num & 0x55) << 1; 
    return num; 
} 
/****************************************************************************** 
** Function name: reverse_bits_32 
          
** caratteristiche:  
 
  uint32_t x = 0x12345678; // 305419896 in decimale 
    uint32_t reversed =


reverse_bits_32(x); 
******************************************************************************/ 
uint32_t reverse_bits_32(uint32_t num) { 
    num = (num & 0xFFFF0000) >> 16 | (num & 0x0000FFFF) << 16; 
    num = (num & 0xFF00FF00) >> 8  | (num & 0x00FF00FF) << 8; 
    num = (num & 0xF0F0F0F0) >> 4  | (num & 0x0F0F0F0F) << 4; 
    num = (num & 0xCCCCCCCC) >> 2  | (num & 0x33333333) << 2; 
    num = (num & 0xAAAAAAAA) >> 1  | (num & 0x55555555) << 1; 
    return num; 
}




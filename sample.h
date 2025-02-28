

// scorre il vettore di dimensione n, calcola la somma di vett[i]*vett[i+1], setta a 1 la variabile alarm se la somma è maggiore di 255 (ritorna la somma)
extern unsigned int calcola_somma_prodotto(unsigned int vett[], unsigned int n, char* alarm);


// scorre il vettore di dimensione numero_misure, restituisce la somma dei valori>min e valori<max
extern unsigned int totale_pressioni_con_filtro(unsigned char VETT[], unsigned int  numero_misure, unsigned char MAX, unsigned char MIN);


// Riceve un vettore di dimensione N e lo ordina
// Restituisce il numero degli elementi del vettore
// se devi lavorare con 8-bit nell'assember modifica LDR -> LDRB e STR -> STRB
// ovviamente modifica anche il prototipo di questa funzione con la dichiarazione di vett
extern unsigned int bubble_sort(int vett[], int n); 

extern unsigned int bubble_sort_8bit(char vett[], int n); 

extern unsigned int bubble_sort_reverse(int vett[], int n);
extern unsigned int bubble_sort_reverse_8bit(char vett[], int n);



extern int estrai_minimo(int vett[], int n);

extern int estrai_massimo(int vett[], int n);



// conta valori >=min e <=max
extern int conta_valori_in_range(int vett[], int n, int min, int max);


// il primo elemento diventa ultimo, il secondo diventa il penultimo
extern int vettore_reverse(int vett[], int n);

// se ho una funzione con più di 4 parametri, nell'assembler
// dopo PUS{R4-R7, LR}, il quinto parametro sarà a SP+36, il sesto parametro a SP+40, il settimo parametro a SP+44  ....


extern int funzione_5_parametri(int a,int b,int c,int d,int e,int f );



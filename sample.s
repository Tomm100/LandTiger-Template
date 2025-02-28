			AREA function_code, CODE, READONLY  



;   EXPORT funzione_5_parametri

;funzione_5_parametri FUNCTION
;      PUSH {R4-R11, LR}
;	  
;	  LDR R4, [SP, #36]
;	  MOV R5, #0xcafe
;	  STR R5, [R4]
;	  POP {R4-R11, PC}
;	  ENDFUNC
; Algoritmo Bubble Sort con vettore di int
; L'indirizzo del vettore è in R0
; La dimensione del vettore è in R1
;	EXPORT bubble_sort 


;bubble_sort FUNCTION
;    PUSH {R4-R11, LR}       ; Salva i registri che useremo e il link register

;    CMP R1, #1              ; Se la dimensione del vettore è <= 1, non fare nulla
;    BLE done

;    MOV R4, R0              ; Copia l'indirizzo del vettore in R4
;    MOV R5, R1              ; Copia la dimensione del vettore in R5

;outer_loop
;    SUBS R5, R5, #1         ; R5 = dimensione corrente - 1
;    BEQ done                ; Se la dimensione è 0, termina

;    MOV R6, R4              ; R6 è il puntatore al primo elemento del vettore
;    MOV R7, #0              ; Indice del loop interno

;inner_loop
;    LDR R8, [R6]            ; Carica il valore corrente in R8
;    LDR R9, [R6, #4]        ; Carica il valore successivo in R9

;    CMP R8, R9              ; Confronta R8 e R9
;    MOVGT R10, R8           ; Se R8 > R9, copia R8 in R10
;    MOVGT R8, R9           ; Se R8 > R9, copia R9 in R8
;    MOVGT R9, R10           ; Se R8 > R9, copia R10 in R9

;    STR R8, [R6]            ; Memorizza il valore corretto nella posizione corrente
;    STR R9, [R6, #4]        ; Memorizza il valore corretto nella posizione successiva

;    ADD R6, R6, #4          ; Vai al prossimo elemento (incrementa il puntatore di 4 byte)
;    ADD R7, R7, #1          ; Incrementa l'indice
;    CMP R7, R5              ; Controlla se siamo alla fine del vettore
;    BLT inner_loop          ; Ripeti il loop interno se non finito

;    B outer_loop            ; Ripeti il loop esterno

;done
;    POP {R4-R11, PC}        ; Ripristina i registri e ritorna

;	ENDFUNC


	
;		EXPORT bubble_sort_8bit
;bubble_sort_8bit FUNCTION
;    PUSH {R4-R11, LR}       ; Salva i registri che useremo e il link register

;    CMP R1, #1              ; Se la dimensione del vettore è <= 1, non fare nulla
;    BLE done

;    MOV R4, R0              ; Copia l'indirizzo del vettore in R4
;    MOV R5, R1              ; Copia la dimensione del vettore in R5

;outer_loop
;    SUBS R5, R5, #1         ; R5 = dimensione corrente - 1
;    BEQ done                ; Se la dimensione è 0, termina

;    MOV R6, R4              ; R6 è il puntatore al primo elemento del vettore
;    MOV R7, #0              ; Indice del loop interno

;inner_loop
;    LDRB R8, [R6]           ; Carica il valore corrente (8 bit) in R8
;    LDRB R9, [R6, #1]       ; Carica il valore successivo (8 bit) in R9

;    CMP R8, R9              ; Confronta R8 e R9
;    MOVGT R10, R8           ; Se R8 > R9, copia R8 in R10
;    MOVGT R8, R9            ; Se R8 > R9, copia R9 in R8
;    MOVGT R9, R10           ; Se R8 > R9, copia R10 in R9

;    STRB R8, [R6]           ; Memorizza il valore corretto (8 bit) nella posizione corrente
;    STRB R9, [R6, #1]       ; Memorizza il valore corretto (8 bit) nella posizione successiva

;    ADD R6, R6, #1          ; Vai al prossimo elemento (incrementa il puntatore di 1 byte)
;    ADD R7, R7, #1          ; Incrementa l'indice
;    CMP R7, R5              ; Controlla se siamo alla fine del vettore
;    BLT inner_loop          ; Ripeti il loop interno se non finito

;    B outer_loop            ; Ripeti il loop esterno

;done
;    POP {R4-R11, PC}        ; Ripristina i registri e ritorna
;	ENDFUNC




;	EXPORT bubble_sort_reverse
;		
;bubble_sort_reverse FUNCTION

;    PUSH {R4-R11, LR}       ; Salva i registri che useremo e il link register

;    CMP R1, #1              ; Se la dimensione del vettore è <= 1, non fare nulla
;    BLE done

;    MOV R4, R0              ; Copia l'indirizzo del vettore in R4
;    MOV R5, R1              ; Copia la dimensione del vettore in R5

;outer_loop
;    SUBS R5, R5, #1         ; R5 = dimensione corrente - 1
;    BEQ done                ; Se la dimensione è 0, termina

;    MOV R6, R4              ; R6 è il puntatore al primo elemento del vettore
;    MOV R7, #0              ; Indice del loop interno

;inner_loop
;    LDR R8, [R6]            ; Carica il valore corrente (32 bit) in R8
;    LDR R9, [R6, #4]        ; Carica il valore successivo (32 bit) in R9

;    CMP R8, R9              ; Confronta R8 e R9
;    MOVLT R10, R8           ; Se R8 < R9, copia R8 in R10
;    MOVLT R8, R9            ; Se R8 < R9, copia R9 in R8
;    MOVLT R9, R10           ; Se R8 < R9, copia R10 in R9

;    STR R8, [R6]            ; Memorizza il valore corretto (32 bit) nella posizione corrente
;    STR R9, [R6, #4]        ; Memorizza il valore corretto (32 bit) nella posizione successiva

;    ADD R6, R6, #4          ; Vai al prossimo elemento (incrementa il puntatore di 4 byte)
;    ADD R7, R7, #1          ; Incrementa l'indice
;    CMP R7, R5              ; Controlla se siamo alla fine del vettore
;    BLT inner_loop          ; Ripeti il loop interno se non finito

;    B outer_loop            ; Ripeti il loop esterno

;done
;    POP {R4-R11, PC}        ; Ripristina i registri e ritorna
;	ENDFUNC

;		EXPORT bubble_sort_reverse_8bit
;bubble_sort_reverse_8bit   FUNCTION

;    PUSH {R4-R11, LR}       ; Salva i registri che useremo e il link register

;    CMP R1, #1              ; Se la dimensione del vettore è <= 1, non fare nulla
;    BLE done

;    MOV R4, R0              ; Copia l'indirizzo del vettore in R4
;    MOV R5, R1              ; Copia la dimensione del vettore in R5

;outer_loop
;    SUBS R5, R5, #1         ; R5 = dimensione corrente - 1
;    BEQ done                ; Se la dimensione è 0, termina

;    MOV R6, R4              ; R6 è il puntatore al primo elemento del vettore
;    MOV R7, #0              ; Indice del loop interno

;inner_loop
;    LDRB R8, [R6]           ; Carica il valore corrente (8 bit) in R8
;    LDRB R9, [R6, #1]       ; Carica il valore successivo (8 bit) in R9

;    CMP R8, R9              ; Confronta R8 e R9
;    MOVLT R10, R8           ; Se R8 < R9, copia R8 in R10
;    MOVLT R8, R9            ; Se R8 < R9, copia R9 in R8
;    MOVLT R9, R10           ; Se R8 < R9, copia R10 in R9

;    STRB R8, [R6]           ; Memorizza il valore corretto (8 bit) nella posizione corrente
;    STRB R9, [R6, #1]       ; Memorizza il valore corretto (8 bit) nella posizione successiva

;    ADD R6, R6, #1          ; Vai al prossimo elemento (incrementa il puntatore di 1 byte)
;    ADD R7, R7, #1          ; Incrementa l'indice
;    CMP R7, R5              ; Controlla se siamo alla fine del vettore
;    BLT inner_loop          ; Ripeti il loop interno se non finito

;    B outer_loop            ; Ripeti il loop esterno

;done
;    POP {R4-R11, PC}        ; Ripristina i registri e ritorna
;	ENDFUNC



		
;		EXPORT estrai_minimo
;estraiminimo FUNCTION
;		 PUSH {R4-R11, LR}
;        MOV R6, R0           ; Salva l'indirizzo base del vettore in R6
;        MOV R7, R1           ; Salva la dimensione del vettore in R7


;        CMP R7, #0           ; Verifica se la dimensione del vettore è zero
;        BEQ fine             ; Se la dimensione è zero, termina


;        LDR R4, [R6]         ; Carica il primo elemento del vettore in R4 (valore minimo corrente)
;        ADD R6, R6, #4       ; Incrementa il puntatore al prossimo elemento
;        SUB R7, R7, #1       ; Decrementa la dimensione del vettore

;FindMinLoop
;        CMP R7, #0           ; Controlla se ci sono ancora elementi nel vettore
;        BEQ fine             ; Se non ci sono più elementi, termina

;        LDR R5, [R6]         ; Carica l'elemento corrente in R5
;        CMP R5, R4           ; Confronta l'elemento corrente con il minimo attuale
;        MOVLT R4, R5         ; Se R5 < R4, aggiorna il minimo con R5

;        ADD R6, R6, #4       ; Incrementa il puntatore al prossimo elemento
;        SUB R7, R7, #1       ; Decrementa la dimensione del vettore
;        B FindMinLoop        ; Ripeti il ciclo

;fine
;        MOV R0, R4           ; Salva il minimo trovato in R0
;			
;		POP {R4-R11, PC}
;	        ENDFUNC



;		EXPORT estrai_massimo
;estrai_massimo FUNCTION
;        PUSH {R4-R11, LR}
;        MOV R6, R0           ; Salva l'indirizzo base del vettore in R6
;        MOV R7, R1           ; Salva la dimensione del vettore in R7

;        CMP R7, #0           ; Verifica se la dimensione del vettore è zero
;        BEQ fine             ; Se la dimensione è zero, termina

;        LDR R4, [R6]         ; Carica il primo elemento del vettore in R4 (valore massimo corrente)
;        ADD R6, R6, #4       ; Incrementa il puntatore al prossimo elemento
;        SUB R7, R7, #1       ; Decrementa la dimensione del vettore

;FindMaxLoop
;        CMP R7, #0           ; Controlla se ci sono ancora elementi nel vettore
;        BEQ fine             ; Se non ci sono più elementi, termina

;        LDR R5, [R6]         ; Carica l'elemento corrente in R5
;        CMP R5, R4           ; Confronta l'elemento corrente con il massimo attuale
;        MOVGT R4, R5         ; Se R5 > R4, aggiorna il massimo con R5

;        ADD R6, R6, #4       ; Incrementa il puntatore al prossimo elemento
;        SUB R7, R7, #1       ; Decrementa la dimensione del vettore
;        B FindMaxLoop        ; Ripeti il ciclo

;fine
;        MOV R0, R4           ; Salva il massimo trovato in R0

;        POP {R4-R11, PC}
;        ENDFUNC





	

;	EXPORT conta_valori_in_range

;conta_valori_in_range FUNCTION
;		
;		PUSH {R4-R11, LR}
;	
;	     MOV     R4, R0             ; Copia l'indirizzo base del vettore in R4
;        MOV     R5, R1             ; Copia la dimensione del vettore in R5
;        MOV     R6, R2             ; Copia il valore minimo del range in R6
;        MOV     R7, R3             ; Copia il valore massimo del range in R7
;        MOV     R3, #0             ; R3 servirà come contatore

;loop
;        CMP     R5, #0             ; Controlla se la dimensione del vettore è 0
;        BEQ     fine                ; Se sì, termina il ciclo

;        LDR     R2, [R4], #4       ; Carica il prossimo elemento del vettore in R2 e avanza l'indirizzo

;        CMP     R2, R6             ; Confronta il valore con il minimo del range
;        BLT     next               ; Se è minore del minimo, passa al prossimo elemento

;        CMP     R2, R7             ; Confronta il valore con il massimo del range
;        BGT     next               ; Se è maggiore del massimo, passa al prossimo elemento

;        ADD     R3, R3, #1         ; Incrementa il contatore se il valore è nel range

;next
;        SUBS    R5, R5, #1         ; Decrementa la dimensione del vettore
;        BNE     loop               ; Continua il ciclo se ci sono ancora elementi

;fine
;        MOV     R0, R3             ; Metti il contatore nel registro R0 (valore di ritorno)
;		 POP {R4-R11, PC}
;	
;		ENDFUNC




;		EXPORT vettore_reverse
;			
;vettore_reverse
;	
;	 PUSH {R4-R11, LR}
;	 MOV R4, R0              ; Copia l'indirizzo base del vettore in R4
;    MOV R5, R1              ; Copia la dimensione del vettore in R5

;    SUB R6, R5, #1          ; Calcola l'indice dell'ultimo elemento (dimensione - 1)
;    MOV R7, #0              ; R7 tiene traccia dell'indice iniziale (0)
;    MOV R8, R4              ; R8 tiene l'indirizzo dell'elemento iniziale
;    ADD R9, R4, R6, LSL #2  ; R9 tiene l'indirizzo dell'elemento finale

;reverse_loop
;    CMP R7, R6              ; Confronta gli indici (iniziale e finale)
;    BGE reverse_done        ; Se R7 >= R6, il reverse è completo

;    ; Scambia gli elementi usando istruzioni condizionali
;    LDR R10, [R8]           ; Carica il valore dell'elemento iniziale in R10
;    LDR R11, [R9]           ; Carica il valore dell'elemento finale in R11
;    STR R11, [R8]           ; Scrive il valore dell'elemento finale all'indirizzo iniziale
;    STR R10, [R9]           ; Scrive il valore dell'elemento iniziale all'indirizzo finale

;    ; Aggiorna gli indirizzi e gli indici
;    ADD R8, R8, #4          ; Incrementa l'indirizzo iniziale di 4 byte
;    SUB R9, R9, #4          ; Decrementa l'indirizzo finale di 4 byte
;    ADD R7, R7, #1          ; Incrementa l'indice iniziale (R7)
;    SUBS R6, R6, #1         ; Decrementa l'indice finale (R6) e aggiorna i flag
;    BGT reverse_loop        ; Ripeti il ciclo se R7 < R6

;reverse_done



;	  POP {R4-R11, PC}

;                EXPORT  calcola_somma_prodotto


;; PRIMA FUNZIONE
;calcola_somma_prodotto   FUNCTION    ;dichiarata in sample.h
;            
;			 ; implementa la seguente funzione C
;			 ; result = calcola_somma_prodotto((unsigned int * )vett, N, (char*)&alarm);
;			 ; calcola sommatoria di vett[i]*vett[i+1] -> N deve essere pari
;			 ; setta alarm a 1 se il risultato è maggiore di 255
;            
;			PUSH {R4-R7, LR}    ; salvo nello stack i registri che andrò a spostare e LR
;             ;R0 indirizzo vettore
;			 ;R1 N
;			 ;R2 indirizzo alarm
;			 
;			 
;			 MOV R5, R0    ;salvo in R5 indirizzo del vettore
;			 MOV R0, #0    ; Azzero R0 che conterrà il risultato da ritornare
;			 MOV R4, #0
;             			 
;loop       
;            LDR R6, [R5]
;			ADD R5, R5, #4
;			ADD R4, R4, #1
;			LDR R7, [R5]
;			ADD R5, R5, #4
;			ADD R4, R4, #1
;			
;			MUL R6, R6,R7    ; R6*R7
;			ADD R0, R0, R6   ; result + R5*R6
;			CMP R0, #255
;			MOVHI R0, #1
;			STRHI R0, [R2]
;			BHI exit
;			CMP R1, R4
;			BNE loop 
;			 
;			 
;exit			 
;			 
;            POP {R4-R7, PC}     ; ristabilsco i registri e il PC
;          ENDFUNC
;	



;; SECONDA FUNZIONE
;      EXPORT  totale_pressioni_con_filtro
;			
;totale_pressioni_con_filtro FUNCTION
;;		 R0 -> indirizzo vettore
;;		 R1 -> numeroMisure
;;		 R2 -> max
;;		 R3 -> min
;	    PUSH {R4-R11, LR}
;		
;		MOV R5, R0  ; copio in R5 l'indirizzo del vettore
;		MOV R6, #0  ; contatore
;		MOV R0, #0  
;		
;		
;loop2
;		LDRB R7, [R5]    ; R7 valore corrente
;		CMP R7, R2
;		BLT controlloMin   ; se è minore di max salto
;		ADD R5, R5, #1 
;	    ADD R6, R6, #1
;		CMP R6, R1
;		BNE loop2
;		B exit2



;controlloMin
;       CMP R7, R3
;	   ADDGT R0, R0, R7
;	   ADD R5, R5, #1
;	   ADD R6, R6, #1

;      
;		
;		CMP R6, R1
;		BNE loop2
;		
;exit2		
;		POP {R4-R11, PC}
;	
;	
;	
;	ENDFUNC
	
	END
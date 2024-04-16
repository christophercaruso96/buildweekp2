/***
 * Author: Christopher Caruso
 * Date: 2024-04-16
 * Notes: COMMENTI PRESENTI SOLO SULLE MODIFICHE AL CODICE ORIGINALE
***/


#include <stdio.h> 

//Aggiunte define per il preprocessore
//Il preprocessore sostituirà le keyword col valore associato in tutto il codice 
#define NO_BOF_VALUE 5
#define BOF_VALUE 10

/*** PROTOTIPI FUNZIONI ***/
void get_int_value (int *); //prototipo per funzione che valida l'input utente sugli interi(l'uso del passaggio per riferimento viene illustrato in seguito)
int get_total_iterations(); //prototipo per funzione scelta utente con menù


/*** MAIN  ***/

int main () {

	//valorizzata dimensione array con keyword nella define
	int vector[NO_BOF_VALUE];
	int swap_var;
	//dichiarata variabile per settare il numero di iterazioni a seconda della scelta utente
	int counter_limit =  get_total_iterations();
    
	
	printf ("Inserimento di %d valori interi:\n", counter_limit); 

	//nei cicli for ho riciclato le variabili counter perchè hanno lo scope valido in iterazione e non serve dichiararne una per ogni ciclo
	for (int i = 0 ; i < counter_limit ; i++){
		printf("[%d]:", i+1);
		get_int_value(&vector[i]); //uso il passaggio per riferimento per rendere possibile il BOF
		//con una chiamata a funzione del tipo vector[i] = get_int_value()
		//viene effettuato un passaggio per valore e non per riferimento patchando la possibilità di generare il BOF
	}

	printf ("Il vettore inserito e':\n");
	for (int i = 0 ; i < counter_limit ; i++){
		printf("[%d]: %d", i+1, vector[i]);
		printf("\n");
	}
	
	for (int i = 0 ; i < counter_limit - 1; i++){
		for (int j = 0 ; j < counter_limit - i - 1; j++){
				if (vector[j] > vector[j+1]){
					swap_var=vector[j]; 
					vector[j]=vector[j+1];
					vector[j+1]=swap_var;
				}
		}
	}

	printf("Il vettore ordinato e':\n");
	
	for (int i = 0; i < counter_limit; i++){
		printf("[%d]:", i+1);
		printf("%d\n", vector[i]);
	}
	
	return 0;
}


/*** DEFINIZIONE FUNZIONI ***/


//definita funzione per gestire il controllo input sui valori da inserire nel vettore
//se non viene inserito un type int continua a chiedere il reinserimento
//creando una void che lavora sui puntatori è possibile passare il pointer alla scanf
//garantendo la possibilità di generare un BOF
void get_int_value(int *pointer){
		int value;
        int status_scan = scanf("%d", pointer);
        char char_trash;
        while(status_scan < 1) {
                printf("Inserire valore di tipo int!\n");
                scanf("%c", &char_trash);
                status_scan = scanf("%d", pointer);
        }
}

//questa funzione serve a definire il numero di iterazioni da eseguire nei cicli per l'inserimento, l'ordinamento e la stampa del vettore
//se l'utente sceglie 1 le iterazioni corrispondono alla dimensione del vettore
//se l'utente sceglie 2, per generare il BOF, le iterazioni saranno maggiori del valore settato per la dimensione del vettore
int get_total_iterations(){

	int user_choise, iterations;
	
	printf("Effettuare una scelta tra:\n\t1) Eseguire programma corretto\n\t2) Eseguire programma con BOF\n");
	
	get_int_value(&user_choise);

	//viene settato il valore della variabile iterations in base alla scelta utente
	switch(user_choise){
		case 1:
			iterations = NO_BOF_VALUE;
			printf("NO_BOF_VALUE\n");
			break;
		case 2:
			iterations = BOF_VALUE;
			printf("BOF_VALUE\n");
			break;
		default: 
			printf("Scelta non valida! Applicazione default 1\n");
			iterations = NO_BOF_VALUE;
	}

	//viene restituito il numero di iterazioni da eseguire nei cicli
	return iterations;

}
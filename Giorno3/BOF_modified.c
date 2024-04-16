#include <stdio.h> 

//COMMENTI PRESENTI SOLO NELLE MODIFICHE AL CODICE ORIGINALE 

//PROTOTIPI FUNZIONI
int get_int_value (int*); //prototipo per funzione che valida l'input utente sugli interi


//MAIN 

int main () {

int vector [5], i, j, k; 
int swap_var; 


printf ("Inserire 10 interi:\n"); 

for ( i = 0 ; i < 10 ; i++)
	{
	int c= i+1; 
	printf("[%d]:", c);
	get_int_value(&vector[i]);
	}


printf ("Il vettore inserito e':\n");
for ( i = 0 ; i < 10 ; i++) 
        {
        int t= i+1;
        printf("[%d]: %d", t, vector[i]);
	printf("\n");
	}


for (j = 0 ; j < 10 - 1; j++) 
	{
	for (k = 0 ; k < 10 - j - 1; k++)
		{
			if (vector[k] > vector[k+1])
			{
			swap_var=vector[k]; 
			vector[k]=vector[k+1];
			vector[k+1]=swap_var;
			}
		}
	}
printf("Il vettore ordinato e':\n");
for (j = 0; j < 10; j++) 
	{
	int g = j+1;
	printf("[%d]:", g);
	printf("%d\n", vector[j]);
	}

return 0;


}


//DEFINIZIONE FUNZIONI

int get_int_value(int *pointer){
        int status_scan = scanf("%d", pointer);
        char char_trash;
        while(status_scan < 1) {
                printf("Input non valido!\n");
                scanf("%c", &char_trash);
                status_scan = scanf("%d", pointer);
        }
}
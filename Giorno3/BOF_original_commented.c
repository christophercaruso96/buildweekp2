#include <stdio.h> //import libreria standard input-output
/*
	DESCRIZIONE: Viene richiesto all'utente di inserire 10 interi per il popolamento di un vettore.
				 Dopo l'inserimento il vettore viene stampato a video.
				 Dopo la stampa, il vettore viene riordinato con l'ausilio di una variabile tampone / di swap.
				 Dopo l'ordinamento viene stampato a video il vettore ordinato.
*/

int main () {//apertura main

int vector [10], i, j, k; //dichiarazione di un array di 10 interi e di 3 variabili intere
int swap_var; //dichiarazione variabile intera


printf ("Inserire 10 interi:\n"); //Stampa a video richiesta inserimento 10 interi

for ( i = 0 ; i < 10 ; i++)//ciclo for per inserire valore per valore nel vettore
	{
	int c= i+1; 
	printf("[%d]:", c);
	scanf ("%d", &vector[i]);
	}


printf ("Il vettore inserito e':\n");
for ( i = 0 ; i < 10 ; i++) //iterazione per la stampa dei valori inseriti
        {
        int t= i+1;
        printf("[%d]: %d", t, vector[i]);
	printf("\n");
	}


for (j = 0 ; j < 10 - 1; j++) //cicli annidati per ordinamento dell'array
	{
	for (k = 0 ; k < 10 - j - 1; k++)
		{
			if (vector[k] > vector[k+1])
			{
			swap_var=vector[k]; //viene usata la variabile swap per effettuare gli scambi nell'ordinamento
			vector[k]=vector[k+1];
			vector[k+1]=swap_var;
			}
		}
	}
printf("Il vettore ordinato e':\n");
for (j = 0; j < 10; j++) //ciclo for per la stampa del vettore ordinato
	{
	int g = j+1;
	printf("[%d]:", g);
	printf("%d\n", vector[j]);
	}

return 0; //uscita dal main OK


}

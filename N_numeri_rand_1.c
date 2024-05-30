#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
    int N;
    time_t t;   //variabile di tipo tempo usata in srand

    printf("Quanti numeri randomici vuoi generare da 0 a 1?(min 100): ");
    scanf("%d", &N);

    srand((float) time(&t));    //funzione srand che ogni volta  che il programma viene fatto partire 
                                //assegna un valore casuale a t per generare numeri casuali nuovi

    printf("I tuoi numeri sono:\n");
    for (int i = 0; i < N; i++)
    {                                                       //Siccome rand e RAND_MAX sono funzioni che restituiscono valori interi uso il casting
        printf("%f\n", ((float)rand()/(float)RAND_MAX)*1);  //per assegnargli un valore float quando la divisione viene effettuata. Qui faccio la
    }                                                       //divisione tra il numero generato e il massimo numero generabile con il range tra 0 e 1
    
}
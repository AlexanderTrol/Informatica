#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
    int N;
    time_t t;

    printf("Quanti numeri randomici vuoi generare da 0 a 70.5?(min 100): ");
    scanf("%d", &N);

    srand((float) time(&t));

    printf("I tuoi numeri sono:\n");
    for (int i = 0; i < N; i++)
    {                                                        //Siccome rand e RAND_MAX sono funzioni che restituiscono valori interi uso il casting
        printf("%f\n", ((float)rand()/(float)RAND_MAX)*70.5);//per assegnargli un valore float quando la divisione viene effettuata. Qui faccio la
    }                                                        //divisione tra il numero generato e il massimo numero generabile con il range di 70.5.
    
}
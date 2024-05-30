#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
    int N;
    time_t t;   //variabile di tipo tempo usata in srand

    printf("Quanti numeri randomici vuoi generare da 0 a 70?(min 100): ");
    scanf("%d", &N);

    srand((int) time(&t));  //funzione srand che ogni volta  che il programma viene fatto partire 
                            //assegna un valore casuale a t per generare numeri casuali nuovi

    printf("I tuoi numeri sono:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", rand()%70);  //funzione rand che genera un numero casuale che va da 0 a 70
    }
    
}
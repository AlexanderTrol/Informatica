#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
    int N;
    float a, b;
    time_t t; //variabile di tipo tempo usata in srand

    printf("Quanti numeri randomici vuoi generare tra a e b?(min 100): ");
    scanf("%d", &N);
    
    printf("Definisci a e b:");
    scanf("%f", &a);  //scanf per assegnare un valore float ad a
    scanf("%f", &b);  //scanf per assegnare un valore float a b

    srand((float) time(&t));  //funzione srand che ogni volta  che il programma viene fatto partire 
                              //assegna un valore casuale a t per generare numeri casuali nuovi

    printf("I tuoi numeri sono:\n");
    
    if (a > b){ //if nel caso in cui a sia più grande di b
        for (int i = 0; i < N; i++)
        {                                                      //Siccome rand e RAND_MAX sono funzioni che restituiscono valori interi uso il casting
        printf("%f\n", b+((float)rand()/(float)RAND_MAX)*(a-b)); //per assegnargli un valore float quando la divisione viene effettuata. Qui faccio la
        }                                                      //divisione tra il numero generato e il massimo numero generabile con il range di a-b. Si
    }                                                          //toglie b perchè altrimenti sforerebbe in più con il range o poi sommo b per non far si che
                                                               //il range sia più piccolo del dovuto e così il risultato è nei range giusti  
    else if (a < b){ //if nel caso in cui b sia più grande di a
        for (int i = 0; i < N; i++)
        {
        printf("%f\n", a+((float)rand()/(float)RAND_MAX)*(b-a)); //l'operazione nel printf è uguale con quella di prima ma essendo a<b le variabili sono invertite
        }
    }
    
    else{ //ultimo caso in cui a e b siano uguali
        for (int i = 0; i < N; i++)
        {
        printf("%f\n", a || b); //essendo che a e b sono uguali viene stampato il valore di una delle 2 variabili
        }
    }
}
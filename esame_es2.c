#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>

#define NUM 1000000

int main(){
    time_t t;
    int i=0, N=0, valori[NUM], p=0, d=0;
    bool flag = true;

    srand((int) time(&t));

    while(flag)
    {
        printf("Inserisci un valore tra 100 e 1 milione: ");
        scanf("%d", &N);

        if (N < 0 || N < 100 || N > NUM){
            flag = true;
            printf("\nErrore: inserisci un nuovo valore\n");
        }
        else{
            for (i = 0; i < N; i++){
                valori[i] = rand() % 51;
            }
            flag = false;
        }
        
    }
    
    for (i = 0; i < N; i++)
    {
        if ((valori[i] % 2) == 0) p++;
        else d++;
    }

    printf("I numeri pari sono %d\nI numeri dispari sono: %d", p, d);
    
}
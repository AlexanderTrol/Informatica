#include<stdio.h>
int main(){
    int N=0, i=0;
    float somma = 0, M=0;
    float dati[100];

    printf("\nInserisci valori: ");
    scanf("%d", &N);
    
    printf("\nInserisci i valori:");
    for (i = 0; i < N; i++)
    {
        scanf("%f", &dati[i]);
    }

    for (i = 0; i < N; i++)
    {
        somma += dati[i];
    }

    M = somma/N;
    printf("\nLa media e': %f", M);    
    
}
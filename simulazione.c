#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int main(){
    int N=0, i=0;
    int dati[50];
    char q[] = "quadrato", b[] = "base";
    FILE *fp;
    time_t t;

    srand((int) time(&t));

    N=10+rand()%41; //punto 1 
    printf("Il numero casuale generato e': %d", N);
    
    for (i = 0; i < N; i++)
        dati[i] = 0;
    

    for (i = 0; i < N; i++) //punto 2
        dati[i] = rand() % N;
    
    fp = fopen("numeri.txt", "w");
    for(i = 0; i < N; i++){  //punto 3
        if((pow(dati[i], 2) < INT_MAX))
        {
            dati[i] = pow(dati[i], 2);
            fprintf(fp, "%d \t %s\n", dati[i], q);
        }
        
        else if((pow(dati[i], 2) > INT_MAX))
            fprintf(fp, "%d \t %s\n", dati[i], b);
    }
}
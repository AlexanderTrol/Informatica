//Alessandro Ausili popa, Angelica Maria Pasquini, Maria Miriam Conte

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

float cerchio(float g); //Funzione di gauss per il calcolo dell'altezza dei vari intervallini di un andamento gaussiano
int main(){

    int i=0, N=100000000, cnt=0;
    float A=0, Ny=0, x=0, y=0, A1=0, pigreco=0, r=0;
    time_t t;

    srand((float)time (&t));// genero numeri casuali

    for (i = 0; i < N; i++)
    {
        x=((float)rand()/(float)RAND_MAX)*1; //punto x generato sull'asse delle x da 0 a 1
        y=((float)rand()/(float)RAND_MAX)*1; //punto y generato sull'asse delle y da 0 a 1

        r=pow(x,2)+pow(y,2);

        if (r<=1) //se la distanza dall'origine è più grande del raggio massimo (1) allora cnt non viene incrementato perchè i punti sono generati fuori dal 1/4 di circonferenza
            cnt++; //incremento dei punti all'interno del quarto di circonferenza    
    }

    printf("%f", ((float)cnt/(float)N)*4); //stampa del PI castato in float. più grande è N più è preciso il risultato del PI
}
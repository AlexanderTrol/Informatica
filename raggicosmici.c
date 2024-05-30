#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define N 100
#define celle 149

int main(){
    int i=0, j=0;
    float alfa[N], rilevatore[celle];
    time_t t;
    
    srand((float) time(&t));

    for(i=0; i<celle; i++){
        rilevatore[i]=0.13;
        j++;
        rilevatore[j]=0.003;
        i++;
        j++;
    }

    for (i = 0; i < celle; i++)
    {
        printf("%f\n", rilevatore[i]);
    }
    

    for(i=0; i<N; i++){
        alfa[i] = ((float)rand()/(float)RAND_MAX)*(M_PI_2);
    }

}
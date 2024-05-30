#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

float gauss(float g); //Funzione di gauss per il calcolo dell'altezza dei vari intervallini di un andamento gaussiano
int main(){
    int a;
    float x;

    printf("Scegli il tipo di distribuzione:\n1-Gaussiana\n");
    scanf("%d", &a);
    if(a==1)gauss(x);
}

float gauss(float g){
    int i=0, N=0, n, j=0, k=0, cnt=0, Nygenerati=1000000;
    float dati[100], max=0, min, dx, M=0, somma=0, sommatoria=0, varianza=0, std=0, deltax=0, x=0, h=0, a=0, b=0, c=0;
    float Nx=0, Ny=0, A=0, integrale=0;
    FILE  *fp;
    time_t t;

    srand((float) time(&t));    //funzione srand che ogni volta ceh genera un seme da cui partire che il programma viene fatto partire

    fp=fopen("pianoinclinato.dat", "r"); //Apertura file del piano inclinato
    
    while(fscanf(fp, "%f", &dati[i]) != EOF){ //inserimento dei dati dento l'array dati[]
        somma=somma+dati[i];
        i++;  //incremento i++ per mandare avanti il ciclo
        N++;  //incremento di N per capire il numero di dati dentro il file.dat
    }

    //Calcolo e stampa della media
    M=somma/N;
    
    i=0;  //porto il valore di i a 0
    min=dati[i];  //essendo che i indica la prima cella di dati[] la eguaglio a min cosi da dargli un valore di riferimento a cui confrontare in seguito i minimi
    for(i=0; i<N; i++){ //ciclo che serve a capire il massimo e il minimo del vettore dati[]
        if(dati[i]>max)(max=dati[i]); //se il valore nella cella del'array è maggiore di max allora fai si che max assuma quel valore
        else(max=max);  //altrimenti lascia max uguale a se stesso
        
        if(dati[i]<min)(min=dati[i]);  //se il valore nella cella dell'array è minore di min allora fai si che min assuma quel valore
        else(min=min);  //altrimenti lascia min uguale a se stesso
    }

    n=sqrt(N); //calcolo delle classi di frequenza

    dx=(max-min)/n; //calcolo ampiezza delle classi di frequenza
    min = min-dx/10;
    max = max+dx/10;
    
    //std e stampa
    somma=0.0;
    for(i=0; i<N; i++){
        sommatoria=pow((dati[i]-M), 2);
        somma=sommatoria+somma;
    }
    
    //Calcolo varianza, std e sua stampa
    varianza=somma/(N-1);
    std=sqrt(varianza);

    deltax=dx/10;

    a=(M-n*std); //estremo a della gaussiana
    b=(M+n*std); //estremo b della gaussiana

    for(j=0; j<n; j++){
        for(k=0; k<n; k++){
            x=min+j*dx+(k+0.5)*deltax;
            h=(1/(std*sqrt(2*3.1415))) * exp((-(pow(x-M,2)))/(2*pow(std, 2)));
            
            //ciclo for per estrarre la x tra a e b e la x tra 0 e max
            //Nygenerati indica quanti ceppie di punti x e y vogliamo generare
            for(i=0; i<Nygenerati; i++){
                if (a > b){ //if nel caso in cui a sia più grande di b
                    Nx=b+((float)rand()/(float)RAND_MAX)*(a-b);                                                     
                }    
                else if (a < b){ //if nel caso in cui b sia più grande di a
                    Nx=b+((float)rand()/(float)RAND_MAX)*(a-b);
                }
                else{ //ultimo caso in cui a e b siano uguali
                    printf("%f\n", a || b); //essendo che a e b sono uguali viene stampato il valore di una delle 2 variabili
                }

                //Calcolo Ny
                if (a > b){ //if nel caso in cui a sia più grande di b
                    Ny=((float)rand()/(float)RAND_MAX)*max;                                                  
                }    
                else if (a <= b){ //if nel caso in cui b sia più grande di a
                    Ny=((float)rand()/(float)RAND_MAX)*max;   
                }

                //Se y è minore di f(x) in questo caso h
                if (Ny <= h){
                    for (i = 0; i < Nygenerati  ; i++)cnt++;
                }

                //Calcolo Area totale
                if (a > b){ //if nel caso in cui a sia più grande di b
                    A=(a-b)*max;                                                     
                }    
                else if (a < b){ //if nel caso in cui b sia più grande di a
                    A=(b-a)*max;
                }
                else{ //ultimo caso in cui a e b siano uguali
                    A=(a || b)*max; //essendo che a e b sono uguali viene moltiplicato per max il valore di una delle 2 variabili
                }
            }
        }
    }

    //Calcolo Area totale
    if (a > b){ //if nel caso in cui a sia più grande di b
        A=(a-b)*max;                                                     
    }    
    else if (a < b){ //if nel caso in cui b sia più grande di a
        A=(b-a)*max;
    }
    else{ //ultimo caso in cui a e b siano uguali
        A=(a || b)*max; //essendo che a e b sono uguali viene moltiplicato per max il valore di una delle 2 variabili
    }

    //Calcolo area integrale
    integrale=A*cnt/Nygenerati;
    printf("\nL'area dell'integrale e': %f", integrale);
}
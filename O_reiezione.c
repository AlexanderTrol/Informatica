#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

float gauss(float g); //Funzione di gauss per il calcolo dell'altezza dei vari intervallini di un andamento gaussiano
float esp(float e);   //Funzione esponenziale che restituisce l'altezza degli intervallini di un andamento esponenziale
int main(){
    int a;
    float x;

    printf("Scegli il tipo di distribuzione:\n1-Gaussiana\n2-Esponenziale\n");
    scanf("%d", &a);
    if(a==1)gauss(x);
    if(a==2)esp(x);
}

float gauss(float g){
    int i=0, N=0, n, j=0, k=0;
    float dati[100], max=0, min, dx, M=0, somma=0, sommatoria=0, varianza=0, std=0, deltax=0, x=0, h=0, a=0, b=0, c=0;
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

    printf("Il valore di h\n");
    for(j=0; j<n; j++){
        for(k=0; k<n; k++){
            x=min+j*dx+(k+0.5)*deltax; //calcolo del punto x che sta ad indicare l'altezza della gaussiana

            //punto h in cui viene inserita la formula della distribuzione gaussiana e con il for va a formare la sua funzione
            h=(1/(std*sqrt(2*3.1415))) * exp((-(pow(x-M,2)))/(2*pow(std, 2)));
            printf("%f\n", h);

            //Questi if else stanno ad indicare se i valori randomici creati stanno sotto la curva gaussiana valori randomici creati  tra gli estremi a e b
            if (a > b){ //if nel caso in cui a sia più grande di b
                for (int i = 0; i < N; i++){
                        c=b+((float)rand()/(float)RAND_MAX)*(a-b);
                        if (c < h){
                            printf("%f\n", c);
                        }   
                }                                                      
            }    
            else if (a < b){ //if nel caso in cui b sia più grande di a
                for (int i = 0; i < N; i++){
                        c=b+((float)rand()/(float)RAND_MAX)*(a-b);
                        if (c < h){
                            printf("%f\n", c);
                        }
                }
            }
        
            else{ //ultimo caso in cui a e b siano uguali
                for (int i = 0; i < N; i++)
                {
                    if ((a || b) < h){
                        printf("%f\n", a || b);
                    }
                }
            }
        }
    }
}

float esp(float e){
    int i=0, N=0, n=0, j=0, k=0;
    float dati[100], max=0, min=0, dx=0, somma=0, deltax=0, x=0, h=0, a=0, b=0;
    FILE *fp;
    time_t t;

    srand((float) time(&t));    //funzione srand che ogni volta ceh genera un seme da cui partire che il programma viene fatto partire

    fp=fopen("datiExp.dat", "r"); //Apertura file del piano inclinato
    
    while(fscanf(fp, "%f", &dati[i]) != EOF){ //inserimento dei dati dento l'array dati[]
        somma=somma+dati[i];
        i++;  //incremento i++ per mandare avanti il ciclo
        N++;  //incremento di N per capire il numero di dati dentro il file.dat
    }
    
    i=0;  //porto il valore di i a 0
    min=dati[i];  //essendo che i indica la prima cella di dati[] la eguaglio a min cosi da dargli un valore di riferimento a cui confrontare in seguito i minimi
    for(i=0; i<N; i++){ //ciclo che serve a capire il massimo e il minimo del vettore dati[]
        if(dati[i]>max)
            max=dati[i]; //se il valore nella cella del'array è maggiore di max allora fai si che max assuma quel valore
        
        if(dati[i]<min)
            min=dati[i];  //se il valore nella cella dell'array è minore di min allora fai si che min assuma quel valore
    }

    n=sqrt(N); //calcolo delle classi di frequenza

    dx=(max-min)/n; //calcolo ampiezza delle classi di frequenza
    min = min-dx/10;
    max = max+dx/10;

    deltax=dx/10;

    h=0;
    printf("Il valore di h\n");
    for(j=0; j<n; j++){
        for(k=0; k<n; k++){
            x = min+j*dx+(k+0.5)*deltax;    //calcolo del punto x che sta ad indicare l'altezza della gaussiana
            
            if(dati[k] >= 0){   //Questi if else stanno ad indicare se i valori randomici creati stanno sotto la curva gaussiana valori randomici creati  tra gli estremi a e b
                //punto h in cui viene inserita la funzione della distribuzione esponenziale
                h = (x*(exp(-(x*dati[k]))));
            }
            else if(dati[k] < 0) h = 0;

            for (int p = 0; p < n; p++){
                a = ((float)rand()/(float)RAND_MAX) * max;
                if (a < h){  //se il punto a, generato randomicamente è più piccolo di h allora rientra dentro la gaussiana e viene generato
                    printf("%f\n", a);
                }
            }

            printf("%f\n", h);
        }
    }
}
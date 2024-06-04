#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    char cognome[20];
    int eta;
}Persona;

void inserimento(char*, char*, int*);

void inserimento(char* nome, char* cognome, int* eta){

    printf("Inserisci Nome:");
    scanf("%[^\n]%*c", nome);

    printf("Inserisci Cognome:");
    scanf("%[^\n]%*c", cognome);

    printf("Inserisci Età:");
    scanf("%d", eta);
}
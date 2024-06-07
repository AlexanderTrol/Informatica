#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    char nome[20],
         cognome[20];
    int eta;
}Persona;


typedef struct elemento{
    Persona valore;
    int dato;
    struct elemento* next;
}Nodo;

Nodo* ins_testa(Nodo* head, Persona p){
    Nodo* newElement = (Nodo*)malloc(sizeof(Nodo));

    if (newElement == NULL) {
        printf("Errore: malloc ha fallito\n");
        exit(1);
    }

    newElement -> valore = p;
    newElement -> next = head;
    head = newElement;

    return newElement;
}

Nodo* ins_elemento(Nodo* head, int dati){
    Nodo* newElement = (Nodo*)malloc(sizeof(Nodo));

    if (newElement == NULL) {
        printf("Errore: malloc ha fallito\n");
        exit(1);
    }

    newElement -> dato = dati;
    newElement -> next = head;
    head = newElement;

    return newElement;
}

Nodo* ins_coda(Nodo* head, int dati){
    Nodo* newElement = (Nodo*)malloc(sizeof(Nodo));

    if (newElement == NULL){
        printf("Errore: malloc ha fallito\n");
        exit(1);
    }

    if (newElement->next == NULL){
        newElement->next = ins_elemento(head, dati);
        newElement->next = head;
        head = newElement;

        return head;
    }    
}

void stampa_lista(Nodo* head){
    while (head != NULL){
        printf("Nome: %s\nCognome: %s\nEtà: %d\n", head->valore.nome, head->valore.cognome, head->valore.eta);
        head = head->next;
    }
}

void stampa_nodi(Nodo* head){
    Nodo* precedente = NULL;
    while (head != NULL){
        precedente = head;
        printf("Dato: %d\n", precedente->dato);
        head = head->next;
        
    }

    
    
}
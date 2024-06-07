#include "liste_semplici.h"

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "it_IT.UTF-8");

    Nodo* head = NULL;
    Persona p;
    int i = 0;

    for (i = 0; i < 3; i++){

        printf("Inserisci il nome: ");
        scanf("%s", p.nome);
        fflush(stdin);

        printf("Inserisci il cognome: ");
        scanf("%s", p.cognome);
        fflush(stdin);

        printf("Inserisci l'età: ");
        scanf("%d", &p.eta);

        head = ins_testa(head, p);
    }

    stampa_lista(head);
     
    return 0;
}
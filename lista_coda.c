#include "liste_semplici.h"

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "it_IT.UTF-8");

    Nodo* tail = NULL;
    Nodo* head = NULL;
    Persona p;

    head = ins_elemento(head, 10);
    head = ins_elemento(head, 26);
    head = ins_elemento(head, 18);
    

    stampa_nodi(head);

    return 0;
}
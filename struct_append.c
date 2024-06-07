#include <stdio.h>
#include <locale.h>
#include "struct.h"

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "it_IT.UTF-8");

    FILE* fp;
    Persona p;

    fp = fopen("struct_append.txt", "a");
    
    inserimento(p.nome, p.cognome, &p.eta);

    fprintf(fp, "\nNome: %s\nCognome: %s\nEtà: %d", p.nome, p.cognome, p.eta);

    fclose(fp);
    return 0;
}
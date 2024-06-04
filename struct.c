#include <stdio.h>
#include <locale.h>
#include "struct.h"

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "it_IT.UTF-8");

    FILE* fp;
    Persona p;

    fp = fopen("struct.txt", "w");
    
    inserimento(p.nome, p.cognome, &p.eta);

    fprintf(fp, "Nome: %s\nCognome: %s\nEtà: %d\n", p.nome, p.cognome, p.eta);

    fclose(fp);
    return 0;
}

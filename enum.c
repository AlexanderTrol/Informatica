#include <stdio.h>
typedef enum {
    GENNAIO,
    FEBBRAIO,
    MARZO,
    APRILE,
    MAGGIO,
    GIUGNO,
    LUGLIO,
    AGOSTO,
    SETTEMBRE,
    OTTOBRE,
    NOVEMBRE,
    DICEMBRE
} Mesi;

int a;

void *fun() {
    return &a;
}

int main(int argc, char const *argv[]) {
    int *b;

    b = (int *)fun();

    printf("%p", b);
    printf("\n%p", &a);

    return 0;
}

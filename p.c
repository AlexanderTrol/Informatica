#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int* x;
    int i = 0;

    x = (int*)malloc(5 * sizeof(int));

    for (i = 0; i < 5; i++)
        *(x + i) = i;

    for (i = 0; i < 5; i++)
        printf("%d ", *(x + i));

    for (i = 0; i < 5; i++)
        printf("%d ", (x + i));

    for (i = 0; i < 5; i++)
        printf("%p ", *(x + i));

    for (i = 0; i < 5; i++)
        printf("%p ", (&x + i));

    free(x);
}
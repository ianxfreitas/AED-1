#include <stdio.h>
#include <math.h>

int main () {
    int i;

    printf("--FOR--\n");
    for (i = 1; i <= 100; i++) {
        printf("%d\n", i);
    }

    printf("--WHILE--\n");
    i = 1;
    while (i <= 100){
        printf("%d\n", i);
        i++;
    }

    printf("--DO WHILE--\n");
    i = 1;
    do {
       printf("%d\n", i);
       i++;
    } while (i <= 100);

    return 0;
}
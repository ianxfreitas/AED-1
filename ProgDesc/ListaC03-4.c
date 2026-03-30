#include <stdio.h>

int main () {
    int i = 0;
    
    printf("--FOR--\n");
    for (i; i <= 100000; i++){
        i += 1000;
        printf("%d\n", i);
        i = i - 1;
    }
    
    printf("--WHILE--\n");
    int numero = 0;
    while (numero <= 100000){
        printf("%d\n", numero);
        numero += 1000;
    }

    return 0;
}
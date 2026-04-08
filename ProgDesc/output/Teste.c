#include <stdio.h>
#include <stdlib.h>

int main() {
    int n[5];
    int *p = n;

    for (int i = 0; i < 5; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", p);
        p++;
    }

    p = n;

    for (int i = 0; i < 5; i++){
        printf("O array: %d\n", *p);
        p++;
    }
}
#include <stdio.h>
#include <stdlib.h>

void inteiro(int *n, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d\n", *n);
        n++;
    }
}

int main () {
    int *p;
    int n[5];

    for(int i = 0 ; i < 5; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &n[i]);
    }

    inteiro(n, 5);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int inteiro(int *n, int tamanho){
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += *n;
        n++;
    }
    return soma;
}

int main () {
    int n[5];

    for(int i = 0 ; i < 5; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &n[i]);
    }

    printf("A soma eh %d\n", inteiro(n, 5));
    return 0;
}
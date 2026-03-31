#include <stdio.h>

int main () {
    int i, valor, soma = 0;
    float media;

    for (i = 1; i<=10; i++){
        printf("Digite o %d numero inteiro : ", i);
        scanf("%d", &valor);
        soma =+ valor;
    }

    media = soma / 10;

    printf("\nMedia: %.2f\n", media);

    return 0;
}
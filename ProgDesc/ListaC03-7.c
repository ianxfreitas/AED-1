#include <stdio.h>

int main() {
    int valor, soma = 0, contador = 0;
    float media;

    while (contador < 10){
        printf("Digite o valor %d: ", contador + 1);
        scanf("%d", &valor);

        if ( valor > 0){
            soma += valor;
            contador++;
        } else {
            printf("erro, Digite um numero positivo\n");
        }
    }

    media = soma / 10;

    printf("\nMedia: %.2f\n", media);

    return 0;
}
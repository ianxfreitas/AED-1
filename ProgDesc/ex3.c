/*Leia números até o usuário digitar 0, e mostre a soma*/

#include <stdio.h>

int main() {
    int numero = 0, soma = 0, valor = 1;

    do {
        printf("Digite o %d numero: ", valor);
        scanf("%d", &numero);
        
        soma += numero;
        valor++;

    } while(numero != 0);

    printf("A soma dos numeros fornecidos eh: %d", soma);

    return 0;
}
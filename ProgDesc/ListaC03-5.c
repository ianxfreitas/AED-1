#include <stdio.h>

int main() {
    int i, valor, soma = 0;

    for (i = 1; i <= 10; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &valor);
        soma += valor;
    }

    printf("\nSoma total: %d\n", soma);

    return 0;
}
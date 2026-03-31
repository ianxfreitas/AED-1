#include <stdio.h>

int main() {
    int numero;

    for (int i = 1; i <= 10 ; i++){
        printf("Digite o %d numero: ", i);
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            printf("%d eh par\n", numero);
        }
    }
}
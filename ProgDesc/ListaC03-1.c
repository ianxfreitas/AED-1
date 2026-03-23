/*Faca um programa que determine o mostre os cinco primeiros multiplos de 3, considerando numeros maiores que 0.*/

#include <stdio.h>

int main() {
    int i;

    printf("Os 5 primeiros múltiplos de 3 (maiores que 0) são:\n");
    printf("--------------------------------------------------\n");

    // O laço vai de 1 até 5
    for (i = 1; i <= 5; i++) {
        // Multiplica o índice 'i' por 3 para encontrar o múltiplo
        printf("%d\n", i * 3);
    }

    return 0;
}
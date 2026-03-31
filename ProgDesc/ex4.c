/*Mostre a tabuada de um número digitado pelo usuário*/

#include <stdio.h>

int main () {
    int numero;
    
    printf("Digite um numero de 1 a 10: ");
    scanf("%d", &numero);

    printf("--- TABUADA DO %d ---\n", numero);

    for (int i = 1; i <= 10; i++){
        int resultado = numero * i;

        printf("%d x %d = %d\n", numero, i, resultado);
    }
    return 0;
}
/*Crie uma função que calcula o fatorial de um número*/
#include <stdio.h>

long int fatorial(int n){
    long int resultado = 1;

    for (int i = 1; i <= n; i++){
        resultado *= i;
    }

    return resultado;
}

int main() {
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    printf("fatorial de %d = %ld\n", n, fatorial(n));
}
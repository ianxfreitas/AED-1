/*Crie uma função que recebe um número e retorna a soma dos seus dígitos*/

#include <stdio.h>

int somaDigitos(int n){
    int soma = 0;

    while (n > 0){
        soma += n % 10;
        n = n / 10;
    }

    return soma;
}

int main(){
    int n;

    printf("Digite um valor inteiro: ");
    scanf("%d", &n);

    printf("o valor de %d = %ld", n, somaDigitos(n));

    return 0;
}
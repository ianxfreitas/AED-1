/*Ler um numero inteiro. Se o numero lido for negativo, escreva a mensagem “Numero
invalido”. Se o numero for positivo, calcular o logaritmo deste numero.*/
#include <stdio.h>
#include <math.h>

int main () {
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    double ln = log2(n);

    if ( n < 0) {
        printf("Numero invalido!");
    } else {
        printf("O logaritmo desse numero eh: %f\n", ln);
    }

    return 0;
}
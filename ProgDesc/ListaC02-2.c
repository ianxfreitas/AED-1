/*Leia um numero fornecido pelo usuario. Se esse numero for positivo, calcule a raiz
quadrada do numero. Se o numero for negativo, mostre uma mensagem dizendo que o
numero e invalido.*/

#include <stdio.h>
#include <math.h>

int main() {
    double n, raiz;

    printf("Digite um numero inteiro: ");
    scanf("%lf", &n);

    raiz = sqrt(n);

    if ( n >= 0){
        printf("%.2lf", raiz);
    } else {
        printf("Valor invalido");
    }
    return 0;
}
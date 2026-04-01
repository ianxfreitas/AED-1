/*Crie uma função recursiva que calcula o fatorial*/
#include <stdio.h>

long int fatorial(int n){
    if ( n >= 1) 
        return n * fatorial(n - 1);
    else 
        return 1;
}

int main() {
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    printf("fatorial de %d = %ld", n, fatorial(n));
}
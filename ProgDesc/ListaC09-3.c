/*Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do
teclado. Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.*/

#include <stdio.h>

int main() {
    int n1, n2;

    int* ptr_n1;
    int* ptr_n2;

    ptr_n1 = &n1;
    ptr_n2 = &n2;

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", ptr_n1);

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", ptr_n2);

    if (ptr_n1 > ptr_n2){
        printf("O endereço de n1(%p) eh maior que o de n2(%p)\n", ptr_n1, ptr_n2);
        printf("O conteudo de n1: %d", *ptr_n1);
    } else {
        printf("O endereço de n2(%p) eh maior que o de n1(%p)\n", ptr_n2, ptr_n1);
        printf("O conteudo de n2: %d", *ptr_n2);
    }

    return 0;
}
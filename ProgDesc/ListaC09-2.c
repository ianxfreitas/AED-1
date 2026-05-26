/*Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec¸os e
exiba o maior enderec¸o.*/

#include <stdio.h>

int main() {
    int n1 = 10, n2 = 100;
    int* ptr_n1;
    int* ptr_n2;
    ptr_n1 = &n1;
    ptr_n2 = &n2;

    if (ptr_n1 > ptr_n2) {
        printf("O endereco de n1 (%p) eh maior que o de n2 (%p)\n", ptr_n1, ptr_n2);
    } else {
        printf("O endereco de n2 (%p) eh maior que o de n1 (%p)\n", ptr_n2, ptr_n1);
    }

    return 0;
}
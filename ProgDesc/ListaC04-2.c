/*crie um programa que le 6 valores inteiros e, em seguida, mostre na tela os valores lidos.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int valores[6];
    int i;

    for(i = 0; i < 6; i++){
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valores[i]);
    }

    printf("Os valores lidos sao: ");
    for(i = 0; i < 6; i++){
        printf("%d ", valores[i]);
    }
    printf("\n");

    return 0;
}
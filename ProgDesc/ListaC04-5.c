/*Leia um vetor de 10 posicoes. Contar e escrever quantos valores pares ele possui.*/

#include <stdio.h>

int main(){
    int v[10];
    int i;
    int pares = 0;

    for (i = 0; i < 10; i++){
        printf("Digite a posicao %d do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }

    for(i = 0; i < 10; i++){
        if ( v[i] % 2 == 0 ){
            printf("%d ", v[i]);
            pares++;
        }
    }
    printf("\n");

    printf("O vetor tem %d valores pares", pares);
    return 0;
}
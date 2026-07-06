/*Escreva um programa em C que:

Declare um vetor de 6 inteiros com valores à sua escolha
Percorra o vetor e encontre o maior valor
Imprima esse maior valor no final*/

#include <stdio.h>
#include <string.h>

int main() {
    int vetor[6] = {1,3,5,7,4,2};
    int maiorAteAgora = vetor[0];

    for (int i = 0; i < 6; i++) {
        if ( vetor[i] > maiorAteAgora){
            maiorAteAgora = vetor[i];
        }
    }

    printf("O maior valor do vetor é %d", maiorAteAgora);
    
    return 0;
}

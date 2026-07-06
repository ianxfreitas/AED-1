/*Declare um vetor de 8 inteiros com valores à sua escolha (inclua pelo menos um número repetido)
Percorra o vetor e conte quantas vezes o maior valor aparece nele
Imprima o maior valor e a quantidade de vezes que ele aparece*/

#include <stdio.h>

int main() {
    int vetor[8] = {1,9,5,7,9,2,9,6};
    int resultado = vetor[0];
    int count = 0;

    for ( int i = 0; i < 8; i++ ){
        if(vetor[i] >= resultado){
            resultado = vetor[i];
        }
    }

    for ( int i = 0; i < 8; i++ ){
        if (vetor[i] == resultado){
            count++;
        }
    }

    printf("O maior valor eh: %d\n", resultado);
    printf("O %d apareceu %d vezes\n", resultado, count);

    return 0;
}
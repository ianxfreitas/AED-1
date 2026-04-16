/*Ler um conjunto de numeros reais, armazenando-o em vetor e calcular o quadrado das
componentes deste vetor, armazenando o resultado em outro vetor. Os conjuntos tem
10 elementos cada. Imprimir todos os conjuntos.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float reais[10], resultado[10];

    for(int i = 0; i < 10; i++){
    printf("Digite o %d numero real: ", i + 1);
    scanf("%f", &reais[i]);
    }

    for(int i = 0; i < 10; i++){
        printf("%.2f ", reais[i]);
    }
    printf("\n");

    for(int i = 0; i < 10; i++){
    resultado[i] = reais[i] * reais[i];
    printf("%.2f", resultado[i]);
    }
}
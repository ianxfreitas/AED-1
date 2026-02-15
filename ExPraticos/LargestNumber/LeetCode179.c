#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica(int a, int b) {
    char s1[50]; 
    char s2[50];
    
    sprintf(s1, "%d%d", a, b);
    sprintf(s2, "%d%d", b, a);
    
    return strcmp(s1, s2);
}


void quick(int* vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = vetor[fim];
        int i = inicio - 1;
        int j;
        
        for (j = inicio; j < fim; j++) {
            // aqui chamo minha função verifica pra ordenar de forma que
            // a combinação maior fique na frente
            if (verifica(vetor[j], pivo) > 0) {
                i++;
                // fiz a troca manual aqui mesmo sem criar outra função
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
        
        // coloco o pivo no lugar certo
        int aux2 = vetor[i + 1];
        vetor[i + 1] = vetor[fim];
        vetor[fim] = aux2;
        
        // chamo recursivo pras duas metades
        quick(vetor, inicio, i);
        quick(vetor, i + 2, fim);
    }
}

char* largestNumber(int* nums, int numsSize) {
    quick(nums, 0, numsSize - 1);
    
    if (nums[0] == 0) {
        char* res0 = (char*)malloc(2);
        strcpy(res0, "0");
        return res0;
    }
    
    // aloquei um tamanho fixo grande pra garantir que não falte memória
    char* resposta = (char*)malloc(numsSize * 20 * sizeof(char));
    resposta[0] = '\0'; 
    
    char buff[30];
    int k;
    // aqui vou concatenando todos os números já ordenados
    for (k = 0; k < numsSize; k++) {
        sprintf(buff, "%d", nums[k]);
        strcat(resposta, buff);
    }
    
    return resposta;
}

int main() {
    int nums[] = {10, 2};
    int tamanho = 2;

    printf("Entrada: [ 10 2 ]\n");

    char* resultado = largestNumber(nums, tamanho);
    printf("Saida: %s\n", resultado);

    free(resultado); 
    
    getchar(); 

    return 0;
}
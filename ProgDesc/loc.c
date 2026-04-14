#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &numero);

    int *p = malloc( numero * sizeof(int));
    int *inicio = p;

    for ( int i = 0; i < numero; i++){
        printf("Digite o %d valor: ", i + 1);
        scanf("%d", p);
        p++;
    }

    p = inicio;

    for (int i = 0; i < numero; i++){
        printf("%d ", *p);
        p++;
    }
    free(inicio);

    return 0;
}
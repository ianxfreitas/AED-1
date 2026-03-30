/*Escreva o menu de opc¸ ˜oes abaixo. Leia a opc¸ ˜ao do usu ´ario e execute a operac¸ ˜ao esco-
lhida. Escreva uma mensagem de erro se a opc¸ ˜ao for inv ´alida.
Escolha a op¸c~ao:
1- Soma de 2 n´umeros.
2- Diferen¸ca entre 2 n´umeros (maior pelo menor).
3- Produto entre 2 n´umeros.
4- Divis~ao entre 2 n´umeros (o denominador n~ao pode ser zero).
Op¸c~a*/

#include <stdio.h>

int main () {
    int opcao;
    
    printf("1 - Soma de 2 numeros:\n");
    printf("2 - Diferenca entre 2 numeros(maior pelo menor)\n");
    printf("3 - Produto entre 2 numeros\n");
    printf("4 - Divisao entre 2 numeros ( o denominador nao pode ser zero)\n");
    printf("Opcao: \n");
    scanf("%d", &opcao);

    switch (opcao){
        case 1:
        printf("A soma de 2 numeros eh n + n");
        break;

        case 2:
        printf("A diferenca entre 2 numero eh n / n");
        break;

        case 3:
        printf("O produto entre 2 numero eh n * n");
        break;

        case 4:
        printf("A divisao entre 2 numero n0 / n1 (onde n1 tem que ser diferente de 0)");
        break;

        default:
        printf("Opcao invalida, escolha uma das operacoes disponiveis");
        break;
    }

    return 0;
}
#include <stdio.h>

int main() {
    int value;

    printf("Digite um numero inteiro: ");
    scanf("%d", &value);

    if ( value % 2 == 0 ){
        printf("%d eh par.\n", value);
    } else {
        printf("%d eh impar.\n", value);
    }

    return 0;
}
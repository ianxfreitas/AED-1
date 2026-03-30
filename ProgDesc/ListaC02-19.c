    /*Faca um programa para verificar se um determinado numero inteiro e divisıvel por 3 ou
    5, mas nao simultaneamente pelos dois.*/

    #include <stdio.h>

    int main () {
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    if ((n % 3 == 0) ^ (n % 5 == 0)) {
        printf("O numero %d e divisivel por 3 ou por 5, mas nao simultaneamente.\n", n);
    } 
    else if ((n % 3 == 0) && (n % 5 == 0)) {
        printf("O numero %d e divisivel por 3 e 5 simultaneamente (invalido).\n", n);
    } 
    else {
        printf("O numero %d nao e divisivel por 3 nem por 5.\n", n);
    }

    return 0;
}
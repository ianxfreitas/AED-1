/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro,
real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de
cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a
modificacao*/

#include <stdio.h>
#include <string.h>

int main(){
    int inteiro = 10;
    float real = 1.12;
    char xar = 'A';

    int* ptr_inteiro;
    float* ptr_real;
    char* ptr_xar;

    ptr_inteiro = &inteiro;
    ptr_real = &real;
    ptr_xar = &xar;
    
    printf("Valores originais\n");
    printf("inteiro: %d\n", inteiro);
    printf("real: %.2f\n", real);
    printf("xar: %c\n\n", xar);

    *ptr_inteiro = 67;
    *ptr_real = 3.14;
    *ptr_xar = 'Z';

    printf("Valores atualizados\n");
    printf("inteiro: %d\n", inteiro);
    printf("real: %.2f\n", real);
    printf("xar: %c\n\n", xar);

    return 0;
}
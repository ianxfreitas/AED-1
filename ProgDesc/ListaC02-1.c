/*Faca um programa que receba dois numeros e mostre qual deles eh o maior.*/
#include <stdio.h>

int main() {
  int num1, num2;

  printf("Digite o primeiro numero inteiro: ");
  scanf("%d", &num1);

  printf("Digite o segundo numero inteiro: ");
  scanf("%d", &num2);

  if (num1 > num2){
    printf("O %d eh maior que %d", num1, num2);
  } if (num1 == num2) {
    printf("O %d e %d sao o mesmo numero", num2, num1);
  } else {
    printf("O %d eh maior que %d", num2, num1);
  }
  return 0;
}

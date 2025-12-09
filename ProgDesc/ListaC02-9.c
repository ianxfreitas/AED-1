/*. Leia o salario de um trabalhador e o valor da prestacao de um emprestimo. Se a
prestacao for maior que 20% do salario imprima: Emprestimo nao concedido, caso
contrario imprima: Emprestimo concedido.
*/

#include <stdio.h>

int main () {
    float salario, prestacao;

    printf("Digite o seu salario: ");
    scanf("%f", &salario);

    printf("Digite o valor da prestacao: ");
    scanf("%f", &prestacao);

    float limite = salario * 0.20;

    if (prestacao <= limite) {
        printf("Emprestimo concedido!");
    } else {
        printf("Emprestimo nao concedido!");
    }

    return 0;
}

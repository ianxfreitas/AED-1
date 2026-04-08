#include <stdio.h>
#include <string.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
    float altura;
}Pessoa;

int main(){ 
    Pessoa p;
    Pessoa *ptr = &p;

    printf("Digite seu nome: ");
    scanf("%s",p.nome);

    printf("Digite sua idade: ");
    scanf("%d",&p.idade);
    
    printf("Digite sua altura em cm: ");
    scanf("%f",&p.altura);

    printf("%s, %d anos, %.0f cm", ptr->nome, ptr->idade, ptr->altura);

    return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    int idade;
    char nome[50];
}Pessoa;

int main(){
    int cadastro;
    
    printf("Quantas pessoas voce deseja cadastrar? ");
    scanf("%d", &cadastro);

    Pessoa *p = malloc( cadastro * sizeof(Pessoa));

    for ( int i = 0; i < cadastro; i++){
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", p[i].nome);
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &p[i].idade);
    }

    for (int i = 0; i < cadastro; i++){
        printf("%s tem %d anos\n", p[i].nome, p[i].idade);
    }
    free(p);
    return 0;
}   
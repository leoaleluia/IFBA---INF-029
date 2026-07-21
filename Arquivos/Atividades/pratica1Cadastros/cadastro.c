#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

typedef struct cadastro{
    int kay;
    char nome[TAM];
    struct cadastro *prox;
}cadastro;

cadastro *novoNo(int num, char nome[TAM]){
    cadastro *novo = (cadastro*) malloc(sizeof(cadastro));
    novo->prox = NULL;
    strcpy(novo->nome, nome);
    novo->kay = num;
    return novo;

}

void inserirInicio(cadastro **lista, int num, char nome[TAM]){
    cadastro *novo;
    novo = novoNo(num, nome);

    if(*lista == NULL){
        *lista = novo;
    }else{
        novo->prox = *lista;
        *lista = novo;
    }
}


int main(){
    int res = 0;
    int num = 0;
    char nome[20];
    cadastro *listaTeste = NULL;
    FILE *teste;
    teste = fopen("cadastro.txt", "a+");

    printf("Deseja adicionar algum nome?");
    scanf("%d", &res);
    while(res != 0){
        printf("Digite seu nome");
        scanf("%s", nome);

        printf("Digite sua chave");
        scanf("%d", &num);

        inserirInicio(&listaTeste, num, nome);

        printf("Deseja inserir mais?");
        scanf("%d", &res);

    }
    cadastro *atual = listaTeste;
    while(atual != NULL){
        fprintf(teste, "%d -- %s\n", atual->kay, atual->nome);
        atual = atual->prox;
    }
    fclose(teste    );

}
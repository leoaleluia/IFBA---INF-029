#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No *prox;
}No;


No* criarNo(int num){

}

void imprimirComNo(No *lista){
    
    No *atual = lista->prox;

    while(atual != NULL){
        printf("%d", atual->num);
        atual = atual->prox;
    }
}

void inserirComCabecote(No *lista, int num){
    No *novo;
    novo = criarNo(num);

    novo->prox = lista->prox;
    lista->prox = novo;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *prox;
} no;


no* criaNo(int valor){
    no *novo = (no *) malloc(sizeof (no));
    if(novo == NULL){
        printf("Erro na alocação");
        exit(1);
    }
    novo->num = valor;
    novo->prox = NULL;
}

void inserirInicio(no **lista, int num){
    no *novo;
    novo = criaNo(num);
    novo->prox = *lista;
    *lista = novo;

}

void inserirFim(no **lista, int num){
    no *novo;
    novo = criaNo(num);
    if (*lista == NULL){
        *lista = novo;
    }

    no *item = *lista;
    while (item->prox != NULL){
        item->prox;
    }

    item->prox = novo;
    
    return *lista;
}

void inserirMeio(no **lista, int num, int pos){
    no *novo;
    novo = criaNo(num);
    
    if(*lista == NULL && pos == 0){
        *lista = novo;
    }

    no *item = *lista;

    for(int i = 0; i < pos - 1 && item->prox != NULL; i++){
        item = item->prox;
    }

    novo->prox = item->prox;
    item->prox = novo;

    return *lista;

}


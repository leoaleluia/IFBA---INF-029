#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No *prox;

}No;

No* criarNo(int num){
    No *novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        printf("Memória não alocada");
        exit(1);
    }
    novo->num = num;
    novo->prox = NULL;
    
    return novo;
}

void inserirNoInicio(No **lista, int num){
    No *novo;
    novo = criarNo(num);

    novo->prox = *lista;
    *lista = novo;
}

void imprimir(No *lista){
    No *nLista;
    nLista = lista;

    for(No *i = lista; i != NULL; i = i->prox){
        printf("%d", i->num);
    }
}

void inserirMeio(No **lista, int num){
    No *novo;
    novo = criarNo(num);
    No *i = *lista;
    if(*lista == NULL){
        *lista = novo;

    }else if((*lista)->prox > num){
        novo->prox = *lista;
        *lista = novo;
    }else{
        while(i->prox != NULL && i->prox->num < num){
            i = i->prox;
        }
    }

    novo->prox = i->prox;
    i->prox = novo;
}
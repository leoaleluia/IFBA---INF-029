#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *prox;
    struct no *ant;
}no;

no* criaElemento(int num){
    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL){
        printf("Memória não alocada");
        exit(1);
    }

    novo->num = num;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void inserirNoInicioSemCabecote(no **inicio, int num){
    no *novo;
    novo = criaElemento(num); 
    //o novo no aponta para onde a lista começava (no exemplo 10)
    novo->prox = *inicio;
    //o novo apaonta para null
    novo->ant = NULL;

    //se a lista não estiver vazia apontamos para o anterior, ou seja, o 10 ta apontando para o 20
    if(*inicio != NULL){
        (*inicio)->ant = novo;
    }
    //inicioo agora é o 20 que ja está apontando para o 10 na linha 27  
    *inicio = novo;
}


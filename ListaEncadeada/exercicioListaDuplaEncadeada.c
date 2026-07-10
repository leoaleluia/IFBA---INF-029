#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int num;
    struct no *prox;
    struct no *ant;
}no;

no *criarNo(int num){
    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }

    novo->num = num;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void listarTrazPraFrente(no *lista){
    if(lista == NULL){
        printf("Lista vazia");
    }

    no *i = lista;
    //Levamos o I ate o ultimo elemnto  da lista, apontando ele mesmo para o proximo
    while(i != NULL){
        i = i->prox;
    }

    //iniciamos o retorno do ultimo elemento, ou seja, o I do laço acima, porem vamos decrementar atras do ant
    for(no *j = i; j != NULL; j = j->ant){
        printf("%d", j->num);
    }

}

    void inserirNoFinal(no **lista, int num){
        no *novo;
        novo = criarNo(num);

        if(*lista == NULL){
            *lista = novo;
        }else{
            no *i = *lista;
            while(i->prox != NULL){
                i = i->prox;
            }
            i->prox = novo;
            novo->ant = i;
        }
        
    }

    void inserirInicio(no **lista, int num){
        no *novo;
        novo = criarNo(num);

        novo->prox = *lista;
        novo->ant = NULL;
        if(*lista = NULL){
            (*lista)->ant = NULL;
        }
        *lista = novo;

    }


    void inserirMeio(no **lista, int num){
        no *novo;
        novo = criarNo(num);

        if((*lista)->num > num){
            novo->prox = *lista;
            novo->ant = NULL;
            (*lista)->ant = novo;
            *lista = novo; 
        }
        no *i;
        i = *lista;
        while(i->prox !=NULL && i->prox->num < num){
            i = i->prox;
        }
        novo->prox = i->prox;
        novo->ant = i;
        i->prox = novo;
    }
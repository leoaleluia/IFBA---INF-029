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

    }else if((*lista)->num > num){
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

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no *prox;
} No;

// Retorna 1 se removeu com sucesso, ou 0 se o número não existia
int removerSemCabecote(No **lista, int valorALimpar) {
    
    // Se a lista estiver completamente vazia, não há o que remover
    if (*lista == NULL) {
        return 0; 
    }

    No *noParaDeletar = NULL;

    // -------------------------------------------------------------
    // CASO ESPECIAL: O número a ser removido está no PRIMEIRO nó
    // -------------------------------------------------------------
    if ((*lista)->num == valorALimpar) {
        noParaDeletar = *lista;     // Guarda o endereço do primeiro nó
        *lista = (*lista)->prox;    // O início da lista passa a ser o SEGUNDO nó
        free(noParaDeletar);        // Apaga o primeiro nó antigo da memória
        return 1;                   // Sucesso!
    }

    // -------------------------------------------------------------
    // CASO GERAL: O número está no meio ou no fim da lista
    // -------------------------------------------------------------
    No *i = *lista; // Ponteiro auxiliar para caminhar pela lista

    // Procuramos o nó ANTERIOR ao que queremos deletar.
    // O loop continua enquanto houver um próximo nó E ele não for o alvo.
    while (i->prox != NULL && i->prox->num != valorALimpar) {
        i = i->prox; // Avança o ponteiro auxiliar
    }

    // Se saímos do loop porque i->prox virou NULL, o número não foi encontrado
    if (i->prox == NULL) {
        return 0; 
    }

    // Se encontramos, significa que 'i->prox' é o cara que vai sumir!
    noParaDeletar = i->prox; 

    // A MÁGICA DA COSTURA:
    // O nó 'i' (anterior) pula o 'noParaDeletar' e aponta direto para o próximo dele.
    i->prox = noParaDeletar->prox;

    // Agora que a lista está costurada e segura, libertamos a memória do nó
    free(noParaDeletar);

    return 1; // Sucesso!
}
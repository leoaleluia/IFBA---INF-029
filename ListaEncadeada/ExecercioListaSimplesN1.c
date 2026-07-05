#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int num;
    struct no *prox;
}no;

no* criarNo(int valor){
    no *novo = (no *) malloc(sizeof(no));
    if(novo == NULL){
        printf("Memória não alocada");
        exit(1);
    }
    novo->num = valor;
    novo->prox = NULL;
    return novo;
}

int contarItem(no *lista){
    int cont = 0;
    for(no *i = lista; i != NULL; i = i->prox){
        cont++;
    }
    return cont;
}

void buscaNum(no *lista, int num){
    for(no *i = lista; i != NULL; i = i->prox){
        if(i->num == num){
            return i->num;
        }
    }
    return NULL;
}

void inserirNoInicio(no **lista, int num){
    no *novo;
    novo = criarNo(num);

    novo->prox = *lista;
    *lista = novo;

}

void excluirElementoSimples(No **lista, int valorParaRemover) {
    // Caso base: Se a lista estiver vazia, não há o que excluir
    if (*lista == NULL) {
        return;
    }

    // ========================================================
    // CASO ESPECIAL: O elemento a ser removido é o PRIMEIRO
    // ========================================================
    if ((*lista)->conteudo == valorParaRemover) {
        No *aux = *lista;       // 1. Guarda o endereço do primeiro nó
        *lista = (*lista)->prox; // 2. O início da main pula para o segundo nó
        free(aux);              // 3. Apaga o antigo primeiro da memória
        return;                 // Fim da função
    }

    // ========================================================
    // CASO GERAL: O elemento está no meio ou no fim da lista
    // ========================================================
    no *anterior = *lista; // Ponteiro que fica uma casa atrás

    // O laço 'for' começa a partir do SEGUNDO nó (anterior->prox)
    for (no *i = anterior->prox; i != NULL; i = i->prox) {
        
        // Encontramos o nó com o valor procurado!
        if (i->num == valorParaRemover) {
            
            // A PONTE SE REFAZ: O nó de trás (anterior) pula o nó atual (i)
            // e aponta direto para o próximo (i->prox)
            anterior->prox = i->prox;
            
            free(i); // Agora o nó atual pode ser apagado com segurança
            return;  // Missão cumprida, encerra a função
        }
        // Se não achou ainda, o 'anterior' dá um passo para a frente
        // para continuar colado na traseira do navegador 'i'
        anterior = i;
    }
}
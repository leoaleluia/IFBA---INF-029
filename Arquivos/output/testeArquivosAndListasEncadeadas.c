#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct No{
    int num;
    struct No *prox;
}No;

No *novoNo(int num){
    No *novo = (No*) malloc(sizeof(No));
    novo->num = num;
    novo->prox = NULL;
}

void inserirInicio(No **listaTeste, int num){
    No *novo = (No*) malloc(sizeof(No));
    novo = novoNo(num);
    novo->prox = *listaTeste;
    *listaTeste = novo;
    return novo;
}

/*

int main(){
    FILE *teste;
    teste = fopen("testeConListaEncadeada.txt", "w");
    if(teste == NULL){
        printf("Lista com erro");
        system("pause");
    }

    No *lista = NULL;
    inserirInicio(&lista, 30);
    inserirInicio(&lista, 23);
    No *atual = lista;

    while(atual != NULL){
        fprintf(teste, "%d\n", atual->prox);
        atual = atual->prox;
    }
    fclose(teste);
    return 0;
}
*/
int main(){
    FILE *teste;
    teste = fopen("testeConListaEncadeada.txt", "w");
    if(teste == NULL){
        printf("Erro ao abrir o arquivo");
        return 1; // Encerra o programa se der erro no arquivo
    }

    // CORREÇÃO 1: Começa com NULL (sem o malloc que cria nó fantasma)
    No *lista = NULL; 
    
    inserirInicio(&lista, 3);
   

    No *atual = lista;
    
    // CORREÇÃO 2: Olha para o nó atual, garantindo que lê até o último
    while(atual != NULL){
        // CORREÇÃO 3: Grava o 'num' (inteiro) e não o 'prox' (ponteiro)
        fprintf(teste, "%d\n", atual->num); 
        
        atual = atual->prox; // Avança para o próximo
    }
    
    fclose(teste);
    printf("Arquivo gravado com sucesso!\n");
    return 0;
}

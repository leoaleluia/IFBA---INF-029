#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 50 

int main(){
    /*int **vet = (int *) malloc (3 * sizeof(int));
    for(int i = 0; i < 3; i++){
        vet[i] = NULL;
    }*/

    int *vet[3];
    int tam;
    int num;
    int pos; int iCont;

    for(int i = 0; i < 3; i++){
        vet[i] = NULL;
    }

    for(int i = 0; i < 2; i++){
        printf("Digite o tamanho do vet adicionado na pos %d", i);
        scanf("%d", &tam);
        vet[i] = (int*) malloc(tam * sizeof(int));
        for(int j = 0; j < tam; j++){
            printf("Digite o valor adicionado na pos %d do vetor", j);
            scanf("%d", &num);
            vet[i][j] = num;
        }
    }
   

    for(int i = 0; i < 3; i++){
        if(vet[i] == NULL){
            printf("Gaveta vazia");
            free(vet[i]);
        }
    }
}
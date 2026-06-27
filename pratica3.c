#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int *vet = (int *) malloc (3 * sizeof(int));
    vet[0] = 10;
    vet[1] = 20;
    vet[2] = 30;
    int qtd = 3;
    int num = 0;

    printf("Digite um número para excluir");
    scanf("%d", &num);
    for(int i = 0; i < 3; i++){
        if(vet[i] == num){
            for(int j = i; j < qtd - 1; j++){
                vet[j] = vet[j+1];
            }
            qtd--;
        }
    }  
    for(int i = 0; i < qtd; i++){
        printf("%d\n", vet[i]);
    }
    free(vet);
}
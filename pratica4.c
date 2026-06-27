#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int num;
    int *vet = (int*) malloc(4 * sizeof(int));
    int *vetCopia = (int*) malloc(4 * sizeof(int));
    int numMenor = 0;
    int qtd = 0;
    printf("digite os números");
    for(int i = 0; i < 4; i++){
      printf("digite os números");
      scanf("%d", &num);
      vet[i] = num;
      vetCopia[i] = num;
    }
    for(int i = 0; i < 4 - 1; i++){
        for(int j = 0; j - 1 - i; j++){
            if(vetCopia[j] > vetCopia[j+1]){
                numMenor = vetCopia[j];
                vetCopia[j] = vetCopia[j+1];
                vetCopia[j+1] = numMenor;
            }
        }

    }
    for (int i = 0; i < 4; i++){
        printf("%d", vetCopia[i]);
    }
    free(vet);
    free(vetCopia);
}
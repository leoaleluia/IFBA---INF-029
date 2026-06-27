#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int *vet = (int *) malloc (5 * sizeof(int));
    int qtdAtual = 0;
    int ctr = 0;
    int num = 0;

    
    while(ctr == 0){
        if(qtdAtual < 5){
            printf("Digite o número para adicionar no vetor");
            scanf("%d", &num);
            vet[qtdAtual] = num;
            qtdAtual++;
        }else{
            printf("vetor lotado");
            ctr = 1;
        }
        
    }
    for(int i = 0; i < qtdAtual; i++){
        printf("%d\n", vet[i]);
    }
}
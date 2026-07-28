#include <stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>


int main(){
    
    FILE *estoque;
    estoque = fopen("estoque.txt", "a+");
    char nome[50];
    int quantidade = 0;
    float preco = 0.0;


    int ctr;
    printf("Deseja inserir algo no arquivo? 0 para sair e 1 para entrar");
    scanf("%d", &ctr);

    while(ctr != 0 ){
        printf("Digite o nome do produto\n");
        scanf("%s", nome);
        printf("Digite o preço do produto\n");
        scanf("%f", &preco);
        printf("Digite a quantidade\n");
        scanf("%d", &quantidade);
        fprintf(estoque,"%s - %d - %f\n", nome, quantidade, preco);

        printf("Deseja continuar?");
        scanf("%d", &ctr);
    }
    fclose(estoque);

}
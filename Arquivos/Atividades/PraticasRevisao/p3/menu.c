#include <stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>


int main(){

    FILE *menu;
    menu = fopen("menu.txt", "a+");

    int res = 0;
    char nome[50];
    printf("Deseja adicionar algum item ao menu?");
    scanf("%d", &res);

    while(res != 0){
        printf("Qual o nome do item");
        scanf("%s", nome);
        fprintf(menu, "%s\n", nome);

        printf("Deseja continuar? aperte 0 para sair e 1 para continuar");
        scanf("%d", &res);
    }
     fclose(menu);
}
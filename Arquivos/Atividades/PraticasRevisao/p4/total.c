#include <stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>

int main(){

    FILE *menu;
    menu = fopen("estoque.txt", "r");
    int qtd = 0;
    float valor = 0.0;
    char nome[50];
    while(fscanf(menu, "%s - %d - %f", nome, &qtd, &valor) != EOF){
        printf("item: %s | Qtd: %d | subtotal: %.2f\n", nome, qtd, qtd * valor);
    }
    
    fclose(menu);
}
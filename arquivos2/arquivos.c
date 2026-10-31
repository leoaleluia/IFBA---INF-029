#include <stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>
#define TAM 10

typedef struct pessoas{
    int idade;
    char nome[50];
    int chave;
}pessoas;

pessoas listaPessoas[TAM];
int qtd = 0;

int cadastrarPessoas(){
    if(qtd < TAM){
        pessoas p;
        printf("Digite seu nome");
        fgets(p.nome, 50, stdin);
        printf("Digite a idade");
        scanf("%d", &p.idade);
        p.chave = qtd + 1;
        listaPessoas[qtd] = p;
        qtd++;
        return 1;
    }else{
        printf("Lista Cheia");
        return 0;

    }
}

void mostrarLista(){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%d %s %d \n", listaPessoas[i].idade, listaPessoas[i].nome, listaPessoas[i].chave);
    }
}


int main(){
    cadastrarPessoas();
    mostrarLista();
}


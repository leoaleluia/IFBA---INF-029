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
        printf("Digite seu nome: ");
        scanf(" %[^\n]", p.nome);
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

void salvarListaEmArquivo(){
    FILE *arq = fopen("lista.txt", "w");
    int i;
    if(arq){
        fprintf(arq, "%d\n", qtd);
        for(i = 0; i < qtd; i++){
            fprintf(arq, "%s", listaPessoas[i].nome);
            fprintf(arq, "%d\n", listaPessoas[i].idade);
            fprintf(arq, "%d\n", listaPessoas[i].chave);
        }
        fclose(arq);
    }else{
        printf("erro na abertura do documento");
    }
}

void lerArquivo(){
    FILE *arq = fopen("lista.txt", "r");
    int i;
    if(arq){
        fscanf(arq, "%d\n", &qtd);
        for(i = 0; i < qtd; i++){
            pessoas p;
            fgets(p.nome, 50, arq);
            fscanf(arq, "%d\n", &p.idade);
            fscanf(arq, "%d\n", &p.chave);
            listaPessoas[i] = p;
        }
        fclose(arq);
    }else{
        printf("erro ao tentar fazer leitura");
    }

}


int main(){

    int ctr = 0;
    int op;

    while(ctr == 0){
        printf("Escolha uma das opções Cadastrar: 1; Salvar Lista: 2; Imprimir Lista: 3; ler arquivo: 4 fechar: 5");
        scanf("%d", &op);
        switch (op){
            case 1:
                cadastrarPessoas();
                break;
            case 2:
                salvarListaEmArquivo();
                break;
            case 3:
                mostrarLista();
                break;
            case 4:
                lerArquivo();
                break;
            case 5:
                ctr = 1;
                break;
            default:
                printf("Opção errada");
                break;
        }
    }
}


#include <stdio.h>
#include <stdlib.h>

typedef struct alunos{
    int nota;
    char nome[30];
}alunos;

void cadastrarAluno(alunos *lista, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("nome: ");
        scanf(" %[^\n]", lista[i].nome);
        printf("nota: ");
        scanf("%d", &lista[i].nota);
    }
}

void exibirAlunos(alunos *lista, int qtd){
   for(int i = 0; i < qtd; i++){
    printf("%d, %s\n", lista[i].nota, lista[i].nome);
   }
}
    
int main(){
    int qtd = 4;
    alunos *lista = (alunos *) malloc (qtd * sizeof(alunos));
    //crie um vetor de alunos, como tamanho de "qtd" que caiba a estrutura de alunos
    cadastrarAluno(lista, qtd);
    exibirAlunos(lista, qtd);
}
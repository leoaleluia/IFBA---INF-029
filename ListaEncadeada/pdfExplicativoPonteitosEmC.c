#include <stdio.h>
#include <stdlib.h>



//O codigo em questão trata da inserção no final sem cabeçote;

//Cria a estrutura, ou seja, o NO
int tam = 0;
typedef struct reg {
	int conteudo;
  struct reg *prox;
} No;

//Função que cria um NÓ a cada vez que é criado um novo elemento da estrutura

No* criarElemento(int valor){
	No *novo = (No *)malloc(sizeof(No)); //malloca para criar um novo nó, ou seja, uma nova inserção de elemtno
	if(novo == NULL){
        printf("Falta Memoria\n");
        exit(1);
	}
	novo->conteudo = valor; //independente da quantidade de elementos na estrutura, sempre será criado um no apontando para NULL, pois esse no sera inserido na lista, ou seja, No *inicioSemCabecote do main
	novo->prox = NULL;
	return novo;
}

void inserirInicioSemCabecote(No **inicio, int val){
    No* novo = criarElemento(val);
    No* ref;
    
    novo->prox = *inicio;
    
    *inicio = novo;
}
void inserirNoFinalComCabecote(No *inicio, int val){

    // Com cabeçote nós adcionamos sempre no proximo
	No* tmp;
	No* novo = criarElemento(val);

	if(inicio->prox == NULL){
		inicio->prox = novo;
	}
	else{
		tmp = inicio->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

//inserindo no final
void inserirNoFinalSemCabecote(No **inicioSemCabecote, int val){
    //O **inicioSemCabecote do parametro da funçao recebe o No *inicioSemcacote do main.
    No *novo; //Criamos um nó para poder usálo como dado para ser armazenado no No *inicioSemCabecote
    No *atual;

    novo = criarElemento(val); //Usamos esse No para poder ser armazenado a referencia de mais um NÓ criado dentro dele, pois quem sempre aponta para o próximo é o nó criado na função a acima

    if(*inicioSemCabecote == NULL)
        *inicioSemCabecote = novo; //Caso o nó acima seja NULL, ou seja, vazio, ele começa com o novo criado.
    else{
        atual = *inicioSemCabecote; //Caso não o NÓ criado acima recebe todos os NÓS ja criados


        while(atual->prox != NULL)
            atual = atual->prox; //Aqui ele verifica qual o ultimo nó e ao fim adciona nele


        atual->prox = novo;
    }
}

/*Função main: 
int main() {
    No *inicioSemCabecote = NULL; // Status: NULL
    
    // 1. Inserindo o 5 (A lista muda de NULL para apontar pro 5)
    inserirNoFinalSemCabecote(&inicioSemCabecote, 5); 
    
    // 2. Inserindo o 6 (O programa varre a lista, acha o 5 e engata o 6 nele)
    inserirNoFinalSemCabecote(&inicioSemCabecote, 6);
    
    // 3. Inserindo o 7 (O programa varre a lista, pula o 5, acha o 6 e engata o 7)
    inserirNoFinalSemCabecote(&inicioSemCabecote, 7);*/
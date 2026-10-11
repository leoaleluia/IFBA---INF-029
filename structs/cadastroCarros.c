#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30
typedef struct carros{
    int ano;
    float preco;
    char modelo[TAM];
}carros;

void criarCarros(int ano, float preco, const char modelo[], carros *carro){
    carro->ano = ano;
    carro->preco = preco;
    strcpy(carro->modelo, modelo);
}

void criarListaCarros(carros *lista, int qtd){
        for(int i = 0; i < qtd; i++){
            printf("Digite o ano do carro: \n");
            scanf("%d",&lista[i].ano);
            printf("Digite o valor do carro com pontos no lugar da virgula: \n");
            scanf("%f", &lista[i].preco);
            printf("Digite o modelo do carro: ");
            scanf(" %[^\n]", lista[i].modelo);
            
        }
}

void listarCarros(carros *lista, int qtd){
    float mCaro = 0;
    for(int i = 0; i < qtd; i++){
        if(lista[i].preco > mCaro){
            mCaro = lista[i].preco;
        }
        printf(" Ano: %d \n Valor: %2.f, \nModelo: %s \n", lista[i].ano, lista[i].preco, lista[i].modelo);
    }
    printf("\no Carro mais caro é o %2.f", mCaro);
}
int main(){
    int qtd = 0;
    printf("Quantos carros terão na lista? ");
    scanf("%d", &qtd);
    carros *lista = (carros*) malloc (qtd * sizeof (carros));
    criarListaCarros(lista, qtd);
    listarCarros(lista, qtd);
    /*carros *carro1 = malloc (sizeof (carros));
    carros *carro2 = malloc (sizeof (carros));
    if(carro1 == NULL && carro2 == NULL ){
        printf("Erro ao alocar memória");
        return 1;
    }

    criarCarros(2010, 1800.00, "wolks", carro1);
    criarCarros(2011, 1500.00, "chevrolet", carro2);

    printf("ano: %d \n preco: %2.f \n modelo1: %s", carro1->ano, carro1->preco, carro1->modelo);*/

}
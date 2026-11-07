#include <stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>

typedef struct carros{
    char veiculo[20];
    int custo;
}carros;

carros carro;
char linha[100];

void cadastro(){
    printf("Digite o nome do veiculo");
    scanf(" %[^\n]", carro.veiculo);
    printf("Digite o custo da manutenção");
    scanf("%d", carro.custo);
}

void criarArquivo(){
    FILE *arq = fopen("listaCar.txt", "w");
    fprintf(arq, "CARROS E SEUS CUSTOS DE MANUTENÇÃO\n");
    fclose(arq);
}

void cadastrarVeiculos(){
    FILE *arq = fopen("listaCar.txt", "a");
    printf("Digite o nome do carro");
    scanf(" %[^\n]", carro.veiculo);
    printf("Digiteo o custo do conserto");
    scanf("%d", &carro.custo);
    fprintf(arq, "veiculo %s | custo: %d\n" , carro.veiculo, carro.custo);
    fclose(arq);
}

void ListarVeiculos(){
    FILE *arq = fopen("listaCar.txt", "r");

    while(fgets(linha, sizeof(linha), arq) != NULL){
        printf("%s\n", linha);
    }
    printf("\n");
    fclose(arq);
}

int main(){

    int op = 0;

    while(op != 4){
        printf("Deseja criar e cadastrar escolha 1, cadastrar escolha 2 ou mostrar escolha 3 ou fechar opções escolha 4? ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            criarArquivo();
            cadastrarVeiculos();
            break;
        case 2:
            cadastrarVeiculos();
            break;
        case 3:
            ListarVeiculos();
            break;
        case 4:
            op = 4;
            break;
        default:
            printf("nenhuma opção reconhecida");
            break;
        }
    }
}
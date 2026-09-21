#include <stdio.h>
#include <stdlib.h>


/*void funcTroca(int *a, int *b){
    int a1 = *a;
    *a = *b;
    *b = a1;
}

int main(){
    int a = 10;
    int b = 5;
    funcTroca(&a, &b);

    printf("%d %d", a, b);
}*/

int functionDiv(int *a){
    *a = *a / 10;
    return *a;
}

int main(){
    int a1 = 25;
    functionDiv(&a1);
    printf("%d", a1);
}

//############################################################################
#include <stdio.h>

//Funções para serem usadas no ponteiro de função
int somar(int a, int b) {
    return a + b;
}

int multiplicar(int a, int b) {
    return a * b;
}

// Função que recebe um PONTEIRO DE FUNÇÃO como parâmetro (Callback)
void executarOperacao(int x, int y, int (*operacao)(int, int) ){//Ponteiro de func para dois inteiros 
    int resultado = operacao(x, y);
    printf("Resultado da operação: %d\n", resultado);
}

int main() {
    // Declara o ponteiro para função
    int (*ptrFuncao)(int, int);

    ptrFuncao = somar;// o ponteiro de função, que aponta para as funções do inicio será usado na func abaixo
    
    executarOperacao(10, 5, ptrFuncao); // Imprime: 15 observe o uso do ptrFunção

    ptrFuncao = multiplicar;
    executarOperacao(10, 5, ptrFuncao); // Imprime: 50

    return 0;
}
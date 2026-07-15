#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(){
    /* ---- Para abrir e escrever (alterar) (se existente  ) um arquivo. (se existir ele apaga)
    FILE *f;
    f = fopen("arquivo.txt", "w");
    if(f == NULL){
        printf("Erro na abertura ");
        system("pause");
        exit(1);
    }   
    char texto[20] = "Meu programa em 2";
    unsigned int i;

    for(i = 0; i < strlen(texto); i++){
        fputc(texto[i], f);
    }
    fclose(f);

    system("pause");
    return 0; */

    //Para mostrar na tela um arquivo
    //Podemos criar outro ponteiro para acessar o arquivo
    
    /*
    FILE *mesmoF;
    mesmoF = fopen("arquivo.txt", "r");
    if(mesmoF == NULL){
        printf("erro na abertura do programa");
        system("pause");
        exit(1);
    }
    char c;
    unsigned int i;
    for(i = 0; i < 10; i++){
        c = fgetc(mesmoF);
        printf("%c", c);
    }*/
    

FILE *mesmoF;
mesmoF = fopen("arquivo.txt", "w");
if(mesmoF == NULL){
    printf("Erro de abertura");
    system("pause");
    return(1);
}
char c[20] = "meu programa em C";
int retorno = fputs(c, mesmoF);
if(retorno == EOF){
    printf("erro");
}
fclose(mesmoF);

    
}
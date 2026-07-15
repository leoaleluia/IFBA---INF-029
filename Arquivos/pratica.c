#include <stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>


int main(){

    FILE *f1;
    FILE *f2;
    char mundo[] = "olá mundo";


    f2 = fopen ("minusculo.txt", "w");

    if(f1 == NULL || f2 == NULL){
        printf("Erro na abertura do programa");
        system("pause");
        
        exit(1);
    }

    for(int i = 0; i < 9; i++){
        fputc(mundo[i], f2);
    }
    fclose(f2);
    
    f2 = fopen("minusculo.txt", "r");
    f1 = fopen("maiusculo.txt", "w");
    char c = fgetc(f2);
    while(c != EOF){
        fputc(toupper(c), f1);
        c = fgetc(f2);
    }

    fclose(f1);
    fclose(f2);

}
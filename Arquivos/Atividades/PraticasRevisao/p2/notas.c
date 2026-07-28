#include <stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>
#include <math.h>

int main(){

    FILE *notas;

    /*
    notas = fopen("notas.txt", "w");
    fprintf(notas, "%f\n", 7.5);
    fprintf(notas, "%f\n", 9.5);
    fprintf(notas, "%f\n", 5.5);
    */
    notas = fopen("notas.txt", "r");

    float notaLida = 0.0;
    float soma = 0.0;
    while(fscanf(notas, "%f", &notaLida)!= EOF){
        soma += notaLida;
    }

    printf("%f notas", soma);

    fclose(notas);
}
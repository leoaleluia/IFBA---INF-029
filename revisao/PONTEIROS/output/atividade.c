#include <stdio.h>
#include <stdlib.h>

void verificarPar(int num, int *numV){
    if(num % 2 == 0){
        *numV = 1;
    }else{
        *numV= 2;
    }
}

void divv(int div, int divisor, int *quo, int *res){
    *quo = div / divisor;
    *res = div % divisor;
}
int main(){

    int num = 5;
    int divi = 2;
    int quo; 
    int res;
    verificarPar(num, &res);
    divv(num, divi, &quo, &res);
    printf("%d, %d", quo, res);
}
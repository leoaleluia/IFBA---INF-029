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
    int a1 = *a;
    int a2 = 0;
    a2 = a1 % 10;
    *a = a1 / 10;

    return a1 = a1 % 10;
}

int main(){
    int a1 = 25;
    int a2 = functionDiv(&a1);
    printf("%d", a2);
}


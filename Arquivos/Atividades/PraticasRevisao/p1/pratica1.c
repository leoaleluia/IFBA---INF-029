#include <stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>


int main(){
    FILE *tb;
    int numTst = 0;
    tb = fopen("tabuada.txt", "w");

    printf("Digite um número");
    scanf("%d", &numTst);
    int ctr = 0;
    while(ctr < 10 ){
        fprintf(tb, "%d x %d = %d\n", ctr, numTst, ctr * numTst);        
        ctr++;
    }

    fclose(tb);

}
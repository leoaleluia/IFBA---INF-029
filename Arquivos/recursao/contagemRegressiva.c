#include <stdio.h>

void regressiva(int n){

    if(n <= 0){
        printf("FOgo");
    }

    printf("%d\n ", n);

    regressiva(n - 1);
}



int main(){
    int n1 = 10;
    regressiva(n1);

}
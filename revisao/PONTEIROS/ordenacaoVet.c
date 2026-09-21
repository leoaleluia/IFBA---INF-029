#include <stdio.h>
#include <stdlib.h>


void ordenaVet(int vet[]){
    int ctr = 0;
    for(int i = 0; i < 6 - 1; i++){
        for(int j = i + 1; j < 6 - 1; j++ ){
            if(vet[i] > vet[j]){
                ctr = vet[j];
                vet[j + 1] = vet[i];
                vet[i] = ctr;
            }
        }
    }
}

int main(){
 int vet[] = {5, 3, 6, 8, 4, 2};
 ordenaVet(vet);
 for(int i = 0; i < 6; i++){
    printf("%d", vet[i]);
 }
}
#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void burbujeo(int[], int);

int main(){
    int vector[] = {15, 64, 2, 4, 10};
    burbujeo(vector, TAM);
    for (int i = 0; i< TAM; i++){
        printf("%d: %d\n", i+1, vector[i]);
    }
}

void burbujeo(int v[], int tam){
    int i, j, aux;
    for(i=0;i<tam-1;i++){
        for(j=0;j < tam-1-i;j++){
            if(v[j] >=v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}
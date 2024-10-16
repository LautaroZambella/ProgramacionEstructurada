/*
Carga aleatoriamente un vector de 10 posiciones
busca bninariamente un elemento.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaAleatoria(int[], int);
void ordenar(int[], int);
void mostrar(int[], int);
int busqBinaria(int[], int, int);

int main(){
    int vector[10] = {0};
    int busq;
    srand(time(NULL));

    cargaAleatoria(vector, 10);
    ordenar(vector, 10);
    mostrar(vector, 10);
    printf("Ingrese un numero del 1 al 100 para buscar\n");
    scanf("%d",&busq);
    int pos = busqBinaria(vector, busq, 10);
    if(pos != -1){
        printf("El elemento esta en la pos: %d", pos+1);
    }else{
        printf("No se encuentra al elemento");
    }
}

void cargaAleatoria(int v[], int cant){
    int i;
    for(i = 0; i <cant; i++){
        v[i] = rand()%100;
    }
}

void ordenar(int v[], int cant){
    int i, j, aux;
    for(i = 0; i < cant-1; i++){
        for(j = 0; j <cant-1-i;j++){
            if(v[j]>=v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void mostrar(int v[], int num){
    int i;
    for(i = 0; i < num; i++){
        printf("%d: %d\n", i+1, v[i]);
    }
}

int busqBinaria(int v[], int busc, int ce){
    int pos = -1, li = 0, ls = ce-1, med;
    while(pos == -1 && li <= ls){
        med = (li + ls)/2;
        if(v[med] == busc){
            pos = med;
        }else{
            if(busc > v[med]){
                li = med+1;
            }else{
                ls = med-1;
            }
        }
    }
    return pos;
}
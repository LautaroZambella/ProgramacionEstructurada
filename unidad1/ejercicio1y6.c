/*
1.6 Dado un conjunto de 10 números enteros ordenados de menor a mayor, ingresar por teclado 3 números más
no ordenados. Insertarlos donde correspondan. Mostrar en pantalla la serie inicial y la final. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void cargaAleatoria(int[], int, int);
void Mostrar(int[], int);
void burbujeo(int[], int);
void cargaNuevo(int[], int[], int);

int main(){
    int vec[TAM] = {0};
    int vectorNuevo[13] = {0};

    srand(time(NULL));
    cargaAleatoria(vec, TAM, 100);
    burbujeo(vec, TAM);
    Mostrar(vec, TAM);
    printf("-\n");
    cargaNuevo(vec, vectorNuevo, TAM);
    burbujeo(vectorNuevo, 13);
    Mostrar(vectorNuevo, 13);
    return 0;
}

void cargaAleatoria(int vec[], int ce, int max){
    int i = 0;
    for(i; i< ce; i++){
        vec[i] = rand() % max;
    }
}

void Mostrar(int v[], int ce ){
    int i = 0;
    for(i; i<ce;i++){
        printf("%d: %d\n",i+1,v[i]);
    }
}

void burbujeo(int vec[], int ce){
    int i,j,aux;
    for(i = 0; i < ce - 1; i++){
        for(j = 0; j < ce -1 - i; j++){
            if(vec[j] >= vec[j+1]){
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
}

void cargaNuevo(int vec[], int cargar[], int ce){
    int aux = 0;
    for(int i = 0; i < ce; i++){
        cargar[i] = vec[i];
    }

    for(int j = 0; j < 3;){
        printf("Ingrese el siguiente numero\n");
        scanf("%d",&aux);
        if(aux > 0){
            cargar[10 + j] = aux;
            j++;
        }
    }
}
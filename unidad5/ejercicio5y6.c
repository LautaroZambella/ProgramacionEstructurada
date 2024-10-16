/*
5.6 Cargar un vector de enteros con números aleatorios de 3 cifras máximo.
Realizar una función que retorne un puntero al mayor valor del vector
Mostrar el máximo valor mediante el puntero y la posición en la cual se encuentra
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void cargaAleatoria(int[], int, int);
void mostrar(int[], int);
int* mayor(int[], int);

int main(){
    int vec[10] = {0};
    srand(time(NULL));
    cargaAleatoria(vec, 10, 1000);
    mostrar(vec, 10);
    int *paux;
    paux = mayor(vec, 10);
    printf("El valor mayor es: %d y esta en la posicion: %d\n", *paux, (paux - vec) + 1);
    return 0;
}

void cargaAleatoria(int v[], int ce, int max){
    int i;
    for(i = 0; i < ce; i++){
        *(v+i) = rand()%max;
    }
}

void mostrar(int v[], int ce){
    int i;
    for(i = 0; i < ce; i++){
        printf("Numero: %d\n",*(v+i));
    }
}

int* mayor(int v[], int ce){
    int i, mayor = 0, *pmayor;
    for(i = 0; i < ce; i++){
        if(*(v+i) > mayor){
            mayor = *(v+i);
            pmayor = v+i;
        }
    }
    return pmayor;
}
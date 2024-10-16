#include <stdio.h>

void carga(int[], int);
void mostrar(int[], int);

int main(){
    int vec[5];
    carga(vec, 5);
    mostrar(vec, 5);
    return 0;
}

void carga(int v[], int ce){
    int i = 0;
    for(i; i < ce; i++){
        printf("Ingrese un entero\n");
        scanf("%d", v + i);
    }
}

void mostrar(int v[], int ce){
    int i;
    for(i = 0; i < ce; i++){
        printf("%d\n",*(v+i));
    }
}
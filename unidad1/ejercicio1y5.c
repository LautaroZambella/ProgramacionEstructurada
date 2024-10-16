#include <stdio.h>
#include <stdlib.h>

void cargaCodigos(int[], int);
int validNum(int, int, int[]);
void mostrarVec(int[], int);
int busquedaSecuencial(int[], int, int);

int main(){
    int codArt[15] = {0};
    int vendedro[5] = {0};
    int cantidades[15] = {0};

    cargaCodigos(codArt, 15);
    mostrarVec(codArt, 15);
}

void cargaCodigos(int v[], int tam){
    int i = 0;
    for(i; i< tam; i++){
        v[i] = validNum(100, 999, v);
    }
}

void mostrarVec(int v[], int tam){
    int i = 0;
    for(i; i< tam; i++){
        printf("%d: %d\n", i+1, v[i]);
    }
}

int validNum(int li, int ls, int v[]){
    int aux, posAux;
    do{
        printf("Ingrese el numero\n");
        scanf("%d",&aux);
        posAux = busquedaSecuencial(v, aux, 15);
    }while((aux < li || aux > ls) && posAux == -1);
    return aux;
}

int busquedaSecuencial(int v[], int busc, int tam){
    int i= 0, pos = -1;
    while(pos == -1 && i < tam){
        if(v[i] == busc){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}
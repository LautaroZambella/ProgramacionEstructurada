/*
2.1 Ingresar una matriz de 3x3 por teclado y un número entero. 
Realizar el producto de la matriz por la constante.
*/

#include <stdio.h>
#include <stdlib.h>
#define FIL 3
#define COL 3

void cargaMatriz(int[][COL], int, int);
void multiplicarMat(int[][COL], int, int, int);
void MostrarMatxFil (int[][COL], int, int);

int main(){
    int Mat[FIL][COL] = {0};
    int escalar;

    printf("Ingrese el escalar\n");
    scanf("%d",&escalar);
    cargaMatriz(Mat, FIL, COL);
    multiplicarMat(Mat, FIL, COL, escalar);
    MostrarMatxFil(Mat, FIL, COL);
    return 0;
}

void cargaMatriz(int m[][COL], int fil, int col){
    int i,j, aux;

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            printf("Ingrese el siguiente numero\n");
            scanf("%d",&aux);
            m[i][j] = aux;
        }
    }
}

void multiplicarMat(int m[][COL], int fil, int col, int num){
    int i,j;

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            m[i][j] = m[i][j]*num;
        }
    }
}

void MostrarMatxFil(int m[][COL], int fil, int col){
    int i,j;

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            printf("\n%d: %d: %d\n", i, j, m[i][j]);
        }
    }
}
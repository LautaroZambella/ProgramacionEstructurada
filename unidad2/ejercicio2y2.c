/*
2.2 Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un 
vector con la suma por fila de
dicha matriz y otra función que calcule la suma por columna en otro vector
*/

#include <stdio.h>
#include <stdlib.h>
#define FIL 5
#define COL 4

void cargaMat(int[][COL], int, int);
void sumaFila(int[][COL], int[], int, int);
void SumaPorColumnas(int[][COL], int[], int, int);

void MostrarMatxFil (int[][COL], int, int);
void mostrarVector (int[], int);

int main(){
    int Mat[FIL][COL] = {0};
    int vSumaFilas[FIL] = {0};
    int vSumaColumnas[COL] = {0};

    cargaMat(Mat, FIL, COL);
    sumaFila(Mat, vSumaFilas, FIL, COL);
    SumaPorColumnas(Mat, vSumaColumnas, FIL, COL);
    MostrarMatxFil(Mat, FIL, COL);
    mostrarVector(vSumaFilas, FIL);
    mostrarVector(vSumaColumnas, COL);
}

void cargaMat(int m[][COL], int fil, int col){
    int i,j, aux;

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            printf("Ingrese el siguiente numero\n");
            scanf("%d",&aux);
            m[i][j] = aux;
        }
    }
}

void sumaFila(int mat[][COL], int v[], int fil, int col){
    int f,c,suma;
    for(f = 0; f<fil; f++){
        suma = 0;
        for(c = 0; c < col; c++){
            suma += mat[f][c];
        }
        v[f]= suma;
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

void mostrarVector (int v[], int fil){
    int i = 0;
    for(i; i < fil; i++){
        printf("%d: %d\n", i, v[i]);
    }
}

void SumaPorColumnas(int mat[][COL], int vec[], int cf, int cc)
{
    int f,c,suma;
    for (c=0;c<cc;c++){
        vec[c]=0;
        for (f=0;f<cf;f++)
        vec[c] += mat[f][c];
    }
}

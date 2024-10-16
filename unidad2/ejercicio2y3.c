/*
2.3 Cargar de forma aleatoria una matriz de 5 x 8 con números de 2 cifras. 
Determinar el máximo valor almacenado en la matriz indicando cuantas veces 
se repite y en que posiciones.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 5
#define COL 8

void cargaMatriz(int[][COL], int, int, int);
void MostrarMatxFil (int[][COL], int, int);
int Maximo(int[][COL], int, int);
void mostrarMaximo(int[][COL], int, int, int);

int main(){
    int max;
    int Mat[FIL][COL] = {0};

    srand(time(NULL));


    cargaMatriz(Mat, FIL, COL, 10);
    MostrarMatxFil(Mat, FIL, COL);
    max = Maximo(Mat, FIL, COL);
    printf("\n%d\n", max);
    mostrarMaximo(Mat, FIL, COL, max);
}

void cargaMatriz(int m[][COL], int fil, int col, int limit){
    int i,j;

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            m[i][j] = rand()%limit;
        }
    }
}

void MostrarMatxFil(int M[][COL], int f, int c)
{ int i, j;

    for (i = 0; i < f; i++){
        printf ("\n%3d\t", i + 1);
        for (j = 0; j < c; j++)
            printf("\t%6d", M[i][j]);
    }
}

int Maximo(int m[][COL], int f, int c){
    int max = m[0][0], i, j;
    for(i = 0; i < f; i++){
        for(j = 0; j<c; j++){
            if(m[i][j] > max){
                max = m[i][j];
            }
        }
    }
    return max;
}

void mostrarMaximo(int m[][COL], int f, int c, int max){
    int cont = 0, i, j;
    printf("El valor maximo es: %d y se encuentra en las siguientes posiciones: \n", max);
    for(i = 0; i < f; i++){
        for(j = 0; j < c; j++){
            if(m[i][j] == max){
                printf("fila: %d, col: %d\n", i+1, j+1);
                cont++;
            }
        }
    }
    printf("El numero maximo se repite: %d veces", cont);
}
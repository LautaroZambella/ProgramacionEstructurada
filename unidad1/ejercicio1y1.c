/*
1.1 Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void cargaAleatoria(int[], int, int);
int menor(int[], int);
int mayor(int[], int);
void mostrar(int[], int);
void mostrarMenor(int[], int, int);
void mostrarMayor(int[], int, int);

int main(){
    int vector[20];
    srand(time(NULL));
    cargaAleatoria(vector,20,100);
    int valorMasChico = menor (vector, 20);
    int valorMasGrande = mayor(vector, 20);
    mostrar(vector, 20);
    mostrarMenor(vector, valorMasChico, 20);
    mostrarMayor(vector, valorMasGrande, 20);
    return 0;
}

void cargaAleatoria(int vec[], int ce, int max){
    for(int i = 0; i < ce; i++){
        vec[i] = rand() %max;
    }
}

int menor(int vec[], int N){
    int min = vec[0];
    for (int i = 0; i <N; i++){
        if (vec[i] < min){
            min = vec[i];
        }
    }
    return min;
}

int mayor(int vec[], int N){
    int max = vec[0];
    for (int i = 0; i <N; i++){
        if (vec[i] > max){
            max = vec[i];
        }
    }
    return max;
}

void mostrar(int vec[], int ce){
    for (int i = 0; i < ce; i++){
        printf("%d: %d\n", i + 1, vec[i]);
    }
}

void mostrarMenor(int vec[], int min, int N){
    int cont = 0;

    printf("El valor mas chico del vector es: %d\n", min);

    for (int i = 0; i <N; i++){
        if (vec[i] == min){
            cont++;
        }
    }

    printf("El valor mas chcico se repite: %d veces\n", cont);
}

void mostrarMayor(int vec[], int max, int N){
    int cont = 0;

    printf("El valor mas grande del vector es: %d\n", max);

    for (int i = 0; i <N; i++){
        if (vec[i] == max){
            printf("posicion: %d", i +1);
            cont++;
        }
    }

    printf("El valor mas grande se repite: %d veces\n", cont);
}
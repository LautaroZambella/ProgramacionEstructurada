#include <stdio.h>
#include <stdlib.h>
#define FIL 12
#define COL 9

void cargaInicial(char[][COL], int, int);
void mostrarMat(char[][COL], int, int);
void reservas(char[][COL], int, int);
int cambioColumna(int);
void cantVacios(char[][COL], int, int);
void cantRporFila(char[][COL], int[], int, int, int);
void mostrarVector(int[], int);
void filasVacias(int[], int);
void mayorCantFila(int[], int);

int main(){
    char asientos[FIL][COL];
    int RporFila[FIL] = {0};

    cargaInicial(asientos, FIL, COL);
    mostrarMat(asientos, FIL, COL);
    reservas(asientos, FIL, COL);
    cantRporFila(asientos, RporFila, FIL, COL, FIL);
    cantVacios(asientos, FIL, COL);
    mostrarVector(RporFila, FIL);
    filasVacias(RporFila, FIL);
    mayorCantFila(RporFila, FIL);

    printf("\nGracias por comprar con nosotros\n");
}

void cargaInicial(char asientos[][COL], int fil, int col){
    int i, j;
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            asientos[i][j] = 'D';
        }
    }
}

void mostrarMat(char asientos[][COL], int fil, int col){
    int i, j;
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            printf(" %c ", asientos[i][j]);
        }
        printf("\n");
    }
}

void reservas(char asientos[][COL], int fil, int col){
    int fila, columna;
    do{
        printf("Ingrese el numero de fila\n");
        scanf("%d",&fila);
    }while(fila > 12 || fila == 0);

    while(fila > 0){
        do{
            printf("Ingrese el numero de columna\n");
            scanf("%d",&columna);
        }while(columna > 9 && columna < 1);
        columna = cambioColumna(columna);

        if(asientos[fila-1][columna-1] == 'D'){
            asientos[fila-1][columna-1] = 'R';
        } else{
            printf("Asiento ocupado, elija otro\n");
        }

        mostrarMat(asientos, FIL, COL);
        do{
            printf("Ingrese el numero de fila\n");
            scanf("%d",&fila);
        }while(fila > 12 || fila == 0);
    }
}

int cambioColumna(int prev){
    int next;

    switch(prev){
        case 1:
            next = 5;
            break;
        case 2:
            next = 4;
            break;
        case 3:
            next = 6;
            break;
        case 4:
            next = 3;
            break;
        case 5:
            next = 7;
            break;
        case 6:
            next = 2;
            break;
        case 7:
            next = 8;
            break;
        case 8:
            next = 1;
            break;
        case 9:
            next = 9;
            break;
    }
    return next;
}

void cantVacios(char asientos[][COL], int fil, int col){
    int i, j;
    int totalVacios = 108;
    int reservados = 0;
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            if(asientos[i][j] == 'R'){
                totalVacios = totalVacios -1;
                reservados++;
            }
        }
    }
    printf("\nHay %d asientos vacios y %d asientos reservados\n", totalVacios, reservados);

}

void cantRporFila(char asientos[][COL], int RporFilas[], int fil, int col, int tam){
    int i, j;
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            if(asientos[i][j] == 'R'){
                RporFilas[i]++;
            }
        }
    }
}

void mostrarVector(int v[], int fil){
    int i = 0;
    for(i; i < fil; i++){
        printf("Fila: %d, espectadores: %d\n", i +1, v[i]);
    }
}

void filasVacias(int v[], int fil){
    int i = 0, cont = 0;
    for(i; i < fil; i++){
        if(v[i] == 0){
            printf("\nLa fila %d esta vacia\n", i+1);
            cont++;
        }
    }
    printf("\nHay %d filas vacias\n", cont);
}

void mayorCantFila(int v[], int fil){
    int i, max = v[0], j;
    for(i = 0; i < fil; i++){
        if (v[i] > max){
            max = v[i];
        }
    }

    printf("El mayor numero de espectadores en una fila es de: %d\n", max);
    for(j = 0; j < fil; j++){
        if(v[j] == max){
            printf("La fila %d tiene esta cantidad de espectadores\n", j+1);
        }
    }
}
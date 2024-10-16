#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargaCodigos(char[][4], int[]);
void mostrar(char[][4], int[], int, int[]);
void comprasDiarias(char[][4], int[], int[], int);
int buscar(char[][4], char[], int);
int minimo(int[], int);
void mostrarMinimo(char[][4], int[], int[], int, int);
void ordenar(char[][4], int[], int[], int);

int main(){
    char cod [50][4];
    int precio [50] = {0};
    int unidadesCompradas[50] = {0};

    int cant = cargaCodigos(cod, precio);
    mostrar(cod, precio, cant, unidadesCompradas);
    comprasDiarias(cod, precio, unidadesCompradas, cant);
    ordenar(cod, precio, unidadesCompradas, cant);
    mostrar(cod, precio, cant, unidadesCompradas);
}

int cargaCodigos(char cod[][4], int precio[]){
    char aux[50];
    int i = 0;

    printf("Ingrese el primer codigo:\n");
    scanf("%s", aux);
    fflush(stdin);

    while((strcmp(aux, "FIN") != 0) && i < 50){
        strcpy(cod[i], aux);
        do{
            printf("Ingrese el precio del producto: %d\n", i);
            scanf("%d",&precio[i]);
        }while(precio[i] <= 0);
        getchar();

        do{
            printf("Ingrese el siguiente codigo:\n");
            scanf("%s",aux);
            fflush(stdin);
        }while(strcmp(aux, "\0") == 0);
        i++;
    }
    return i;
}

void mostrar(char cod[][4], int precios[], int cant, int unidades[]){
    int i = 0;

    for(i; i < cant; i++){
        printf("CODIGO: %s, PRECIO: %d, UNIDADES: %d\n", cod[i], precios[i], unidades[i]);
    }
}

void comprasDiarias(char cod[][4], int precios[], int unidadesCompradas[], int cant){
    char aux[4];
    int auxNum = 0;
    int totalRecaudado = 0;
    
    printf("Ingrese un codigo comprado hoy\n");
    scanf("%s",aux);
    fflush(stdin);
    do{
        printf("Ingrese cuantos prdocutos se compraron\n");
        scanf("%d",&auxNum);
    }while(auxNum < 0);
    getchar();

    while(auxNum > 0){
        int pos = buscar(cod, aux, cant);
        if(pos != -1){
            unidadesCompradas[pos] += auxNum;
        }else{
            printf("El codigo no existe en los previamente ingresados\n");
        }
        printf("Ingrese un codigo comprado hoy\n");
        scanf("%s",aux);
        fflush(stdin);
        do{
            printf("Ingrese cuantos prdocutos se compraron\n");
            scanf("%d",&auxNum);
        }while(auxNum < 0);
        getchar();
    }

    for(int j = 0; j < cant; j++){
        totalRecaudado += precios[j] * unidadesCompradas[j];
    }
    printf("El dia de hoy se recaud %d en ventas\n", totalRecaudado);
    int min = minimo(unidadesCompradas, cant);
    mostrarMinimo(cod, precios, unidadesCompradas, min, cant);
}

int minimo(int v[], int n){
    int min = v[0];
    for(int i = 0; i < n; i++){
        if (v[i] < min){
            min = v[i];
        }
    }
    return min;
}

void mostrarMinimo(char cod[][4], int precios[], int uniades[], int min, int N){
    int i = 0;
    printf("El valor minimo de compras es de %d y fueron los siguientes productos: \n", min);
    for(i; i < N; i++){
        if(uniades[i] == min){
            printf("CODIGO %s, posicion: %d\n", cod[i], i+1);
        }
    }
}

int buscar(char v[][4], char buscado[], int N){
    int i = 0, pos = -1;
    while(pos == -1 && i < N){
        if(strcmp(v[i], buscado) == 0){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

void ordenar(char cod[][4], int precio[], int unidades[], int cant){
    int i,j, aux1, aux2;
    char aux[4];

    for(i = 0; i < cant-1; i++){
        for(j = 0; j < cant -1 -i; j++){
            if(strcmp(cod[j], cod[j+1])){
                strcpy(aux, cod[j]);
                strcpy(cod[j], cod[j+1]);
                strcpy(cod[j+1], aux);
                aux1 = precio[j];
                precio[j] = precio[j+1];
                precio[j+1] = aux1;
                aux2 = unidades[j];
                unidades[j] = unidades[j+1];
                unidades[j+1] = aux2;
            }
        }
    }
}
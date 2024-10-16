/*
1.2 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void cargarCodigos(int[], int, int);
void cargarPedidos(int[], int);
void mostrar(int[], int[], int);
int buscar(int[], int, int);
int menor(int[], int);
int mayor(int[], int);
void mostrarMenor(int[], int[], int, int);
void mostrarMayor(int[], int[], int, int);

int main(){
    int vCodigos[TAM] = {0};
    int pedidos[TAM] = {0};
    cargarCodigos(vCodigos, TAM, 4);
    cargarPedidos(pedidos, TAM);
    int valorMinimo = menor(pedidos, TAM);
    int valorMaximo = mayor(pedidos, TAM);
    mostrar(vCodigos, pedidos, TAM);
    mostrarMayor(pedidos, vCodigos, valorMaximo, TAM);
    mostrarMenor(pedidos, vCodigos, valorMinimo, TAM);
}

void cargarCodigos(int v[], int ce, int maxDigitos){
    int pos, aux;
    for (int i = 0; i < ce; i++){
        do {
            printf("Ingrese un num\n");
            scanf("%d",&aux);
            pos = buscar(v, aux, i);
            if(pos != -1)
                printf("El dato es un duplicado\n");
        }while(pos != -1);
        v[i] = aux;
    }
}

void cargarPedidos(int v[], int ce){
    int aux, cantPedidos = 0;
    do{
        printf("Ingrese que producto quiere cargar: \n");
        scanf("%d",&aux);
        if(aux != 0){
            if(aux >= 1 && aux <= 10){
                printf("Ingrese la cant de pedidos\n");
                scanf("%d",&cantPedidos);
                v[aux-1] = v[aux-1] + cantPedidos; 
            }
        }
    }while(aux != 0);
}

int buscar(int v[], int datoABuscar, int cantElem){
    int i = 0;
    int pos = -1;
    while(pos == -1 && i<cantElem){
        if(v[i] == datoABuscar){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

void mostrar(int v[], int vec[],int tam){
    for(int i = 0; i<tam; i++){
        printf("%d: %d: %d\n", i + 1, v[i], vec[i]);
    }
}

int menor(int v[], int N){
    int min = v[0];
    for (int i = 0; i<N; i++){
        if(v[i] < min){
            min = v[i];
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

void mostrarMenor(int vpedidos[], int vCod[], int min, int N){
    int pos = buscar(vpedidos, min, N);
    for (int i = 0; i<N; i++){
        if(vpedidos[pos] == min){
            printf("El producto de codigo: %d tuvo la menor cantidad de pedidos con %d pedidos\n", vCod[pos], vpedidos[pos]);
        }
    }
}

void mostrarMayor(int vpedidos[], int vCod[], int max, int N){
    int pos = buscar(vpedidos, max, N);
    for (int i = 0; i<N; i++){
        if(vpedidos[pos] == max){
            printf("El producto de codigo: %d tuvo la menor cantidad de pedidos con %d pedidos\n", vCod[pos], vpedidos[pos]);
        }
    }
}
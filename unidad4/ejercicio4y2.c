#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cod;
    float precio;
    int stock;
}medicamento;

void ingreso(medicamento[], int);
void busc_medi(medicamento[], int);
int busc_precio(medicamento[], int, int);
void informe(medicamento[], int);

int main(){
    medicamento productos[5];
    ingreso(productos, 5);
    busc_medi(productos, 5);
    informe(productos, 5);
    return 0;
}

void ingreso(medicamento v[], int tam){
    int i = 0;
    for(i; i < tam; i++){
        do{
            printf("Ingrese el cod del prod\n");
            scanf("%d",&v[i].cod);
        }while(v[i].cod < 99 || v[i].cod > 999);
        do{
            printf("ingrese el preico\n");
            scanf("%f",&v[i].precio);
        }while(v[i].precio <= 0);
        do{
            printf("Ingrese el stock\n");
            scanf("%d",&v[i].stock);
        }while(v[i].stock < 0);
    }
}

void busc_medi(medicamento v[], int tam){
    int aux;
    do{
        printf("Ingrese el cod del que quiere saber el precio\n");
        scanf("%d",&aux);
    }while((aux < 99 || aux > 999) && aux !=0);
    while(aux != 0){
        if(busc_precio(v, aux, tam) < 0){
            printf("No se encontro un medicamento con ese codigo\n");
        }else{
            printf("El precio del medicamente con ese codigo es de: %d\n", busc_precio(v, aux, tam));
        }
        do{
            printf("Ingrese el sigueitne cod\n");
            scanf("%d",&aux);
        }while((aux < 99 || aux > 999) && aux !=0);
    }
}

int busc_precio(medicamento v[], int busc, int tam){
    int i = 0, pos = -1;
    while(pos == -1 && i < tam){
        if(busc == v[i].cod){
            pos = i;
        }else{
            i++;
        }
    }
    if(pos != -1){
        pos = v[pos].precio;
    }
    return pos;
}

void informe(medicamento v[], int tam){
    int i = 0;
    for(i; i < tam; i++){
        if(v[i].stock < 10){
            printf("El articulo de codigo: %d tiene menos de 10 unidades\n", v[i].cod);
        }
    }
}

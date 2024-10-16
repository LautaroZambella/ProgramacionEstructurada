#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cod[6];
    float precio;
    char desc[31];
    int vendidos;
    float importeTotal;
} Tprod;

int carga(Tprod[], int);
void mostrar(Tprod[], int);
int busquedaCod(char[], Tprod[], int);
void ventasMensuales(Tprod[], int);

int main(){
    // Tprod Neumatico1;

    // strcpy(Neumatico1.cod, "ABCDE");
    // Neumatico1.precio = 23;

    // printf("El precio del Neumatico1 es de: %.2f y su codigo es: %s", Neumatico1.precio, Neumatico1.cod);
    Tprod productos[50];
    int cant = carga(productos, 50);
    ventasMensuales(productos, cant);
    mostrar(productos, cant);
    return 0;
}

int carga(Tprod al[], int ct){
    char auxDesc[31], auxCod[6];
    int i = 0;

    printf("\nIngrese la desc del producto\n");
    gets(auxDesc);

    while(i < ct && strcmp(auxDesc, "FIN") != 0){
        strcpy(al[i].desc, auxDesc);
        printf("\nIngrese el codigo del prod\n");
        gets(auxCod);
        strcpy(al[i].cod, auxCod);
        do{
            printf("\nIngrese el precio del producto\n");
            scanf("%f",&al[i].precio);
            getchar();
        }while(al[i].precio <= 0);
        do{
            printf("\nIngrese unidades vendidas del producto\n");
            scanf("%d",&al[i].vendidos);
            getchar();
        }while(al[i].vendidos < 0);
        al[i].importeTotal = al[i].precio * al[i].vendidos;
        printf("\nIngrese la desc del producto\n");
        gets(auxDesc);
        i++;
    }

    
    return i;
}

void mostrar(Tprod prod[], int ce){
    int i = 0;
    for(i; i < ce; i++){
        printf("\nEl producto de cod: %s, y descrip: %s, con un precio de: %.2f, y unas cant vendidas de: %d, tuvo un importe de %.2f", prod[i].cod, prod[i].desc, prod[i].precio, prod[i].vendidos, prod[i].importeTotal);
    }
    printf("\nultima linea de codigo");
}

int busquedaCod(char buscado[], Tprod prod[], int cant){
    int i = 0, pos = -1;
    while(pos == -1 && i < cant){
        if(strcmp(buscado, prod[i].cod) == 0){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

void ventasMensuales(Tprod prod[], int cant){
    char auxCod[6];
    int i, auxPedidos;
    do{
        printf("\nIngrese el codigo del prodcuto\n");
        gets(auxCod);
    }while(busquedaCod(auxCod, prod, cant) == -1);
    do{
        printf("\nIngrese la cant de unidades pedidas\n");
        scanf("%d",&auxPedidos);
    } while(auxPedidos < 0);

    while(auxPedidos>0){
        i = busquedaCod(auxCod, prod, cant);
        prod[i].vendidos += auxPedidos;
        prod[i].importeTotal = prod[i].vendidos * prod[i].precio;
        do{
            printf("\nIngrese el codigo del prodcuto\n");
            gets(auxCod);
        }while(busquedaCod(auxCod, prod, cant) == -1);
        do{
            printf("\nIngrese la cant de unidades pedidas\n");
            scanf("%d",&auxPedidos);
        } while(auxPedidos < 0);
    }
}
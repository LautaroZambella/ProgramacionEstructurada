/*
5.7 Dada la siguiente estructura:
typedef struct
{
int codigo;
char descripcion[31];
float precio;
}sProductos
a. Crear una variable del tipo sProductos
b. Ingresar por teclado los campos
c. Crear un puntero a dicha estructura
d. Mostrar los datos ingresados mediante el puntero utilizando las dos nomenclaturas posibles
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char desc[31];
    float precio;
}sProductos;

void carga(sProductos *);
void mostrar(sProductos);

int main(){
    sProductos producto; // = {23, "xd ee", 33.3};
    sProductos *p;
    p = &producto;
    carga(p);
    mostrar(producto);
}

void carga(sProductos *prod){
    printf("Ingrese el codigo del producto\n");
    scanf("%d",&prod->codigo);
    printf("Ingrese la descripcion del producto\n");
    fflush(stdin);
    gets(prod->desc);
    fflush(stdin);
    printf("ingrese el precio del producto\n");
    scanf("%f",&prod->precio);
}

void mostrar(sProductos prod){
    printf("EL producot de cod: %d, descripcion: %s tiene un precio de %.2f\n",prod.codigo, prod.desc, prod.precio);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int mes;
    int anio;
    int dia;
    int cod;
    float importe;
}venta;

void leer();

int main(){
    venta v[3] = {{3, 2015, 29, 876, 105.5}, {6, 2023, 10, 111, 15.5},{9, 2019, 6, 222, 10.5}};
    FILE *p;
    p = fopen("ventas.dat", "wb");
    if(p == NULL){
        exit(1);
    }
    fwrite(v, sizeof(venta), 3, p);
    fclose(p);
    leer();
}

void leer(){
    FILE *p;
    venta al;

    p = fopen("ventas.dat", "rb");
    if(p == NULL){
        printf("DEntro del if");
        exit(1);
    }
    fread(&al, sizeof(venta),1, p);
    while(!feof(p)){
        printf("El alumno de dni: %d, nombre: %d, nota 1: %d, nota 2: %f tiene un promedio de: %d\n", al.mes, al.dia, al.anio, al.importe, al.cod);
        fread(&al, sizeof(venta),1, p);
    }
    fclose(p);
}
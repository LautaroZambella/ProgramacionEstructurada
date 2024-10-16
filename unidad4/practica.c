#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int cod;
    char nombre[26];
    char coccion;
    int vendidas;
    float precio;
    int dias[7];
} gustos;

int carga(gustos[], int);
int validarNum(int, int, int);
int buscar(gustos[], int, int);
void mostrar(gustos[], int);
void cargaVenta(gustos[], int);
void informeXdia(gustos[], int);
void mayorVenta(gustos[], int);
void ventaXcoccion(gustos[], int);

int main(){
    gustos empanadas[20];
    int cant = carga(empanadas, 20);
    mostrar(empanadas, cant);
    cargaVenta(empanadas, cant);
    informeXdia(empanadas, cant);
    mayorVenta(empanadas, cant);
    ventaXcoccion(empanadas, cant);
}

int carga(gustos v[], int cant){
    int i = 0, aux;
    aux = validarNum(100, 999, 0);

    while (aux != 0){
        v[i].cod = aux;
        for(int j = 0; j < 7; j++){
            v[i].dias[j] = 0;
        }
        fflush(stdin);
        printf("Ingrese el nombre del gusto\n");
        gets(v[i].nombre);
        fflush(stdin);

        do{
            printf("Ingrese el tipo de coccion\n");
            scanf("%c",&v[i].coccion);
            v[i].coccion = toupper(v[i].coccion);
            fflush(stdin);
        }while(v[i].coccion != 'H' && v[i].coccion != 'F' && v[i].coccion != 'S');

        

        do{
            printf("Ingrese la cantidad ya vendida\n");
            scanf("%d",&v[i].vendidas);
        }while(v[i].vendidas <= 0);

        do{
            printf("Ingrese el precio de cada unidad\n");
            scanf("%f",&v[i].precio);
        }while(v[i].precio <= 0);
        
        i++;

        do{
            printf("Ingrese el codigo de la siguiente empana\n");
            scanf("%d",&aux);
        }while(((aux < 100 || aux > 999) && aux != 0) || buscar(v, aux, i) != -1);
    }
    return i;
}

int validarNum(int min, int max, int fin){
    int aux;
    do{
        printf("Ingrese el codigo\n");
        scanf("%d",&aux);
    }while((aux < min || aux > max) && aux != fin);
    return aux;
}

int buscar(gustos v[], int buscado, int ce){
    int i = 0, pos = -1;
    while(i < ce && pos == -1){
        if(v[i].cod == buscado){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

void mostrar(gustos v[], int cant){
    for(int i = 0; i < cant; i++){
        printf("Codigo de empanda: %d\n", v[i].cod);
        printf("Nombre de empanda: %s\n",v[i].nombre);
        printf("Coccion de empanda: %c\n",v[i].coccion);
        printf("cantidad de ventas: %d\n",v[i].vendidas);
        printf("Precio de empanda: %f\n",v[i].precio);
        printf("----------------\n");
    }
}

void cargaVenta(gustos v[], int cant){
    int pos, aux, i, auxventas;
    printf("---------CARGA VENTASAAAAA--------\n");
    do{
        printf("Ingrese el codigo de la empanada\n");
        scanf("%d",&aux);
    }while(buscar(v, aux, cant) == -1 && aux != 0);
    while(aux != 0){
        pos = buscar(v, aux, cant);
        for(i = 0; i < 7; i++){
            do{
                printf("Ingrese las ventas del dia: %d\n", i+1);
                scanf("%d",&auxventas);
            }while(auxventas < 0);
            v[pos].vendidas += auxventas;
            v[pos].dias[i] += auxventas;
        }
        do{
            printf("Ingrese el codigo de la siguiente empanada\n");
            scanf("%d",&aux);
        }while(buscar(v, aux, cant) == -1 && aux != 0);
    }
}

void informeXdia(gustos v[], int cant){
    int i;
    for(i = 0; i < cant; i++){
        printf("La empanada de nombre: %s, vendio: \n",v[i].nombre);
        for(int j = 0; j < 7; j++){
            printf("dia: %d, vendio: %d\n", j+1, v[i].dias[j]);
        }
    }
}

void mayorVenta(gustos v[], int cant){
    char aux[26];
    int mayor = v[0].vendidas;
    for(int i = 0; i < cant; i++){
        if(v[i].vendidas > mayor){
            mayor = v[i].vendidas;
            strcpy(aux, v[i].nombre);
        }
    }
    printf("El gusto de mayor ventas fue: %s con %d ventas\n", aux, mayor);
}

void ventaXcoccion(gustos v[], int cant){
    int ventas[3] = {0};

    for(int i = 0; i < cant; i++){
        if(v[i].coccion == 'H'){
            ventas[0] +=v[i].vendidas;
        }else if(v[i].coccion == 'S'){
            ventas[1] +=v[i].vendidas;
        }else{
            ventas[3] +=v[i].vendidas;
        }
    }
    printf("Las empanadas de coccion H vendieron: %d\n",ventas[0]);
    printf("Las empanadas de coccion F vendieron: %d\n",ventas[2]);
    printf("Las empanadas de coccion S vendieron: %d\n",ventas[1]);
}
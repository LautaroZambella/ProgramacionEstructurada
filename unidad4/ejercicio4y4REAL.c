#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cod;
    char name[50];
    int numVentas;
    float acumulado;
}cliente;

int carga_cliente(cliente[], int);
int buscar(cliente[], int, int);
void mostrarStrcut(cliente[], int);
void cargaVentas(cliente[], int[], int, int);
void ventasXvendedor(int[], int);
void ordenar(cliente[], int);

int main(){
    cliente clientes[100];
    int vendedor[10] = {0};
    int cant = carga_cliente(clientes, 100);
    mostrarStrcut(clientes, cant);
    cargaVentas(clientes, vendedor, cant, 10);
    mostrarStrcut(clientes, cant);
    ventasXvendedor(vendedor, 10);
    ordenar(clientes, cant);
    mostrarStrcut(clientes, cant);
}

int carga_cliente(cliente v[], int cantMax){
    int i = 0, aux;

    do{
        printf("Ingrese el numero de cliente\n");
        scanf("%d",&aux);
    }while((aux < 1000 || aux > 9999) && aux != 999);
    while(aux != 999){
        v[i].cod = aux;
        fflush(stdin);
        printf("Ingrese el nombre del cliente\n");
        gets(v[i].name);
        v[i].numVentas = 0;
        v[i].acumulado = 0;
        i++;
        fflush(stdin);
        do{
            printf("Ingrese el numero de cliente\n");
            scanf("%d",&aux);
        }while(((aux < 1000 || aux > 9999) || buscar(v, aux, i) != -1)&& aux != 999);
    }
    return i;
}

int buscar(cliente v[], int aux, int ce){
    int i = 0, pos = -1;
    while(i < ce && pos == -1){
        if(v[i].cod == aux){
            pos = i; // {0, 4, 8}
        }else{
            i++;
        }
    }
    return pos;
}

void mostrarStrcut(cliente v[], int max){
    for(int i = 0; i < max; i++){
        printf("El cliente de numero: %d, con nombre: %s, tuvo tantas ventas: %d y facturo tanto: %.2f\n",v[i].cod,v[i].name,v[i].numVentas,v[i].acumulado);
    }
}

void cargaVentas(cliente cli[], int ven[], int cant, int vendCant){
    printf("--VENTAS--\n");
    int i, aux, auxNumventa;
    float auxImporte = 0;
    do{
        printf("Ingrese el numero del cliente\n");
        scanf("%d",&aux);
    }while(((aux < 1000 || aux > 9999) || buscar(cli, aux, cant) == -1) && aux != 999);
    while(aux != 999){
    i = buscar(cli, aux, cant);
        do{
            printf("Ingrese el importe a pagar\n");
            scanf("%f",&auxImporte);
        }while(auxImporte < 0);
        do{
            printf("Ingrese el numero de vendedor\n");
            scanf("%d",&auxNumventa);
        }while(auxNumventa < 1 || auxNumventa  > 10);
        cli[i].acumulado += auxImporte;
        cli[i].numVentas++;
        ven[auxNumventa-1]++;
        do{
            printf("Ingrese el numero del cliente\n");
            scanf("%d",&aux);
        }while(((aux < 1000 || aux > 9999) || buscar(cli, aux, cant) == -1) && aux != 999);
    }
}

void ventasXvendedor(int v[], int cant){
    for(int i = 0; i < cant; i++){
        printf("El vendedor: %d, realizo : %d ventas\n", i+1, v[i]);
    }
}

void ordenar(cliente v[], int cant){
    cliente aux;
    int i, j;
    for(i = 0; i < cant -1; i++){
        for(j = 0; j < cant -1 -i; j++){
            if(v[j].acumulado < v[j+1].acumulado){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}
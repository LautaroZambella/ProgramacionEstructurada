#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int num;
    char nombre[31];
    char categoria;
    float valorHs;
    float sueldo;
    int horas[5];//pongo 5 dias en vez de 21 xd nashe skibidi pomni toilte;
}empleado;

int cargaEmpleados(empleado[], int);
int buscar(empleado[], int, int);
int validarInt(int, int, int);
float validarReal(int, int);
void mostrar(empleado[], int);
void cargaHoras(empleado[], int);
void mostrarHoras(empleado[], int);
float maximoSueldo(empleado[], int);
void mostrarMaximo(empleado[], int, float);
void importeXcategoria(empleado[], int);

int main(){
    empleado empleados[100];
    int cant = cargaEmpleados(empleados, 100);
    mostrar(empleados, cant);
    cargaHoras(empleados, cant);
    mostrarHoras(empleados, cant);
    float maximo = maximoSueldo(empleados, cant);
    mostrarMaximo(empleados, cant, maximo);
    importeXcategoria(empleados, cant);
}

int cargaEmpleados(empleado v[], int max){
    int i = 0, aux;
    aux = validarInt(100, 999, 0);
    while(aux != 0){
        v[i].num = aux;
        v[i].sueldo = 0;
        fflush(stdin);
        printf("Ingrese nombre de empleado\n");
        gets(v[i].nombre);
        fflush(stdin);
        do{
            printf("Ingrese la categoria del empleado\n");
            scanf("%c",&v[i].categoria);
            v[i].categoria = toupper(v[i].categoria);
        }while(v[i].categoria != 'A' && v[i].categoria != 'D' && v[i].categoria != 'E' && v[i].categoria != 'T');
        v[i].valorHs = validarReal(1000, 5000);
        i++;
        do{
            printf("Ingrese el numero del siguiente empleado\n");
            scanf("%d",&aux);
        }while(((aux < 100 || aux > 999) && aux != 0) || buscar(v, aux, i) != -1);
    }
    return i;
}

int buscar(empleado v[], int buscado, int ce){
    int i = 0, pos = -1;
    while(i < ce && pos == -1){
        if(v[i].num == buscado){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

int validarInt(int min, int max, int fin){
    int aux;
    do{
        printf("Ingrese el numero del empleado\n");
        scanf("%d",&aux);
    }while((aux < min || aux > max) && aux != fin);
    return aux;
}

float validarReal(int min, int max){
    float aux;
    do{
        printf("Ingrese cuanto cobra por hora el empleado\n");
        scanf("%f",&aux);
    }while(aux < min || aux > max);
    return aux;
}

void mostrar(empleado v[], int cant){
    int i;
    for(i = 0; i < cant; i++){
        printf("Numero de empleado: %d\n", v[i].num);
        printf("Nombre de empleado: %s\n", v[i].nombre);
        printf("Categoria de empleado: %c\n", v[i].categoria);
        printf("Valor de Hora: %.2f\n", v[i].valorHs);
        printf("Sueldo de empleado: %.2f\n", v[i].sueldo);
        printf("------------------------\n");
    }
}

void cargaHoras(empleado v[], int ce){
    int aux, pos;
    float acu = 0;
    do{
        printf("Ingrese el num del empleado a cargar horas\n");
        scanf("%d",&aux);
    }while(aux != 0 && buscar(v, aux, ce) == -1);
    while(aux != 0){
        pos = buscar(v, aux, ce);
        for(int j = 0; j < 5; j++){
            v[pos].horas[j] = 0;
            do{
                printf("Ingrese cuanto trabajo el dia: %d\n", j+1);
                scanf("%d",&v[pos].horas[j]);
            }while(v[pos].horas[j] < 0 || v[pos].horas[j] > 8);
            acu += v[pos].horas[j];
        }
        v[pos].sueldo = acu*v[pos].valorHs;
        do{
            printf("Ingrese el num del empleado a cargar horas\n");
            scanf("%d",&aux);
        }while(aux != 0 && buscar(v, aux, ce) == -1);
    }
    for(int k = 0; k < ce; k++){
    }
}

void mostrarHoras(empleado v[], int cant){
    int i;
    for(i = 0; i < cant; i++){
        printf("\nEl empleado: %s trabajo estas horas estos dias: \n",v[i].nombre);
        for(int j = 0; j < 5; j++){
            printf("Dia: %d, horas: %d\n",j+1, v[i].horas[j]);
        }
    }
}

float maximoSueldo(empleado v[], int ce){
    int i = 0;
    float maximo = v[i].sueldo;

    for(i; i < ce; i++){
        if(v[i].sueldo > maximo){
            maximo = v[i].sueldo;
        }
    }
    return maximo;
}

void mostrarMaximo(empleado v[], int ce, float max){
    int i = 0;
    printf("El/los empleados con el sueldo mas alto es/son: \n");
    for(i; i < ce; i++){
        if(v[i].sueldo == max){
            printf("Empleado: %s\n", v[i].nombre);
        }
    }
}

void importeXcategoria(empleado v[], int cant){
    float acu[4] = {0};
    for(int i = 0; i < cant; i++){
        if(v[i].categoria == 'A'){
            acu[0] += v[i].sueldo;
        }else if(v[i].categoria == 'D'){
            acu[1] += v[i].sueldo;
        }else if(v[i].categoria == 'E'){
            acu[2] += v[i].sueldo;
        }else{
            acu[3] += v[i].sueldo;
        }
    }
    printf("En la categoria A el importe a pagar es: %f\n",acu[0]);
    printf("En la categoria D el importe a pagar es: %f\n",acu[1]);
    printf("En la categoria E el importe a pagar es: %f\n",acu[2]);
    printf("En la categoria F el importe a pagar es: %f\n",acu[3]);
}
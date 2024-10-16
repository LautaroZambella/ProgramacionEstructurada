/*
3.3 Ingresar nombre y DNI de los alumnos de un curso.
Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN. 
Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. 
Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargaApellidos(char[][50], int[]);
void mostrar(char[][50], int[], int);
void encuentraYbusca(char[][50], int[], int);

int main(){
    char apellidos[50][50];
    int dni[50] = {0};

    int cant = cargaApellidos(apellidos, dni);
    mostrar(apellidos, dni, cant);
    encuentraYbusca(apellidos, dni, cant);
    printf("\nFin del codigo fernanfloo");

    return 0;
}

int cargaApellidos(char apellidos[][50], int dnis[]){
    char auxiliar[50];
    int i = 0, auxDni;
    
    printf("Ingrese el primer apellido: \n");
    fgets(auxiliar, 50, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = 0;
    fflush(stdin);

    while((strcmp(auxiliar, "FIN") != 0) && i < 50){
        do{
            printf("Ingrese el dni del alumno\n");
            scanf("%d",&auxDni);
        }while(auxDni < 0 || auxDni > 10000000);
        strcpy(apellidos[i], auxiliar);
        dnis[i] = auxDni;
        i++;
        fflush(stdin);

        printf("Ingrese el siguiente apellido: \n");
        fgets(auxiliar, 50, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = 0;
        fflush(stdin);
    }
    return i;
}

void mostrar(char vn[][50], int dni[], int cant){
    int i;
    for(i = 0; i<cant; i++){
        printf("%s: DNI: %d\n",vn[i], dni[i]);
    }
}

void encuentraYbusca(char vs[][50], int dni[], int cant){
    char aux[50];

    printf("Ingrese un nombre a buscar\n");
    fgets(aux, 50, stdin);
    aux[strcspn(aux, "\n")] = 0;
    
    while(strcmp(aux, "no buscar mas") != 0){
        int pos = -1, i = 0;
        while((pos == -1 && i < cant)){
        if(strcmp(vs[i], aux) == 0){
            pos = i;
        }else{
            i++;
        }
    }
    if(pos != -1){
            printf("Alumno: %s, dni: %d, posicion:%d\n", vs[i], dni[i], pos+1);
        } else{
            printf("No se encuentra en la lista");
        }
        printf("Ingrese un nombre a buscar\n");
        fgets(aux, 50, stdin);
        aux[strcspn(aux, "\n")] = 0;
    }
}
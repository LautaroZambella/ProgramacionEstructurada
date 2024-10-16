/*
Dada la estructura alumno:
struct alumno
{
char nom[31];
int dni;
};
Realizar un programa que permita cargar alumnos y mostrarlos. Como máximo permitir 50 alumnos. El ingreso
finaliza con un DNI igual a 0. Realizar una función para cargar y otra para mostrar usando notación de punteros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nom[31];
    int dni;
} alumno;

int carga(alumno[], int);
void mostrar(alumno[], int);

int main(){
    alumno alumnos[50];
    int cant = carga(alumnos, 50);
    mostrar(alumnos, cant);
}

int carga(alumno v[], int cm){
    int auxDni, i = 0;
    alumno *p;
    do{
        printf("Ingrese el dni del primer alumno\n");
        scanf("%d",&auxDni);
    }while(auxDni <= 9999999 && auxDni != 0);
    while(auxDni != 0 && i < 50){
        p = &v[i];
        p->dni = auxDni;
        fflush(stdin);
        printf("Ingrese el nombre del alumno\n");
        gets(p->nom);
        fflush(stdin);
        i++;
        do{
            printf("Ingrese el dni del primer alumno\n");
            scanf("%d",&auxDni);
        }while(auxDni <= 9999999 && auxDni != 0);
    }
    return i;
}

void mostrar(alumno v[], int ce){
    int i;
    alumno *p;
    for(i = 0; i < ce; i++){
        p = v + i;
        printf("El alumnno: %s tiene un dni igual a : %d\n", p->nom, p->dni);
    }
}
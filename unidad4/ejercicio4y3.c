#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dni;
    char name[80];
    int nota1;
    int nota2;
    float notaF;
}alumno;

int ingreso(alumno[], int);
void resultado(alumno[], int);
void promocionados(alumno[]);

int main(){
    alumno alumnos[80];
    int cant = ingreso(alumnos, 80);
    resultado(alumnos, cant);
    promocionados(alumnos);
}

int ingreso(alumno v[], int tam){
    int i, auxDni;
    char auxName[80];

    do{
        printf("Ingrese el dni del siguiente alumno a ingresar\n");
        scanf("%d",&auxDni);
        fflush(stdin);
    }while((auxDni <= 999 || auxDni >= 99999999) && auxDni != 0);
    while(i < tam && auxDni != 0){
        printf("Ingrese el nombre y apellido del alumno\n");
        gets(auxName);
        fflush(stdin);

        do{
            printf("Ingrese la nota del primer parcial\n");
            scanf("%d",&v[i].nota1);
        }while(v[i].nota1 <1 || v[i].nota1 > 10);

        do{
            printf("Ingrese la nota del segundo parcial\n");
            scanf("%d",&v[i].nota2);
        }while(v[i].nota2 <1 || v[i].nota2 > 10);

        v[i].notaF=(v[i].nota1+v[i].nota2)/2;

        v[i].dni = auxDni;

        strcpy(v[i].name, auxName);

        i++;
        fflush(stdin);
        do{
            printf("Ingrese el dni del siguiente alumno a ingresar\n");
            scanf("%d",&auxDni);
        }while((auxDni <= 999 || auxDni >= 99999999) && auxDni != 0);
        fflush(stdin);
    }
    return i;
}

void resultado(alumno v[], int cant){
    int i, acu = 0;
    for(i = 0; i < cant; i++){
        if(v[i].nota1 >= 4 && v[i].nota2 >= 4){
            acu++;
        }
    }
    printf("%d aprobraon la materia\n", acu);
}

void promocionados(alumno v[]){
    for(int i = 0; i < 80; i++){
        if(v[i].nota1 >= 7 && v[i].nota2 >= 7){
            printf("El alumne: %s con dni: %d tuvo una nota de: %f\n",v[i].name,v[i].dni,v[i].notaF);
        }
    }
}
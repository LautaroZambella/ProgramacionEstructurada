/*
Los datos de los alumnos de una comisión de Computación Transversal son:
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a. Declarar un tipo de dato que contenga la información del alumno.
b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.
c. Leer los datos del archivo, mediante la Función LECTURA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int num;
    char nom[81];
    int nota1;
    int nota2;
    float prom;
} alumno;

void cargar();
void leer();

int main(){
    cargar();
    leer();
}

void cargar(){
    int aux;
    FILE *p;
    alumno alumnos;
    p = fopen("ALUMNOS.dat", "wb");
    if(p == NULL){
        exit(1);
    }
    do{
        printf("Ingrese el dni del alumno\n");
        scanf("%d",&aux);
    }while(aux < 100 && aux != 0);
    while(aux != 0){
        alumnos.num = aux;
        fflush(stdin);
        printf("Ingrese el nombre del alumno\n");
        gets(alumnos.nom);
        do{
            printf("Ingrese la nota 1\n");
            scanf("%d",&alumnos.nota1);
        }while(alumnos.nota1 < 1 || alumnos.nota1 > 10);
        do{
            printf("Ingrese la nota 2\n");
            scanf("%d",&alumnos.nota2);
        }while(alumnos.nota2 < 1 || alumnos.nota2 > 10);
        alumnos.prom = (alumnos.nota1 + alumnos.nota2) / 2.0;
        fwrite(&alumnos, sizeof(alumno),1,p);
        do{
            printf("Ingrese el dni del alumno\n");
            scanf("%d",&aux);
        }while(aux < 100 && aux != 0);
    }
    fclose(p);
}

void leer(){
    FILE *p;
    alumno al;

    p = fopen("ALUMNOS.dat", "rb");
    if(p == NULL){
        printf("DEntro del if");
        exit(1);
    }
    fread(&al, sizeof(alumno),1, p);
    while(!feof(p)){
        printf("El alumno de dni: %d, nombre: %s, nota 1: %d, nota 2: %d tiene un promedio de: %f\n", al.num, al.nom, al.nota1, al.nota2, al.prom);
        fread(&al, sizeof(alumno),1, p);
    }
    fclose(p);
}
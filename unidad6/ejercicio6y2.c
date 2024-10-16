/*
6.2 Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior se desea desarrollar un
programa que, basado en la información del archivo, genere 3 archivos:
• Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
• Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4 pero no
promocionados).
• Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).
Para comprobar los datos guardados realizar una función que reciba por parámetro el nombre del archivo
a mostrar, lo abre y muestre su contenido. Se debe invocar a la función 3 veces para mostrar todos los
archivos generados.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    char nom[81];
    int nota1;
    int nota2;
    float prom;
} alumno;

void leer(char[]);
void proceso();

int main(){
    leer("ALUMNOS.DAT");
    proceso();
    leer("promocionados.dat");
    leer("cursados.dat");
    leer("recursantes.dat");
    return 0;
}

void leer(char string[]){
    FILE *p;
    alumno al;

    p = fopen(string, "rb");
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

void proceso(){
    FILE *p;
    FILE *prom;
    FILE *curso;
    FILE *burros;
    alumno al;

    p = fopen("ALUMNOS.DAT", "rb");
    if(p == NULL){
        printf("DEntro del if");
        exit(1);
    }
    prom = fopen("promocionados.dat", "wb");
            if(prom == NULL){
                exit(1);
            }
    curso = fopen("cursados.dat", "wb");
            if(curso == NULL){
                exit(1);
            }
    burros = fopen("recursantes.dat", "wb");
            if(burros == NULL){
                exit(1);
            }
    fread(&al, sizeof(alumno),1, p);
    while(!feof(p)){
        if(al.nota1 >= 7 && al.nota2 >= 7){
            fwrite(&al, sizeof(alumno),1,prom);
        }else if(al.nota1 >= 4 && al.nota2 >= 4){
            fwrite(&al, sizeof(alumno),1,curso);
        }else{
            fwrite(&al, sizeof(alumno),1,burros);
        }
        fread(&al, sizeof(alumno),1, p);
    }
    fclose(prom);
    fclose(curso);
    fclose(burros);
    fclose(p);
}
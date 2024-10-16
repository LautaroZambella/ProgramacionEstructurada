/*Una plataforma de streaming necesita un programa para organzar peliculas. Esta plataforma tiene
como máximo 500 peliculas. El programa primero debe ingresar las peliculas, de cada una se ingresa código de pelicula
(entero de 4 cifras), título(cadena de 25 caracteres) y género (cadena de 15 caracteres), verificando que no haya
peliculas repetidas comprobándolo por su código. 
El ingreso de las peliculas finaliza con código de pelicula cero.
Luego se ingresan las descargas realizadas en el mes de abril, por cada una se ingresa código de 
pelicula y dia de descarga.
El ingreso de las descargas finaliza con código de peliculas cero.
Validar con función/es el ingreso del código de pelicula y día.
se pide:
    1) Informar cantidad de descargas de cada pelicula en cada día del mes
    2) Informar cantidad total de descargas de peliculas del genero COMEDIA
    3) Informar el título de la/s pelicula/s que tuvieron la mayor cantidad de descargas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int cod;
    char titulo[26];
    char genero[16];
    int cant;
} pelicula;

int carga(pelicula[], int);
int buscar(pelicula[], int, int);
void mostrar(pelicula[], int);
void cargaDescargas(pelicula[], int[][500]);
void descargasXdia(pelicula[], int[][500]);
void peliculasXdia(pelicula[], int[][500], int);
void comedia(pelicula[], int);


int main(){
    pelicula peliculas[500];
    int dias[30][500] = {{0}};
    int cant = carga(peliculas, 500);
    mostrar(peliculas, cant);
    cargaDescargas(peliculas, dias);
    peliculasXdia(peliculas, dias, cant);
    comedia(peliculas, cant);
}

int carga(pelicula v[], int max){
    int i = 0, aux;

    do{
        printf("Ingrese el codigo de la pelicula\n");
        scanf("%d",&aux);
    }while((aux < 1000 || aux > 9999) && aux != 0);

    while(aux != 0){
        v[i].cod = aux;
        fflush(stdin);
        printf("Ingrese el titulo de la pelicula\n");
        gets(v[i].titulo);
        fflush(stdin);
        printf("Ingrese el genero de la pelicula\n");
        gets(v[i].genero);
        v[i].cant = 0;

        i++;

        do{
            printf("Ingrese el codigo de la pelicula\n");
            scanf("%d",&aux);
        }while(((aux < 1000 || aux > 9999) && aux != 0) || buscar(v, aux, i) != -1);
    }
    return i;
}

int buscar(pelicula v[], int busc, int cant){
    int i = 0, pos = -1;
    while(i < cant && pos == -1){
        if(v[i].cod == busc){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

void mostrar(pelicula v[], int cant){
    int i = 0;
    for(i; i<cant; i++){
        printf("La pelicula de codigo: %d, de titulo: %s tiene el genero de: %s\n",v[i].cod,v[i].titulo,v[i].genero);
    }
}

void cargaDescargas(pelicula v[], int m[][500]){
    int i = 0, aux, pos, auxDia;

    do{
        printf("Ingrese un codigo de pelicula\n");
        scanf("%d",&aux);
    }while(((aux < 1000 || aux > 9999) || buscar(v, aux, 500) == -1) && aux != 0);
    while(aux != 0){
        pos = buscar(v, aux, 500);
        do{
            printf("Ingrese el dia de descarga\n");
            scanf("%d",&auxDia);
        }while(auxDia < 1 || auxDia > 30);
        m[auxDia][pos]++;
        
        v[pos].cant++;

        do{
            printf("Ingrese un codigo de pelicula\n");
            scanf("%d",&aux);
        }while(((aux < 1000 || aux > 9999) || buscar(v, aux, 500) == -1) && aux != 0);
    }
}

void peliculasXdia(pelicula v[], int m[][500], int cant){
    int i, j, pos;

    for(i = 0; i < 30; i++){
        for(j = 0; j < cant; j++){
            pos = buscar(v, j, 500);
            printf("El dia %d la pelicula de codigo: %d se descargo %d veces\n", i, v[pos].cod, m[i][j]);
        }
    }
}

void comedia(pelicula v[], int cant){
    int contador = 0;
    for(int i = 0; i < cant; i++){
        if(strcmpi(v[i].genero, "COMEDIA") == 0){
            contador++;
        }
    }
    printf("Se ")
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int carga(char[][7], int[], float[], int);
int buscar(char[][7], char[], int);
void mostrar(char[][7], int[], float[], int);
void porcentaje(int, int);

int main(){
    char patentes[30][7];
    int dias[30] = {0};
    float dolares[30] = {0};
    int cant = carga(patentes, dias, dolares, 30);
    mostrar(patentes, dias, dolares, cant);
    porcentaje(cant, 30);
}

int carga(char pat[][7], int dias[], float dol[], int cant){
    char aux[7];
    int i = 0;
    printf("Ingrese la primer patente\n");
    gets(aux);
    fflush(stdin);
    while(i < 30 && strcmpi(aux, "FINDIA") != 0){
        strcpy(pat[i], aux);
        do{
            printf("Ingrese la cant de dias: \n");
            scanf("%d",&dias[i]);
        }while(dias[i] < 1);
        do{
            printf("Ingrese el precio del dolar\n");
            scanf("%f",&dol[i]);
        }while(dol[i] <= 0);

        i++;
        do{
            fflush(stdin);
            printf("Ingrese la siguiente patente\n");
            gets(aux);
            fflush(stdin);
        }while(buscar(pat, aux, i) != -1);
    }
    return i;
}

int buscar(char vec[][7], char busc[], int cant){
    int i = 0, pos = -1;
    while(i < cant && pos == -1){
        if(strcmpi(vec[i], busc) == 0){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

void mostrar(char pat[][7], int dias[], float dol[], int cant){
    int i;
    for(i = 0; i<cant; i++){
        printf("El auto de patente: %s sera alquilado %d dias al precio de %.2f por dia\n", pat[i], dias[i], dol[i]);
    }
}

void porcentaje(int ac, int to){
    float porcentaje =(ac*100)/to;
    printf("Se alquilaron: %.2f sobre el total de los autos totales \n", porcentaje);
}
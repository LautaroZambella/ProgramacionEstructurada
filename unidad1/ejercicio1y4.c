/*
1.4 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado
de mayor a menor por nota.
*/

#include <stdio.h>
#include <stdlib.h>

int buscar(int[], int, int);
void carga(int[], int[], int);
void mostrar(int[], int[], int);
void burbujeo(int[], int[], int);


int main(){
    int vDNI[60] = {0};
    int vNotas[60] = {0};
    carga(vDNI, vNotas, 60);
    burbujeo(vNotas, vDNI, 60);
    mostrar(vDNI, vNotas, 60);
}

void carga(int vdni[], int vnotas[], int ce){
    int aux, pos, auxiliarinterior, otroaux;
    do{
        printf("Ingrese de que alumno quiere ingresar los datos:\n");
        scanf("%d",&aux);
        if(aux > 0 && aux <= 60){
            if(vdni[aux-1] == 0){
                do{
                    printf("Ingrese el dni del alumno %d\n", aux);
                    scanf("%d",&auxiliarinterior);
                    printf("Ingrese la nota del alumno %d\n", aux);
                    scanf("%d",&otroaux);
                    pos = buscar(vdni, auxiliarinterior, 60);
                    if (pos != -1){
                        printf("Dni ya ingresado\n");
                    }
                }while(pos != -1);
                vdni[aux-1] = auxiliarinterior;
                vnotas[aux-1] = otroaux;
            }else{
                printf("Ya ingreso datos de este alumno\n");
            }
        }
    }while(aux-1 >= 0);
}

int buscar(int v[], int datoAbuscar, int N){
    int i = 0, pos = -1;
    while (pos == -1 && i < N){
        if(v[i] == datoAbuscar){
            pos = i;
        }else{
            i++;
    }}
    return pos;
}

void mostrar(int dni[], int notas[], int N){
    for(int i = 0; i < N; i++){
        if(dni[i] != 0){
            printf("El alumno de DNI: %d tuvo una nota de %d\n",dni[i],notas[i]);
        }
    }
}

void burbujeo(int notas[], int dni[], int N){
    int i, j, auxNotas, auxDNI;
    for(i=0;i<N-1;i++){
        for(j=0;j >= N-1-i;j++){
            if(notas[j] >=notas[j+1]){
                auxNotas = notas[j];
                notas[j] = notas[j+1];
                notas[j+1] = auxNotas;
                auxDNI = dni[j];
                dni[j] = dni[j+1];
                dni[j+1] = auxDNI;
            }
        }
    }
}
/*
5.5 Al programa anterior agregarle una función que reciba la dirección de inicio del vector y un número a buscar
y retorne un puntero al dato encontrado o NULL sino lo encuentra. En el main agregar un proceso de
búsqueda que se repita hasta ingresar un número negativo o cero a buscar. Si se lo encontró se debe
indicar en que posición del vector estaba (calcular dicha posición utilizando la dirección retornada)
*/

#include <stdio.h>

void carga(int[], int);
void mostrar(int[], int);
int* busqueda(int[], int);

int main(){
    int vec[5];
    int aux;
    int *paux;
    carga(vec, 5);
    mostrar(vec, 5);
    do{
        printf("Ingrese un numero a buscar: \n");
        scanf("%d",&aux);
        paux = busqueda(vec, aux);
        if(paux != NULL){
            printf("El numero es el %d", *(paux));
            int i = paux - vec;
            printf("\nEl numero esta en la posicion: %d\n", i + 1);
        }else{
            printf("NO se encontro al num\n");
        }
    }while(aux > 0);
    return 0;
}

void carga(int v[], int ce){
    int i = 0;
    for(i; i < ce; i++){
        printf("Ingrese un entero\n");
        scanf("%d", v + i);
    }
}

void mostrar(int v[], int ce){
    int i;
    for(i = 0; i < ce; i++){
        printf("%d\n",*(v+i));
    }
}

int* busqueda(int v[], int busc){
    int i = 0, *paux = NULL;
    while(i < 5 && paux == NULL){
        printf("\nIn the while: %d\n", *(v+i));
        if(*(v + i ) == busc){
            paux = v+i;
        }else{
            i++;
        }
    }
    return paux;
}
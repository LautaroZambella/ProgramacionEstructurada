/*
5.3 Realizar una función que permita ingresar por teclado un valor entero, un flotante y un carácter. La función
no debe retornar ningún valor. Las variables se declaran y se muestran en el programa principal.
*/

#include <stdio.h>
#include <stdlib.h>

void cargaDatos(int*, float*, char*);

int main(){
    int a;
    float b;
    char c;

    cargaDatos(&a, &b, &c);

    printf("\nInt: %d, float: %.2f, char: %c\n", a, b, c);
}

void cargaDatos(int *pa, float *pb, char *pc){
    printf("Ingrese el entero a mostrar: \n");
    scanf("%d",pa);
    fflush(stdin);
    printf("Ingrese el float a mostrar: \n");
    scanf("%f",pb);
    fflush(stdin);
    printf("Ingrese el char a mostrar: \n");
    scanf("%c",pc);
}
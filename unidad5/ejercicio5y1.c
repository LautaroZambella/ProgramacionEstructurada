/*
5.1 Crear una variable entera y un puntero a dicha variable
Asignar el valor 10 a la variable mediante el puntero
Mostrar:
a) la dirección de la variable
b) la dirección del puntero
c) el contenido de la variable
d) el contenido de la variable accediendo mediante el puntero
e) el contenido del puntero
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, *p;

    p = &a;
    *p = 10;

    printf("Direccion de la variable a: %p\n", &a);
    printf("Direccion del puntero p: %p\n",&p);
    printf("a contiene el valor: %d\n", a);
    printf("El valor de a segun p: %d\n",*p);
}
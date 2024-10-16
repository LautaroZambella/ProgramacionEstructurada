/*
5.2 Definir dos números enteros y dos punteros a dichos números. Accediendo mediante los punteros sumar
ambos números y mostrar el resultado por pantalla.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, result, *pa, *pb;

    pa = &a;
    pb = &b;

    *pa = 10;
    *pb = 20;

    result = *pa + *pb;
    printf("Resultado es igual a: %d", result);
    return 0;
}
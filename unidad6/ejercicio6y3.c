/*
El archivo ventas.dat contiene información histórica de las ventas realizadas por una empresa desde el año
2014 al 2023. El formato de registro es el siguiente:
• Mes (entero)
• Año (entero)
• Dia (entero)
• Código de Producto (entero)
• Importe de la venta (real)
Se pide ingresar un rango de años y mostrar un cuadro ventas realizadas en cada mes de cada año. Por ejemplo,
si se ingresa desde 2020 a 2022 debe mostrar lo siguiente:
    Mes 1 Mes 2 Mes 3 ……. Mes 12
2020 xxx xxx xxx xxx
2021 xxx xxx xxx xxx
2022 xxx xxx xxx xxx 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int mes;
    int anio;
    int dia;
    int cod;
    float importe;
}venta;

int main(){
    
}
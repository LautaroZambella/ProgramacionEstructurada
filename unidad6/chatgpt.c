#include <stdio.h>
#include <stdlib.h>

#define MAX_ANIOS 10
#define MAX_MESES 12

typedef struct {
    int mes;
    int anio;
    int dia;
    int codigoProducto;
    float importe;
} Venta;

void leerVentas(Venta ventas[], int *cantidadVentas);
void contarVentas(int inicio, int fin, Venta ventas[], int cantidadVentas, int matrizVentas[MAX_ANIOS][MAX_MESES]);
void sumarImportes(int inicio, int fin, Venta ventas[], int cantidadVentas, float matrizImportes[MAX_ANIOS][MAX_MESES]);
void mostrarCuadro(int inicio, int fin, int matrizVentas[MAX_ANIOS][MAX_MESES], float matrizImportes[MAX_ANIOS][MAX_MESES], int mostrarImportes);

int main() {
    Venta ventas[1000];
    int cantidadVentas = 0;
    leerVentas(ventas, &cantidadVentas);

    int inicioAnio, finAnio;
    printf("Ingrese el rango de años (inicio y fin): ");
    scanf("%d %d", &inicioAnio, &finAnio);

    int matrizVentas[MAX_ANIOS][MAX_MESES] = {0};
    float matrizImportes[MAX_ANIOS][MAX_MESES] = {0};

    contarVentas(inicioAnio, finAnio, ventas, cantidadVentas, matrizVentas);
    sumarImportes(inicioAnio, finAnio, ventas, cantidadVentas, matrizImportes);

    int opcion;
    do {
        printf("\nSeleccione la vista:\n1. Cantidad de ventas\n2. Importe total\n3. Salir\n");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                mostrarCuadro(inicioAnio, finAnio, matrizVentas, matrizImportes, 0);
                break;
            case 2:
                mostrarCuadro(inicioAnio, finAnio, matrizVentas, matrizImportes, 1);
                break;
        }
    } while (opcion != 3);

    return 0;
}

void leerVentas(Venta ventas[], int *cantidadVentas) {
    FILE *archivo = fopen("ventas.dat", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de ventas.\n");
        exit(1);
    }

    while (fread(&ventas[*cantidadVentas], sizeof(Venta), 1, archivo)) {
        (*cantidadVentas)++;
    }

    fclose(archivo);
}

void contarVentas(int inicio, int fin, Venta ventas[], int cantidadVentas, int matrizVentas[MAX_ANIOS][MAX_MESES]) {
    for (int i = 0; i < cantidadVentas; i++) {
        if (ventas[i].anio >= inicio && ventas[i].anio <= fin) {
            matrizVentas[ventas[i].anio - inicio][ventas[i].mes - 1]++;
        }
    }
}

void sumarImportes(int inicio, int fin, Venta ventas[], int cantidadVentas, float matrizImportes[MAX_ANIOS][MAX_MESES]) {
    for (int i = 0; i < cantidadVentas; i++) {
        if (ventas[i].anio >= inicio && ventas[i].anio <= fin) {
            matrizImportes[ventas[i].anio - inicio][ventas[i].mes - 1] += ventas[i].importe;
        }
    }
}

void mostrarCuadro(int inicio, int fin, int matrizVentas[MAX_ANIOS][MAX_MESES], float matrizImportes[MAX_ANIOS][MAX_MESES], int mostrarImportes) {
    printf("\nCuadro de ventas de %d a %d\n", inicio, fin);
    printf("Mes 1 Mes 2 Mes 3 ... Mes 12\n");
    for (int anio = inicio; anio <= fin; anio++) {
        printf("%d ", anio);
        for (int mes = 0; mes < MAX_MESES; mes++) {
            if (mostrarImportes)
                printf("%.2f ", matrizImportes[anio - inicio][mes]);
            else
                printf("%d ", matrizVentas[anio - inicio][mes]);
        }
        printf("\n");
    }
}

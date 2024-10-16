/*Una cadena de artículos del hogar necesita liquidar comisiones de sus casi 50 vendedores y para ello se deben registrar y almacenar con la estructura adecuada:

- Numero de Vendedor (entero de 2 cifras no correlativo y sin repetidos)
- Nombre Vendedor (string de 25 caracteres)
- Sector (E = Electrodomésticos, M = Muebles, V = Vajillas, T = Telefonía)
- Porcentaje de comisión (entero entre 5 y 15)
- Comisión a cobrar (real)

La liquidación de comisiones termina con el ingreso de un número de vendedor igual a cero.  
Luego por cada vendedor se ingresarán las ventas que hizo por cada día (real mayor o igual que 0) en los 21 días del mes y debe actualizar la comisión a cobrar. También finaliza con un número de vendedor igual a cero.

**Se necesita determinar e informar:**

1. Listado de comisiones cobradas por día y vendedor mostrando su nombre (resolver en una función).
2. El nombre del vendedor que cobra la menor comisión actualizada, en caso de ser más de uno mostrarlos a todos.
3. El importe total a pagar de comisiones por cada sector (resolver en una función).

Validar todos los datos que ingresen por teclado según lo indicado.  
El código debe estar correctamente indentado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIAS 3

typedef struct{
    int num;
    char name[26];
    char sector;
    int porcentaje;
    float comision;
} vendedor;

int cargaVendedores(vendedor[], int);
int buscar(vendedor[], int, int);
void mostrarVendedores(vendedor[], int);
void cargaVentas(vendedor[], float[][DIAS], int);
void mostrarMat(float[][DIAS], int, vendedor[]);
void menorComision(vendedor[], int);
void totalComPorSector(vendedor[], int);

int main(){
    vendedor vendedores[50];
    float ventas[50][DIAS] = {{0}};

    int cant = cargaVendedores(vendedores, 50);
    mostrarVendedores(vendedores, cant);
    cargaVentas(vendedores, ventas, cant);
    mostrarVendedores(vendedores, cant);
    mostrarMat(ventas, cant, vendedores);
    menorComision(vendedores, cant);
    totalComPorSector(vendedores, cant);
}

int cargaVendedores(vendedor v[], int cant){
    int i = 0, auxNum;
    
    do{
        printf("Ingrese el numero de vendedor\n");
        scanf("%d",&auxNum);
    }while((auxNum < 10 || auxNum > 99) && auxNum != 0);
    while(auxNum != 0 && i < cant){
        v[i].num = auxNum;
        fflush(stdin);
        printf("Ingrese el nombre del vendedor\n");
        gets(v[i].name);
        fflush(stdin);
        do{
            printf("Ingrese el sector del vendedor\n");
            scanf("%c",&v[i].sector);
            v[i].sector = toupper(v[i].sector);//EMVT
            fflush(stdin);
        }while(v[i].sector != 'E' && v[i].sector != 'M' && v[i].sector != 'V' && v[i].sector != 'T');
        do{
            printf("Ingrese el porcentaje de comision\n");
            scanf("%d",&v[i].porcentaje);
        }while(v[i].porcentaje < 5 || v[i].porcentaje > 15);
        v[i].comision = 0;

        i++;

        do{
            printf("Ingrese el numero de vendedor\n");
            scanf("%d",&auxNum);
        }while(((auxNum < 10 || auxNum > 99) && auxNum != 0) || buscar(v, auxNum, i) != -1);
    }
    return i;
}

int buscar(vendedor v[], int busc, int tam){
    int i = 0, pos = -1;
    // printf("%d: %d\n", busc, tam);
    while(i < tam && pos == -1){
        // printf("Vuelta numero i:%d",i);
        if(v[i].num == busc){
            pos = i;
            // printf("Dentro del if: %d -> pos y %d -> es i", pos, i);
        }else{
            i++;
        }
    }
    // printf("POS: %d", pos);
    return pos;
}

void mostrarVendedores(vendedor v[], int tam){
    int i = 0;
    for(i; i<tam; i++){
        printf("El vendedor de num: %d y nombre: %s que trabaja en el sector: %c\n con un porcentaje de: %d tiene una comision de %.2f\n",v[i].num,v[i].name,v[i].sector,v[i].porcentaje,v[i].comision);
    }
}

void cargaVentas(vendedor v[], float mat[][DIAS], int cant){
    int auxNum, pos;
    float auxVentas;
    do{
        printf("Ingrese el numero de vendedor\n");
        scanf("%d",&auxNum);
    }while(((auxNum < 10 || auxNum > 99) && auxNum != 0) || buscar(v, auxNum, cant) == -1);


    while(auxNum != 0){
        pos = buscar(v, auxNum, cant);
        int i = 0, j = 0;
        float acu = 0;
        for(i; i<DIAS; i++){
            do{
                printf("Ingrese cuanto se vendio carajo\n");
                scanf("%f",&auxVentas);
            }while(auxVentas < 0);
            mat[pos][i] += auxVentas;
            acu += mat[pos][i];
        }
        v[pos].comision += (acu*v[pos].porcentaje)/100;

        do{
            printf("Ingrese el numero de vendedor\n");
            scanf("%d",&auxNum);
        }while(((auxNum < 10 || auxNum > 99) || buscar(v, auxNum, cant) == -1) &&  auxNum != 0);
    }
}

void mostrarMat(float mat[][DIAS], int cant, vendedor v[]){
    int i = 0, j = 0;
    for(i = 0; i<cant;i++){
        for(j = 0;j<DIAS;j++){
            printf("nombre vendedor: %s, venta del dia: %.2f ", v[i].name, mat[i][j]);
        }
        printf("\n");
    }
}

void menorComision(vendedor v[], int cant){
    float min = v[0].comision;
    int i;

    for(i = 1; i<cant; i++){
        if(v[i].comision < min){
            min = v[i].comision;
        }
    }
    int j;
    printf("Los vendedores con la menor comision son: \n");
    for(j = 0; j < cant; j++){
        if(v[j].comision == min){
            printf("%s\n",v[j].name);
        }
    }
    printf("Con una comision de: %.2f",min);
}

void totalComPorSector(vendedor v[], int cant){
    int i;
    float cantXSec[4] = {0};//EMVT
    for(i = 0; i<cant; i++){
        if(v[i].sector == 'E'){
            cantXSec[0] += v[i].comision;
        }else if(v[i].sector == 'M'){
            cantXSec[1] += v[i].comision;
        }else if(v[i].sector == 'V'){
            cantXSec[2] += v[i].comision;
        }else{
            cantXSec[3] += v[i].comision;
        }
    }
    printf("\nEn el sector E el total es: %f, sector M: %f, sector V: %f, sector T: %f\n",cantXSec[0],cantXSec[1],cantXSec[2],cantXSec[3]);
}
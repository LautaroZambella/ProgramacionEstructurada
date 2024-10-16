#include <stdio.h>
#include <stdlib.h>
#define FIL 3
#define COL 3

void cargaInicial(char[][COL], int, int);
void mostrarMat(char[][COL], int, int);
void gameLoop(char[][COL], int, int);
int winCheck(char[][COL], int, int);

int main(){
    char game[FIL][COL];

    cargaInicial(game, FIL, COL);
    gameLoop(game, FIL, COL);
}

void cargaInicial(char game[][COL], int fil, int col){
    char blank = '\0';
    int i, j;
    for(i = 0; i<fil; i++){
        for(j = 0; j < col; j++){
            game[i][j] = blank;
        }
    }
}

void mostrarMat(char game[][COL], int fil, int col){
    int i, j;
    for(i = 0; i<fil; i++){
        for(j = 0; j < col; j++){
            printf(" %c", game[i][j]);
        }
        printf("\n");
    }
}

void gameLoop(char game[][COL], int fil, int col){
    int filaDeseada, columnaDeseada, i = 0, victory = 0;
    mostrarMat(game, fil, col);

    while(i < 9 && victory == 0){
        do{
            printf("Ingrese una fila\n");
            scanf("%d",&filaDeseada);
        }while(filaDeseada < 0 || filaDeseada > 3);
        do{
            printf("Ingrese una columna\n");
            scanf("%d",&columnaDeseada);
        }while(columnaDeseada < 0 || columnaDeseada > 3);

        if(game[filaDeseada-1][columnaDeseada-1] == '\0'){
            if(i % 2 == 0){
                game[filaDeseada-1][columnaDeseada-1] = 'X';
            }else{
                game[filaDeseada-1][columnaDeseada-1] = 'O';
            }
            i++;
            mostrarMat(game, fil, col);
        }else{
            printf("Espacio ya ocupado, elija otro\n");
        }
        victory = winCheck(game, fil, col);
    }
    if(victory > 0){
        printf("\nGano el jugador 1\n");
    }else if(victory < 0){
        printf("\nGano el jugador 2\n");
    }else{
        printf("\nEmpate\n");
    }
}

int winCheck(char game[][COL], int fil, int col){
    if((game[0][0] == 'X' && game[0][1] == 'X' && game[0][2] == 'X')
    || (game[1][0] == 'X' && game[1][1] == 'X' && game[1][2] == 'X')
    || (game[2][0] == 'X' && game[2][1] == 'X' && game[2][2] == 'X')
    ||(game[0][0] == 'X' && game[1][0] == 'X' && game[2][0] == 'X')
    || (game[0][1] == 'X' && game[1][1] == 'X' && game[2][1] == 'X')
    || (game[0][2] == 'X' && game[1][2] == 'X' && game[2][2] == 'X')
    || (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X')
    || (game[2][0] == 'X' && game[1][1] == 'X' && game[0][2] == 'X')){
        return 1;
    } else if((game[0][0] == 'O' && game[0][1] == 'O' && game[0][2] == 'O')
    || (game[1][0] == 'O' && game[1][1] == 'O' && game[1][2] == 'O')
    || (game[2][0] == 'O' && game[2][1] == 'O' && game[2][2] == 'O')
    ||(game[0][0] == 'O' && game[1][0] == 'O' && game[2][0] == 'O')
    || (game[0][1] == 'O' && game[1][1] == 'O' && game[2][1] == 'O')
    || (game[0][2] == 'O' && game[1][2] == 'O' && game[2][2] == 'O')
    || (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O')
    || (game[2][0] == 'O' && game[1][1] == 'O' && game[0][2] == 'O')){
        return -1;
    }
    return 0;
}

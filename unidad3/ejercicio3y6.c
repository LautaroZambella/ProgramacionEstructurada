/*
3.6 Realizar el juego del ahorcado. Primero se debe ingresar la palabra a adivinar de hasta 10 caracteres. Luego
se muestra por cada letra un guion bajo para que el jugador sepa la cantidad de letras a adivinar. Se irá
ingresando una a una las letras y si estas se encuentran en la palabra las deberá ir mostrando en el lugar
correspondiente. Por cada letra que no se encuentre en la palabra perderá una vida. El jugador dispondrá de
5 vidas para intentar ganar el juego.
*/
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

void getString(char[]);
void gameLoop(char[], int, int);
char guess();
int checkForGuess(char[], int, char, char[]);

int main() {
    int vidas = 5;
    // char str[] = "Hellooo, World!"; //Declare and initialize a string 
    // int len = strlen(str); //Calculate the length of the string using strlen() 

    // printf("The length of the string '%s' is %d\n", str, len);
    char adivinar[11];
    // char check = 'c';
    getString(adivinar);
    printf("--COMIENZA EL JUEGO CARAJO!!!--\n");
    printf("La palabra a adivinar es: %s\n",adivinar);
    int len = strlen(adivinar);
    fflush(stdin);
    gameLoop(adivinar, len, vidas);
    // printf("Lenght: %d, char = %c\n",len,check);
    // for(int i = 0; i<len;i++){
    //     if(adivinar[i] == check){
    //         printf("Son iguales\n");
    //     }
    // }
    return 0; 
}

void getString(char toGuess[11]){
    fflush(stdin);
    printf("\nIngrese la palabra a adivinar\n");
    gets(toGuess);
    // printf("La palabra a adivinar es: %s\n",toGuess);
}

void gameLoop(char adivinar[11], int len, int vidas){
    char copia[11];
    char nextGuess;
    for(int i = 0; i < 10; i++){
        if(i<len){
            copia[i] = '_';
        }else{
            copia[i] = '\0';
        }
    }
    for(int j = 0; j < 11; j++){
        printf("%c ",copia[j]);
    }
    nextGuess = guess();
    while(vidas > 0 || strcmpi(copia, adivinar)){
        vidas += checkForGuess(copia, len, nextGuess, adivinar);
        nextGuess = guess();
        for(int j = 0; j < 11; j++){
        printf("%c ",copia[j]);
    }
    }
    printf("\n--FIN DEL JUEGO CARAJO--\n");
}

char guess(){
    char intento;
    fflush(stdin);
    printf("Ingrese la letra para adivinar\n");
    scanf("%c",&intento);
    return intento;
}

int checkForGuess(char str[11], int len, char guess, char adivinar[11]){
    int i;
    // printf("%s:   %c\n", str, guess);
    for(i = 0; i < len; i++){
        printf("\n%d\n", i);
        if(adivinar[i] == guess){
            str[i] = guess;
            return 0;
        }
    }
    printf("Letra NO presente\n");
    return -1;
}
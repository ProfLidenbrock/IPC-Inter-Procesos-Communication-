/*
PROGRAMA QUE CAPTURA HASTA 5 SIGINT (Control+C)
*/

#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
 
//Declaramos los prototipos de funciones
void manejador(int signum);
 
//Variables globales
int con = 0;
 
//PROGRAMA PRINCIPAL
int main(int argc, char **argv){
 
    //Capturamos la señal SIGINT
    signal(SIGINT, manejador);
 
    printf("Ejemplo de signal\n");
 
    //Hacemos un bucle para permitir que se hagan hasta 5 SIGINTs
    while(con<5);

}
 
//Funcion manejador
//Cuando se presiona un sigint se llama a esta función
void manejador (int signum){
    con++;
    printf("\nRecibi la señal nº%d sigint\n", con);

    signal(SIGINT, manejador);
}

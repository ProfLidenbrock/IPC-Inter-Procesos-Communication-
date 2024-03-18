#include <stdio.h>
#include <stdlib.h>         // uso fork()
#include <unistd.h>         // uso fork()
#include <sys/wait.h>       // uso wait()
#include <sys/types.h>

#include <signal.h>

//Declaramos los prototipos de funciones
void manejador(int signum);

//Variable global
int bandera = 1;

//PROGRAMA PRINCIPAL
int main(int argc, char **argv){
 
    //Capturamos la señal SIGALRM
    signal(SIGALRM, manejador);

    printf("EN 10 segundos se creara una alarma\n");
    //Crear alarma en segundos
    alarm(10);
 
    //Mientras bandera sea 1, no finalizar el programa
    int contador = 1;
    while(bandera){
        sleep(1);
        printf("Estoy en el bucle %d segundos. \n", contador);
        contador++;
    }

    printf("Finalizo el progrma. \n");
    exit(0);
 
}
 
//Funcion manejador
void manejador (int signum){
    printf("\nRecibi una alarma (y salgo del bucle) \n");
    //signal(SIGINT,SIG_DFL);
    bandera = 0;                // Cambiamos el valor de la variable global para salir del buble infinito
}

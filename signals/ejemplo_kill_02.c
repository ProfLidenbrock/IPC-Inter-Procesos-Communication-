/*

MODO DE EJECUCION DEL PROGRAMA
------------------------------

    ./ejemplo_kill_02 SIGUSR1      o
    ./ejemplo_kill_02 SIGPIPE


EXPLICACION DEL PROGRAMA
------------------------

Nada mas ejecutar el programa, se prepara para capturar las señales SIGUSR1 y SIGUSR2

Se crea un proceso hijo que quedara en bucle infinito.

El padre, se prepara para capturar la señal SIGINT (control + C).
Cuando el proceso padre reciba la signal SIGINT, ejecutara su manajador que mandara la signal SIGUSR1 o SIGUSR2 (dependiendo de lo que hayamos puesto como parametro de entrada) en
  linea de comandos. 

Cuando el hijo ejecute se manejador, cambia la bandera y sale del bucle infinito.


*/


//El padre debe mandar una señal SIGUSR1 o SIGUSR2 al hijo
//La señal debe pasarse a través de la consola
 
#include <stdio.h>
#include <stdlib.h>     // uso fork()
#include <unistd.h>     // uso fork()
#include <sys/wait.h>   // uso wait()
#include <signal.h>		// uso de señales
#include <sys/types.h>
#include <string.h>     // uso de strcmp

//Prototipos
void manejador(int signum);
void manejador2(int signum);
 
//Variables globales
int bandera = 1;
int pid, status;
char *parametro;
 
int main(int argc, char **argv){
	parametro = argv[1];	//Guardamos el argumento 1 en la variable parametro
 
 	signal(SIGUSR1, manejador2);		//Capturamos las señales
 	signal(SIGUSR2, manejador2);

 	pid = fork();
 	if(pid == 0){	// proceso HIJO
 		printf("Soy el hijo \n");
 
 		while(bandera);				//Utilizamos la variable bandera para que el proceso no termine
 
 	} else {		//proceso PADRE
 
 		signal(SIGINT, manejador);	//Capturamos la señal SIGINT para luego enviar la señal al hijo
 		wait(&status);				//Esperamos que termine el hijo
 	}
}
 
void manejador(int signum){
	printf("PID: %d", pid);
 
 	if(strcmp(parametro, "SIGUSR1") == 0){		//Comparamos si el parametro es SIGUSR1
 		printf("\n Mandando la signal SIGUSR1 a mi hijo\n");
 		kill(pid, 10);						//Enviamos la señal al hijo
 
 	} else {
 		printf("\n Mandando la signal SIGUSR2 a mi hijo\n");
 		kill(pid, 12);						//Enviamos la señal al hijo
 	} 
}
 
void manejador2(int signum){
	printf("Recibi la signal %d de mi padre\n", signum);		// Mostramos la señal que fue enviada por el padre
 	bandera = 0;												// Rompemos el bucle infinito
}

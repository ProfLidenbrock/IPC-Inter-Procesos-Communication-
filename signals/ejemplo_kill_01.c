#include <stdio.h>
#include <stdlib.h>     // uso fork()
#include <unistd.h>     // uso fork()
#include <sys/wait.h>   // uso wait()
#include <signal.h>
#include <sys/types.h>
 
//Declaramos los prototipos de funciones
void manejador(int signum);
 

int bandera = 1;    //Variable global
 
int main(int argc, char **argv){
 
    int status,pid;
 
    pid=fork();
    if (pid == 0){        //Proceso hijo

        printf("Soy hijo y estoy esperando una señal de mi padre, mi pid es: %d\n",getpid());
    
        signal(SIGUSR1, manejador);      //Capturamos la señal SIGUSR1
 
        //Utilizamos la variable bandera para que el proceso no termine
        while(bandera);
 
        //Usamos el comando kill para enviar una señal
        //Se necesita el pid del padre y la señal
        kill(getppid(), SIGUSR2);

    } else {                    //Proceso padre
 
        //Capturamos la señal SIGUSR2
        signal(SIGUSR2, manejador);
        printf("Soy Padre, mi pid es: %d\n",getpid());
 
        //Esperamos 3 segundos
        sleep(3);
 
        //Usamos el comando kill para enviar una señal al hijo
        //(Se necesita el pid y la señal)
        kill(pid, SIGUSR1);
 
        //Esperamos que termine el hijo
        wait(&status);
        printf("Mi hijo termino con un estado: %d\n", status);
    }
}
 
//Funcion manejador
void manejador (int signum){
    if(signum == SIGUSR1){        //Si la señal es SIGUSR1 entonces
        printf("Recibi una senal de mi padre %d\n", signum);

    } else {                    //Si es SIGUSR2 entonces
        printf("Recibi una senal de mi hijo %d\n", signum);
    }
    bandera = 0;
}

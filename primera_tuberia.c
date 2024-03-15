/*
Ejemplo de la creación de una primera tubería en Linux.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXLINEA 10

int main(int argc, char *argv[]){

	int n, fd[2];
    pid_t pid;
    char linea[50];

    if (pipe(fd) < 0){
        printf("Error en creacion de pipe");
    }
 	
 	if ((pid=fork()) < 0){
 		printf("Error en el fork ");

    } else if (pid > 0){                // proceso PADRE
        close(fd[0]);
        write(fd[1], "HOLA MUNDO", MAXLINEA);

    } else {                            // proceso HIJO
        close(fd[1]);
        n = read(fd[0], linea, MAXLINEA);
        write(STDOUT_FILENO, linea, n);
    }
    exit(0);
}

#include <stdio.h>
#include <stdlib.h>         // uso fork()
#include <unistd.h>         // uso fork()
#include <sys/wait.h>       // uso wait()
#include <sys/types.h>

#include <signal.h>

void alarma(){
   printf("Acabo de recibir un SIGALRM. \n");
}

//PROGRAMA PRINCIPAL
int main(int argc, char **argv){

    signal(SIGALRM,alarma);

    printf("Acabo de programar la captura de un SIGALRM. \n");
    alarm(3);

    printf("Ahora he programado la alarma para que venga en 3 segundos. \n");
    pause();

    printf("Ahora continúo con la ejecución normal. \n");
}

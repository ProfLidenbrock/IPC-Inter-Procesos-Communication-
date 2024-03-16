/*

Demostracion de que si intentamos leer informacion de una tuberia que NO CONTIENTE NADA, NOS BLOQUEAMOS.

El programa puede recibir parametros por linea de comandos (./bloqueante 6) y entonces 
    1º escribira informacion en una pipe
    2º luego la leera

Si el programa NO recibe parametros por linea de comandos (./bloquante), entonces:
    No escribira nada en la pipe
    Cuando intente leer se quedara bloqueado.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {

  int pipefd[2];
  if (pipe(pipefd)) {
    perror("pipe() failed");
    exit(-1);
  }

  if (argc > 1) {
    char c = 0;
    if (write(pipefd[1], &c, 1) != 1) {
      perror("write() failed");
      exit(-1);
    }
    printf("ESCRIBE informacion \n");
  }

  char c;
  if (read(pipefd[0], &c, 1) != 1) {
    perror("read() failed");
    exit(-1);
  }
  printf("LEE informacion \n");
  exit(0);
}

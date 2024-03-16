/*

PREGUNTA
--------

¿Por que si descomentas la linea 25, ya no muestra el mensaje?

¿Se esta bloquando el proceso?, ¿Que esta sucediendo?


*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {

  char c = 0;

  int tuberia[2];

  pipe(tuberia);

  //close(tuberia[0]);                 // DESCOMENTA ESTA LINEA Y PRUEBA EL FUNCIONAMIENTO DE NUEVO
  write(tuberia[1], &c, 1);
  
  printf("ESCRIBE informacion en la tuberia \n");
  exit(0);
  
}

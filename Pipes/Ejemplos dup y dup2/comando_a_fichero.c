/*
Ejemplo donde se hace uso de la llamada dup2() y donde se envia la ejecucion de EXEC a un fichero de texto.

La salida estándar y la salida de error en el proceso hijo son sustituidas por el descriptor de fichero "test.txt"
*/

#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {      // Proceso HIJO

        int fd = open("test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

        dup2(fd, 1);   // make stdout go to file
        dup2(fd, 2);   // make stderr go to file - you may choose to not do this
                       // or perhaps send stderr to another file

        close(fd);     // fd no longer needed - the dup'ed handles are sufficient

        execlp("ls", "ls", NULL);

    } else {                // Proceso PADRE

        while (wait(NULL) > 0) {} // wait for each child process
    }

    return 0;
}

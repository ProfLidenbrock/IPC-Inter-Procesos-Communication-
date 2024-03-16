Los procesos pueden ser independientes o cooperar entre sÍ.

¿Por qué puede ser interesante que varios procesos cooperen?

1) Para compartir información.
2) Para acelerar la computación que realizan.
3) Por modularidad

Para poder cooperar, los procesos necesitan comunicarse (IPC = Interprocess Communication)

Para comunicar datos hay 2 modelos principalmente:

- Memoria compartida (Shared memory)
Los procesos utilizan variables que pueden leer/escribir

- Paso de mensajes (Message passing)
Los procesos utilizan funciones para enviar/recibir datos.

¿De qué dispondremos para hacer esto?

• Señales (Signals): son eventos enviados por otros procesos (del mismo usuario) o por el kernel para indicar determinadas condiciones.

• Tuberías (Pipes): dispositivos que permiten comunicar 2 procesos que se ejecutan en la misma máquina. 
Los primeros datos que se envían son los primeros que se reciben. 
La idea principal es conectar la salida de un programa con la entrada de otro (este sistema es utilizado principalmente por la shell).

• FIFOS: funcionan con pipes que tienen un nombre en el sistema de ficheros. Los procesos a comunicarse no tienen porque tener una relación de familia.

• Sockets: dispositivos que permiten comunicar 2 procesos a través de la red. 

• Semáforos: contenedores que permiten controlar el acceso a recursos compartidos. Se utilizan para prevenir el acceso de más de un proceso a un recurso compartido (por ejemplo, memoria)

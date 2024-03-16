Una de las primeras cosas que aprende un programador de UNIX es que cada programa en ejecución comienza con 3 archivos ya abiertos:

Archivos estándar proporcionados por UNIX

![image](https://github.com/ProfLidenbrock/IPC-Inter-Procesos-Communication-/assets/163530177/61d20e89-d553-4ae6-8d0d-b8894f820866)

![image](https://github.com/ProfLidenbrock/IPC-Inter-Procesos-Communication-/assets/163530177/2af3a43a-0391-4328-bd71-0a47697f4bf8)

Para facilitar el acceso a los distintos recursos del sistema (zona de almacenamiento en disco, teclado, pantalla, socket,…), el kernel de Linux vincula cada recurso con un fichero, real (espacio en disco) o virtual (en memoria, como /dev y /proc). 

Ejemplos habituales son:
![image](https://github.com/ProfLidenbrock/IPC-Inter-Procesos-Communication-/assets/163530177/41f15936-ca5e-4545-870d-7b7b787daca5)

Cuando un proceso necesita acceder a un recurso, debe hacer lo siguiente:

1. Abrir el fichero correspondiente al recurso: Como respuesta, el SO devolverá al proceso el descriptor (o descriptor de fichero) con el que el proceso podrá acceder al fichero.

2. Accede al fichero/recurso usando el descriptor suministrado por el sistema: el proceso indicará el descriptor al kernel, éste localiza el fichero y accede al recurso asociado.

![image](https://github.com/ProfLidenbrock/IPC-Inter-Procesos-Communication-/assets/163530177/9fc02484-1afe-440d-bd11-9b1cf021cba5)

Un descriptor no es más que un nº entero, con las siguientes características:

![image](https://github.com/ProfLidenbrock/IPC-Inter-Procesos-Communication-/assets/163530177/c5c48402-7648-4ae9-b8c9-f04ccec5cd3e)

![image](https://github.com/ProfLidenbrock/IPC-Inter-Procesos-Communication-/assets/163530177/a39f4388-a4ea-4154-b5b7-825436d8c170)

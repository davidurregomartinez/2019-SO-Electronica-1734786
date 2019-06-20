mem.c
Para lograr que este programa funcione, se debía de desactivar la generación
aleatoria de direcciones de memoria. Para ello se digitó el siguiente comando
en la terminal: "echo 0 > /proc/sys/kernel/randomize_va_space".
Este comando escribe un 0 en el archivo de la dirección, desactivando así la
generación aleatoria de direcciones de memoria, si se excede el maximo soportado
por la variable int, el programa experimenta fallos.


threads.c

en este programa se define una variable global counter y se iguala a cero
de mycommon.h se define el pthread, los hilos, como una variable puerta
se define un metodo *worker el cual va a ser llamado por los procesos.

en la funcion principal main() se verifica con un condicional si el numero de
argumentos es el de dos numeros, requeridos para el proceso, luego
se usa la funcion crear puerta definida en mycommons.h junto con la variable
de puerta, se usa el vector de argumentos para definir el numero de veces
que itera el programa, esto se obtiene en entero usando una funcion que lo
convierte de ascii.

Posteriromente se declaran los procesos como pthread_t

con pthread se crea el proceso usando la posicion de memoria de los procesos
como argumento y la funcion worker como atributo, luego usando pthread_join
se ejecutan los procesos al mismo tiempo, aqui el primer proceso como es
definido en el metodo worker va a cerrar la puerta y va a impedir que el otro
proceso acceda a esta seccion de memoria mientras que este usa los argumentos
para ejecutar el ciclo y modificar la variable, luego este abre la puerta
la cual bloquea el segundo proceso pthread_join despues de estar en
"sleep" mientras el primer proceso modificaba counter, leugo este proceso la
modifica y la abre de nuevo, psoteriormente se usa destruir_puerta(m)
para borrarla y finalizar el programa


io.c

se declara un puntero *fp como FILE, tipo archivo, para que el programa pueda
leerlo
se declaran una variable de posicion del puntero y un contador de posicion

usando un condicional se checha con 'F_OK' el cual es definido en unistd.h
para verificar la existencia del archivo, si este es diferente de cero
el archivo exsite, este es el caso porque se definio POSIX_SOURCE

se le asigna a el puntero de archivo el resutlado de usar el metodo fopen
con es string de argumento de la funcion main que en este caso seria el
archivo de texto abierto desde la terminal, la extension "r" es para abrirlo
de modo lectura.

se usa la funcion fseek a el archivo anteriormente asignado y a partir de la
posicion 0 se manda el puntero de posicion al final de el string
usando SEEK_END

luego se asigna a una variable esta posicion final con la funcion
ftell()

se usa un ciclo comparando la posicion final con un contador que incia en cero
este aumenta en uno en cada iteracion, luego el puntero del archivo se ubica 
al final del puntero restandole el valor de i,posteriormente imprime el caracter
en el que se encuentra y continua interando hasta que alcance el valor final del 
puntero del archivo.

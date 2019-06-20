// programa para leer archivo al reves como argumento

#include <stdio.h>
#define _POSIX_SOURCE
#include <string.h>
#undef _POSIX_SOURCE
#include <unistd.h>

int main(int argc, char *argv[]){
FILE *fp;  //se declara un puntero de tipo archivo(FILE) para que el programa pueda usar el archivo
int pnt = 0; // variable posicion de puntero
int i =0; // contador de posicion

/*se define si el archivo existe sin abrirlo usando la funcion access
y usando el modo F_OK el cual determina la existecia del archivo

*/

if( access( fp, F_OK) != 0) {
	printf("el archivo existe");

} else {
	printf("el archivo no existe");
}

//se abre el archivo
fp = fopen(argv[1], "r");

// se ubica alpuntero del archivo al final del mismo
fseek(fp,0,SEEK_END);
// ftell nos indica la posicion de el puntero del archivo
pnt = ftell(fp);

/*se usa un ciclo comparando la posicion final con un contador que incia en cero
este aumenta en uno en cada iteracion, luego el puntero del archivo se ubica 
al final del puntero restandole el valor de i,posteriormente imprime el caracter
en el que se encuentra y continua interando hasta que alcance el valor final del 
puntero del archivo.
*/
while( i < pnt ){
	i++;
	fseek(fp, -i, SEEK_END);
	printf("%c", fgetc(fp));

}
printf("\n");
fclose(fp);
return 0;

}

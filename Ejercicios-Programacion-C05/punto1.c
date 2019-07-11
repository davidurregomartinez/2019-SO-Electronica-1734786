#include <unistd.h>
#include <stdio.h>


int main(int argc, char** argv){
	int var = 123456;
	int pid = fork();
	if(pid==0){
	  printf("Variable vista por el hijo: %d \n", var);
	  var=659684;
	  printf("Variable cambiada por el proceso hijo: %d \n", var);
	} else {
	  printf("Variable vista por el padre: %d \n", var);
	  var=1839284;
	  printf("Variable cambiada por el proceso padre: %d \n",var);
	}
	return 0;
}

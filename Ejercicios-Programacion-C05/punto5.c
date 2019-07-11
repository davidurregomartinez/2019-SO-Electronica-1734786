//si el wait se pone en el child, pues esperaria a que termine el padre
//algo que ocurre naturalmente.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
int rc = fork();
if(rc == 0) {
	printf("hello, I am child (pid:%d)\n", (int) getpid());

} else {
	int rc_wait = wait(NULL);
	printf("hello i'm parent" );
}

return 0;
}

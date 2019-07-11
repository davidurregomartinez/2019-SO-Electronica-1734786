#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int  argc, char *argv[]) {

int rc = fork();
if(rc < 0){
	fprintf(stderr, "fork failed\n");
	exit(1);
}else if (rc == 0) {
	printf("hello i'm child (pid:%d)\n",rc, (int)
	getpid());
}else {
	printf("hello, i'm parent of %d (pid:%d)\n",rc,
	(int) getpid());
}
char *args[2];
args[0] = "/bin/ls";
args[1] = NULL;
execv(args[0], args );

return 0;

}


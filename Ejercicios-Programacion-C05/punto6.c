/*waitpid se suspende hasta que el hijo termine o hasta que de informacion de proceso
la cual si se provee, retorna inmediatamente. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
pid_t pid;
int status;
if(pid == 0) {
        printf("hello, I am child (pid:%d)\n", (int) getpid());

} else {
        int rc_wait = waitpid(pid, &status, WNOHANG);
        printf("hello i'm parent" );
}

return 0;

}

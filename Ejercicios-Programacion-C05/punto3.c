#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int
main() {
	int rc = fork();
	else if (rc == 0) {
		printf("hello \n");
	}
	else {
		sleep(1);
		printf("goodbye \n");
	}

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TOK_BUFSIZE 64
#define DELIM " \t\r\n"

char *leerl(void){
  char *lin = NULL;
  size_t bufsize = 0;
  getline(&lin, &bufsize, stdin);
  return lin;
}

char **parsetok(char *lin){
  int bufsize = TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(lin, DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, " allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}



int main(int argc, char** argv, char **envp) {
  char *lin;
  char **args;
  char comando[256];
  pid_t pid;
  while (1) {
    char cw[1024];
    getcwd(cw, sizeof(cw));
    printf("%s", cw);
    printf("> ");
    lin = leerl();
    args = parsetok(lin);
    if (strncmp(args[0],"exit",4) == 0) {
      break;
    }
    pid = fork();
    if (pid != 0) {
      wait(NULL);
    } else {
       if (strcmp(args[0],"dir") == 0) {
      char *argsi[2];
      argsi[0] = "/bin/ls";
      argsi[1] = NULL;
      	execv(argsi[0], argsi);
        // listar el contenido de archivos en ese directorio
	// printf("debo listar archivos\n");
      }  else if (strcmp(args[0], "clear") == 0) {
          system("clear");
        // limpiar pantalla
        
       } else if (strcmp(args[0], "cd") == 0){
	 chdir(args[1]);
	 

       } else if (strcmp(args[0], "environ") == 0){
	 for (char **env = envp; *env != 0; env++)
	   {
	     char *thisEnv = *env;
	     printf("%s\n", thisEnv);    
	   }
       } else if (strcmp(args[0], "echo") == 0){
	 printf("%s\n", args[1]);
	 
       }else { 
        //strtok
        //revisar alguna variante de exec 
        //exec(comando);
      }
    }
  }
  	
  exit(0);
}

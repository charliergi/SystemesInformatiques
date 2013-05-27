/**************************************
 * fork-wait.c
 *
 * Programme d'exemple d'utilisation de
 * fork
 *
 *************************************/
///AAA
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main (int argc, char *argv[])  {
  int status;
  pid_t pid;

  pid=fork();

  if (pid==-1) {
    // erreur � l'ex�cution de fork
    perror("fork");
    exit(EXIT_FAILURE);
  }
  // pas d'erreur
  if (pid==0) {
    sleep(8);
    return(42);
  }
  else {
    // processus p�re
    int fils=waitpid(pid,&status,0);
    if(fils==-1) {
      perror("wait");
      exit(EXIT_FAILURE);
    }
    if(WIFEXITED(status)) {
      printf("Le fils %d s'est termin� correctement et a retourn� la valeur %d\n",fils,WEXITSTATUS(status));
      return(EXIT_SUCCESS);
    }
    else {
      if( WIFSIGNALED(status)) {
	printf("Le fils %d a �t� tu� par le signal %d\n",fils,WTERMSIG(status));
      }
      return(EXIT_FAILURE);
    }
  }
}
///BBB

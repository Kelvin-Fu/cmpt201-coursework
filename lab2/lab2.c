/**Lab2.c
#Kelvin Fu
#Date:21/9/2025*/
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *buff = NULL;
  size_t size = 0;
  ssize_t num_char;

  while (1) {

    printf("Enter programs to run.\n> ");

    num_char = getline(&buff, &size, stdin);
    if (num_char == -1) {
      break;
    } else if (num_char <= 1) {
      printf("Exiting\n");
      break;
    }

    if (buff[num_char - 1] == '\n') {
      buff[num_char - 1] = '\0';
    }

    pid_t pid = fork();
    if (pid < 0) {
      printf("fork failed");
      continue;
    }

    if (pid == 0) {
      execl(buff, buff, (char *)NULL);
      printf("Exec failure\n");
      exit(EXIT_FAILURE);
    } else {
      int status;
      waitpid(pid, &status, 0);
    }
  }

  free(buff);
  return 0;
}

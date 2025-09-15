/*
 * Student: Kelvin Fu
 * Lab: 1
 * Date: 14/9/2025
 * Description: Read a full line of user input and prints out each token one at at a time on a new
 * line.
 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buff = NULL;
  size_t size = 0;

  printf("Please enter some text: ");

  ssize_t num_char = getline(&buff, &size, stdin);
  if (num_char == -1) {
    perror("getline failed");
    free(buff);
    exit(EXIT_FAILURE);
  }

  printf("Tokens:\n");

  char *saveptr;
  char *ret = strtok_r(buff, " ", &saveptr);
  while (ret != NULL) {
    printf("%s\n", ret);
    ret = strtok_r(NULL, " ", &saveptr);
  }
  free(buff);
  return 0;
}

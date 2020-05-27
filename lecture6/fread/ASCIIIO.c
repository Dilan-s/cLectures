#include <stdio.h>
#include <stdlib.h>
int main(void) {
  char buffer[100];
  fprintf(stdout, "Enter a string: ");
  fgets(buffer, sizeof(buffer), stdin);
  FILE *out;
  if ((out = fopen("output.txt", "w")) == NULL) {
    perror("output.txt");
    exit(EXIT_FAILURE);
  }
  if (fputs(buffer, out) <= 0) {
    perror("fputs failure");
    exit(EXIT_FAILURE);
  }
  fclose(out);
  return EXIT_SUCCESS;
} 

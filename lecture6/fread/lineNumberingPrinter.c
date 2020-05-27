#include <stdio.h>
#include <string.h>

int main(void) {
  FILE *in;
  char buffer[10];
  int lineNo = 1, isLineStart = 1;
  if ((in = fopen("input.txt", "r")) == NULL) {
    perror("input.txt"); return 1;
  }
  while(fgets(buffer, sizeof(buffer), in) != NULL) {
    if (isLineStart) {printf("%4d ", lineNo++);}
    fputs(buffer, stdout);
    isLineStart = buffer[strlen(buffer)-1] == '\n';
  }
  fclose(in);
  return 0;
}

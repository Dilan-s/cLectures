#include <stdio.h>
#include <stdlib.h>

int main() {

  int *arr = calloc(100, sizeof(int));

  free(arr);

  return EXIT_SUCCESS;
}

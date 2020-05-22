#include <stdio.h>

void printSizeArray(char array[100]) {
  printf("sizeof(array) = %li\n", sizeof(array));
}

void printSizePtr(char *ptr) {
  printf("sizeof(ptr) = %li\n", sizeof(ptr));
}

int main(void) {
  char buffer[100];
  printf("sizeof(buffer) = %li\n", sizeof(buffer));
  printSizeArray(buffer);
  printSizePtr(buffer);
  return 0;
}

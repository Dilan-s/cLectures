#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

  char quote[] = "To be or not to be";

  printf("%s\n", quote);
  
  memset(quote, '.', 9);

  printf("%s\n", quote);

  return EXIT_SUCCESS;

}

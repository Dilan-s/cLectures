#include <stdio.h>
#include "magic.h"
int main(void) {
  initMagic();
  printf("The magic value is %d\n", magic);
  return 0;
}

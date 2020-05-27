#include <assert.h>
#include <stdio.h>

void doSomething(int i) {
  assert(i>1);
}

int main(void) {
  doSomething(1);
  printf("We don’t reach this code.\n");
  return 0;
}

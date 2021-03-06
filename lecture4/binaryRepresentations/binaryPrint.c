#include <stdio.h>
#include <stdint.h>

void printBits(uint32_t x) {
  int i;
  uint32_t mask = 1 << 31;
  for(i=0; i<32; ++i) {
    if((x & mask) == 0){
      printf("0");
    }
    else {
      printf("1");
    }
    x = x << 1;
  }
  printf("\n");
}

int main() {
  int a = 1 << 16;
  printBits(a);
  uint32_t x = 330;
  uint32_t y = 77;
  uint32_t z = 122;
  printBits(x);
  printBits(x << 2);
  printBits(x >> 2);
  printBits(~x);
  printBits(y);
  printBits(z);
  printBits(y|z);
  printBits(y&z);
  printBits(y^z);
  return 0;

}

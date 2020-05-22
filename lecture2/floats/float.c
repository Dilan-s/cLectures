#include <stdio.h>

int main() {

  float x = 1, y = 0.0000001;

  printf("size of float = %ld\n", sizeof(float));

  float sum = x + y;
  float diff = sum - x;
  
  printf("sum=%12.12f diff=%6.12f\n", sum, diff);

  int z = 4.999;

  printf("z = %d\n", z);

  unsigned int a = 0;

  printf("a = %u\n", a);

  a--;

  printf("a = %u\n", a);

  double b;

  b = (double) (3/4);
  printf("b = %lf\n", b);

  b = (double) (3)/4;
  printf("b = %lf\n", b);

  b = (double) (3)/(double) (4);
  printf("b = %lf\n", b);

  return 0;
 

}

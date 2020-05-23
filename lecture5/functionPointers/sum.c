#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

int mul(int a, int b){
  return a * b;
}

int sum(int a, int b){
  return a + b;
}

int power(int a, int b) {
  return pow(a,b);
}

int main (void) {

  int (*sum_ptr) (int, int);
  sum_ptr = &sum; // can be sum, &sum or *sum
  
  printf("the sum of 39 and 73 is %i\n", sum_ptr(39, 73));
  
  srand48(time(NULL));
  
  int (*array_func_ptr[3])(int, int) = {sum, mul, power};

  /*
  array_func_ptr[0] = sum;
  array_func_ptr[1] = mul;
  array_func_ptr[2] = power; 
  */
  
  const char *names[] = {"sum", "mul", "power"};

  int choice = lrand48() % 3;

  int result;

  printf("choosing %s\n", names[choice]);

  result = array_func_ptr[choice](3, 4);

  printf("result is %d\n", result);
  
  return 0;
}

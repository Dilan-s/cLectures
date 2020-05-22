#include <stdio.h>

int fib(int number) {
  if (number == 0 || number == 1) {
    return number;
  } else {
    return fib(number - 1) + fib (number - 2);
  }
}

int main(void) {
  int n;
  printf("enter the number: ");
  scanf("%d", &n);
  
  printf ("fib of %d = %d\n", n, fib(n));
  return 0;
}
  

#include <stdio.h>


int helperfib(int a, int b, int n) {
  if (n < 2) {
    return b;
  }
  return helperfib(b, a+b, n-1);
}

int goodfib(int n){
  return helperfib(0, 1, n);
}

int badfib(int n){
  if (n < 2) {
    return n;
  }
  return badfib(n-1) + badfib(n-2);
}

int main(){

  printf("good fib: %d\n", goodfib(10));
  printf("bad fib: %d\n", badfib(10));
  return 0;
}

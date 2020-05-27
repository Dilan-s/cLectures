#include <stdio.h>

double global = 4.0;

void account() {
  int i = 1;
  printf("In account(): i = %d\n", i);
  i ++;
}

void account2() {
  static int i = 1;
  printf("In account2(): i = %d\n", i);
  i ++;
} 

void account3() {
  printf("In account3(): global = %g\n", global);
  global++;

}

int main() {
  int j=2;
  for(int i=j; i<10; i++) /* i local to for block */
    {
      printf("i+j=%d\n", i+j);
    }
  // printf("i=%d\n", i+j);

  account();
  account();

  account2();
  account2();

  account3();
  account3();

  
  return 0;
}

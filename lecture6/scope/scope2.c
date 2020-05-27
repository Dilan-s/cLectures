#include <stdio.h>

int a = 7;
void one(int a, int b) {
  int c = 9;
  printf("a=%d b=%d c=%d\n",a,b,c);
}

int main(void) {

  int b = 3, c = 10;
  {
    int a = -10;
    int b = 20;
    printf("a=%d b=%d c=%d\n",a,b,c);
  }
  one(-1,-2);
  printf("a=%d b=%d c=%d\n",a,b,c); 
  return 0;
}

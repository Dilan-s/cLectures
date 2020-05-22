#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}


void printAddresses(int depth) {
  printf("Addres of depth: %p\n", &depth);

  if (depth > 0){
    printAddresses(depth - 1);
  }
}


int main () {

  int *c;

  int a  = 7;

  c = &a;

  printf("%d\n", a);
  printf("%d\n", *c);

  *c = 100;

  printf("%d\n", a);

  printAddresses(5);

  char greeting[] = "Hello world!\n";
  char *currentLetter = greeting;

  while (*currentLetter != '\0') {
    putchar(*currentLetter);
    ++currentLetter;
  }

  char str1[] = "is"; char str2[] = "in";

  char *i[2];
  i[0] = str1;
  i[1] = str2;

  char **ii = i;

  printf("will print ’is’: %s\n",i[0]);
  printf("will print ’in’: %s\n",i[1]);
  printf("will print ’is’: %s\n",*ii);
  ii++;
  printf("will print ’in’: %s\n",*ii);
  
  int d = 42;
  int e = 77;
  printf("d: %i, e: %i\n", d, e);
  swap(&d, &e);
  printf("d: %i, e: %i\n", d, e);


  return 0;

}

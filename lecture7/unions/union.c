#include <stdio.h>

typedef struct test2 {
  char c;
  int i;
} test2;

typedef union test {
  char c; int i;
} test;

union example { int i; char c; };

void print_example(const union example u) {
  printf("u.i: %i\nu.c: %c\n\n", u.i, u.c);
}

int main(void) {
  
  printf("sizeof(char)         = %ld\n", sizeof(char));
  printf("sizeof(int)          = %ld\n", sizeof(int));
  printf("sizeof(union test)   = %ld\n", sizeof(union test));
  printf("sizeof(struct test2) = %ld\n", sizeof(struct test2));

  test t;
  printf("&t.c = %p, &t.i = %p\n", &t.c, &t.i);

  union example u;
  printf("Setting u.c to ’q’...\n");
  u.c = 'q';
  print_example(u);

  printf("Setting u.i to 3137...\n");
  u.i = 3137;
  print_example(u);

  printf("Setting u.c to ’q’...\n");
  u.c = 'q';
  print_example(u);
  
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MB (1024*1024)
//const int MB = 1024 * 1024;
//enum{MB = 1024 * 1024};

/*
#define buffer_size 1048576*sizeof(double)

int buffer_size(struct buffer *buff){
  return buff->size;
}
 
BECOMES:

int 1048576*sizeof(double)(struct buffer *buff) {
  return buff->size;
}
*/

#define BIT_SETS(value, bits, mask) ((value & mask) == bits)

void do_action(const uint32_t opcode) {
  if (BIT_SETS(opcode, 0x01400000, 0x03e00000)) {
    printf("match\n");
  } else {
    printf("no match\n");
  }
}

#define OPERATOR_FUNCTION(name,operator)\
  static int name(const int a, const int b) {\
  return a operator b;\
  }

OPERATOR_FUNCTION(add, +)
OPERATOR_FUNCTION(mul, *)
OPERATOR_FUNCTION(divide, /)
OPERATOR_FUNCTION(mod, %)
  
static void print_result(int (*func)(int, int), int a, int b) {
  printf("func(%i, %i) = %i\n", a, b, func(a, b));
}

int main(void) {
  do_action(0);
  do_action(0x01400000);
  int a = 42, b = 37;
  print_result(&add, a, b);
  print_result(&mul, a, b);
  print_result(&divide, a, b);
  print_result(&mod, a, b);
  return 0;
}

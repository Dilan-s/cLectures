#include <stdio.h>

void greet(){
  printf("Hello world!\n");
}

int main(int argc, char *argv[]){
  greet();
  greet(42, 5.4, "foo");
  int x;
  printf("we have %d arguments\n", argc);
  for (int n = 0; n < argc; n++){
    printf("argv[%d] = %s\n", n, argv[n]);
  }
  return 0;

}

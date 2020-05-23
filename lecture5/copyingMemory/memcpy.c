#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
  char str[] = "Morning World!";
  char time[] = "Evening";

  printf("%s\n", str);

  memcpy(str, time, 7);

  printf("%s\n", str);
}

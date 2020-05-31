#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (){

  char *string = "hello";
  char *string2 = " there";
  //strlen(char *) - does not include '\0'

  printf("%s, length: %ld\n", string, strlen(string));
  printf("%s, length: %ld\n", string2, strlen(string2));

  //strcat(dest, src, n) - requies dest to have size strlen(dest) + n + 1

  char *concat = malloc(5 + 6 + 1);

  strcat(concat, string);
  strcat(concat, string2);

  printf("concat: %s, length: %ld\n", concat, strlen(concat));

  char *a = "a";
  char *b = "b";
  char *c = "c";
  
  printf("a compared with b : %d\n", strcmp(a, b));
  printf("b compared with a : %d\n", strcmp(b, a));
  printf("a compared with c : %d\n", strcmp(a, c));
  printf("c compared with a : %d\n", strcmp(c, a));
  printf("b compared with c : %d\n", strcmp(b, c));
  printf("c compared with b : %d\n", strcmp(c, b));
  printf("a compared with a : %d\n", strcmp(a, a));
  printf("b compared with b : %d\n", strcmp(b, b));
  printf("c compared with c : %d\n", strcmp(c, c));
  
  char cpy[6];

  strcpy(cpy, string);

  printf("original: %s, copy: %s\n", string, cpy);
  
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print_backwards(const char message[]){

  int length = strlen(message);

  for (int i = length - 1; i >= 0; i--){

    printf("%c", message[i]);

  }
  
}

char to_uppercase_character(char ch) {

  return (ch >= 'a' && ch <= 'z') ? (ch + 'A' - 'a') : ch;

}

void to_uppercase_string(char str[]){

  for (; *str ; str++) {

    *str = to_uppercase_character(*str);

  }
  // for (; (*str = (toupper(*str)) != '\0'; str ++);
}

int main(void) {

  char message[100];

  strcpy(message, "hElLo class!");

  printf("before [%s]\n", message);
  
  to_uppercase_string(message);

  printf("after [%s]\n", message);

  return 0;

}

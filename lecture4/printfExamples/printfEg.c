#include <stdio.h>

int main(void) {
  /*  
  int i = 72;
  printf("An integer: %d\n", i);

  float f = 3.1;
  double d = 72.1;
  printf("A double: %f, a float: %f\n", d, f);

  char s[] = "The quick brown fox...";
  printf("A string: %s\n", s);

  char x = 'A', y = 'B', z = '\n';
  printf("Two characters and a newline: %c%c%c", x, y, z);
*/
  int j;
  printf("I take an integer input with scanf: ");
  scanf("%d ", &j);
  printf("input was: %d\n", j);

  char t[100];
  printf("%ld\n", sizeof(t)*sizeof(char));
  printf("I take a string input of max length 100 with fgets: ");
  fgets(t, sizeof(t)*sizeof(char), stdin);
  printf("input was: %s\n", t);
  
  char c;
  printf("I take a char input with getchar: ");
  c = getchar();
  printf("input was: %c\n", c);

  


}

#include <stdio.h>

/* Challenge 1: 
   Make this program give the "welcome to the answer..."
   output using any number of lines of code in function
   innocent. 
 */

/* Challenge 2:
   Make this program give the "welcome to the answer..."
   output using just one line of code in function innocent
   (one C statement) */

void innocent(void) {
  /*  int x[3] = {10, 20, 30};
  int n;
  for (n = 3; x[n] != 1; n++);
  x[n] = 21; */

  /*  int x;
  int *p;
  for(p = &x; *p != 1; p++);
  *p=21; */

  for(int *p = (int *) &p; !(*p == 1 && (*p = 21)); p++);
}


int main() {
  /*const*/ int one = 1;
  printf("before: one + one = %d\n", one + one);

  innocent();

  printf("after: one + one = %d\n", one + one);

  if (one + one == 2) 
    printf("we live in a very boring, ordinary world\n");

  if (one + one == 42) 
    printf("welcome to the answer to life, the universe and everything\n");

  return 0;
}

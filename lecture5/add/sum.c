#include <stdio.h>
#include "add.h"

int main(void) {

  int sum = add(5, 4);

  const int a[] = {1,2,3,4};
  const int b[] = {2,3,4,5};

  int sum2[4];

  add_array(a, b, sum2, 4);
  
  printf("%d\n", sum);
  printf("{");
  for (int i =0; i < 4; i++){
    printf("%d", sum2[i]);
    if (i != 3) {
      printf(", ");
    }
  }
  printf("}\n");
  return 0;

}

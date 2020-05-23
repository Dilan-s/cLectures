#include <stdlib.h>


int main(void)
{
  double *squares = malloc(100 * sizeof(double));
  for(int i = 0; i <= 100; ++i)
    squares[i] = i * i;
  return EXIT_SUCCESS;
}

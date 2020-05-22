#include <stdio.h>

enum Renderflag {AMBIENT=1, DIFFUSE=2, SPECULAR=4};

int main(void) {
  int flags = AMBIENT | SPECULAR;
  if (flags & AMBIENT) {
    printf("Ambient is set.\n");
  }
  if (flags & DIFFUSE) {
    printf("Diffuse is set.\n");
  }
  if (flags & SPECULAR) {
    printf("Specular is set.\n");
  }
 return 0;
}

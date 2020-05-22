#include <stdio.h>

enum Colour {RED/* = -50 */, GREEN, YELLOW};

void printColour(enum Colour col) {
  switch(col) {
  case RED:
    printf("RED\n");
    break;
  case GREEN:
    printf("GREEN\n");
    break;
  case YELLOW:
    printf("YELLOW\n");
    break;
  default:
    printf("Not a valid colour\n");
  }
}

int main (void) {
  enum Colour col = YELLOW;
  printf("col = {%d, %d, %d}\n", RED, GREEN, YELLOW);
  printColour(col);
  printColour((enum Colour) -50);

  return 0;
}
  

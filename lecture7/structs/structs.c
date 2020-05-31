#include <stdio.h>
#include <stdlib.h>

struct vertex {
  float x;
  float y;
};
// struct vertex v; creating an instance

struct strings {
  char str[10];
  char *strPtr;
};
//struct strings s1; creating an instrance;

struct point {
  int x;
  int y;
};

struct vertex flip(struct vertex p) {
  struct vertex result;
  result.x = -p.x; result.y = p.y;
  return result;
}

void flip2(struct vertex *p) {
  p->x = -p->x;
}

int main() {
  struct point p1;
  p1.x = 10;
  p1.y = 20;
  printf("(%d,%d)\n", p1.x, p1.y);

  struct point p2 = {20, 30};
  printf("(%d,%d)\n", p2.x, p2.y);

  struct point *p3 = malloc(sizeof(struct point));
  (*p3).x = 30;
  p3->y = 40;
  printf("(%d,%d)\n", p3->x, p3->y);
  free(p3);

  struct vertex p4;
  p4.x = 5.0; p4.y = 5.0;
  printf("(%f, %f)\n", p4.x, p4.y);
  struct vertex flipped1 = flip(p4);
  printf("(%f, %f)\n", flipped1.x, flipped1.y);

  struct vertex p5;
  p5.x = 6.0; p5.y = 6.0;
  printf("(%f, %f)\n", p5.x, p5.y);
  flip2(&p5);
  printf("(%f, %f)\n", p5.x, p5.y);
  
  return 0;
}

#include <stdio.h>

struct point {
  float x, y;
};

void flip(struct point *p, int position);

int main(void) {
  struct point p[3];
  for(int i=0; i<3; i++){
    p[i].x = 2.0 *i;
    p[i].y = 4.0 *i;
  }
  for(int i=0; i<3; i++){
    printf("(%f, %f)\n", p[i].x, p[i].y);
    flip(p,i);
    printf("(%f, %f)\n", p[i].x, p[i].y);
  }
}

void flip(struct point *p, int position) {
  p[position].x = -p[position].x;
  p[position].y = -p[position].y;
}

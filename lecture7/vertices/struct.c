#include <stdio.h>
#include <stdlib.h>

struct Vertex {
  double x,y;
  struct Vertex *another;
  void (*drift)(struct Vertex *);
};

typedef struct Vertex Vertex;

void go_north(Vertex *_this) {
  _this->y++;
}

void go_south(Vertex *_this) {
  _this->y--;
}

void go_east(Vertex *_this) {
  _this->x++;
}

void go_west(Vertex *_this) {
  _this->x--;
}

void print_vertex(Vertex v) {
  printf("(%lf,%lf)\n", v.x, v.y);
}

int main() {
  Vertex vert = {1, 2, NULL, go_north};
  /*  vert.x = 1;
      vert.y = 2;
      vert.another = NULL;
      vert.drift = go_north;*/

  print_vertex(vert);
  vert.drift(&vert);    
  print_vertex(vert);

  vert.drift = go_east;
  vert.drift(&vert);
  print_vertex(vert);
  
  Vertex p = {-1,5,NULL, go_north };

  Vertex v[2]= { {2,4,&p, go_south} , {1,5,&v[0], go_west} };
  
  v[0].x = 7;
  v[0].y = 8;
  v[0].drift(&v[0]);
  v[1].drift(&v[1]);

  Vertex *h = (Vertex *) malloc(sizeof(Vertex));
  (*h).x = 100;   // h->x = 100
  (*h).y = 200;

  Vertex *arr = (Vertex *) calloc(100,sizeof(Vertex));
  arr[5].x = 5;
  arr[5].y = 7;
  free(arr);

  h->x = 300;  // pointer_to_structure->field  <==> (*pointer_to_structure).field  
  h->y = 400;
  h->another = h;
  h->drift = go_west;

  print_vertex(*h);
  h->drift(h);
  print_vertex(*h);

  free(h);

  return 0;
}

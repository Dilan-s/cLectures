#include <stdio.h>

struct Vertex {
  double x,y;
};

typedef struct Vertex vertex_t;

typedef struct point{
  int x, y;
} point_t;


typedef struct {
  double real;
  double imag;
} complex;


void printComplex(complex *mc){
  printf("%lg + %lgi\n", mc->real, mc->imag);
}



int main(){
  vertex_t a;
  a.x =10;
  a.y = 20;
  printf("(%f,%f)\n", a.x, a.y);

  point_t b = {20, 30};
  printf("(%d,%d)\n", b.x, b.y);

  complex c1 = {1.0, 0.5}; /* assignment at declaration */
  printComplex(&c1); /* pass pointer to struct */
  c1.real = 10.0; /* piecewise assignment */
  printComplex(&c1);
  return 0;

}

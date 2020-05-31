#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const double PI = 3.1415926535; 

typedef union {
        struct{
            double x,y,z; 
        };
        double raw[3];
} vec3d_t;

int main() {

  vec3d_t v;
  v.x = 4.0;
  v.raw[1] = 3.0; // Equivalent to v.y = 3.0
  v.z = 2.0;

  printf("(%lf,%lf,%lf)\n", v.x, v.y, v.z);
  printf("(%lf,%lf,%lf)\n", v.raw[0], v.raw[1], v.raw[2]);
  return 0;
}

enum ShapeKind { Square, Rectangle, Circle };

struct Shape {
    int centerx;
    int centery;
    enum ShapeKind kind;
    union {
        struct { int side; };           /* Square */
        struct { int length, height; }; /* Rectangle */
        struct { int radius; };         /* Circle */
    };
};


typedef struct {
    bool is_float;
    union {
       float f;
       char* s;
    };
} mychoice_t;

double as_float(mychoice_t* ch) {
  return (ch->is_float) ? ch->f : atof(ch->s);
}

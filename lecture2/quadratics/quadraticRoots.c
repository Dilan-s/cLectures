#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double discriminant(double a, double b, double c) {
  return b * b - 4 * a * c;
}

bool quadroots(double a, double b, double c, double *r1, double *r2){
  double disc = discriminant(a,b,c);

  if (disc < 0) {
    return false;
  }

  *r1 = (-b + sqrt(disc))/(2*a);
  *r2 = (-b - sqrt(disc))/(2*a);

  return true;
}

bool quadroots_array(const double coeff[], double roots[]){
  return quadroots(coeff[0], coeff[1], coeff[2], &roots[0], &roots[1]);
}

int main() {
  double root1, root2;
  bool real_roots = quadroots(1, -5, 6, &root1, &root2);
  if (real_roots) {
    printf("root1 = %lf, root2 = %lf\n", root1, root2);
  } else {
    printf("no real roots.\n");
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double **allocate_2D_array(unsigned int rows, unsigned int cols) {
  double **m;
  m =(double **) calloc(rows, sizeof(double *));
  assert(m != NULL); //or assert(m)
  for (int r = 0; r < rows; r ++) {
    m[r] = (double *) calloc(cols, sizeof(double));
    assert(m[r] != NULL);
  }
  return m;
}

double **allocate_2D_array_v2(unsigned int rows, unsigned int cols) {
  double **m = malloc (rows * sizeof(double *));
  assert(m != NULL);
  m[0] = malloc (rows * cols * sizeof(double));
  assert(m[0] != NULL);
  for (int i = 0; i <rows; i++){
    m[i] = m[i-1] + cols;
  }
  return m;
}

void free_2D_array(double **m, int rows) {
  for (int r = 0; r < rows; r++) {
    free(m[r]);
  }
  free(m);
}

void free_2D_array_v2(double **m){
  free(m[0]);
  free(m);
}

void printMatrix(double **m, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%8.5lf ", m[i][j]);
    }
    printf("\n");
  }
}

void randomMatrix(double **m, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m[i][j] = (double) rand()/RAND_MAX;
    }
  }
}

void addMatrix(double **a, double **b, double **r, int rows, int cols){
   for (int i = 0; i < rows; i++) {
     for (int j = 0; j < cols; j++) {
	r[i][j] = a[i][j] + b[i][j];
     }
   }
 }


int main() {
  
  double *x = (double *) calloc(10, sizeof(double));

  int rows = 5, cols = 5;
  double **matrix = allocate_2D_array(rows,cols);
  free_2D_array(matrix, 5);

  double **matrixA = allocate_2D_array(rows, cols);
  double **matrixB = allocate_2D_array(rows, cols);
  double **matrixR = allocate_2D_array(rows, cols);

  randomMatrix(matrixA, rows, cols);
  randomMatrix(matrixB, rows, cols);

  printf("A:\n");
  printMatrix(matrixA, rows, cols);
  printf("B:\n");
  printMatrix(matrixB, rows, cols);

  addMatrix(matrixA, matrixB, matrixR, rows, cols);
  printf("Sum:\n");
  printMatrix(matrixR, rows, cols);


  /*
  double **matrix2 = allocate_2D_array_v2(rows,cols);
  matrix2[5][3] = 10; not working unsure why  
  free_2D_array_v2(matrix2);
  */


  free(x);
  return 0;
}

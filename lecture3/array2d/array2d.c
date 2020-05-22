#include <stdio.h>

#define COLS 3

void printArray(int matrix[][COLS], int rows) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int matrix[2][COLS] = {{1, 2, 3}, {4, 5, 6}};
  printArray(matrix, 2);
  return 0;
}

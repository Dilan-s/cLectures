#include "add.h"
 
int add(int a, int b) {
  return a + b;
}

void add_array(const int a[], const int b[], int sum[], int length) {

  for (int n = 0; n < length; n++) {
    sum[n] = add(a[n], b[n]);
  }

}

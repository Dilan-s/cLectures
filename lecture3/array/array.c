#include <stdio.h>

#define NUMBER_OF_EMPLOYEES 6

int sum_array(const int arr[], int length) {
  int total = 0;
  for (int n=0; n<length; n++){
    total+= arr[n];
  }
  return total;
}

void print_array(const int arr[], int length){
  printf ("{");
  for (int n=0; n < length; n++) {
    printf("%d", arr[n]);
    if (n != length -1){
      printf(", ");
    }
  }
  printf("}\n");
}

int main() {

  int hours_worked[NUMBER_OF_EMPLOYEES] = {10, 20, 30, 40, 50, 60};
  int hourly_pay = 10;

  print_array(&hours_worked[0], NUMBER_OF_EMPLOYEES);

  hours_worked[2] = 100;

  print_array(hours_worked, NUMBER_OF_EMPLOYEES);
  print_array(&hours_worked[1], NUMBER_OF_EMPLOYEES-1);

  int sum_hours = sum_array(hours_worked, NUMBER_OF_EMPLOYEES);

  printf("total hours worked is %d\n", sum_hours);
  printf("hourly pay is %d per punds per hour\n", hourly_pay);
  printf("total wage bil is %d\n", sum_hours*hourly_pay);


  //array bounds caution
  printf("...and now...\n");
  
  hours_worked[-1] = 500;
  
  printf("total hours worked is %d\n", sum_hours);
  print_array(hours_worked, NUMBER_OF_EMPLOYEES);

  hours_worked[-2] = 200;
  
  printf("hourly pay is %d per punds per hour\n", hourly_pay);   
  printf("total wage bil is %d\n", sum_hours*hourly_pay);

  return 0;
}

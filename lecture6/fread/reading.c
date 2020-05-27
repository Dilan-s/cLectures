#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  if((fp = fopen("input.txt", "r")) == NULL){
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  
  int number;
  int total = 0;
  /*
    get first element
    while not at the end of the file {
      process element
      get next element
    }
  */

  
  /*
  fscanf(fp, "%d", &number);
  while(!feof(fp)){
    total+=number;
    printf("read [%d] total is now [%d]\n", number, total);
    fscanf(fp, "%d", &number);
    }*/
  while (fscanf(fp, "%d", &number)==1){
    total+=number;
    printf("read [%d] total is now [%d]\n", number, total); 
  }


  
  fclose(fp);
  return EXIT_SUCCESS;
}

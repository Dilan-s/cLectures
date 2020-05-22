#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
  
  for(int i=0; i<argc; ++i) {
    printf("argv[%i] = %s\n", i, argv[i]);
  }
  
  int count =0;
  
  if(argc >1) {
    count = atoi(argv[1]);
  }
  
  printf("the number of count is %d\n", count);
  for(int i=0; i< count; i++){
    printf("%d\n",i);
  }
}

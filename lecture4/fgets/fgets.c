#include <stdio.h>

void getstr(char buf[], int size) {
  fgets(buf, size, stdin);
  int i=0;
  while(buf[i]!='\0') {
    if (buf[i]=='\n') {
      buf[i] = '\0';
    } else {
      ++i;
    }
  }
}


int main(){
  char buff[100];

  getstr(buff, 100);

  printf("%s\n", buff);

  return 0;

}

#include<stdio.h>

#define POLITE

#ifdef POLITE

void say_hello(void){
	printf("Welcome to C120.3 (C Programming)\n");
	return;
}

#endif

#ifdef COOL

void say_hello(void){
	printf("Yo, hello\n");
	return;
}

#endif

int main(void){
	int n;
	for (n=0; n < 3; n++){
		say_hello();
	}
 	return 0;
}

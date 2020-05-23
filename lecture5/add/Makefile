CC = gcc
CFLAGS = -Wall -g
BUILD = sum

all: $(BUILD)

sum: sum.o add.o

add.o : add.c add.h

sum.o : sum.c add.h

clean :
	/bin/rm -f $(BUILD) *.o core

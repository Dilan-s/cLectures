CC = gcc
CFLAGS = -Wall -g
BUILD = main

all: $(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o core *~

main: main.o magic.o
main.o: magic.h main.c
magic.o: magic.c magic.h

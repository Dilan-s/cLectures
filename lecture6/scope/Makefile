CC = gcc
CFLAGS = -g -Wall
BUILD = scope scope2 staticFile1

all: $(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o core *~

scope: scope.o
scope2: scope2.o
staticFile1: staticFile1.o staticFile2.o
staticFile1.o: staticFile1.c staticFile2.c
staticFile2.o: staticFile2.c

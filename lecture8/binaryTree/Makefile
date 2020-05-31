CC = gcc
CFLAGS = -g -Wall
BUILD = stringTree

all: $(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o *~ core

stringTree: stringTree.o binaryTree.o

stringTree.o: binaryTree.h

binaryTree.o: binaryTree.h

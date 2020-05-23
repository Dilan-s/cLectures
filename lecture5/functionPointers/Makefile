CC = gcc
CFLAGS = -Wall -g
BUILD = sum

all: $(BUILD)

sum: sum.c
	gcc sum.c -o sum -lm

clean:
	/bin/rm -f $(BUILD) *.o core

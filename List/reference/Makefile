CC=gcc
CFLAGS=-Wall -g

all: test

test: list.o test.o
	$(CC) $(CFLAGS) -o test list.o test.o

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

test.o: test.c list.h
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -f *.o test

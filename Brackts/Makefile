CC=gcc
CFLAGS=-Wall -g
OBJ=main.o stack.o
TARGET=main

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f $(OBJ) $(TARGET)

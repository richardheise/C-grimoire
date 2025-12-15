# Makefile for sorting algorithms analysis

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = analysis.c sorting_lib.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = analysis

# Default rule
all: $(TARGET)

# Rule to link the object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Rule to clean the compiled files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean

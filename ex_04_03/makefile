# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-c -O3 -Wall

# Clang-format command
CLANG_FORMAT=clang-format

# Targets

all: prog

prog: main.o getop.o getch.o stack.o
	$(CC) $^ -o $@ -lm
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -lm

format_all:
	$(CLANG_FORMAT) -i --style=Microsoft *.c *.h

format:
	$(CLANG_FORMAT) -i --style=Microsoft $(filter %.c,$(MAKECMDGOALS))

clean:
	rm -rf *.o

.PHONY: format clean format_all

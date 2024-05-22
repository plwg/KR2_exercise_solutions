# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-O3 -Wall

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -lm

clean:
	rm -rf *.o
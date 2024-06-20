# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-O3 -Wall

# Clang-format command
CLANG_FORMAT=clang-format

# Targets
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -lm

format_all:
	$(CLANG_FORMAT) -i --style=Microsoft *.c *.h

format:
		$(CLANG_FORMAT) -i --style=Microsoft $(filter %.c,$(MAKECMDGOALS))

clean:
	rm -rf *.o

.PHONY: format clean format_all

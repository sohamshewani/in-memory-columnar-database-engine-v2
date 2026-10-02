CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=-lm
OBJS=src/columnar.o src/compression.o src/scan.o src/types.o
all: src/main

src/main: src/main.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.c include/%.h
	$(CC) $(CFLAGS) -c -o $@ $<

test: all
	make check

clean:
	rm -f src/*.o src/main
	make clean-tests

check:
	make test-unit
	make test-integration
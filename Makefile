CC=g++
CFLAGS=-g -O0 -std=c++11 -Wall -I./include

BIN=bin

SOURCES=src/factorial.cc tests/factorial_testsuite.cc tests/main.cc
OBJFILES=$(wildcard obj/*.o)

obj/factorial.o: $(SOURCES)
	$(CC) $(CFLAGS) -c src/factorial.cc -o obj/factorial.o
	$(CC) $(CFLAGS) -c tests/factorial_testsuite.cc -o obj/factorial_testsuite.o
	$(CC) $(CFLAGS) -c tests/main.cc -o obj/main.o

test: $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o bin/tests

clean: 
	@rm -f obj/*.o tests/*.o

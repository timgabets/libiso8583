CC=g++
CFLAGS=-g -O0 -std=c++11 -Wall -I./include

BIN=bin

SOURCES=src/factorial.cc tests/factorial_testsuite.cc tests/main.cc
OBJFILES=$(wildcard obj/*.o)

all: $(SOURCES)
	$(CC) $(CFLAGS) -c $^ 
	@mv *.o obj/

test: $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o bin/tests

clean: 
	@rm -f obj/*.o tests/*.o

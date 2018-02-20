CC=g++
CFLAGS=-g -O0 -std=c++11 -Wall -I./include

SOURCES=src/factorial.cc 
TESTS=tests/factorial_testsuite.cc tests/main.cc
OBJFILES=$(wildcard obj/*.o)

all: $(SOURCES) $(TESTS)
	$(CC) $(CFLAGS) -c $^ 
	@mv *.o obj/

test: $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o bin/tests

clean: 
	@rm -f obj/*.o tests/*.o

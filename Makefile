CC=g++
CFLAGS=-g -O0 -std=c++11 -Wall -I./include

SOURCES=$(wildcard src/*.cc)
TESTS=$(wildcard tests/*.cc)
OBJFILES=$(wildcard obj/*.o)

all: $(SOURCES) $(TESTS)
	$(CC) $(CFLAGS) -c $^ 
	@mv *.o obj/

test: $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o bin/tests

clean: 
	@rm -f obj/*.o tests/*.o

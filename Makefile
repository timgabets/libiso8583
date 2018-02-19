CC=g++
CFLAGS=-g -O0 -std=c++11 -Wall -I./include

BIN=bin

all:
	$(CC) $(CFLAGS) -c src/factorial.cc -o obj/factorial.o

test: all
	$(CC) $(CFLAGS) -c tests/factorial_testsuite.cc -o obj/factorial_testsuite.o
	$(CC) $(CFLAGS) -c tests/main.cc -o obj/main.o
	$(CC) $(CFLAGS) obj/factorial.o obj/main.o obj/factorial_testsuite.o -o bin/tests

clean: 
	@rm -f $(OBJ)/*.o tests/*.o

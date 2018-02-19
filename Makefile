CC=g++
CFLAGS=-g -O0 -std=c++11 -Wall -I./include

BIN=bin

obj/factorial.o: src/factorial.cc tests/factorial_testsuite.cc tests/main.cc
	$(CC) $(CFLAGS) -c src/factorial.cc -o obj/factorial.o
	$(CC) $(CFLAGS) -c tests/factorial_testsuite.cc -o obj/factorial_testsuite.o
	$(CC) $(CFLAGS) -c tests/main.cc -o obj/main.o

test: obj/factorial.o obj/factorial_testsuite.o obj/main.o
	$(CC) $(CFLAGS) $^ -o bin/tests

clean: 
	@rm -f obj/*.o tests/*.o

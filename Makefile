CC=g++
CFLAGS=-g -O0 -std=c++11 -Wno-write-strings -I./include

SRCS=$(wildcard src/*.cc)
TESTS=$(wildcard tests/*.cc)
OBJS=$(wildcard obj/*.o)

all: $(SRCS) $(TESTS)
	$(CC) $(CFLAGS) -c $^ 
	@mv *.o obj/

test: $(OBJS)
	$(CC) $(CFLAGS) $^ -o bin/tests
	bin/tests

clean: 
	@rm -f obj/*.o tests/*.o

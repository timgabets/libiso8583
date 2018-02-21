CC=g++
CFLAGS=-g -O0 -std=c++11 -Wno-write-strings -I./include

#BINDIR=bin
#OBJDIR=obj
#
#SRCS=$(wildcard src/*.cc)
#TESTS=$(wildcard tests/*.cc)
#OBJS=$(patsubst src/%.cc,obj/%.o, $(SRCS))
#
#$(OBJS): $(SRCS) $(TESTS) | $(OBJDIR)
#	$(CC) $(CFLAGS) -c $^ 
#	@mv *.o $(OBJDIR)
#
#test: $(patsubst tests/%.cc,obj/%.o, $(TESTS)) $(OBJS) | $(BINDIR)
#	$(CC) $(CFLAGS) $^ -o $(BINDIR)/tests
#	@$(BINDIR)/tests
#
#$(BINDIR):
#	@mkdir $(BINDIR)
#
#$(OBJDIR):
#	@mkdir $(OBJDIR)
#

all: obj/parser.o obj/parser_suite.o obj/main.o

obj/parser.o: src/parser.cc include/parser.hh
	$(CC) $(CFLAGS) -c src/parser.cc -o $@

obj/parser_suite.o: obj/parser.o tests/parser_suite.cc
	$(CC) $(CFLAGS) -c tests/parser_suite.cc -o $@

obj/main.o: tests/main.cc include/snow.h
	$(CC) $(CFLAGS) -c tests/main.cc -o $@

test: tests/main.cc tests/parser_suite.cc
	$(CC) $(CFLAGS) obj/parser.o obj/parser_suite.o obj/main.o -o bin/tests
	@bin/tests

clean: 
	@rm -f obj/*.o tests/*.o

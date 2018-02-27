CC=g++
CFLAGS=-g -o0 -std=c++11 -Wno-write-strings -I./include
# Check astyle documentation for details http://astyle.sourceforge.net/astyle.html
CODE_STYLE_OPTIONS=--style=linux --indent=tab -T8
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

OBJECTS=obj/parser.o obj/main.o obj/conv_tools.o
TESTOBJECTS=obj/conv_tools_suite.o obj/parser_suite.o obj/bitops_suite.o

TESTSRCS=tests/conv_tools_suite.cc tests/parser_suite.cc tests/bitops_suite.cc \
	tests/main.cc

all: $(OBJECTS) $(TESTOBJECTS)

obj/conv_tools.o: src/conv_tools.cc include/conv_tools.hh
	$(CC) $(CFLAGS) -c src/conv_tools.cc -o $@

obj/parser.o: src/parser.cc include/parser.hh
	$(CC) $(CFLAGS) -c src/parser.cc -o $@

obj/parser_suite.o: obj/parser.o tests/parser_suite.cc
	$(CC) $(CFLAGS) -c tests/parser_suite.cc -o $@

obj/conv_tools_suite.o: tests/conv_tools_suite.cc
	$(CC) $(CFLAGS) -c tests/conv_tools_suite.cc -o $@

obj/bitops_suite.o: tests/bitops_suite.cc include/bitops.hh
	$(CC) $(CFLAGS) -c tests/bitops_suite.cc -o $@

obj/main.o: tests/main.cc include/snow.h
	$(CC) $(CFLAGS) -c tests/main.cc -o $@

test: $(TESTSRCS) $(TESTOBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS)  $(TESTOBJECTS) -o bin/tests
	@bin/tests

check:
	cppcheck --force --enable=all src/*.cc

indent:
	@astyle $(CODE_STYLE_OPTIONS) src/*.cc

clean:
	@rm -f obj/*.o tests/*.o

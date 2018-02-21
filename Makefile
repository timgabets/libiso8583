CC=g++
CFLAGS=-g -O0 -std=c++11 -Wno-write-strings -I./include

BINDIR=bin
OBJDIR=obj

SRCS=$(wildcard src/*.cc)
TESTS=$(wildcard tests/*.cc)
OBJS=$(wildcard obj/*.o)

all: $(SRCS) $(TESTS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $^ 
	@mv *.o $(OBJDIR)

test: $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $(BINDIR)/tests
	$(BINDIR)/tests

$(BINDIR):
	@mkdir $(BINDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean: 
	@rm -f obj/*.o tests/*.o

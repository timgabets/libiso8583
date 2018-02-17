CC=g++
CFLAGS=-g -O0 -I./include
BIN=factorial

all:
	$(CC) $(CFLAGS) $(BIN).cc -o $(BIN)

test:
	@./$(BIN)

clean: 
	@rm -f *.o $(BIN)

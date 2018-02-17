CC=g++
CFLAGS=-g -O0 -I./include
SRC=src
OBJ=obj

BIN=factorial

all:
	$(CC) $(CFLAGS) -c $(SRC)/$(BIN).cc -o $(OBJ)/$(BIN).o

test:
	@./$(BIN)

clean: 
	@rm -f $(OBJ)/*.o

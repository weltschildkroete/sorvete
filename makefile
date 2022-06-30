.POSIX:

include config.mk

TEST = test-sorvete

SRC = sorvete.c test_sorvete.c
OBJ = $(SRC:.c=.o)
INC = sorvete.h

all: $(TEST)

$(BIN): $(OBJ)

$(OBJ): $(INC)

$(TEST): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

.c.o:
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

test: $(TEST)
	./$(TEST)

clean:
	rm -f $(BIN) $(OBJ)

.PHONY: all test clean

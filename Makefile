CC := gcc

CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -g -Iinclude
SANFLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer

SRC := $(wildcard src/*.c)
BIN := bin/main

.PHONY: all run clean

all: $(BIN)

$(BIN): $(SRC) examples/main.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $(SANFLAGS) -o $@ $^

run: $(BIN)
	./$(BIN)

clean:
	rm -rf bin
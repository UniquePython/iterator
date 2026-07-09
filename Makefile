CC := gcc

CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -Wcast-qual -g -Iinclude -Iexamples
SANFLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer

SRC := $(wildcard src/*.c)
EXAMPLES := $(wildcard examples/*.c)
BINS := $(patsubst examples/%.c,bin/%,$(EXAMPLES))

.PHONY: all run clean

all: $(BINS)

bin/%: examples/%.c $(SRC)
	@mkdir -p bin
	$(CC) $(CFLAGS) $(SANFLAGS) -o $@ $^

run: all
	@for bin in $(BINS); do ./$$bin; done

clean:
	rm -rf bin
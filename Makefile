CC := gcc

CFLAGS := -std=c11 \
           -Wall -Wextra -Wpedantic \
           -Wcast-qual -Wshadow \
           -Wconversion -Wsign-conversion \
           -Wstrict-prototypes -Wmissing-prototypes \
           -Wwrite-strings \
           -Og -g \
           -Iinclude -Iexamples

SANFLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer

SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,obj/%.o,$(SRC))

EXAMPLES := $(wildcard examples/*.c)
BINS := $(patsubst examples/%.c,bin/%,$(EXAMPLES))

.PHONY: all run clean

all: $(BINS)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(SANFLAGS) -c $< -o $@

bin/%: examples/%.c $(OBJ)
	@mkdir -p bin
	$(CC) $(CFLAGS) $(SANFLAGS) $< $(OBJ) -o $@

run: all
	@for bin in $(BINS); do ./$$bin; done

clean:
	rm -rf obj bin
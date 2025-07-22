CC = gcc

# Use pkg-config to get GTK+ 3 compiler and linker flags
CFLAGS = -Wall -Iinclude `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`

SRC := $(wildcard src/**/*.c) $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, build/%.o, $(SRC))
BIN := build/school_sys

DATA_DIR = data
DATA_FILES = $(DATA_DIR)/students.bin $(DATA_DIR)/parents.bin $(DATA_DIR)/teachers.bin

.PHONY: all clean data

all: $(BIN) data

# Compile source files to object files
build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link the final executable with GTK libraries
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Create data directory and placeholder files if missing
data:
	@mkdir -p $(DATA_DIR)
	@for file in $(DATA_FILES); do \
		[ -f $$file ] || touch $$file; \
	done

# Clean all build artifacts
clean:
	rm -rf build/*

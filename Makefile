# Install
BIN = demo

# Compiler
CC = clang
DCC = g++

# Flags
CFLAGS += -std=c89 -Wall -Wextra -pedantic -O2

SRC = src/temp_sensor.cc src/gui.cc main.cc
OBJ = $(SRC:.c=.o)

# Modes
.PHONY: g++
gcc: CC = g++
gcc: $(BIN)

.PHONY: clang
clang: CC = clang
clang: $(BIN)

$(BIN):
	@mkdir -p bin
	rm -f bin/$(BIN) $(OBJS)
	$(CC) $(SRC) -o bin/$(BIN) -lX11 -lGL


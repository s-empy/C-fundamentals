CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Iinclude
SRC = src/bits.c src/main.c
TARGET = bits_demo

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean


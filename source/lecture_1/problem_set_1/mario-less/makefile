CC = gcc
CFLAGS = -Wall -Werror

TARGET = mario_test
SRC = mario.c pyramid_drawer.c
OBJ = $(SRC:.c=.o)
HEADER = pyramid_drawer.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

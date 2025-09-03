CC = cc
SRC = src/main.c
OUT = YourGame
INCLUDE = -Iinclude
RAYLIB_FLAGS = $(shell pkg-config --libs --cflags raylib)

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) $(INCLUDE) $(RAYLIB_FLAGS) -o $(OUT)

clean:
	rm -f $(OUT)

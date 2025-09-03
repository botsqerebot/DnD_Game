
CC = cc
#SRC = src/main.c
SRC = $(wildcard src/**/*.c) $(wildcard src/*.c)
OUT = DnD_Game
BUILD_DIR = build
OUT_PATH = $(BUILD_DIR)/$(OUT)
INCLUDE = -Iinclude
RAYLIB_FLAGS = $(shell pkg-config --libs --cflags raylib)

all: $(OUT_PATH)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OUT_PATH): $(SRC) | $(BUILD_DIR)
	$(CC) $(SRC) $(INCLUDE) $(RAYLIB_FLAGS) -o $(OUT_PATH)

clean:
	rm -f $(OUT_PATH)

CC := gcc

NAME := gameboy
MAIN := main.c
VALGRIND_LOG := valgrind-out.txt

SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
TESTS_DIR := tests

# OBJS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(INC_DIR)/*.h) $(BUILD_DIR)/$(NAME)
CFLAGS := -o$(BUILD_DIR)/$(NAME) -I$(INC_DIR) -I$(SRC_DIR) -Wall

all: build run

build: .FORCE
	$(CC) $(SRC_DIR)/$(MAIN) $(CFLAGS)
	
run:
	$(BUILD_DIR)/$(NAME)

test:

check:
	valgrind --leak-check=full \
			 --show-leak-kinds=all \
			 --track-origins=yes \
			 $(BUILD_DIR)/$(NAME)
	
.PHONY: clean
clean:
	rm $(BUILD_DIR)/$(NAME)

.FORCE:

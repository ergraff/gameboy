NAME := gameboy
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
TESTS_DIR := tests

OBJS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(INC_DIR)/*.h)

all: build run

build: $(OBJS)
	touch $(BUILD_DIR)/$(NAME)
	gcc $(SRC_DIR)/main.c -o$(BUILD_DIR)/$(NAME) -I$(INC_DIR) -I$(SRC_DIR) -Wall
	
run:
	@./$(BUILD_DIR)/$(NAME)

test:

check:
	

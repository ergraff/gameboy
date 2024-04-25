CC := gcc

# Main
NAME := gameboy
MAIN := main.c
VALGRIND_LOG := valgrind-out.txt

SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
BIN_DIR := bin


all: build run

build: .FORCE
	@$(CC) -c $(SRC_DIR)/gb.c -o $(BUILD_DIR)/gb.o -I$(INC_DIR)
	@$(CC) -c $(SRC_DIR)/instr.c -o $(BUILD_DIR)/instr.o -I$(INC_DIR)
	@$(CC) -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o -I$(INC_DIR)
	@$(CC) $(BUILD_DIR)/main.o -o $(BIN_DIR)/$(NAME) $(BUILD_DIR)/gb.o $(BUILD_DIR)/instr.o -I$(INC_DIR) -Wall

	
run:
	@$(BIN_DIR)/$(NAME)

check:
	valgrind --leak-check=full \
			 --show-leak-kinds=all \
			 --track-origins=yes \
			 $(BIN_DIR)/$(NAME)
	
clean:
	@rm $(BUILD_DIR)/*.o
	@rm $(BIN_DIR)/$(NAME)

.FORCE:
.PHONY: clean

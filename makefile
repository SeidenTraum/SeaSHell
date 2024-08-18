
# Compiler
CC = gcc

# Flags
CFLAGS = -c

# Source files
SRCS = src/corelib/proc.c src/corelib/term.c src/corelib/inbuilt/cd.c src/main.c

# Object files
OBJS = $(SRCS:src/%.c=bin/%.o)

# Output binary
BIN = CSH

# Colors
RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m

# Directories
BIN_DIR = bin
CORE_DIR = bin/corelib
INBUILT_DIR = bin/corelib/inbuilt
DIR_TREE = $(BIN_DIR) $(CORE_DIR) $(INBUILT_DIR)

# Default target
all: $(BIN)

# Ensure the directory structure exists
$(DIR_TREE):
	@echo -e "$(YELLOW)Creating directory structure...$(RESET)"
	@mkdir -p $(DIR_TREE)

# Compile each source file to an object file
bin/%.o: src/%.c $(DIR_TREE)
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $< -o $@

# Link object files to create the final binary
$(BIN): $(OBJS)
	@echo -e "$(GREEN)Linking...$(RESET)"
	$(CC) $(OBJS) -o $(BIN)

# Clean up object files and binary
clean:
	@echo -e "$(RED)Cleaning up...$(RESET)"
	rm -rf $(BIN) $(BIN_DIR)

.PHONY: all clean

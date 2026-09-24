# Macros (Variables)
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
SRC = src
OBJ = obj
BIN = bin

# Files
SOURCES = $(SRC)/main.c $(SRC)/mystrfunctions.c $(SRC)/myfilefunctions.c
OBJECTS = $(OBJ)/main.o $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
TARGET = $(BIN)/client

# The first target is the default one when you just type 'make'
all: $(TARGET)

# Linking Rule: Connects all the .o files to make the final executable
# (This exact rule is asked about in your REPORT.md!)
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Compilation Rule: Converts any .c file into a .o file
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Rule: Deletes generated files so we can start fresh
clean:
	rm -f $(OBJ)/*.o $(BIN)/client
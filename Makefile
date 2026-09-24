# Macros (Variables)
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
SRC = src
OBJ = obj
BIN = bin
LIB = lib

# Files
OBJECTS = $(OBJ)/main.o $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o

# Targets
CLIENT_MULTIFILE = $(BIN)/client
CLIENT_STATIC = $(BIN)/client_static
STATIC_LIB = $(LIB)/libmyutils.a

# Default target now builds both the old client and the new static client
all: $(CLIENT_MULTIFILE) $(CLIENT_STATIC)

# --- FEATURE 2: Direct Linking ---
$(CLIENT_MULTIFILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(CLIENT_MULTIFILE)

# --- FEATURE 3: Static Library Linking ---

# 1. Create the static library archive (.a) from object files
$(STATIC_LIB): $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
	ar rcs $(STATIC_LIB) $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o

# 2. Build the new executable using the static library
$(CLIENT_STATIC): $(OBJ)/main.o $(STATIC_LIB)
	$(CC) $(CFLAGS) $(OBJ)/main.o -L$(LIB) -lmyutils -o $(CLIENT_STATIC)


# Compilation Rule: Converts any .c file into a .o file
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Rule: Empties out generated files
clean:
	rm -f $(OBJ)/*.o $(BIN)/* $(LIB)/*
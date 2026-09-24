# Macros (Variables)
CC = gcc
# Added -fPIC here so all object files are compiled as Position-Independent Code
CFLAGS = -Wall -Iinclude -fPIC

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
CLIENT_DYNAMIC = $(BIN)/client_dynamic
STATIC_LIB = $(LIB)/libmyutils.a
DYNAMIC_LIB = $(LIB)/libmyutils.so

# Default target now builds all three versions!
all: $(CLIENT_MULTIFILE) $(CLIENT_STATIC) $(CLIENT_DYNAMIC)

# --- FEATURE 2: Direct Linking ---
$(CLIENT_MULTIFILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(CLIENT_MULTIFILE)

# --- FEATURE 3: Static Library ---
$(STATIC_LIB): $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
	ar rcs $(STATIC_LIB) $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o

$(CLIENT_STATIC): $(OBJ)/main.o $(STATIC_LIB)
	$(CC) $(CFLAGS) $(OBJ)/main.o -L$(LIB) -lmyutils -o $(CLIENT_STATIC)

# --- FEATURE 4: Dynamic Library ---
# Create the shared object (.so) file using the -shared flag
$(DYNAMIC_LIB): $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
	$(CC) -shared $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o -o $(DYNAMIC_LIB)

# Build the executable using the dynamic library
$(CLIENT_DYNAMIC): $(OBJ)/main.o $(DYNAMIC_LIB)
	$(CC) $(CFLAGS) $(OBJ)/main.o -L$(LIB) -lmyutils -o $(CLIENT_DYNAMIC)


# Compilation Rule
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Rule
clean:
	rm -f $(OBJ)/*.o $(BIN)/* $(LIB)/*
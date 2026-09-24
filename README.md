# Operating Systems Lab - Assignment 01

## Author
**Mohammad Daniyal Usman**

## Overview
This project demonstrates advanced C programming compilation techniques in a Linux environment. It covers direct multi-file compilation, static linking, dynamic linking, and system-level installation with manual pages.

## Project Structure
* `src/`: Contains all `.c` source code files.
* `include/`: Contains all `.h` header files.
* `obj/`: Stores compiled `.o` object files.
* `lib/`: Stores generated static (`.a`) and dynamic (`.so`) libraries.
* `bin/`: Stores final executable programs.
* `man/`: Contains the `groff` formatted manual pages.

## Features Implemented
1. **Multi-file Build**: Direct compilation of multiple source files into a single executable.
2. **Static Library (`.a`)**: Archiving object files into a statically linked library using `ar`.
3. **Dynamic Library (`.so`)**: Compiling Position-Independent Code (`-fPIC`) and linking a shared object.
4. **Man Pages & Install**: Groff-formatted system documentation installed directly into Linux `man` directories.

## How to Build and Run
Use the included `Makefile` to compile the project.

```bash
# Build all versions (direct, static, dynamic)
make

# Run the statically linked executable
./bin/client_static

# Run the dynamically linked executable
export LD_LIBRARY_PATH=$PWD/lib:$LD_LIBRARY_PATH
./bin/client_dynamic
```

## System Installation
To install the program globally on your Linux system along with its manual page:
```bash
sudo make install
```
Once installed, you can run the program from anywhere using `client` and read the manual using `man wordCount`.

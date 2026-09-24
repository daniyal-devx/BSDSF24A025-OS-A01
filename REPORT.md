# BSDSF24A025-OS-A01 - Technical Report

## Feature 2: Version Control and Tags
**1. What is a git tag and why is it useful?**
A tag is a permanent pointer to a specific commit. It is useful for marking release points (like v1.0), so we can always find the exact code used for that release even if the main branch continues to change.

**2. What is the difference between a simple tag and an annotated tag?**
A simple (lightweight) tag is just a bookmark to a commit. An annotated tag is a full object stored in the Git database that includes the creator's name, email, date, and a release message.

## Feature 3: Static Libraries
**3. What is the purpose of the `ar` command and `ranlib`?**
The `ar` (Archiver) command takes multiple compiled `.o` object files and bundles them together into a single static library `.a` file. `ranlib` generates an index (symbol table) inside the archive to help the linker find functions faster. (Note: using `ar rcs` does both simultaneously).

**4. When you run `nm` on your `client_static` executable, are the symbols for functions like `mystrlen` present? What does this tell you about how static linking works?**
Yes, they are present and marked with a 'T' (Text section). This proves that during static linking, the linker actually extracts the machine code from the `.a` library and physically copies it directly into the final executable, making it completely self-contained.

## Feature 4: Dynamic Libraries
**5. What is Position-Independent Code (`-fPIC`) and why is it a requirement for shared libraries?**
Since dynamic libraries are loaded into memory at runtime alongside many other programs, they cannot predict what exact memory addresses they will occupy. `-fPIC` ensures all memory references in the library are relative, allowing it to execute correctly no matter where the OS places it in RAM.

**6. Explain the difference in file size between your static and dynamic clients.**
The static client contains the actual physical machine code of the utility functions copied directly into the executable by the linker. The dynamic client only contains references and relies on the `.so` file existing on the system at runtime. (Note: For very tiny functions, Linux ELF overhead makes the sizes look identical, but for large libraries, static executables are significantly larger).

**7. What is the `LD_LIBRARY_PATH` environment variable and why was it necessary to set it?**
It is a variable that tells the OS's dynamic loader where to search for shared `.so` libraries before looking in the default system folders (like `/usr/lib`). It was necessary because our custom `libmyutils.so` is in a local project directory, so the loader couldn't find it without our explicit help.

## Feature 5: Man Pages and Installation
**8. What is groff?**
Groff is a typesetting system and formatting language used in Linux to write and format standard manual (man) pages.

**9. Why do you need to run `sudo make install` instead of just `make install`?**
The `install` target uses the `cp` command to copy files into `/usr/local/bin` and `/usr/local/share/man`. These are protected system directories, so we must use `sudo` to gain temporary root (administrator) privileges to modify them.
# 📄 get_next_line

**get_next_line** is a project from the 42 curriculum that focuses on reading a line from a file descriptor efficiently and safely.
It teaches fundamental concepts in file I/O, static variables, and memory management in C.

---

# 🧠 Project Overview

The goal is to create a function that returns a single line from a file descriptor each time it’s called — just like how you might use fgets, but without relying on standard library functions.
After each call, the function remembers where it left off, allowing you to read through a file line by line.

---

# ⚙️ Function Prototype

```
char *get_next_line(int fd);

```
- fd → File descriptor to read from.

- Return value → The next line from the file, including the newline character (\n) if one is found. Returns NULL at end of file or on error.

---

# 📁 Mandatory Files

- get_next_line.c — main function implementation

- get_next_line_utils.c — helper functions (string operations, buffer handling)

- get_next_line.h — header file with prototypes and definitions

---

# 🧩 Allowed Functions

- read()

- malloc()

- free()

---

# 🧪 Compilation

Compile your code with the following flags:

```

cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl

```
---

# 🔍 Example Usage

```
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}

```

---

# 🧠 What I Learned

- How file descriptors and the read() function work

- Efficiently managing static variables to preserve state between calls

- Handling dynamic memory and avoiding leaks

- Building modular, reusable C code

---

# 💡 Bonus Part (optional)

The bonus version of get_next_line supports reading from multiple file descriptors at once, storing each file’s reading state independently.

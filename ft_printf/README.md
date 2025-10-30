## 🖨️ ft_printf

**ft_printf** is a project from the 42 curriculum that replicates the behavior of the standard C library function `printf`.  
The goal is to implement formatted output using variadic functions, string manipulation, and type handling in C.

---

## 🧠 Project Overview

The project teaches how formatted printing works under the hood — including handling different data types, format specifiers, and buffer management.  
You’ll recreate a simplified version of `printf` that supports most common conversions.

---

## ⚙️ Function Prototype

int ft_printf(const char *format, ...);

---

## 🧩 Supported Conversions

- `%c` — Print a single character  
- `%s` — Print a string  
- `%p` — Print a pointer address in hexadecimal  
- `%d` / `%i` — Print a signed integer  
- `%u` — Print an unsigned integer  
- `%x` — Print a lowercase hexadecimal number  
- `%X` — Print an uppercase hexadecimal number  
- `%%` — Print a literal percent sign

---

## 🧱 Key Concepts

- Variadic functions (`<stdarg.h>`)  
- Parsing format strings  
- Converting numbers to different bases  
- Memory management and output buffering  
- Writing modular code for different format types

---

## 🧪 Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! The number is %d\n", "world", 42);
    ft_printf("Pointer: %p\n", (void *)&main);
    return 0;
}
```
## Output:
```c

Hello world! The number is 42
Pointer: 0x7ffeefbff4c0


```

## 🛠️ Compilation

Compile your program with:

```c

make

```

Then link it with your main file:

```c
gcc main.c libftprintf.a

```

## 📁 Files

- ft_printf.c — Core function

- ft_parse.c — Handles parsing of format specifiers

- ft_convert.c — Handles conversions and printing

- libft/ — Reused utility functions from the Libft library

- ft_printf.h — Header file

## 🎯 Learning Goals

- Understand how variadic arguments work

- Learn how to modularize code for reusability

- Deepen your understanding of formatted output functions

- Reinforce your string and number manipulation skills

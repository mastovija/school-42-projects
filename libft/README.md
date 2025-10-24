# Libft

**Libft** is a custom implementation of some essential functions from the C standard library, written entirely from scratch.  
This was the first major project at [42 Berlin](https://42berlin.de) and serves as a foundation for all later projects.

---

## 🧠 Project Goals

- Recreate key functions from `<string.h>`, `<ctype.h>`, and `<stdlib.h>`  
- Learn about memory management, pointers, and function design  
- Build a static library (`libft.a`) to be reused in other 42 projects  

---

## ⚙️ Topics Covered

- Pointers and memory allocation  
- String manipulation and array handling  
- Linked lists (bonus part)  
- Header and static library creation  

---

## 🧰 Usage

To compile the library:
```bash
make

Then include it in your own C programs:

#include "libft.h"

and link it:

gcc main.c -L. -lft

##💡 Lessons Learned

-Understanding how basic C functions work under the hood

-Gaining confidence working with memory and debugging segmentation faults

-Writing clean, modular, and reusable code

##📁 Structure

libft/
├── ft_*.c
├── libft.h
├── Makefile
└── README.md

This project was an essential first step into low-level programming, helping me understand what really happens behind higher-level abstractions.

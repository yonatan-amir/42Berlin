###### <em>This project has been created as part of the 42 curriculum by yamir</em>

# Libft

## 📁 Description

Libft is a custom C library that reimplements a collection of essential standard functions from <ctype.h>, <string.h>, <stdlib.h>, and <unistd.h>, along with a set of additional utility functions.
The goal of this project is to understand how these low-level operations work internally and to provide a reusable library for future 42 projects.

# ⍆ Libft includes:

1. Reimplementations of standard C functions (e.g., memcpy, strlen, atoi)

2. Additional utility functions (e.g., ft_split, ft_itoa, ft_strjoin)

3. A full linked-list handling module (t_list)

### This project is foundational for your progres in the 42 curriculum.

## 🚀 Instructions Compilation

To compile the library:

    make

This produces libft.a at the root of the repository.

    Cleaning commands:

    make clean # removes object files


    make fclean # removes object files + libft.a

    make re # rebuild everything

## Using the library in another project

Example:

    cc main.c -L. -lft

    Then run:

    ./a.out

## 📚 Functions Included

### Part 1 — Libc Functions

- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_strlen
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_strlcpy
- ft_strlcat
- ft_toupper
- ft_tolower
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_memchr
- ft_memcmp
- ft_strnstr
- ft_atoi
- ft_calloc
- ft_strdup

### Part 2 — Additional Functions

- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_itoa
- ft_strmapi
- ft_striteri
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

### Part 3 — Linked Lists

- ft_lstnew
- ft_lstadd_front
- ft_lstsize
- ft_lstlast
- ft_lstadd_back
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap

## 🧠 How AI Was Used

AI assistance was used only for learning and clarification, not for providing code.
I used AI to:

- Ask for explanations of C concepts (memory, pointers, linked lists)

- Learn how to build and structure tests

- Clarify formatting rules for README.md

#### All code was written manually, tested, and debugged without AI-generated solutions, following the 42 AI policy.

## 📎 Resources

Here are the main references that guided my implementation:

- man pages: memcpy, memmove, calloc, atoi, etc.

- The official Libft subject

- 42 intra documentation and The Norm

## ✔️ Project Status

- Completed & tested
- Compliant with Norminette
- Builds successfully into libft.a

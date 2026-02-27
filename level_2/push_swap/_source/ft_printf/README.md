_This project has been created as part of the 42 curriculum by yamir._

# Description

`ft_printf` is a static library reimplementation of `printf` for mandatory
conversions:

- `%c`
- `%s`
- `%p`
- `%d`
- `%i`
- `%u`
- `%x`
- `%X`
- `%%`

The implementation is split into a dispatcher (`ft_printf.c`), a parser
(`ft_parse.c`), and conversion handlers (`ft_handle_*.c`).

# Instructions

Build:

```sh
make
```

Rebuild from scratch:

```sh
make re
```

Output:

- `libftprintf.a`

Local tests (not submitted):

- `../printf_tester/`

# Library Flow (How it Works)

High-level runtime flow:

1. `ft_printf(const char *s, ...)` starts `va_list args`.
2. It scans `s` character by character.
3. Normal characters are written directly with `write(1, &s[i], 1)`.
4. On `%`, it calls `handle_percent(...)`:
   - increments index past `%`
   - calls `flag_brain(...)` to parse flags/width/precision/specifier
   - dispatches to the right `ft_handle_*` function by `f->spec`
5. Each handler writes output and returns how many chars it printed.
6. `ft_printf` accumulates printed length and returns final count.

Call graph:

```text
ft_printf
  -> handle_percent
     -> flag_brain
        -> init_flags
        -> parse_flags
           -> set_flag
     -> handle_case
        -> ft_handle_percent
        -> ft_handle_char
        -> ft_handle_str
        -> ft_handle_int
        -> ft_handle_ptr
        -> ft_handle_u
        -> ft_handle_x (lowercase lookup)
        -> ft_handle_x (uppercase lookup)
```

# Dependencies

External functions allowed/used:

- `write`
- `va_start`, `va_arg`, `va_end`

Internal dependencies:

- `libft/libft.a`
  - `ft_isdigit` (used in `ft_parse.c`)
  - `ft_putnbr_fd` (used in `ft_handle_int.c`)

Build dependencies:

- Top-level `Makefile` builds `libft/` first, then `libftprintf.a`.
- Archive is created with `ar`.

# Data Model

`t_flags` in `ft_printf.h` stores parsed format metadata:

- flags: `minus`, `zero`, `sharp`, `plus`, `space`
- `width`
- `precision`
- `precision_set`
- `spec`

Important current state:

- In mandatory behavior, handlers currently only use `spec`.
- Width/precision/flag fields are parsed and stored, but not applied to output.
- This is intentional for mandatory-only scope.

# File-by-File Responsibilities

- `ft_printf.c`
  - Entry point.
  - Main scan loop for the format string.
  - Dispatcher logic to route to handlers based on `spec`.
  - Owns total printed-char accounting.

- `ft_parse.c`
  - Parses format substring after `%`.
  - Initializes `t_flags` and fills fields.
  - Reads flags, width, precision, and final specifier.

- `ft_handle_percent.c`
  - Prints literal `%`.
  - Returns `1`.

- `ft_handle_char.c`
  - Reads `int` from `va_list` (char promotion).
  - Writes single byte.
  - Returns `1`.

- `ft_handle_str.c`
  - Reads `char *`.
  - Prints `(null)` for `NULL`.
  - Otherwise prints bytes until `'\0'`.
  - Returns printed length.

- `ft_handle_int.c`
  - Reads `int`.
  - Prints decimal via `ft_putnbr_fd`.
  - Computes decimal length manually (handles sign and zero).
  - Returns printed length.

- `ft_handle_u.c`
  - Reads `unsigned int`.
  - Prints decimal via recursive helper.
  - Computes length with digit-count helper.
  - Returns printed length.

- `ft_handle_x.c`
  - Reads `unsigned int`.
  - Prints hexadecimal using lookup table argument.
  - Supports both `%x` and `%X` via different lookup strings.
  - Returns printed length.

- `ft_handle_ptr.c`
  - Reads `void *`.
  - For `NULL`, prints `(nil)`.
  - Otherwise prints `0x` + lowercase hex address.
  - Returns printed length.

- `ft_printf.h`
  - Public API (`ft_printf`).
  - `t_flags` type.
  - Internal handler/parser prototypes.

# Resources

- `man 3 printf`
- `man 3 stdarg`
- https://en.cppreference.com/w/c/variadic
- https://en.cppreference.com/w/c/io/fprintf
- 42 subject PDF: `en.subject.pdf`
- 42 norm PDF: `en.norm.pdf`
- AI usage: AI was used for explanations, README file polishing, norm verification.

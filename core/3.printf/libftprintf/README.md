_This project has been created as part of the 42 curriculum by yamir._

# Description

Reimplements `printf` as `ft_printf` and builds it into a static library
(`libftprintf.a`). The goal is to learn variadic arguments, format parsing, and
accurate output/length accounting without using the original `printf` buffer
management.

# Instructions

Build the library:

```sh
make -C libftprintf
```

Output artifact:

- `libftprintf/libftprintf.a`

Local tests (not part of submission):

- `printf_tester/`

# Resources

- `man 3 printf`
- `man 3 stdarg`
- https://en.cppreference.com/w/c/variadic
- https://en.cppreference.com/w/c/io/fprintf
- 42 subject: `printf.en.subject.pdf`
- AI usage: used ChatGPT/Codex for explanations, test case ideas, and draft
  snippets; changes were reviewed and integrated manually.

# Algorithm and Data Structures

The implementation walks the format string left to right:

1. Normal characters are written directly to stdout and counted.
2. On `%`, the format sequence is parsed (flags, width, precision, specifier).
3. The conversion handler (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`)
   prints the formatted value and returns its printed length.

# Bonus

#### Although not finished have began to create the solution:

The parser stores format information in a small struct (`t_flags`) containing:

- flag booleans (`-`, `0`, `#`, `+`, space)
- minimum field width
- precision and a `precision_set` indicator
- conversion specifier

Each handler computes:

- sign/prefix length (for signed numbers or hex prefixes)
- zero padding for precision
- space padding for width

_This project has been created as part of the 42 curriculum by yamir._

# Description

This project implements the `get_next_line` function, which reads and returns one
line at a time from a file descriptor. It focuses on correct line parsing, buffer
management, and safe memory handling.

# Instructions

Build (mandatory):

```
make
```

Rebuild with a specific buffer size:

```
make re BUFFER_SIZE=42
```

Clean:

```
make fclean
```

Bonus (requires bonus source files):

```
make bonus
```

# Algorithm

The function keeps a static stash that stores unread data between calls. Each call
appends new data read from the file descriptor to the stash until a newline is
found or EOF is reached. Once a newline is present, the function splits the stash
into a returned line (including the newline) and the remaining data, which is kept
for the next call. If EOF is reached and the stash still has content, that content
is returned as the final line without a trailing newline. Memory is allocated for
each returned line and for any updated stash, and freed appropriately on errors.

# Resources

- `man 2 read`
- `man 3 malloc`
- 42 subject PDF for `get_next_line`
- Static variables in C
- AI usage: used Codex to review requirements README structure; no code was generated with AI.

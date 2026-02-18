_This project has been created as part of the 42 curriculum by yamir._

# Description

`get_next_line` is a function that reads from a file descriptor and returns one line
per call.

Mandatory behavior:

- Return the next line, including `\n` when present.
- Return the last line without `\n` if file ends without newline.
- Return `NULL` on end of input or on error.
- Preserve unread bytes between calls using a static variable.

# Instructions

cc:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c ../tests/main.c -o gnl_test
```


Output:

- `gnl_test`


# Library Flow (How it Works)

High-level runtime flow:

1. `get_next_line(int fd)` validates `fd` and `BUFFER_SIZE`.
2. It checks static `leftover`:
   - if newline already exists, split immediately and return one line.
3. Otherwise, loop:
   - `read_append(...)` reads up to `BUFFER_SIZE` bytes.
   - new bytes are concatenated to `leftover` with `append(...)`.
   - if newline appears, return `split(&leftover)`.
   - if EOF, stop reading loop.
4. After EOF:
   - if `leftover` still has content, return it once (`flush(...)`).
   - otherwise return `NULL`.

Call graph:

```text
get_next_line
  -> has_n
  -> read_append
     -> read
     -> append
     -> free (old stash)
  -> split
     -> duplicate
     -> free_all (error path)
  -> flush (EOF with remaining content)
  -> clear (read/alloc error path)
```

# Dependencies

External functions allowed/used:

- `read`
- `malloc`
- `free`

Headers:

- `<unistd.h>` for `read`
- `<stdlib.h>` for `malloc`, `free`

Build dependencies:

- Top-level `Makefile` archives object files into `get_next_line.a`.
- Compiler flags: `-Wall -Wextra -Werror`
- Optional define: `-D BUFFER_SIZE=n`

# Data Model

The mandatory implementation uses one persistent static pointer:

- `leftover` in `get_next_line.c`
  - Stores unread tail data between calls.
  - Updated after each read or split.
  - Cleared on fatal error.

Temporary data:

- stack buffer `buf[BUFFER_SIZE + 1]` in `read_append`.
- heap strings returned by `append` / `duplicate`.

# File-by-File Responsibilities

- `get_next_line.c`
  - Public API `get_next_line`.
  - Read loop and decision logic (newline, EOF, errors).
  - Static stash lifecycle (`clear`, `flush`).
  - `read_append` reads and appends fresh bytes.

- `get_next_line_utils.c`
  - `append`: concatenates old stash + fresh read buffer.
  - `has_n`: detects newline in a string.
  - `split`: extracts one line from stash and keeps remainder.
  - internal helpers:
    - `duplicate`: partial/full string copy with allocation.
    - `free_all`: centralized cleanup on split failure.

- `get_next_line.h`
  - Public prototype `get_next_line(int fd)`.
  - Public API only (internal helpers are not exposed).
  - `BUFFER_SIZE` default (`42`) when not defined externally.

# Function-by-Function Purpose

- `get_next_line(int fd)`
  - Main entrypoint.
  - Returns one next line per call, or `NULL`.

- `read_append(int fd, char **stash)` (static)
  - Reads one chunk from `fd`.
  - Appends chunk to `*stash`.
  - Returns read status: `1` data read, `0` EOF, `-1` error.

- `append(char *stash, char *buf)`
  - Allocates and returns concatenation of `stash` + `buf`.

- `has_n(char *s)`
  - Returns `1` if `s` contains `\n`, else `0`.

- `split(char **stash)`
  - Cuts first line from `*stash` (including `\n` if present).
  - Updates `*stash` to unread remainder.
  - Returns allocated line or `NULL` on failure.

- `duplicate(char *s, int len)` (static)
  - Allocates copy of first `len` chars, or full string when `len < 0`.

- `free_all(char **stash, char *line, char *old)` (static)
  - Cleanup helper for split allocation failures.

- `clear(char **stash)` (static)
  - Frees stash and sets it to `NULL`.

- `flush(char **stash)` (static)
  - Returns current stash as final line and resets stash to `NULL`.

- `has_content(char *s)` (static)
  - Returns whether stash contains a non-empty string.

# Algorithm (Choice and Justification)

Chosen approach: incremental buffered reading with a persistent stash.

Why this algorithm:

- Reads only what is needed and stops as soon as a full line is available.
- Handles very small and very large `BUFFER_SIZE` values without logic changes.
- Naturally supports files ending with and without trailing newline.
- Keeps state between calls without global variables (static local pointer only).
- Matches mandatory constraints and allowed function set.

Complexity notes:

- Let `k` be bytes processed in one call.
- Time per call is linear in processed bytes (`O(k)`), with extra copy cost from
  repeated concatenation.
- Memory is proportional to current not-yet-returned data in stash.

# Resources

- `man 2 read`
- `man 3 malloc`
- `man 3 free`
- https://en.cppreference.com/w/c/io/fread
- 42 subject PDF: `get_next_line.en.subject.pdf`
- 42 norm PDF: `en.norm.pdf`
- AI usage: AI was used to improve documentation structure and clarity.

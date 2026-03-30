_This project has been created as part of the 42 curriculum by yoyo._

# 42Berlin

## Description

This repository tracks my progress through the 42 Berlin curriculum and keeps my
project sources, local testers, and supporting documentation in one place.

The current active Level 2 project is `push_swap`. At this stage, the project
already handles argument parsing, integer conversion, duplicate detection, stack
construction, cleanup, index assignment, and the full set of primitive stack
operations. The sorting strategy itself is not implemented yet, so the project
builds cleanly but is not ready for submission.

The repository is organized by training phase:

- `piscine/` for Piscine exercises and rushes
- `pre_core/` for early preparatory work
- `Level_0/` for core level 0 projects
- `level_1/` for core level 1 projects
- `level_2/` for core level 2 projects

Within each project, `_source/` contains the submission-ready code and nearby
test or helper folders are used only for local development.

## Current Progress

### Completed or available in the repo

- `libft`
- `ft_printf`
- `get_next_line`
- `born_2_b_root`
- Piscine and pre-core exercises

### In progress

- `push_swap`

Current `push_swap` status from the code in
`level_2/push_swap/_source/`:

- `Makefile` builds `push_swap`, `ft_printf`, and `libft`
- input parsing accepts split and quoted arguments
- invalid tokens, overflows, and duplicates return `Error\n` on stderr
- stack `a` is built as a linked list
- node indexes are assigned by rank after construction
- `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
  are implemented
- cleanup is present for allocated stack nodes
- `sort.c` is still a stub, so unsorted input is not solved yet

## Instructions

General workflow for this repository:

1. Enter the target project directory.
2. Work in that project's `_source/` directory.
3. Read the subject PDF and confirm allowed functions.
4. Build with the local `Makefile`.
5. Run project-specific tests or local testers when available.
6. Run `norminette` before treating the project as ready.

To build the current `push_swap` work:

```sh
cd level_2/push_swap/_source
make re
```

Example runs:

```sh
./push_swap
./push_swap 42
./push_swap "3 2 1"
./push_swap 1 4 "6 8 9" 3
```

Current behavior of `push_swap`:

- with no arguments, it prints nothing
- on invalid input, it prints `Error` followed by a newline to standard error
- on valid unsorted input, it currently does not emit a sorting sequence because
  the solver is not implemented yet

Submission workflow used in this repository:

1. Copy the contents of the relevant `_source/` directory into a fresh 42
   project repository.
2. Rebuild from scratch.
3. Run `norminette`.
4. Re-run tests and manual checks.
5. Push only after the code matches the subject requirements.

## Norm And Constraints

The repository follows the 42 Norm from [`norm.pdf`](/home/yoyo/code/42berlin/norm.pdf).
The main constraints I am applying across C projects are:

- snake_case naming for files, functions, variables, and types
- 25-line maximum per function
- 80-column maximum per line
- tab-based indentation
- declarations at the top of each function
- `-Wall -Wextra -Werror`
- no unnecessary relinking in Makefiles
- memory must be freed correctly

For `push_swap`, the subject in
[`level_2/push_swap/push_swap.pdf`](/home/yoyo/code/42berlin/level_2/push_swap/push_swap.pdf)
also requires:

- a program named `push_swap`
- integers only, no duplicates
- `Error\n` on stderr for invalid input
- the shortest possible sorting instruction sequence in practice
- instructions separated only by newlines

## Repository Layout

- `piscine/`: early shell and C exercises
- `pre_core/`: preparatory exercises before the common core
- `Level_0/libft/`: custom C standard-library subset
- `level_1/printf/`: `ft_printf`
- `level_1/get_next_line/`: line-by-line file descriptor reader
- `level_1/born_2_b_root/`: system administration project
- `level_2/push_swap/`: stack-sorting project

## Resources

Classic references:

- 42 Norm: [`norm.pdf`](/home/yoyo/code/42berlin/norm.pdf)
- `push_swap` subject:
  [`level_2/push_swap/push_swap.pdf`](/home/yoyo/code/42berlin/level_2/push_swap/push_swap.pdf)
- `man 2 write`
- `man 3 malloc`
- `man 3 free`
- `man 3 exit`
- linked list and stack manipulation references from course notes and standard C
  documentation

AI usage:

- AI was used to review the repository structure, compare the current codebase
  against the `push_swap` subject, extract the relevant README requirements from
  the subject PDF, and rewrite this root `README.md` so it matches the actual
  state of the project.
- AI was not used here to claim missing `push_swap` features as completed; the
  README now explicitly states that the sorting algorithm is still pending.

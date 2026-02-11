# 42Berlin

Personal repository to track my progress through the 42 Berlin curriculum.

## Overview

This repository is organized by curriculum phase and project level. It contains
both submitted project code and local test/support material used during
development and peer-evaluation preparation.

Main goals of this repo:

- Keep project history in one place
- Document implementation choices and constraints
- Make it easy to rebuild, test, and review each project later

## Repository Layout

- `piscine/`
  - Piscine exercises and rushes
- `pre_core/`
  - Early preparatory projects (before Common Core)
- `Level_0/`
  - First Common Core level projects (example: `libft`)
- `level_1/`
  - Intermediate Common Core projects (example: `get_next_line`, `printf`,
    `born_2_b_root`)
- `level_2/`
  - Later Common Core projects (example: `push_swap`)

## Working Conventions

- Mandatory scope first, bonus only when explicitly needed
- Strict 42 Norm compliance before submission
- Build with `-Wall -Wextra -Werror`
- No unnecessary relinking in Makefiles
- Functional behavior verified with project-specific testers
- Memory checked with `valgrind` when relevant

## How To Work In This Repo

1. Enter the target project directory.
2. Read the project subject and verify allowed functions.
3. Build with the local `Makefile`.
4. Run tests from local tester folders (if present).
5. Run `norminette` and fix all reported issues.
6. Re-test after each logic/style fix.

## Readme Policy

Each project README should explain:

- What the project does
- Build/run instructions
- Per-file and per-function responsibilities
- Program flow / algorithm choice
- External dependencies and allowed functions
- Resources used (including how AI was used)

## Notes

- Directory names currently include both `Level_0` and `level_1/level_2`.
  They are intentionally kept as-is to match existing project history.

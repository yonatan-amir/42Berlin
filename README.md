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
  - Early preparatory projects
- `Level_0/`
  - Core level 0 projects
- `level_1/`
  - Core level 1 projects
- `level_2/`
  - Core level 2 projects

Project folder convention:

- `level_X/<project>/_source/`
  - Main project code to copy into a fresh 42 submission repository
- `level_X/<project>/tests/` or `level_X/<project>/*tester/`
  - Local test harnesses that compile against `../_source/...`

## Working Conventions

- Mandatory scope first, bonus only when explicitly needed
- Strict 42 Norm compliance before submission
- Build with `-Wall -Wextra -Werror`
- No unnecessary relinking in Makefiles
- Functional behavior verified with project-specific testers
- Memory checked with `valgrind` when relevant

## How To Work In This Repo

1. Enter the target project directory.
2. Work only inside `_source/` for code changes.
3. Read the project subject and verify allowed functions.
4. Build with `_source/Makefile`.
5. Run tests from local tester folders (if present).
6. Run `norminette` and fix all reported issues.
7. Re-test after each logic/style fix.

## Submission Flow

1. Create/clone the official 42 project repository.
2. Copy content from local `_source/` into that fresh repo.
3. Verify required files and Makefile targets.
4. Run final build + norm + tests.
5. Commit and push to the official 42 repository.

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

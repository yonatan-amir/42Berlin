*This project has been created as part of the 42 curriculum by yoyo.*

<div align="center">

# push_swap

### Architecture-First Implementation (42)

![Language](https://img.shields.io/badge/language-C-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/status-in%20progress-orange?style=for-the-badge)
![Norm](https://img.shields.io/badge/42-Norminette-informational?style=for-the-badge)
![Build](https://img.shields.io/badge/build-make%20re-success?style=for-the-badge)

</div>

<div align="center">
<br>
  <a href="#project-goal"><kbd> <br> Project Goal <br> </kbd></a>&ensp;&ensp;
  <a href="#current-flow"><kbd> <br> Current Flow <br> </kbd></a>&ensp;&ensp;
  <a href="#file-map"><kbd> <br> File Map <br> </kbd></a>&ensp;&ensp;
  <a href="#build-and-run"><kbd> <br> Build & Run <br> </kbd></a>&ensp;&ensp;
  <a href="#next-milestones"><kbd> <br> Next Milestones <br> </kbd></a>
</div>

## Project Goal
`push_swap` sorts unique integers in ascending order using only the allowed operations:
`sa sb ss pa pb ra rb rr rra rrb rrr`

Project success requires both:
- Correctness
- Good operation count

## Current Status
Current phase: **architecture + parser baseline complete, stack/sort implementation pending**.

### Stable now
- `make re` build pipeline works
- Error handling to `stderr` with `Error\n`
- No-output behavior when no arguments
- Numeric conversion and range checks (`INT_MIN` / `INT_MAX`)
- Invalid token rejection
- Duplicate detection on current parsed set

### Pending
- Build real stack/node structures in builder layer
- Implement stack operations (`sa/pb/ra/...`)
- Implement full greedy sorting logic
- Final Norm cleanup and legacy file cleanup

## Current Flow
Runtime flow is now:

1. `main` receives `argc/argv`
2. `parser(...)` returns normalized `int *nums` + `count`
3. `build_program(...)` consumes parsed array and prepares runtime stacks (currently stub)
4. `sort(...)` runs solver and prints operations (currently stub)
5. `clean_program(...)` releases runtime resources

Error flow:
- Any non-zero status from parser/build/sort prints `Error\n` to fd `2` and exits non-zero.

## File Map
### Entry
- `push_swap.c`
Purpose: Orchestrates parser, builder, sorter, and cleanup.

### Contracts and Types
- `push_swap.h`
Purpose: Shared structs (`t_node`, `t_stack`, `t_ps`) and public module entrypoints.

### Parsing
- `parser.c`
Purpose: Parse orchestration and duplicate detection for normalized integer arrays.

- `num_converter.c`
Purpose: Convert one input string into `int *` + count.

### Build
- `build_program.c`
Purpose: Build `t_ps` stacks from parsed integers.
Status: stub.

### Sort
- `sort.c`
Purpose: Execute sorting strategy and emit operations.
Status: stub.

### Cleanup
- `clean_program.c`
Purpose: Free runtime structures owned by `t_ps`.
Status: placeholder.

### Legacy / Planned Cleanup
- `init_program.c`
Purpose: legacy coordinator from earlier flow.
Status: not part of active runtime path.

- `node.c`, `stack.c`
Purpose: earlier experiments and partial helpers.
Status: planned refactor/removal once builder/stack modules are finalized.

## Function Boundaries
- `main`: orchestration only
- `parser`: validation + conversion contract
- `build_program`: data-to-structure construction
- `sort`: algorithm and operation output
- `clean_program`: lifecycle cleanup

## Supported Cases (Current)
- `./push_swap`
- `./push_swap 42`
- `./push_swap "3 2 1"`
- `./push_swap 1 4 "6 8 9" 3`
- `./push_swap "3 2 3"` -> `Error`
- `./push_swap "3 a 1"` -> `Error`
- overflow input -> `Error`

## Build and Run
```bash
cd /home/yoyo/code/42berlin/level_2/push_swap/_source
make re
./push_swap "3 2 1"
```

## Subject Checklist
- Program name: `push_swap`
- No output with no args
- `Error\n` to stderr on invalid input
- Reject invalid int / overflow / duplicates
- Free allocated memory
- Respect Norm in all submitted files

## Next Milestones
1. Finalize parser aggregation for all argv forms in one normalized array.
2. Implement `build_program` to create `stack a` from `nums/count`.
3. Implement stack operations and operation printer.
4. Implement greedy insertion solver.
5. Run full Norm pass and remove legacy files.

## Resources
- Subject PDF: `../push_swap.pdf`
- Norm PDF (repo root): `../../norm.pdf`
- 42 checker binary from intranet resources (`checker_OS`)

_This project has been created as part of the 42 curriculum by yamir._

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

Current phase: **parsing, stack construction and memory management complete, operations + sort pending**.

### Stable now

- `make re` build pipeline works, zero leaks (valgrind clean)
- Error handling to `stderr` with `Error\n`
- No-output behavior when no arguments
- Numeric conversion and range checks (`INT_MIN` / `INT_MAX`)
- Invalid token rejection
- Duplicate detection
- Stack `a` fully built as linked list from parsed integers (`build_program`)
- Memory cleanup for both stacks (`clean_program`)

### Pending

- Implement the 11 stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`)
- Index normalization (rank each value 0..n-1)
- Implement sort algorithm (Turkish/cost-based insertion)
- Delete dead files (`node.c`, `stack.c`)

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
  Purpose: Build stack `a` as a linked list of `t_node` from parsed `int *nums`.
  Status: complete.

### Sort

- `sort.c`
  Purpose: Execute sorting strategy and emit operations.
  Status: stub — to be implemented.

### Cleanup

- `clean_program.c`
  Purpose: Free all nodes in both stacks `a` and `b`.
  Status: complete.

### Legacy / Planned Removal

- `node.c`, `stack.c`
  Purpose: earlier experiments, not in Makefile, not used.
  Status: to be deleted.

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

1. Delete `node.c` and `stack.c` (dead code).
2. Implement the 11 stack operations across `ops_swap.c`, `ops_push.c`, `ops_rotate.c`, `ops_reverse.c`.
3. Add index normalization to `build_program` (rank each value 0..n-1).
4. Implement sort algorithm — hardcoded for 2/3 elements, Turkish cost-based insertion for larger sets.
5. Run full Norm pass (`norminette`).

## Sorting Algorithm: Turkish Algorithm

The chosen algorithm is the **Turkish algorithm** (cost-based greedy insertion sort).

### How it works

1. **Push** everything from stack `a` to stack `b`, except the last 3 elements — while keeping `b` in roughly descending order (largest on top)
2. **Sort** the remaining 3 elements in `a` using hardcoded move sequences
3. **Insert back** — for each element in `b`, calculate the cheapest cost to insert it into its correct position in `a`:
   - Cost = rotations needed in `a` + rotations needed in `b`
   - If both need to rotate the same direction, use `rr` or `rrr` to do both at once (cheaper)
4. Pick the **cheapest** element in `b` each round and push it to `a`
5. Final rotate of `a` to put the smallest element on top

### Why this approach

- Hits the benchmarks: 100 numbers < 700 ops, 500 numbers ≤ 5500 ops
- Conceptually clean — always ask "what's the cheapest next move?"
- Builds naturally on top of the 11 operations

### Index normalization

Before sorting, each node's `index` field is set to its rank (0 = smallest, n-1 = largest). This simplifies comparisons — instead of comparing raw values, the algorithm works with ranks 0..n-1.

## Resources

- Subject PDF: `../push_swap.pdf`
- Norm PDF (repo root): `../../norm.pdf`
- 42 checker binary from intranet resources (`checker_OS`)

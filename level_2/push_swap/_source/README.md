_This project has been created as part of the 42 curriculum by yamir._

<div align="center">

# push_swap

### Architecture-First Implementation (42)

![Language](https://img.shields.io/badge/language-C-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/status-complete-brightgreen?style=for-the-badge)
![Norm](https://img.shields.io/badge/42-Norminette-informational?style=for-the-badge)
![Build](https://img.shields.io/badge/build-make-success?style=for-the-badge)

</div>

<div align="center">
<br>
  <a href="#project-goal"><kbd> <br> Project Goal <br> </kbd></a>&ensp;&ensp;
  <a href="#program-flow"><kbd> <br> Program Flow <br> </kbd></a>&ensp;&ensp;
  <a href="#visual-example"><kbd> <br> Visual Example <br> </kbd></a>&ensp;&ensp;
  <a href="#file-map"><kbd> <br> File Map <br> </kbd></a>&ensp;&ensp;
  <a href="#function-guide"><kbd> <br> Function Guide <br> </kbd></a>&ensp;&ensp;
  <a href="#build-and-run"><kbd> <br> Build & Run <br> </kbd></a>
</div>

## Project Goal

`push_swap` sorts unique integers in ascending order using only the allowed
operations:

`sa sb ss pa pb ra rb rr rra rrb rrr`

Project success requires both:

- Correctness
- Good operation count

This implementation is complete and uses:

- strict parsing and duplicate detection
- linked-list stacks
- index normalization
- direct sorting for very small inputs
- chunk-based pushing from `a` to `b`
- cost-based reinsertion from `b` to `a`

## Current Status

Current phase: **project finished and benchmark-ready**.

### Implemented

- `make` build pipeline
- error handling to `stderr` with `Error\n`
- no-output behavior when no arguments are provided
- numeric conversion with `INT_MIN` / `INT_MAX` protection
- invalid token rejection
- duplicate detection
- full stack construction
- all 11 stack operations
- index assignment
- small sort for 2 and 3 numbers
- chunk-based push phase
- cheapest-move reinsertion phase
- final stack alignment
- full memory cleanup

## Program Flow

Runtime flow:

1. `main` receives `argc/argv`
2. `parser(...)` converts the input into a validated `int *nums` array plus `count`
3. `build_program(...)` transforms that array into linked-list stack `a`
4. `assign_index(...)` gives each node its rank from `0` to `n - 1`
5. `sort(...)` chooses the sorting path:
   - already sorted: do nothing
   - 2 or 3 numbers: direct small sort
   - larger inputs:
     - push chunks from `a` to `b`
     - sort the last 3 nodes in `a`
     - reinsert the cheapest node from `b` into `a`
     - rotate `a` until index `0` is on top
6. operations are printed to standard output
7. `clean_program(...)` frees all memory

### Error Flow

- any parsing or allocation failure prints `Error\n` to file descriptor `2`
- the program then frees what was allocated and exits non-zero

## Visual Example

### Input

```bash
./push_swap 8 3 5 1 6 2 7 4
```

### Step 1: Parse

The parser accepts:

- separate arguments like `./push_swap 3 2 1`
- quoted groups like `./push_swap "3 2 1"`
- mixed input like `./push_swap 1 4 "6 8 9" 3`

After parsing:

```text
[8, 3, 5, 1, 6, 2, 7, 4]
```

### Step 2: Build Stack `a`

```text
top
 a: 8 -> 3 -> 5 -> 1 -> 6 -> 2 -> 7 -> 4
 b: empty
```

### Step 3: Assign Indexes

Each node keeps its value, but also receives a rank:

```text
value:  8  3  5  1  6  2  7  4
index:  7  2  4  0  5  1  6  3
```

The algorithm compares indexes, not raw values.

### Step 4: Push Chunks To `b`

The program pushes selected ranges of small indexes from `a` to `b`.

Conceptually:

```text
a: 7 2 4 0 5 1 6 3
b: -

pb / rb / pb / pb / ...

a: 7 4 5 6
b: 3 1 0 2
```

### Step 5: Sort The Last 3 In `a`

Only 3 nodes remain in `a`, so a direct rule-based sort is used:

```text
a: 7 4 5
-> biggest, smallest, middle
-> apply the matching move sequence
```

After that:

```text
a: 4 5 7
```

### Step 6: Reinsert From `b`

For each candidate in `b`, the algorithm calculates:

- its target position in `a`
- rotations needed in `a`
- rotations needed in `b`
- whether `rr` or `rrr` can reduce total cost

Then it chooses the cheapest node and inserts it.

Conceptually:

```text
a: 4 5 7
b: 3 1 0 2

choose cheapest candidate
rotate a/b
pa
repeat until b is empty
```

### Step 7: Final Alignment

At the end, `a` can be sorted but rotated:

```text
a: 4 5 6 7 8 1 2 3
```

The program finishes by bringing the smallest index to the top:

```text
ra / ra / ...
or
rra / rra / ...
```

Final result:

```text
a: 1 2 3 4 5 6 7 8
```

## Sorting Algorithm: Turkish Algorithm

The chosen algorithm is the **Turkish algorithm**:
a greedy, cost-based insertion strategy.

### How it works

1. Push most nodes from `a` to `b` using chunk thresholds
2. Sort the last 3 nodes in `a`
3. For every node in `b`, compute the cheapest insertion cost
4. Use `rr` or `rrr` when both stacks rotate in the same direction
5. Push the selected node back to `a`
6. Rotate `a` so that index `0` is on top

### Why this approach

- very good operation counts on medium and large inputs
- easy to reason about in phases
- combines well with linked lists and indexed nodes
- allows a clean cost model for reinsertion

## File Map

### Entry

- `push_swap.c`
  Purpose: orchestrates parsing, build, indexing, sorting, and cleanup.

### Contracts And Types

- `push_swap.h`
  Purpose: shared structs (`t_move`, `t_node`, `t_stack`, `t_ps`) and function
  prototypes.

### Initialization And Cleanup

- `init_program.c`
  Purpose: initialize both stacks to a clean empty state.

- `clean_program.c`
  Purpose: free all nodes in both stacks.

### Parsing

- `parser.c`
  Purpose: parse all arguments, merge results, and reject duplicates.

- `num_converter.c`
  Purpose: convert one argument string into validated integers.

### Stack Construction

- `build_program.c`
  Purpose: build stack `a` from the parsed integer array.

### Sorting

- `sort.c`
  Purpose: global sort controller, small sort, chunk pushing, final alignment.

- `insert_chunks.c`
  Purpose: choose the cheapest node from `b` and insert it into `a`.

- `pos_utility.c`
  Purpose: helper functions for target positions, directions, and move costs.

### Operations

- `ops_swap.c`
  Purpose: implement `sa`, `sb`, `ss`.

- `ops_push.c`
  Purpose: implement `pa`, `pb`.

- `ops_rotate.c`
  Purpose: implement `ra`, `rb`, `rr`.

- `ops_r_rotate.c`
  Purpose: implement `rra`, `rrb`, `rrr`.

### Libraries

- `ft_printf/`
  Purpose: custom printf implementation.

- `ft_printf/libft/`
  Purpose: utility library used by `ft_printf` and parser helpers.

## Function Guide

### `push_swap.c`

- `assign_index`
  Scans the nodes in stack `a` and assigns each one its sorted rank.

- `error_exit`
  Frees resources, prints `Error\n`, and returns failure.

- `main`
  Full program entry point.

### `init_program.c`

- `init_program`
  Sets `a` and `b` to empty stacks.

### `clean_program.c`

- `free_stack`
  Frees one linked list.

- `clean_program`
  Frees both runtime stacks.

### `parser.c`

- `check_dup`
  Finds duplicate integers.

- `merge_nums`
  Merges old parsed values with new converted values.

- `append_converted`
  Converts one argument and appends it to the parsed array.

- `parser`
  Main parser entry point.

### `num_converter.c`

- `free_tokens`
  Frees the token array created by `ft_split`.

- `ft_atoi_swap`
  Strict integer conversion with overflow detection.

- `check_spaces`
  Detects if an argument must be split into multiple numbers.

- `tokens_to_nums`
  Converts split tokens into integers.

- `num_converter`
  Main converter for one argument string.

### `build_program.c`

- `new_node`
  Allocates one node.

- `build_program`
  Builds stack `a` from parsed integers.

### `sort.c`

- `sort_small`
  Sorts 2 or 3 nodes directly.

- `get_chunk_size`
  Returns the chunk size used for the current input size.

- `push_chunks`
  Pushes selected ranges from `a` to `b`.

- `is_sorted`
  Checks whether `a` is already sorted.

- `sort`
  Main algorithm controller.

### `insert_chunks.c`

- `apply_joint_rot`
  Executes `rr` or `rrr` when both stacks need the same direction.

- `apply_single_rot`
  Finishes remaining single-stack rotations.

- `execute`
  Performs one full reinsertion move.

- `find_cheapest`
  Picks the cheapest candidate in `b`.

- `insert_chunks`
  Reinserts every node from `b` back into `a`.

### `pos_utility.c`

- `get_cost`
  Returns the shortest rotation cost to reach a position.

- `get_target_pos`
  Finds where an index belongs in stack `a`.

- `set_dirs`
  Chooses forward or reverse direction for a candidate move.

- `get_move_cost`
  Computes total move cost, including combined rotation savings.

- `get_pos`
  Returns the position of a node inside a stack.

### `ops_swap.c`

- `swap`
  Internal swap helper.

- `sa`, `sb`, `ss`
  Swap the top two nodes of one or both stacks.

### `ops_push.c`

- `push`
  Internal push helper.

- `pa`, `pb`
  Move the top node from one stack to the other.

### `ops_rotate.c`

- `rotate`
  Internal forward rotate helper.

- `ra`, `rb`, `rr`
  Rotate one or both stacks upward.

### `ops_r_rotate.c`

- `rotate`
  Internal reverse rotate helper.

- `rra`, `rrb`, `rrr`
  Rotate one or both stacks downward.

## Function Boundaries

The cleanest way to read the code is:

1. `main`
2. `parser`
3. `build_program`
4. `assign_index`
5. `sort`
6. `push_chunks`
7. `sort_small`
8. `insert_chunks`
9. `find_cheapest`
10. `execute`
11. `clean_program`

That order follows the actual life cycle of the program.

## Build And Run

```bash
cd /home/yoyo/code/42berlin/level_2/push_swap/_source
make re
./push_swap "3 2 1"
```

## Subject Checklist

- Program name: `push_swap`
- No output with no args
- `Error\n` to `stderr` on invalid input
- Reject invalid ints, overflow, and duplicates
- Free allocated memory
- Respect Norm in submitted files

## Resources

- Subject PDF: `../push_swap.pdf`
- Norm PDF: `../../norm.pdf`
- 42 checker binary from intranet resources (`checker_OS`)

## AI

- Ai was used in styling This readme file
- Ai was used to expand on my knowledge and to help better document my solution to this task
- Ai was also used styling the make file commands to look like arch linux
- Ai was used in explanation of the subject and understanding.

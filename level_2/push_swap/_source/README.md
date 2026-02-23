*This project has been created as part of the 42 curriculum by yamir.*

# push_swap

## Description
`push_swap` is a constrained sorting project: sort a list of unique integers in ascending order using only two stacks (`a` and `b`) and a limited set of allowed operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

The main objective is not only correctness, but minimizing operation count to meet benchmark targets.

## Current Project State (Living)
- Core data model is defined with linked lists:
  - `t_node`: `value`, `index`, `next`
  - `t_stack`: `head`, `tail`, `size`
  - `t_ps`: stacks `a` and `b`
- Input conversion/parsing is in progress in `push_swap/_source/num_converter.c`.
- `num_converter` currently supports:
  - single token input like `"42"`
  - space-separated token input like `"3 2 1"`
- Conversion validation currently includes:
  - numeric format checks
  - signed integer overflow/underflow checks via `ft_atoi_swap`
  - sign-only input rejection (`"+"`, `"-"`)
- Memory cleanup helpers currently in place:
  - token cleanup via `free_tokens`
  - failure-path cleanup in conversion flow
- Sorting strategy selected: cost-based greedy insertion (not radix).

## Technical Approach and Thought Process
### 1. Parsing first, algorithm second
The project is being built in layers:
1. Guarantee safe and deterministic parsing.
2. Guarantee stable stack primitives.
3. Build sorting logic on top of trusted primitives.

Reasoning: if parsing and memory ownership are unreliable, sorting/debugging quality drops sharply.

### 2. Data structure choice
Singly linked lists are used for stack representation to keep push/pop operations straightforward and to model stack behavior naturally.

### 3. Algorithm choice
Greedy cost-based insertion was chosen to optimize move count in practice for 42 benchmarks:
- evaluate each candidate move cost
- choose cheapest insertion step
- combine rotations when possible (`rr` / `rrr`)

## Instructions
### Build
Project sources are currently under:
- `push_swap/_source`

Build command:
```bash
cd push_swap/_source
make
```

### Run (target behavior)
When implementation is complete:
```bash
./push_swap 2 1 3 6 5 8
./push_swap "3 2 1"
```

### Validation flow (target)
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_OS $ARG
```

## Subject Requirements Checklist
- Program name: `push_swap`
- Inputs: list of integers (stack `a`)
- Output: only instructions, each followed by `\n`
- No output on no arguments
- On error: print `Error\n` to `stderr`
- Handle invalid ints / overflow / duplicates
- Free all heap allocations
- Use allowed functions + libft policy from subject
- Respect Norm on all submitted files

## Benchmarks (from subject)
- 100 numbers: `< 700` operations for top score target
- 500 numbers: `<= 5500` operations for top score target


## Resources
- Official 42 push_swap subject PDF (project root): `push_swap.en.subject.pdf`
- 42 Norm PDF (repository root): `en.norm.pdf`
- Linked-list and complexity references:
  - CLRS (sorting and asymptotic complexity)
  - GeeksforGeeks / CP-algorithms articles on stack operations and greedy heuristics

## AI Usage
- AI has been used to help structure this README.md file
- All code decisions are manually reviewed and adjusted before integration.

## Update Log
- 2026-02-20:
  - Established architecture (`t_ps`, `t_stack`, `t_node`) with linked-list direction.
  - Refined number conversion flow (`num_converter`, `tokens_to_nums`).
  - Improved `ft_atoi_swap` validation behavior and overflow checks.
  - Confirmed greedy insertion direction for sorting strategy.

---

This file is intentionally maintained as a living engineering log. It should be updated after each meaningful implementation milestone.

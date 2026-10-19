# push_swap

![42 School](https://img.shields.io/badge/42-Lisboa-000000?style=flat-square&logo=42&logoColor=white)
![Milestone](https://img.shields.io/badge/milestone-2-informational?style=flat-square)
![Language](https://img.shields.io/badge/language-C-00599C?style=flat-square&logo=c&logoColor=white)
![Algorithm](https://img.shields.io/badge/algorithm-greedy%20cost%20insertion-8A2BE2?style=flat-square)
![Norm](https://img.shields.io/badge/norminette-passing-success?style=flat-square)
![Flags](https://img.shields.io/badge/flags-Wall%20%7C%20Wextra%20%7C%20Werror-critical?style=flat-square)

> Sorting integers with two stacks and eleven instructions — and printing as few instructions as possible.

The program receives a list of integers as stack `a`, with an empty stack `b` beside it. It may only move numbers with eleven instructions — swap the top two, push the top of one stack onto the other, rotate a stack up or down — and its output is the list of instructions that leaves `a` sorted and `b` empty. The grade is not "is it sorted" but "how many instructions did it take": fewer than 700 for 100 numbers, fewer than 5,500 for 500.

That changes what a good sorting algorithm looks like. Comparisons are free — the program can look at both stacks as often as it likes — and only moves cost anything. Quicksort and merge sort are designed to save comparisons, so translating them into rotations wastes moves. The approach here is a greedy insertion that, before every push, computes the exact rotation cost of every candidate and takes the cheapest.

---

## Table of contents

- [Usage](#usage)
- [Building](#building)
- [The instructions](#the-instructions)
- [Algorithm](#algorithm)
- [Data structure](#data-structure)
- [Results](#results)
- [Design notes](#design-notes)
- [Edge cases handled](#edge-cases-handled)
- [What I took away from it](#what-i-took-away-from-it)

---

## Usage

```bash
./push_swap <numbers...>
```

The first argument ends up on top of the stack. Numbers can be given as separate arguments, as one quoted string, or both mixed:

```bash
./push_swap 2 1 3 6 5 8
./push_swap "3 2 1"            # ra, sa
./push_swap "4 67" 3 "87 23"
```

Each instruction is printed on its own line. An already sorted list prints nothing.

To check the result with the 42 checker shipped in the repository:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG     # OK
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l                    # instruction count
```

## Building

```bash
make        # builds libft, then ./push_swap
make clean  # removes obj/
make fclean # removes obj/, the binary and libft.a
make re     # fclean + all
```

Compiled with `-Wall -Wextra -Werror`. `libft` is my own C library from the first project, including `ft_printf`.

## The instructions

| Instruction | Effect |
| --- | --- |
| `sa` / `sb` / `ss` | Swap the first two elements of `a`, of `b`, or of both |
| `pa` / `pb` | Take the top of `b` and put it on `a`, or the top of `a` onto `b` |
| `ra` / `rb` / `rr` | Rotate up: the first element becomes the last — on `a`, `b`, or both |
| `rra` / `rrb` / `rrr` | Rotate down: the last element becomes the first — on `a`, `b`, or both |

`ss`, `rr` and `rrr` are the only way to get two moves for the price of one, and the algorithm is built to use `rr` and `rrr` as often as possible.

## Algorithm

### Small inputs

Two numbers need at most one `sa`. Three numbers are sorted by `sort_three` in at most two instructions: if the largest is on top, `ra`; if it is in the middle, `rra`; then one `sa` if the top two are still out of order. Every one of the six permutations is covered by that rule.

### Everything else

**1. Seed `b`.** Push the first two elements of `a` to `b` with no analysis — there is nothing in `b` to compare against yet.

**2. Push from `a` to `b`, cheapest first, until three are left in `a`** — or until what is left in `a` is already sorted. `b` is kept in *descending* order, read rotationally — it may need rotating, but it is never out of order. For every node in `a`, before every single push:

- Its **target** in `b` is the closest *smaller* number — the node it must sit on top of. If nothing in `b` is smaller, the target is the maximum of `b`, which is where the new minimum belongs in a rotated descending list.
- Its **cost** is the number of rotations to bring it to the top of `a`, plus the number to bring its target to the top of `b`. For a node at position `i` in a stack of length `n`, that is `i` rotations up if it sits in the top half, or `n - i` rotations down if it sits in the bottom half.
- The node with the lowest cost is pushed. If the node and its target are in the same half, the shared part of the journey is done with `rr` or `rrr` first, and only the remainder with single rotations.

**3. Sort the last three in `a`** with `sort_three`.

**4. Push everything back from `b` to `a`.** Now each node's target is the closest *larger* number in `a` — or the minimum of `a` if nothing is larger. Rotate `a` until the target is on top, then `pa`. No cost analysis is needed in this direction: `b` is already in descending order, so its top is always the right next candidate.

**5. Rotate the minimum to the top of `a`**, choosing `ra` or `rra` by which half it sits in.

## Data structure

Each stack is a doubly linked list. Every node carries the number plus the state the cost pass needs:

```c
typedef struct s_node
{
	int				data;
	int				index;         /* position in its stack, refreshed each pass */
	int				push_cost;     /* rotations to bring it and its target up    */
	bool			above_median;  /* top half -> rotate up, bottom -> down      */
	bool			cheapest;      /* the node chosen for the next push          */
	struct s_node	*target_node;  /* where it has to land in the other stack    */
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;
```

Keeping `target_node`, `push_cost` and `above_median` on the node itself separates the two halves of each step: `init_nodes_a` decides what to move and fills the fields, and `move_a_to_b` only reads them and performs the rotations.

## Results

Measured over every order of three numbers and over random inputs drawn from the full `int` range, with every output replayed by an independent checker to confirm the stack ends sorted:

| Size | Runs | Min | Average | Max | Subject limit |
| --- | --- | --- | --- | --- | --- |
| 3 | all 6 orders | 0 | 1.2 | 2 | 3 |
| 5 | 500 | 0 | 8 | 11 | 12 |
| 100 | 500 | 520 | 586 | 659 | 700 |
| 500 | 200 | 5,079 | 5,428 | 5,758 | 5,500 |

All runs sorted correctly. 100 numbers stay under the top-grade limit every time; 500 numbers average under it but go over in roughly a quarter of runs. A 500-number sort takes about 0.09 s, and Valgrind reports no leaks, on success or on error.

## Design notes

- **Exact costs instead of a heuristic.** Chunk-based approaches push numbers to `b` by value range and accept some wasted rotations. Computing every node's real cost before each push is quadratic per push, but at 500 numbers that is still a fraction of a second, and it never pays for a rotation it could have avoided.

- **The median decides the direction.** A node in the top half is reached faster with `ra`, one in the bottom half with `rra`. `current_index` recomputes positions and the `above_median` flag after every move, because every rotation shifts all of them.

- **Shared rotations come first.** When the cheapest node and its target are both in the top half, `rotate_both` issues `rr` until one of them reaches the top, and the single rotations finish the other. The cost formula does not subtract those savings, so it slightly overestimates nodes that would benefit from them — the clearest place to cut moves further.

- **Greedy has a ceiling.** The algorithm only looks one push ahead. That is enough for 100 numbers; for 500, the known next step is to leave the longest already-increasing run in `a` instead of pushing everything to `b`, which removes hundreds of pushes before the greedy part even starts.

- **Parsing builds the list as it validates.** Each argument is split on spaces, each token is checked, converted with an overflow-safe `ft_safe_atoi` that reads into a `long`, compared against the list for duplicates, and appended. Any failure frees the list and the split array before printing `Error`.

## Edge cases handled

| Case | Behaviour |
| --- | --- |
| No arguments, or one empty string | Prints nothing |
| Already sorted | Prints nothing |
| Non-numeric token (`1 a 3`), lone sign (`+`, `-`), double sign (`--2`) | `Error` on stderr, exit 1 |
| Outside `int` range (`2147483648`, `-2147483649`) | `Error` |
| Duplicates, including `0` and `-0` | `Error` |
| A string of only spaces (`" "`) | `Error` |
| `INT_MIN` and `INT_MAX` in the same input | Sorted correctly |

## What I took away from it

- That "the best sorting algorithm" depends on what is being counted. With free comparisons and expensive moves, the right tool was a greedy search over moves, not a textbook sort.
- Doubly linked lists with real pointer surgery — every rotation and push rewires `next` and `prev` on up to four nodes, and an off-by-one leaves a cycle or a dangling `prev`.
- Measuring instead of guessing: an independent checker and a few hundred random runs showed where the algorithm stood against the limits, and where it did not.
- Validation as its own problem: overflow, duplicates and malformed tokens have to be caught before the first instruction is printed, and every error path has to free what was already built.

---

**Author** — Hugo Pinto ([`hguerrei`](https://profile.intra.42.fr/users/hguerrei) · [@Redgtxt](https://github.com/Redgtxt))

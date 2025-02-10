# PUSH_SWAP

## Description

This project aims to sort a list of integers using a limited set of operations on two stacks (`a` and `b`).

An efficient sorting algorithm must be implemented, considering its complexity (*Big O notation*).

🇪🇸 [Leer en Español](README.md)

## Project Structure

### Makefile

- Rules: `all`, `clean`, `fclean`, `re`.
- Must not relink files under any circumstances.

## Function Files

- `push_swap.c`: Main function of the program.
- `check_error_free.c`: Validations and memory management.
- `utils.c`: Auxiliary functions for handling lists.
- `utils_extra.c`: General utility functions.
- `path_to_sort.c`: Algorithms for sorting small lists.
- `algo.c`: Implementation of the sorting algorithm (*Radix*).
- `push.c`: Functions to move elements between stacks.
- `swap.c`: Swap functions.
- `rotate.c`: Functions for rotating elements.
- `reverse_rotate.c`: Functions for reverse rotation.

## Project Rules

- The program works with two stacks (`a` and `b`).
- Initially, `a` contains unsorted numbers, and `b` is empty.
- The objective is to sort `a` in ascending order with the fewest moves possible.
- Only a limited set of operations can be used (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

## Algorithm Used

**Radix Sort** has been implemented, optimized with bitwise operators to reduce the number of buckets and improve performance.

Each number is processed by analyzing its bits and distributing them into stacks efficiently until they are sorted in ascending order.

## Allowed Functions

- `read`, `write`, `malloc`, `free`, `exit`.
- `ft_printf` and any other function from **libft**.

## Bonus

A **checker** is included to verify if the generated instruction sequence correctly sorts the stack.
The bonus part consists in making your own checker.

## Final Considerations

This project has been a practical introduction to complexity analysis and algorithm optimization. **Big O notation** has been studied, different sorting strategies have been explored, and an efficient solution using *bitwise operations* has been implemented.



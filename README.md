This project has been created as part of the 42 curriculum by **miloalex**
# push_swap

`push_swap` is a sorting algorithm project from the 42 curriculum.

The goal is to sort a stack of integers using a limited set of operations, while keeping the number of operations as low as possible.

This implementation uses **TurkSort**, a cost-based sorting strategy that determines which element should be moved from one stack to the other at each step.

---


## Description

The program receives a list of integers and sorts them using two stacks:

* **Stack A** — contains the input numbers.
* **Stack B** — used as auxiliary storage.

At the beginning, all numbers are placed in stack A.

The program must output a sequence of valid operations that leaves the numbers sorted in ascending order in stack A.

### Example

```text
Input:

4 67 3 87 23

Output:

sa
pb
ra
pb
...
```

The exact sequence depends on the implementation and sorting strategy.

---

## Instructions

Only the following operations are allowed:

* `sa`
* `sb`
* `ss`
* `pa`
* `pb`
* `ra`
* `rb`
* `rr`
* `rra`
* `rrb`
* `rrr`

No other operations may be used to manipulate the stacks.

The objective is to produce a valid sorting sequence while minimizing the total number of operations.

---

## Available Operations

### Swap

| Operation | Description                            |
| --------- | -------------------------------------- |
| `sa`      | Swap the first two elements of stack A |
| `sb`      | Swap the first two elements of stack B |
| `ss`      | Perform `sa` and `sb` simultaneously   |

### Push

| Operation | Description                        |
| --------- | ---------------------------------- |
| `pa`      | Push the first element of B onto A |
| `pb`      | Push the first element of A onto B |

### Rotate

| Operation | Description                          |
| --------- | ------------------------------------ |
| `ra`      | Rotate A upward                      |
| `rb`      | Rotate B upward                      |
| `rr`      | Perform `ra` and `rb` simultaneously |

### Reverse Rotate

| Operation | Description                            |
| --------- | -------------------------------------- |
| `rra`     | Rotate A downward                      |
| `rrb`     | Rotate B downward                      |
| `rrr`     | Perform `rra` and `rrb` simultaneously |

---

# Algorithm

This project uses **TurkSort**, a cost-based sorting algorithm designed specifically for `push_swap`.

Instead of blindly moving elements between the stacks, the algorithm evaluates the available moves and chooses an element that can be moved efficiently.

The general process is:

```text
        Stack A
           │
           │
           ▼
      Calculate costs
           │
           ▼
    Find cheapest move
           │
           ▼
   Rotate both stacks
           │
           ▼
        Push
           │
           ▼
      Repeat until
      B is sorted
           │
           ▼
    Push everything
       back to A
```

---

## TurkSort

The main idea behind TurkSort is to calculate the cost of moving each candidate element from one stack to the other.

For each element, the algorithm determines:

1. Where the element currently is.
2. Where the element needs to go.
3. How many rotations are required.
4. Whether rotations can be performed simultaneously.
5. The total cost of the move.

The element with the lowest calculated cost is selected.

## Already Sorted

If the input is already sorted:

```bash
./push_swap 1 2 3 4 5
```

the program should produce no output.

---

## Invalid Input

The program should detect invalid input such as:

### Duplicate numbers

```bash
./push_swap 1 2 3 2
```

### Non-numeric input

```bash
./push_swap 1 2 hello 4
```

### Integer overflow

```bash
./push_swap 2147483648
```

For invalid input, the program should print:

```text
Error
```

---


# Testing

A useful way to test the program is to pipe its output into the 42 `checker` program.

Example:

```bash
ARG="4 67 3 87 23"

./push_swap $ARG | ./checker_linux $ARG
```

A successful sort should return:

```text
OK
```

You can also count the number of operations:

```bash
./push_swap $ARG | wc -l
```

This is useful for evaluating the efficiency of the algorithm.

---

## Random Testing

For larger tests, generate random numbers and check the result:

```bash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')

./push_swap $ARG | ./checker_linux $ARG
```

The checker should report:

```text
OK
```

You can then measure the number of operations:

```bash
./push_swap $ARG | wc -l
```

---

# Makefile

The project supports the usual Makefile commands:

```bash
make
make clean
make fclean
make re
```

| Command       | Description                        |
| ------------- | ---------------------------------- |
| `make`        | Compile the project                |
| `make clean`  | Remove object files                |
| `make fclean` | Remove object files and executable |
| `make re`     | Recompile the project              |

---

# Concepts Used

This implementation makes use of several important concepts:

* Linked lists
* Stack manipulation
* Sorting algorithms
* Target-node calculation
* Cost calculation
* Rotation optimization
* Input parsing
* Error handling
* Algorithmic complexity

TurkSort is particularly useful for `push_swap` because it combines target positioning with operation-cost optimization.

---

# Goal

The goal of `push_swap` is not simply to sort the numbers.

It is to find an efficient sequence of operations using only the operations allowed by the project.

TurkSort approaches this by repeatedly asking:

> **Which element can I move to its correct position with the lowest cost?**

By calculating targets and combining rotations whenever possible, the number of operations can be significantly reduced.

---

# Resources

* 42 `push_swap` subject
* C documentation and standard library references
* Linked-list and stack data-structure documentation
* Algorithm and sorting references

---

## Author

**Milo**

42 Network

---

⭐ If you found this project useful, feel free to star the repository.

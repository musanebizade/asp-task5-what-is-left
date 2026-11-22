#  What is left? (e-olymp 1964)

Musa Nabizada - CSCI 6221 Advanced Software Paradigms, Assignment 5

Solution of the e-Olymp problem "What is left?" in two languages:

- `CPP` - imperative solution (C++)
- `Haskell` - functional solution (Haskell)

Problem: https://www.eolymp.com/en/problems/1964
## Problem

The numbers from 1 to n are written in a row. The moves repeat in this order until one number remains:

1. remove numbers at even positions
2. remove numbers at odd positions
3. remove numbers at positions divisible by 3

Positions are renumbered after every move. The task is to print the last remaining number (1 <= n <= 10^8).

Example: for n = 10 the sequence goes 1..10 -> 1 3 5 7 9 -> 3 7 -> 3 7 -> 3, so the answer is 3.

## C++ solution

The numbers are stored in a `vector<int>`. In every move the elements that stay are copied to the front of the same array, and only the size is updated. This way no second array is needed, and one move is a single pass over the current elements. The `keep` function decides if a position stays for the current move, and `step` goes 0, 1, 2, 0, ... after each move.

Since the array loses at least a third of its elements every three moves, the total work is a small multiple of n.

## Haskell solution

The three moves are functions on lists:

- `keepOdd` keeps the elements at odd positions
- `keepEven` keeps the elements at even positions
- `skipThird` removes every third element

`solve` takes the infinite list `cycle [keepOdd, keepEven, skipThird]` and applies one move at a time until the list has exactly one element. No variables or loops are used, only recursion and pattern matching.

Haskell lists are lazy, so the numbers from `[1 .. n]` are produced and consumed one by one. The full list of 10^8 numbers is never stored in memory, which is why the memory usage stays very small.

## Results on e-Olymp

| Language | Score | Time | Memory |
|---|---|---|---|
| C++ | 100 / 100 | 521 ms | 382.4 MB |
| Haskell | 100 / 100 | 2183 ms | 4.5 MB |

C++ needs more memory because it keeps the whole array of n integers. Haskell is slower per element because of the lazy list overhead, but it uses almost no memory.

## How to run

C++:

    cd CPP
    g++ -O2 main.cpp -o main
    echo 10 | ./main

Haskell:

    cd Haskell
    runghc Main.hs

Both read n from standard input.
# Project Euler

C++ solutions to the [Project Euler](https://projecteuler.net/) problem set, as posed on the
[HackerRank Project Euler track](https://www.hackerrank.com/contests/projecteuler).

Each problem gets its own directory (`euler001`, `euler002`, ...) containing a single
`solution.cpp`. Solutions read multiple test cases from `stdin` (first line: number of cases `T`,
followed by `T` lines of input) and print one answer per line, matching HackerRank's judge format.

## Build & run

```
g++ -O2 -std=c++20 -o solution eulerNNN/solution.cpp && ./solution < input.txt
```

## euler001 — Multiples of 3 and 5

Sum every natural number below `N` that is a multiple of 3 or 5, for each of `T` given values
of `N`.

Closed-form solution: sum the multiples of 3, add the multiples of 5, subtract the multiples of
15 (inclusion–exclusion, since numbers divisible by both would otherwise be counted twice). No
loop over the range is needed — the answer for any `N` is computed directly via the triangular-
number formula, so runtime is `O(1)` per query.

Status: **Accepted**, 100%.

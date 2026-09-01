# Project Euler

C++ solutions to the [Project Euler](https://projecteuler.net/) problem set, as posed on the
[HackerRank Project Euler track](https://www.hackerrank.com/contests/projecteuler).

Each problem lives in its own directory (`euler001`, `euler002`, ...) with a single
`solution.cpp`. Solutions read multiple test cases from `stdin` — first line is the number of
cases `T`, followed by `T` lines of input — and print one answer per line.

## Build & run

```
g++ -O2 -std=c++20 -o solution eulerNNN/solution.cpp && ./solution < input.txt
```

## Problems

| # | Problem | Status |
|---|---|---|
| [001](euler001) | Multiples of 3 and 5 | Accepted, 100% |
| [002](euler002) | Even Fibonacci numbers | Accepted, 100% |
| [003](euler003) | Largest prime factor | Accepted, 100% |

Each problem's own directory has a README (the write-up: approach, why it works, and — where one
exists — a picture of the idea) and a `spec.md` (RFC-style requirements and acceptance criteria for
that solution). Shared write-ups that don't belong to any single problem — the methods themselves,
each with its own picture — live in [`memory-bank/`](memory-bank/_terms.md).
